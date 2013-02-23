//
//  output.cpp
//  Flame_Fractal
//
//  Created by Bunny on 2/23/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#include "output.h"

using namespace std;

Output::Output(){}
Output::Output(vector<numty> & data, string & name) {
    _name = name;
    _data = & data;
}

Output::Output(string & name){
    _name = name;
    _data = nullptr;
}

Output::~Output(){}

bool Output::writeTxt(bool overWrite) {
    if (_name.empty()) return false;
    string fileName = _name;
    ofstream myfile (fileName);
    if (overWrite) myfile.seekp(ios::beg);
    else myfile.seekp(ios::end);
    
    if (myfile.is_open()) {
        for (int i = 0; i < _data->size(); i++ )
            myfile << (*_data)[i]<<"; ";
        myfile.close();
        return true;
    }
    else {
        cout << "Unable to open file";
        return false;
    }
}