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
    Parameters * _pparam;
    std::vector<numty> _xtraj;
    std::vector<numty> _ytraj;
public:
    PointProcess();
    ~PointProcess();
    void postTrans(Parameters & pparam);
    std::vector<numty> getXcord();
    std::vector<numty> getYcord();
    void start(int iter, Parameters & pparam);
};

#endif /* defined(__Flame_Fractal__PointProcess__) */
