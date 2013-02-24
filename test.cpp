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
    
    for (int j = 0; j<10; j ++) {
        newTrans.multiTrans();
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
    PointProcess newProcess;
    std::vector<numty> xcord;
    std::vector<numty> ycord;
    std::cout<<"start !"<<std::endl;
    for (int r = 0 ; r < 2; r++) {
        newProcess.start(2000, para);
        xcord = newProcess.getXcord();
        ycord = newProcess.getYcord();
        std::string fileX = "/Users/bunny/geek/test/fractal/datax2.txt";
        std::string fileY = "/Users/bunny/geek/test/fractal/datay2.txt";
        
//        Output outX(xcord, fileX);
//        outX.writeTxt(false);
//        Output outY(ycord, fileY);
//        outY.writeTxt(false);

        std::cout<<"iteration :" <<r;
        
        // the coordinates to be sent to pointsets !
    }
    std::cout<<"finish !"<<std::endl;
}


/*void Test::_test_qt(){

        QApplication app(argc, argv);
        
        QPushButton bouton("Salut les Zéros, la forme ?");
        bouton.setText("Pimp mon bouton !")
        
        bouton.show();
        
        return app.exec();
} */


void Test::_test_output() {
    std::vector<numty> trydata;
    for (int i = 0; i < 200; i++)
        trydata.push_back(i*i);
    std::string name = "/Users/bunny/geek/test/fractal/myoutput";
//    Output newOut(trydata, name);
//    std::cout<<newOut.writeTxt(true)<<std::endl;
}

/*void Test::_test_random(Rgen & gen) {
    std::vector<numty> probab = {0.2, 0.8};
    DiscFdr whichTrans (probab.begin(),probab.end());
    // random generator machine
    std::vector<numty> tmp;
    for (int i = 0; i<100; i ++) {
        tmp.push_back(whichTrans(gen));
        std::cout<<tmp.at(i)<<", ";
    }
    std::cout<<"\nfinish!"<<std::endl;

}*/