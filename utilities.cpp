//
//  utilities.cpp
//  Flame_Fractal
//
//  Created by Bunny on 2/21/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#include "utilities.h"


static bool isContract( std::vector<numty> par){
    if (par.size() != 6) return false;
    numty det, trace, eig1, eig2;
    det = par[0]*par[4]-par[1]*par[3];
    trace = par[0] + par[4];
    eig1 = (trace + sqrt(trace*trace - 4*det))/2;
    eig2 = trace-eig1;
    return (eig1*eig1<=1 && eig2*eig2<=1);    
}

static bool isValidPoint(numty x, numty y){
    return (x>=LEFT && x<=RIGHT && y>=BOTTOM && y<=TOP);
}

static void errMessage(bool wrong) {
    if (wrong) throw "error here !";
}