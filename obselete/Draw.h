//
//  Draw.h
//  Flame_Fractal
//
//  Created by Jiali Mei on 2/20/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#ifndef __Flame_Fractal__Draw__
#define __Flame_Fractal__Draw__

#include <iostream>
#include <Carbon/carbon.h>
#include <OpenGL/glu.h>
#include <OpenGL/gl.h>
#include "PointSet.h"
#include "Parameters.h"

class Draw{
private:
    std::vector<numty> _pprePointsX;
    std::vector<numty> _pprePointsY;
    std::vector<int> _hits; //to see later
    std::vector<int> _postPoints; //to see later
    
public:
    Draw(PointSet);
    ~Draw();
    void arrange();
    void run();
    void Reshape();
    void Display();
};

#endif /* defined(__Flame_Fractal__Draw__) */
