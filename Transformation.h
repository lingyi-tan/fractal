//
//  Transformation.h
//  Flame_Fractal
//
//  Created by Jiali Mei on 2/20/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#ifndef __Flame_Fractal__Transformation__
#define __Flame_Fractal__Transformation__

#include <iostream>
#include "Parameters.h"
#include "NonLinTrans.h"

class Transformation {
    Parameters * _ppara; // all transformation use the same set of parameters
    int _step;
    std::vector<numty> _input;    // coordinates of input point
    std::vector<numty> _interm;   // coordinates of intermediate results (one after preTrans, and one after nonLinTrans)
    std::vector<numty> _output;   // coordinates of output point

public:
    Transformation();
    Transformation(Parameters &);
    ~Transformation();
    const std::vector<numty> getOutPut();
    const std::vector<numty> getInput();
    void push(const std::vector<numty>);  //
    void preTrans();
    void nonLinTrans();
    void postTrans();
    //void allTrans();
    
};

#endif /* defined(__Flame_Fractal__Transformation__) */
