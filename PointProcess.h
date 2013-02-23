//
//  PointProcess.h
//  Flame_Fractal
//
//  Created by Jiali Mei on 2/20/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#ifndef __Flame_Fractal__PointProcess__
#define __Flame_Fractal__PointProcess__

#include <iostream>
#include "Transformation.h"

class PointProcess {
private:
    numty * _xtraj;
    numty * _ytraj;
    int _steps;
    
public:
    PointProcess();
    ~PointProcess();
    void run();
};

#endif /* defined(__Flame_Fractal__PointProcess__) */
