//
//  Transformation.cpp
//  Flame_Fractal
//
//  Created by Jiali Mei on 2/20/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#include "Transformation.h"

Transformation::Transformation(){
    _ppara = NULL;
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

std::vector<numty> Transformation::getInput() const {
    return _input;
}

std::vector<numty> Transformation::getOutPut() const {
    return _output;
}

void Transformation::push(const numty x, const numty y) {
    _input[0] = x; _input[1] = y;
}

void Transformation::preTrans(int whichPre){
    // linear transformation using parameters of preTrans
    if (_step != 0) {
        std::cout<<"wrong order in transformation"<<std::endl;
        return;
    }
    
    std::vector<numty> tmp = _ppara->getPreTrans(whichPre);
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

void Transformation::nonLinTrans() {
    if (_step != 1) {
        std::cout<<"wrong order in transformation"<<std::endl;
        return;
    }
    numty ranNonLin = rand()%BIG/BIG;
    int which = 0; numty tmp = 0; // reinitiate
    while (ranNonLin > tmp) {
        tmp += _ppara->getProbaNonLin()[which];
        which++;
    }
    which = which-1;
    _ppara->_nonLinTrans[which](_interm[0],_interm[1], &_output[0]);
    //std::cout<<"r.v.: "<<which<<"    ";

    _step = 0;
    
}

void Transformation::multiTrans(){
    
    // linear transformation
    // srand(time(NULL));
    numty ranLin = float(rand()%RANGE)/RANGE;
    int which = 0; numty tmp = 0;
    std::vector<numty> probLin = _ppara->getProbaLin();
    while (ranLin > tmp){
        tmp += probLin[which];
        if (tmp < 1) which ++;
    }
    std::vector<numty> paraLin = _ppara->getPreTrans(which);
    _interm[0] = paraLin[0]* _input[0] + paraLin[1]* _input[1] + paraLin[2];
    _interm[1] = paraLin[3]* _input[0] + paraLin[4]* _input[1] + paraLin[5];

    // non linear transformation
    numty ranNonLin = float(rand()%RANGE)/RANGE;
    which = 0; tmp = 0; // reinitiate
    std::vector<numty> probNonLin = _ppara->getProbaNonLin();
    while (ranNonLin > tmp) {
        tmp += probNonLin[which];
        if (tmp < 1) which++;
    }
    _ppara->_nonLinTrans[which](_interm[0],_interm[1], &_output[0]);
}