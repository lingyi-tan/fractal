//
//  test.cpp
//  Flame_Fractal
//
//  Created by Bunny on 2/23/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#include "test.h"

void Test::_test_vector(){
    std::vector<numty> newx;
    numty tmp;
    int i;
    std::cout<<"enter 10 numbers :\n"<<std::endl;
    for (i = 0; i < 3; i++){
        std::cin>>tmp;
        newx.push_back(tmp);
    }
    std::cout<<"\n the registered input is:\n ";
    for (i = 0; i < newx.size(); i++) {
        std::cout<<newx[i]<<"-"<< *newx.begin()<<"\n";
    }
    newx.erase(newx.begin(), newx.end());
    newx.erase(newx.begin(), newx.end());
    for (i = 0; i < newx.size(); i++) {
        std::cout<<newx[i]<<"-"<< *newx.begin()<<"\n";
    }
    
}

void Test::_test_transform() {
    Parameters para;
    Transformation newTrans(para);
    newTrans.push(0.5,0.5);
    std::vector<numty> probab = para.getProba();
    
    std::default_random_engine generator;
    std::discrete_distribution<int> distribution(probab.begin(), probab.end());
    
    Rgen eng;
    for (int j = 0; j<10; j ++) {
        newTrans.preTrans();
        newTrans.nonLinTrans(eng);
        
        //newTrans.postTrans();
        //or use multiTrans instead to save some time
        
        //newTrans.multiTrans(eng);
        std::vector<numty> point1 = newTrans.getOutPut();
        for (int i = 0; i<point1.size(); i++)
            std::cout<<point1[i]<<", ";
        std::cout<<"\n";
    }
    std::cout<<"voila"<<std::endl;
}

void Test::_test_pointProcess(){
    Parameters para;
    Transformation newTrans(para);
    newTrans.push(0.5,0.5);
    std::vector<numty> probab = para.getProba();
    
    std::default_random_engine generator;
    std::discrete_distribution<int> distribution(probab.begin(), probab.end());
    
    Rgen eng;
    PointProcess newProcess;
    std::vector<numty> xcord;
    std::vector<numty> ycord;
    std::cout<<"start !"<<std::endl;
    for (int r = 0 ; r <10; r++) {
        newProcess.start(2000, eng, para);
        xcord = newProcess.getXcord();
        ycord = newProcess.getYcord();
        std::cout<<"iteration :" <<r;
        
        // the coordinates to be sent to pointsets !
    }
    std::cout<<"finish !"<<std::endl;
}