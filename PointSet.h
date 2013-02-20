//
//  PointSet.h
//  Flame_Fractal
//
//  Created by Jiali Mei on 2/20/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#ifndef __Flame_Fractal__PointSet__
#define __Flame_Fractal__PointSet__

#include <iostream>
#include <vector>
#include "PointProcess.h"

class PointSet {
    int _height;
    int _width;
    int _Nsim;
    float * _ppoints;
    int * _phits;
    float * _ppostPoints;
    
public:
    PointSet(int, int, int);
    ~PointSet();
    void runProcess();
    void pointReceiver(float *);
    void arrange();
    
};

#endif /* defined(__Flame_Fractal__PointSet__) */
