//
//  PointProcess.cpp
//  Flame_Fractal
//
//  Created by Jiali Mei on 2/20/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#include "PointProcess.h"

<<<<<<< HEAD
#define MAXWALK 30
#define NONPLOT 20

PointProcess::PointProcess(){}
PointProcess::~PointProcess(){}

std::vector<numty> PointProcess::getXcord(){
    if (_xtraj.empty()){
        std::cout<<"empty process !\n"<<std::endl;
    }
    return _xtraj;
}

std::vector<numty> PointProcess::getYcord(){
    if (_ytraj.empty()) {
        std::cout<<"empty process !\n"<<std::endl;
    }
    return _ytraj;
}

void PointProcess::postTrans(Parameters & pparam){
    // final transformation to give it a certain symetry...
    std::vector<numty> tmp = pparam.getPostTrans();
    for (int i = 0; i < _xtraj.size(); i++) {
    _xtraj[i] = tmp[0]* _xtraj[i] + tmp[1]* _ytraj[i] + tmp[2];
    _ytraj[i] = tmp[3]* _xtraj[i] + tmp[4]* _ytraj[i] + tmp[5];
    }
    
}

void PointProcess::start(int iter, Rgen & eng, Parameters & pparam){
    UnifFdr runif(-1,1);
    _xtraj.erase(_xtraj.begin(),_xtraj.end());
    _ytraj.erase(_ytraj.begin(),_ytraj.end());
    Transformation transformer(pparam);
    
    for (int it = 0; it < iter; it ++){
        _xtraj.push_back(runif(eng));
        _ytraj.push_back(runif(eng));
        std::vector<numty> tmpx = _xtraj;
        std::vector<numty> tmpy = _ytraj;
        for (int i = 0; i < MAXWALK; i++){
            transformer.push(*tmpx.end(),*tmpy.end());
            /*transformer.preTrans();
            transformer.nonLinTrans(eng);
            transformer.postTrans();*/
            /* or use multiTrans instead to save some time */
            
            transformer.multiTrans(eng);
            
            tmpx.push_back(transformer.getOutPut()[0]);
            tmpy.push_back(transformer.getOutPut()[1]);
            if (i >= NONPLOT) {
                _xtraj.push_back(tmpx.at(i));
                _ytraj.push_back(tmpy.at(i));
                
            }
        }
        
    }
=======
PointProcess::PointProcess(){
    
}

PointProcess::~PointProcess(){
    
}

void PointProcess::run(){
    
>>>>>>> ca699032b77c17fa26f3458bf3b0260ae5c702ba
}