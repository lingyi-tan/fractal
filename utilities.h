//
//  utilities.h
//  Flame_Fractal
//
//  Created by Bunny on 2/21/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#ifndef __Flame_Fractal__utilities__
#define __Flame_Fractal__utilities__

#define LEFT -1
#define RIGHT 1
#define TOP 1
#define BOTTOM -1
#define TINY 0.00001

#include <iostream>
#include <random>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef std::default_random_engine Rgen;
typedef std::discrete_distribution<int> DiscFdr;
typedef std::uniform_real_distribution<double> UnifFdr;
typedef float numty;

static bool isContract( std::vector<numty> );
static bool isValidPoint (numty x, numty y);
static void errMessage(bool);


#endif /* defined(__Flame_Fractal__utilities__) */
