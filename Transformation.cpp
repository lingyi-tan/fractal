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
    _interm.assign(2, 0);
    _output.assign(2, 0);
    _step = 0;
}

Transformation::Transformation(Parameters & para) {
    _ppara = & para;
    _input.assign(2, 0);
    _interm.assign(2, 0);
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

void Transformation::push(const numty x, const numty y) {
    _input[0] = x; _input[1] = y;
}

void Transformation::preTrans(){
    // linear transformation using parameters of preTrans
    if (_step != 0) {
        std::cout<<"wrong order in transformation"<<std::endl;
        return;
    }
    
    std::vector<numty> tmp = _ppara->getPreTrans();
    _interm[0] = tmp[0]* _input[0] + tmp[1]* _input[1] + tmp[2];
    _interm[1] = tmp[3]* _input[0] + tmp[4]* _input[1] + tmp[5];
    _step = 1;
}

/*void Transformation::postTrans(){
    if (_step != 2) {
        std::cout<<"wrong order in transformation"<<std::endl;
        return;
    }
    // linear transformation using parameters of preTrans
    std::vector<numty> tmp = _ppara->getPostTrans();
    _output[0] = tmp[0]* _interm[2] + tmp[1]* _interm[3] + tmp[2];
    _output[1] = tmp[3]* _interm[2] + tmp[4]* _interm[3] + tmp[5];
    _step = 0;
}*/

void Transformation::nonLinTrans(Rgen & engine) {
    if (_step != 1) {
        std::cout<<"wrong order in transformation"<<std::endl;
        return;
    }
    
    std::vector<numty> probab = _ppara->getProba();

    //Problem with random number generator !!!!
    DiscFdr whichTrans (probab.begin(),probab.end());
    // random generator machine
    int which = whichTrans(engine);
    _ppara->_nonLinTrans[which](_interm[0],_interm[1], &_output[0]);
    //std::cout<<"r.v.: "<<which<<"    ";

    _step = 0;
    
}

void Transformation::multiTrans(Rgen & engine){
    std::vector<numty> pre = _ppara->getPreTrans();
    _interm[0] = pre[0]* _input[0] + pre[1]* _input[1] + pre[2];
    _interm[1] = pre[3]* _input[0] + pre[4]* _input[1] + pre[5];
    std::vector<numty> probab = _ppara->getProba();
    
    //Problem with random number generator ?
    
    DiscFdr whichTrans (probab.begin(),probab.end());
    // random generator machine
    int which = whichTrans(engine);
    _ppara->_nonLinTrans[which](_interm[0],_interm[1], &_output[0]);
  
}