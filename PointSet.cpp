//
//  PointSet.cpp
//  Flame_Fractal
//
//  Created by Jiali Mei on 2/20/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//
#define MAXWALK 30
#define NONPLOT 20

#include "PointSet.h"

PointSet::PointSet(int n, Parameters &para){
    std::cout<<n<<std::endl;
    _Nsim = n;
    std::cout<<_Nsim<<std::endl;
    _para = para;
    runProcess();
}

PointSet::~PointSet(){

}

void PointSet::runProcess(){
    std::cout<<_Nsim<<std::endl;
    for (int i = 0;i<_Nsim;i++){
//        std::cout<<i<<std::endl;
        PointProcess point;
        point.start(_Nsim, _para);
        pointReceiver(point.getXcord(),point.getXcord());
    }
}

void PointSet::pointReceiver(std::vector<numty> newPointsX,std::vector<numty> newPointsY){
//    std::cout<<1<<std::endl;
    for (unsigned i=NONPLOT; i<MAXWALK; i++){
//        std::cout<<newPointsX[i]<<std::endl;
        _prepointsX.push_back(newPointsX[i]);
        _prepointsY.push_back(newPointsY[i]);
    }
}

std::vector<numty> PointSet::getPointsX(){
    std::vector<numty> x = _prepointsX;
//    for (unsigned i=0; i<(MAXWALK-NONPLOT)*_Nsim; i++){
//        std::cout<<x[i]<<std::endl;
//        _prepointsX.push_back(x[i]);
//    }
    return x;
}

std::vector<numty> PointSet::getPointsY(){
    std::vector<numty> y = _prepointsY;
    return y;
}