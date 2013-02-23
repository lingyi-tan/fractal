//
//  PointSet.cpp
//  Flame_Fractal
//
//  Created by Jiali Mei on 2/20/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#include "PointSet.h"

PointSet::PointSet(int x, int y, int n){
    _height = x;
    _width = y;
    _Nsim = n;
}

PointSet::~PointSet(){

}

void PointSet::runProcess(int iter, Rgen & gen, Parameters & par){
    for (int i = 0;i<_Nsim;i++){
        PointProcess point;
        point.start(iter, gen, par);
    }
}

void PointSet::pointReceiver(std::vector<numty> newPointsX,std::vector<numty> newPointsY){
    for (unsigned i=0; i<newPointsX.size(); i++){
        _prepointsX.push_back(newPointsX[i]);
        _prepointsY.push_back(newPointsY[i]);
    }
}

void PointSet::arrange(){
    
}

std::vector<numty> PointSet::getPointsX(){
    std::vector<numty> x = _prepointsX;
    return x;
}

std::vector<numty> PointSet::getPointsY(){
    std::vector<numty> y = _prepointsY;
    return y;
}