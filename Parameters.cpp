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

}
Parameters::~Parameters(){}

const int Parameters::getCount(){
    return _k;
}

const std::list<numty> Parameters::getProba() {
    return _prob;
}

const numty * Parameters::getPreTrans(){
    return _preTrans;
}

const numty * Parameters::getPostTrans(){
    return _postTrans;
}

void Parameters::update() {
    // simple update, DEBUG purpose
    _prob = {1,0,0,0, 0,0,0,0, 0,0,0,0}; // 12 probas
    _k = 1;
    numty a[6] = {1,1,0,1,1,0};
    for (int i = 0; i<6; i++) {
        _preTrans[i] = a[i];
        _postTrans[i] = a[i];
    }
}

// still need to define function isContract