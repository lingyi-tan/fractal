//
//  fractal.cpp
//  GlutProject
//
//  Created by Bunny on 1/3/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include "fractal.h"

#define RANDR(lo,hi) ((lo) + (((hi)-(lo)) * drand48()))

int
random_bit (void)
{
    return random () & 01;
}

/* from Paul Bourke */
void
ContractiveMapping (coeff * coeff)
{
    double a, b, d, e;
    
    do
    {
        do
        {
            a = drand48 ();
            d = RANDR (a * a, 1);
            if (random_bit ())
                d = -d;
        }
        while ((a * a + d * d) > 1);
        do
        {
            b = drand48 ();
            e = RANDR (b * b, 1);
            if (random_bit ())
                e = -e;
        }
        while ((b * b + e * e) > 1);
    }
    while ((a * a + b * b + d * d + e * e) >
           (1 + (a * e - d * b) * (a * e - d * b)));
    
    coeff->ac = a;
    coeff->bc = b;
    coeff->cc = RANDR (-2, 2);
    coeff->dc = d;
    coeff->ec = e;
    coeff->fc = RANDR (-2, 2);
}