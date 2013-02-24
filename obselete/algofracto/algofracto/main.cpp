//
//  main.cpp
//  algofracto
//
//  Created by Bunny on 1/11/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//


#include "fractal.h"


#define DMAX 1000000

using namespace std;


double * twonum(double * lala)
{
    if (lala == NULL) lala = (double *)malloc(sizeof(double)*2);
    lala[0] = 5; lala[1] = 5;
    return lala;
    
}

int main(int argc, const char * argv[])
{

    // insert code here...
    //set random number
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::minstd_rand0 lulululu (seed); // minstd_rand0 is a standard linear_congruential_engine
    
    cout<<"start";
    int randvect[DMAX];
    for (int i = 0; i < DMAX; i ++) randvect[i] = lulululu()/lulululu.max();
    std::cout << "end Hello, World!\n"<<lulululu.max()<<endl;
    double lala[2];
    lala[0]=1; lala[1]=2;
    twonum(lala);
    cout<<"1115%34="<<1115%34<<endl;
    
    
    // main part
    double* coeff = NULL;
    // test of contrCoeff
    coeff = fractal::contrCoeff(coeff);
    cout<<"coeff:";
    //for (int i = 0; i <PMAX; i++)    cout<<coeff[i]<<", ";
    double * cor = NULL;
    cor = (double *) malloc(sizeof(double)*2);
    cor[0] = 1; cor[1]=2;
    // test of linTrans
    for (int i = 0;  i < 30; i++) {
        cor = fractal::linTrans(cor, 1, coeff);
        cout<<"cordinates:"<<cor[0]<<","<<cor[1]<<endl;
    }    
    
    //test of fractalhit
    unsigned int * points = NULL;
    points = fractal::fractalHit(points, 100, 100, 500, 20);
    cout<<"points : ";
    for (int i = 0;  i < 30; i++) cout<<points[i]<<",";
    return 0;
}

