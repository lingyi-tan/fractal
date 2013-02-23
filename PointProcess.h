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
<<<<<<< HEAD
    Parameters * _pparam;
    std::vector<numty> _xtraj;
    std::vector<numty> _ytraj;
    int _steps;
public:
    PointProcess();
    ~PointProcess();
    void postTrans(Parameters & pparam);
    std::vector<numty> getXcord();
    std::vector<numty> getYcord();
    void start(int iter, Rgen & eng, Parameters & pparam);
=======
private:
    numty * _xtraj;
    numty * _ytraj;
    int _steps;
    
public:
    PointProcess();
    ~PointProcess();
    void run();
>>>>>>> ca699032b77c17fa26f3458bf3b0260ae5c702ba
};

#endif /* defined(__Flame_Fractal__PointProcess__) */
