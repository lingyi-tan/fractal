//
//  Wrapper.cpp
//  Flame_Fractal
//
//  Created by Jiali Mei on 2/23/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#include "WrapperPointSet.h"

WrapperPointSet::WrapperPointSet(){

//    std::cout <<_nsim<<std::endl;
    srand(time(NULL));
    std::vector<numty> _prepointsX;
    std::vector<numty> _prepointsY;
}

WrapperPointSet::~WrapperPointSet(){

}


void WrapperPointSet::go(int N, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10, int n11, int n12, int n13, int numLin){
    _nsim = N;
//    std::cout <<_nsim<<std::endl;
    bool bools[12] = {(bool)n2,(bool)n3, (bool)n4, (bool)n5, (bool)n6, (bool)n7, (bool)n8, (bool)n9, (bool)n10, (bool)n11, (bool)n12, (bool)n13};
    std::vector<bool> whichNonLin;
    for(int i =0;i<12;i++){
        whichNonLin.push_back(bools[i]);
    }
    Parameters para;
    para.update(whichNonLin, numLin);
    PointProcess pointprocess;
    pointprocess.start(_nsim, para);
    _prepointsX = pointprocess.getXcord();
    _prepointsY = pointprocess.getYcord();
}

std::vector<numty> WrapperPointSet::getPointsX(){
//    std::cout<<30<<std::endl;
    std::vector<numty> x = _prepointsX;
//    for (unsigned i=0; i<(30-20)*_nsim; i++){
//        std::cout<<x[i]<<std::endl;
//        _prepointsX.push_back(x[i]);
//    }
    return x;
}

std::vector<numty> WrapperPointSet::getPointsY(){
    std::vector<numty> y = _prepointsY;
    return y;
}