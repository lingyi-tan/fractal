//
//  Wrapper.cpp
//  Flame_Fractal
//
//  Created by Jiali Mei on 2/23/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#include "WrapperPointSet.h"

WrapperPointSet::WrapperPointSet(int N){
    int _nsim = N;
    srand(time(NULL));
    std::vector<numty> _prepointsX;
    std::vector<numty> _prepointsY;
}

void WrapperPointSet::go(){
    Parameters para;
    para.update();
    PointSet pointset(_nsim, para);
    _prepointsX = pointset.getPointsX();
    _prepointsY = pointset.getPointsY();
}

std::vector<numty> WrapperPointSet::getPointsX(){
    std::vector<numty> x = _prepointsX;
    return x;
}

std::vector<numty> WrapperPointSet::getPointsY(){
    std::vector<numty> y = _prepointsY;
    return y;
}