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
#include "utilities.h"


class Parameters {
    int _k;  // number of chosen non linear transformation functions
    std::vector<numty> _probNonLin; // probability attributed to each non linear transformation
    std::vector<numty> _probLin; // probability of linear transformation
    std::vector<numty> _preTrans[12];  // matrices of pre-linear-transformation
    // the number of pre- transformation should equal the number of non- linear - transformation.
    std::vector<numty> _postTrans; // matrix of post-linear-transformation
    
public:
    Parameters(); //initialization, default value? 
    ~Parameters();
   
    // pointer array pointing to 12 non linear transformations
    void (* _nonLinTrans[12])(const numty, const numty, numty *) = {sinus, spheric, swirl, horseshoe, polar, hankerchief, heart, disc, spiral, hyperbolic, diamond, ex};
    
    void update(std::vector<bool> whichNonLin, int numLin); // better way to exchange with iostream?
    std::vector<numty> getProbaNonLin() const;
    std::vector<numty> getProbaLin() const;
    int getCount() const;
    std::vector<numty> getPreTrans(int which) const;
    std::vector<numty> getPostTrans() const;
    
};

#endif /* defined(__Flame_Fractal__Parameters__) */
