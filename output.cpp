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

void Output::reset(){
    ofstream myfile;
    myfile.open(_name,ios::trunc);    
}

bool Output::writeTxt(bool overWrite) {
    if (_name.empty()) return false;
    //string fileName = _name;
    ofstream myfile;
    if (overWrite) {
        myfile.open(_name,ios::trunc);
        myfile.seekp(ios::beg);
    }
    else {
        myfile.open(_name,ios::app);
        myfile.seekp(ios::end);
    }
    
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