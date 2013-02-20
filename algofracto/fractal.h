//
//  fractal.h
//  algofracto
//
//  Created by Bunny on 1/11/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#ifndef __algofracto__fractal__
#define __algofracto__fractal__

#include <iostream>
#include <random>
#include <chrono>
#include <math.h>
#include <stdio.h>


// define maximum number of parameters
#define PMAX 18
// mixture of transformations 0,1,2... MIX
// normally (MIX + 1)*6 = PMAX
#define MIX 2
#define PI 3.1415926
#define UNIT 1



// initialize coefficients of contract linear transformations
class fractal{
public:
static double * contrCoeff(double * coeff);

static double * linTrans(double * loc, int k, double * coeff);

static double * nonLinTrans(double * loc, int k);



static unsigned int * fractalHit(unsigned int * points, int xrange, int yrange, int sample, int iter);
};

#endif /* defined(__algofracto__fractal__) */

