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
#include "PointProcess.h"

class WrapperPointSet{
    private:
        int _nsim; //Number of initial points
        std::vector<numty> _prepointsX; //table of the positions of the points received from PointProcess
        std::vector<numty> _prepointsY; //table of the positions of the points received from PointProcess
        
    public:
        WrapperPointSet();
        ~WrapperPointSet();
        void go(int N, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int n10, int n11, int n12, int n13, int numLin);
        std::vector<numty> getPointsX(); //provides the X values of the points
        std::vector<numty> getPointsY(); //provides the Y values of the points
};


#endif /* defined(__Flame_Fractal__Wrapper__) */
