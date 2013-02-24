//
//  utilities.h
//  Flame_Fractal
//
//  Created by Bunny on 2/21/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#ifndef __Flame_Fractal__utilities__
#define __Flame_Fractal__utilities__

#define LEFT -2
#define RIGHT 2
#define TOP 2
#define BOTTOM -2
#define TINY 0.00001
#define BIG 10000
#define RANGE 500

#include <iostream>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//typedef std::default_random_engine Rgen;
//typedef std::discrete_distribution<int> DiscFdr;
//typedef std::uniform_real_distribution<double> UnifFdr;
typedef float numty;

static bool isContract( std::vector<numty> par){
    if (par.size() != 6) return false;
    numty det, trace, eig1, eig2;
    det = par[0]*par[4]-par[1]*par[3];
    trace = par[0] + par[4];
    eig1 = (trace + sqrt(trace*trace - 4*det))/2;
    eig2 = trace-eig1;
    return (eig1*eig1<=1 && eig2*eig2<=1);
}

static bool isValidPoint (numty x, numty y){
    return (x>=LEFT && x<=RIGHT && y>=BOTTOM && y<=TOP);
}

static void errMessage(bool wrong) {
    if (wrong) throw "error here !";
}


#endif /* defined(__Flame_Fractal__utilities__) */
