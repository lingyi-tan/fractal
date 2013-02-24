//
//  Wrapper.cpp
//  Flame_Fractal
//
//  Created by Jiali Mei on 2/23/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#include "WrapperPointSet.h"

WrapperPointSet::WrapperPointSet(){

    std::cout <<_nsim<<std::endl;
    srand(time(NULL));
    std::vector<numty> _prepointsX;
    std::vector<numty> _prepointsY;
}

WrapperPointSet::~WrapperPointSet(){

}


void WrapperPointSet::go(int N){
    _nsim = N;
//    std::cout <<_nsim<<std::endl;
    Parameters para;
//    para.update();
    PointSet pointset(_nsim, para);
    _prepointsX = pointset.getPointsX();
    _prepointsY = pointset.getPointsY();
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