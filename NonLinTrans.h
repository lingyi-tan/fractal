//
//  NonLinTrans.h
//  Flame_Fractal
//
//  Created by Jiali Mei on 2/20/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#ifndef __Flame_Fractal__NonLinTrans__
#define __Flame_Fractal__NonLinTrans__

#include "utilities.h"
#include <iostream>
#include <math.h>

// Need to add functions to check validity !!!!!
// or one step to check the range in each function

inline numty norm(numty x, numty y){
    return sqrtf(x*x+ y*y);
}

// 1
static void sinus (const numty x , const numty y, numty * output){
    output[0] = sinf(x);
    output[1] = sinf(y);
}

// 2
static void spheric (const numty x , const numty y , numty * output){
    output[0] = x/norm(x,y);
    output[1] = y/norm(x,y);
}

// 3
static void swirl (const numty x , const numty y , numty * output){
    output[0] = x*sinf(x*x+y*y) - y*cos(x*x+y*y);
    
}

// 4
static void horseshoe (const numty x , const numty y , numty * output){
    numty r = norm(x,y);
    output[0] = (x-y)*(x+y)/r;
    output[1] = 2*x*y/r;
}

// 5
static void polar (const numty x , const numty y , numty * output){
    output[0] = atanf(y/x)/M_PI;
    output[1] = norm(x,y) - 1;
}

// 6
static void hankerchief (const numty x , const numty y , numty * output){
    numty r = norm(x,y);
    output[0] = r * sinf(atanf(y/x) + r);
    output[1] = r * cosf(atanf(y/x) + r);
}

// 7
static void heart (const numty x , const numty y , numty * output){
    numty r = norm(x,y);
    output[0] = r * sinf(atanf(y/x)*r);
    output[1] = -r * cosf(atanf(y/x)*r);
}

// 8
static void disc (const numty x , const numty y , numty * output){
    numty r = norm(x,y);
    output[0] = atanf(y/x) * sinf(M_PI*r)/M_PI;
    output[1] = atanf(y/x) * cosf(M_PI*r)/M_PI;
}

// 9
static void spiral (const numty x , const numty y , numty * output){
    numty r = norm(x,y);
    output[0] = (sinf(atanf(y/x)) + cosf(r))/r;
    output[1] = (sinf(atanf(y/x)) - cosf(r))/r;
}

// 10
static void hyperbolic (const numty x , const numty y , numty * output){
    numty r = norm(x,y); numty the = atanf(y/x);
    output[0] = sinf(the)/r;
    output[1] = r * cosf(the);
}

// 11
static void diamond (const numty x , const numty y , numty * output){
    numty r = norm(x,y); numty the = atanf(y/x);
    output[0] = sinf(the)*cosf(r);
    output[1] = cosf(the)*sinf(r);
}

// 12
static void ex (const numty x , const numty y , numty * output){
    numty r = norm(x,y); numty the = atanf(y/x);
    numty p0 = sinf(the+r); numty p1 = cosf(the + r);
    output[0] = r*(p0*p0*p0 + p1*p1*p1);
    output[1] = r*(p0*p0*p0 - p1*p1*p1);

}

// maybe not useful
class nonLinTrans {
    void (* _pnonLinTrans)(const numty, const numty, numty);
};

#endif /* defined(__Flame_Fractal__NonLinTrans__) */

