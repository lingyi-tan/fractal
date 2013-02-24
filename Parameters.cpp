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

// updata parameters through specifying which non linear trans to be used, and how many non linear to be used.
void Parameters::update(std::vector<bool> whichNonLin, int numLin, int Nsim) {
    // the length of the bool vector has to be 12
    _Nsim = Nsim;
    numty normConst = 0;
    for (int i = 0; i <12; i++) normConst += numty(whichNonLin[i]);
    for (int i = 0; i<12; i++){
        _probNonLin.at(i) = numty(whichNonLin[i])/normConst;
    }

    _probLin.assign(12, 0);
    for (int i = 0; i<numLin; i++)
        _probLin.at(i) = 1/float(numLin);
    
    // generate linear parameters in a random way
    std::vector<numty> tmp;
    tmp.assign(60, 0);
    for (int i = 0; i<60; i++) tmp.at(i) = numty(rand()%RANGE)/RANGE;
    for (int i = 0; i<12; i++){
        _preTrans[i].at(0) = tmp.at(5*i)*cosf(tmp.at(5*i+2));
        _preTrans[i].at(1) = -tmp.at(5*i+1)*sinf(tmp.at(5*i+2));
        _preTrans[i].at(2) = tmp.at(5*i+3);
        _preTrans[i].at(3) = tmp.at(5*i)*sinf(tmp.at(5*i+1));
        _preTrans[i].at(4) = tmp.at(5*i+1)*cosf(tmp.at(5*i+2));
        _preTrans[i].at(2) = tmp.at(5*i+4);
    }

}

// still need to define function isContract