//
//  Transformation.cpp
//  Flame_Fractal
//
//  Created by Jiali Mei on 2/20/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#include "Transformation.h"
#include "Parameters.h"
#include "utilities.h"

Transformation::Transformation(){
    _ppara = nullptr;
    _input.assign(2, 0);
    _interm.assign(4, 0);
    _output.assign(2, 0);
    _step = 0;
}

Transformation::Transformation(Parameters & para) {
    _ppara = & para;
    _input.assign(2, 0);
    _interm.assign(4, 0);
    _output.assign(2, 0);
    _step = 0;
}

Transformation::~Transformation(){}

const std::vector<numty> Transformation::getInput(){
    return _input;
}

const std::vector<numty> Transformation::getOutPut(){
    return _output;
}

void Transformation::push(const std::vector<numty> input) {
    _input = input;
}

void Transformation::preTrans(){
    // linear transformation using parameters of preTrans
    if (_step != 0) {
        std::cout<<"wrong order in transformation"<<std::endl;
        return;
    }
    
    _interm[0] = _ppara->getPreTrans()[0]* _input[0] + _ppara->getPreTrans()[1]* _input[1] + _ppara->getPreTrans()[2];
    _interm[1] = _ppara->getPreTrans()[3]* _input[0] + _ppara->getPreTrans()[4]* _input[1] + _ppara->getPreTrans()[5];
    _step = 1;
}

void Transformation::postTrans(){
    if (_step != 2) {
        std::cout<<"wrong order in transformation"<<std::endl;
        return;
    }
    // linear transformation using parameters of preTrans
    _output[0] = _ppara->getPostTrans()[0]* _interm[2] + _ppara->getPostTrans()[1]* _interm[3] + _ppara->getPreTrans()[2];
    _output[1] = _ppara->getPostTrans()[3]* _interm[2] + _ppara->getPostTrans()[4]* _interm[3] + _ppara->getPreTrans()[5];
    _step = 3;
}

void Transformation::nonLinTrans() {
    if (_step != 1) {
        std::cout<<"wrong order in transformation"<<std::endl;
        return;
    }
    
    Rgen engine;
    
    //Problem with random number generator !!!! 
    DiscFdr whichTrans (_ppara->getProba().begin(),_ppara->getProba().end());
    // random generator machine
    
    _ppara->_nonLinTrans[whichTrans(engine)](_interm[0],_interm[1], &_interm[2]);
   // _ppara->_nonLinTrans[4](_interm[0],_interm[1], &_interm[2]);
    // draw a number (with the predefined probability) to decide which non linear transformation to be used.
    _step = 2;
    
}

