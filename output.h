//
//  output.h
//  Flame_Fractal
//
//  Created by Bunny on 2/23/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#ifndef __Flame_Fractal__output__
#define __Flame_Fractal__output__

#include <iostream>
#include <fstream>
#include "utilities.h"

class Output {
    std::string _name;
    std::vector<numty> * _data;
public:
    Output();
    Output(std::vector<numty> & data, std::string & name);
    Output(std::string & name);
    ~Output();
    void reset();
    bool writeTxt(bool overWrite);
};

#endif /* defined(__Flame_Fractal__output__) */
