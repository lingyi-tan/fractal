//
//  main.cpp
//  Flame_Fractal
//
//  Created by Jiali Mei on 2/20/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//
#include <iostream>
#include <math.h>
#include <boost/python/module.hpp>
#include "Parameters.h"
#include "Transformation.h"
#include "NonLinTrans.h"
#include "PointProcess.h"
#include "PointSet.h"
#include "test.h"

int main(int argc, char * argv[]){
    
    std::cout << "Hello, World\n";
    
    Test testNew;
    //testNew._test_vector();
    Rgen rgen;
    
    
    // 1. initialize parameters
    
    static Parameters para;
    para.update();
    
    // 2. initialize transformation
    
//    testNew._test_transform();
    
    // 3. point process
   
//    testNew._test_pointProcess();
   // 4. point set
    PointSet pointset(20000, rgen, para);
    pointset.runProcess();
    

    // 5. draw
    
/*    numty x = 0.5; numty y = 0.5;
    numty lulu[4]={0,0,0,0};
    void (*foo)(const numty, const numty, numty *);
    foo = spheric;
    foo(x,y,&(lulu[3]));
    for (int i = 0; i<4; i++){
        std::cout<<lulu[i]<<", ";
    }
    std::cout<<"\n"<<std::endl;
    spheric(x, y, &(lulu[0]));
    for (int i = 0; i<4; i++){
        std::cout<<lulu[i]<<", ";
    }
    std::cout<<"\n"<<std::endl;
    return 0; */
}