//
//  Parameters.cpp
//  Flame_Fractal
//
//  Created by Jiali Mei on 2/20/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#include "Parameters.h"


// NEED to check parameters' validity, some robustness test !! 


Parameters::Parameters(){
    numty id[6] = {1,0,0, 0,1,0};
    for (int i = 0; i<6; i++){
        _preTrans.push_back(id[i]);
        _postTrans.push_back(id[i]);
    }
    _k = 0;
    
}

Parameters::~Parameters(){}

const int Parameters::getCount(){
    return _k;
}

const std::vector<numty> Parameters::getProba() {
    return _prob;
}

const std::vector<numty> Parameters::getPreTrans(){
    return _preTrans;
}

const std::vector<numty> Parameters::getPostTrans(){
    return _postTrans;
}

void Parameters::update() {
    // simple update, DEBUG purpose
    _prob.assign(11, 0);
    _prob.push_back(1);
    _k = 1;
    _preTrans.erase(_preTrans.begin(),_preTrans.end());
    _postTrans.erase(_postTrans.begin(), _postTrans.end());
    numty tild[6] = {0.5,0.5,0, 0.5,-0.5,0};
    for (int i = 0; i<6; i++){
        _preTrans.push_back(tild[i]);
        _postTrans.push_back(tild[i]);
    }
    _k = 0;
}

// still need to define function isContract