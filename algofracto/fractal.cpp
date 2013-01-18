//
//  fractal.cpp
//  algofracto
//
//  Created by Bunny on 1/11/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#include "fractal.h"

using namespace std;

double * contrCoeff(double * coeff)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distribution(0, 1);
    auto runif = std::bind(distribution, generator);
    
    coeff = (double *) malloc(sizeof(double)*PMAX);
    if (coeff == NULL) {cout<<"malloc failure"<<endl; return NULL;}
    for (int i = 0; i <= MIX; i++) {
        // rotation plus translation, no flip !!!
        double theta = runif()*2*PI; double mux = runif(); double muy = runif();
        coeff[i*6+0] = cos(theta);
        coeff[i*6+1] = -sin(theta);
        coeff[i*6+2] = mux*UNIT;
        coeff[i*6+3] = sin(theta);
        coeff[i*6+4] = cos(theta);
        coeff[i*6+5] = muy*UNIT;
    }
    return coeff;
}


double * linTrans(double * loc, int k, double * coeff)
{
    if (k<0||k>MIX)
    {
        cout<<"asking for unavailable transformation function!"<<endl;
        return NULL;
    }
    double result[2];

    result[0] = coeff[k*6]*loc[1] + coeff[k*6+1]*loc[2] + coeff[k*6+2];
    result[1] = coeff[k*6+3]*loc[1] + coeff[k*6+4]*loc[2] + coeff[k*6+5];
    loc[0] = result[0];
    loc[1] = result[1];
    return loc;
}

double * nonLinTrans(double * loc, int k)
{
    if (k<0||k>MIX)
    {
        cout<<"asking for unavailable transformation function!"<<endl;
        return NULL;
    }
    double result[2];
    double x = loc[0]; double y = loc[1];
    double r = sqrt(x*x + y*y);
    switch (k)
    {
        case 0:
            result[0] = x;
            result[1] = y;
            break;
        case 1:
            result[0] = sin(x);
            result[1] = sin(y);
            break;
        case 2:
            
            result[0] = x/r;
            result[1] = y/r;
            break;
        case 3:
            result[0] = x*sin(r*r)-y*cos(r*r);
            result[1] = x*cos(r*r)+y*sin(r*r);
            break;
        case 4:
            result[0] = (x-y)*(x+y)/r;
            result[1] = 2*x*y/r;
            break;
        default:
            cout<<"Beyond the scope of defined functions..."<<endl;
            break;
    }
    
    loc[0] = result[0];
    loc[1] = result[1];
    return loc;

}




unsigned int * fractalHit (unsigned int * points, int xrange, int yrange, int sample, int iter)
{
    // coefficients of linear transformation, outer and inner
    double * innerCoeff = nullptr;
    double * outerCoeff = nullptr;
    
    innerCoeff = contrCoeff(innerCoeff);
    outerCoeff = contrCoeff(outerCoeff);
    
    points = (unsigned int *)malloc(sizeof(unsigned int)*xrange*yrange);
    for (int i = 0; i < xrange*yrange; i++) {
        points[i]=0;
    }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<int> dist1(0, xrange*yrange);
    std::uniform_real_distribution<double> dist2(0, 1);
    auto runif = std::bind(dist1, generator);
    auto runif1 = std::bind(dist2, generator);
    
    double * cor = NULL;
    cor = (double *) malloc(sizeof(double)*2);
    cor[0] = 0; cor[1] = 0;
    // simple, unorganized sampling, can be improved later on
    for (int s = 0; s < sample; s++)
    {
        int index = runif();
        
        // NEED TO ADJUST THE SUBSCRIPT : COR !!!
        cor[0] = (index % xrange)/xrange - 0.5; //centralized cordinates of x-axis
        cor[1] = (index % yrange)/yrange - 0.5; //centralized cordinates of y-axis
        for (int step = -20; step < iter; step++)
        {            
            cor = linTrans(cor, (int)(runif1()*MIX), innerCoeff); // inner linear transformation
            cor = nonLinTrans(cor, (int)(runif1()*MIX)); // variation, non linear
            cor = linTrans(cor, ((int)runif1()*MIX), outerCoeff ); // outer linear transformation
            
            // if it goes out of the border !!!!
            if (abs(cor[0])>=0.5 ) cor[0] = 0.25/cor[0];
            else if (abs(cor[1])>=0.5) cor[1] = 0.25/cor[1];
            if (step > 0)
            {
                points[(int)(cor[0]+0.5)*xrange*yrange + (int)(cor[1]+0.5)*yrange] += 1;
                // add a function to specify the way of coloring ?????
            }
        }
        
    }
    return points;
}






















