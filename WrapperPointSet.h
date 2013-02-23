//
//  Wrapper.h
//  Flame_Fractal
//
//  Created by Jiali Mei on 2/23/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#ifndef __Flame_Fractal__Wrapper__
#define __Flame_Fractal__Wrapper__

#include "utilities.h"
#include "Parameters.h"

class WrapperPointSet{
private:
    int _nsim; //Number of initial points
    std::vector<numty> _prepointsX; //table of the positions of the points received from PointProcess
    std::vector<numty> _prepointsY; //table of the positions of the points received from PointProcess
    
public:
    WrapperPointSet(int);
    ~WrapperPointSet();
    void go();
    std::vector<numty> getPointsX(); //provides the X values of the points
    std::vector<numty> getPointsY(); //provides the Y values of the points
};

#endif /* defined(__Flame_Fractal__Wrapper__) */
