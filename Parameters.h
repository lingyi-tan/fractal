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
#include <vector>
#include <iostream>
#include <list>

class Parameters {
    int _k;  // number of chosen non linear transformation functions
    std::vector<numty> _prob; // probability attributed to each non linear transformation
    std::vector<numty> _preTrans;  // matrix of pre-linear-transformation
    std::vector<numty> _postTrans; // matrix of post-linear-transformation
    
public:
    Parameters(); //initialization, default value? 
    ~Parameters();
   
    // pointer array pointing to 12 non linear transformations
    void (* _nonLinTrans[12])(const numty, const numty, numty *) = {sinus, spheric, swirl, horseshoe, polar, hankerchief, heart, disc, spiral, hyperbolic, diamond, ex};
    
    void update(); // better way to exchange with iostream?
    const std::vector<numty> getProba();
    const int getCount();
    const std::vector<numty> getPreTrans();
    const std::vector<numty> getPostTrans();
    bool isContract(bool isPreTrans);
    
};

#endif /* defined(__Flame_Fractal__Parameters__) */
