//
//  test.h
//  Flame_Fractal
//
//  Created by Bunny on 2/23/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#ifndef __Flame_Fractal__test__
#define __Flame_Fractal__test__

#include <iostream>
#include <vector>
#include <math.h>
#include "utilities.h"
#include "Transformation.h"
#include "Parameters.h"
#include "PointProcess.h"
//#include "output.h"

//#include "QApplication"
//#include "QPushButton"


class Test{
public:
    void _test_vector();
    void _test_random();
    void _test_transform();
    void _test_pointProcess( Parameters & );
    void _test_qt();
    void _test_output();
};

#endif /* defined(__Flame_Fractal__test__) */
