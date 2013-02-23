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
    _prob.assign(12, 1);
    //_prob.push_back(1);
    _k = 12;
    
}

Parameters::~Parameters(){}

int Parameters::getCount() const {
    return _k;
}

std::vector<numty> Parameters::getProba() const{
    return _prob;
}

std::vector<numty> Parameters::getPreTrans() const {
    return _preTrans;
}

std::vector<numty> Parameters::getPostTrans() const{
    return _postTrans;
}

void Parameters::update() {
    // simple update, DEBUG purpose
    _k = 1;
    _preTrans.erase(_preTrans.begin(),_preTrans.end());
    _postTrans.erase(_postTrans.begin(), _postTrans.end());
    numty tild[6] = {0.5,0.5,0, 0.5,-0.5,0};
    for (int i = 0; i<6; i++){
        _preTrans.push_back(tild[i]);
        _postTrans.push_back(tild[i]);
    }
}

// still need to define function isContract