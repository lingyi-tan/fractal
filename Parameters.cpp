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
    _postTrans.assign(6, 0);
    _postTrans.at(0) = _postTrans.at(4) = 1;
    for (int k = 0; k<12; k++) {
        _preTrans[k].assign(6, 0);
        _preTrans[k].at(0) = _preTrans[k].at(4) = 0.5;
        _preTrans[k].at(2) = _preTrans[k].at(5) = 0.5*(k%4==0);
        if (k%4 == 3) _preTrans[k] = _postTrans;
    }
    _prob.assign(12, 0);
    _prob.at(0) = 1;
    _k = 1;
    
}

Parameters::~Parameters(){}

int Parameters::getCount() const {
    return _k;
}

std::vector<numty> Parameters::getProba() const{
    return _prob;
}

std::vector<numty> Parameters::getPreTrans(int which) const {
    return _preTrans[which];
}

std::vector<numty> Parameters::getPostTrans() const{
    return _postTrans;
}

// does not do anything !!!
void Parameters::update() {
    // simple update, DEBUG purpose

}

// still need to define function isContract