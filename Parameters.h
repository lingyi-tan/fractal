//
//  Parameters.h
//  Flame_Fractal
//
//  Created by Jiali Mei on 2/20/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#ifndef __Flame_Fractal__Parameters__
#define __Flame_Fractal__Parameters__

#include "NonLinTrans.h"
#include <iostream>
#include <list>

class Parameters {
    int _k;  // number of chosen non linear transformation functions
    std::list<numty> _prob; // probability attributed to each non linear transformation
    numty _preTrans[6];  // matrix of pre-linear-transformation
    numty _postTrans[6]; // matrix of post-linear-transformation
    
public:
    Parameters(); //initialization, default value? 
    ~Parameters();
   
    // pointer array pointing to 12 non linear transformations
    void (* _nonLinTrans[12])(const numty, const numty, numty *) = {sinus, spheric, swirl, horseshoe, polar, hankerchief, heart, disc, spiral, hyperbolic, diamond, ex};
    
    void update(); // better way to exchange with iostream?
    const std::list<numty> getProba();
    const int getCount();
    const numty * getPreTrans();
    const numty * getPostTrans();
    bool isContract(bool isPreTrans);
    
};

#endif /* defined(__Flame_Fractal__Parameters__) */
