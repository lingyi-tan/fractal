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
        _preTrans[k].at(5) = 0.5*(k%4==0);
        _preTrans[k].at(2) = 0.5*(k%4==1);
        if (k%4 == 3) _preTrans[k] = _postTrans;
    }
    _probNonLin.assign(12, 0);
    _probNonLin.at(0) = 1;
    _probLin.assign(12, 1.0/12.0);
    _k = 1;
    
}

Parameters::~Parameters(){}

int Parameters::getCount() const {
    return _k;
}

std::vector<numty> Parameters::getProbaNonLin() const{
    return _probNonLin;
}

std::vector<numty> Parameters::getProbaLin() const{
    return _probLin;
}

std::vector<numty> Parameters::getPreTrans(int which) const {
    return _preTrans[which];
}

std::vector<numty> Parameters::getPostTrans() const{
    return _postTrans;
}

// does not do anything !!!
//void Parameters::update() {
    // simple update, DEBUG purpose

//}u

// still need to define function isContract