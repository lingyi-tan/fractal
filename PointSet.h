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
    int _height; //height of the window
    int _width; //width of the window
    int _Nsim; //number of initial points to take
    std::vector<numty> _prepointsX; //table of the positions of the points received from PointProcess
    std::vector<numty> _prepointsY; //table of the positions of the points received from PointProcess
    
public:
    PointSet(int x, int y, int n); //initialization
    ~PointSet(); //
    void runProcess(int iter, Rgen & gen, Parameters & par);  //creates an object of the class PointProcess to do a recurrence in order to find a group of points to include in the graph
    void pointReceiver(std::vector<numty>,std::vector<numty>); //receives positions of points to include
    void arrange(); //arranges the points in small boxes so that colour options could be applied
    std::vector<numty> getPointsX(); //provides the X values of the points
    std::vector<numty> getPointsY(); //provides the Y values of the points
    
};

#endif /* defined(__Flame_Fractal__PointSet__) */
