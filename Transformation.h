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
    numty _input[2];    // coordinates of input point
    numty _interm[4];   // coordinates of intermediate results (one after preTrans, and one after nonLinTrans)
    numty _output[2];   // coordinates of output point

public:
    Transformation();
    Transformation(const Parameters &);
    ~Transformation();
    const numty * getOutPut();
    const numty * getInput();
    void push(const numty * );  //
    void preTrans();
    void nonLinTrans();
    void postTrans();
    //void allTrans();
    
};

#endif /* defined(__Flame_Fractal__Transformation__) */
