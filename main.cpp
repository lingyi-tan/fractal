//
//  main.cpp
//  Flame_Fractal
//
//  Created by Jiali Mei on 2/20/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//
#include <iostream>
#include <math.h>
#include "Parameters.h"
#include "Transformation.h"
#include "NonLinTrans.h"

int main(int argc, char * argv[]){
    
    std::cout << "Hello, World\n";
    
    // 1. initialize parameters
    
    Parameters para;
    para.update();
    
    // 2. initialize transformation
    
    Transformation newTrans(para);
    
    // 3. point process
    std::vector<numty> point0{0.5,0.5};
    newTrans.push(point0);
    std::default_random_engine generator;
    std::discrete_distribution<int> distribution(para.getProba().begin(), para.getProba().end());

    newTrans.preTrans();
    newTrans.nonLinTrans();
    newTrans.postTrans();
    int choose = distribution (generator);
    std::vector<numty> point1;
    point1= newTrans.getOutPut();
    std::cout <<"choose: "<<choose;
    std::cout<<point1[0]<<point1[1]<<std::endl;
    
  /*  // 4. point set
    
    // 5. draw
    
    numty x = 0.5; numty y = 0.5;
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