//
//  Draw.cpp
//  Flame_Fractal
//
//  Created by Jiali Mei on 2/20/13.
//  Copyright (c) 2013 Bunny. All rights reserved.
//

#include "Draw.h"

Draw::Draw(PointSet set){
    _pprePointsX = set.getPointsX();
    _pprePointsY = set.getPointsY();
}

Draw::~Draw(){
    
}

void Draw::arrange(){

}

void Draw::run(){
    glutInitWindowSize( 800, 600 );
    //glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("Simple");
    //    Init();
    glutDisplayFunc( Display );
    //    glutIdleFunc( Display );
    glutReshapeFunc( Reshape );
    glutMainLoop();
    
    
    // insert code here...
    std::cout << "Hello, World!\n";
}

void Draw::Reshape( int width, int height ){
    
    // We want to set the Modelview matrix
    glMatrixMode( GL_MODELVIEW );
    // We set the view point
    glViewport( 0, 0, width, height );
    // We set the projection matrix
    glMatrixMode( GL_PROJECTION );
    // First let it be the identity matrix
    glLoadIdentity();
    float L; // Longueur entre les 2 plans de coupe verticaux
    float H; // Hauteur entre les 2 plans de coupe horizontaux
    if (width<=height)
    {
        H=(GLfloat) (10*height/width);
        L=10.0;
    }
    else
    {
        H=10.0;
        L=(GLfloat) (10*width/height);
    }
    gluOrtho2D(-L/2,L/2,-H/2,H/2);
}

void Draw::Display(){
    glClearColor(1,1,1,1); // We set the background color
    glClear(GL_COLOR_BUFFER_BIT); // efface le frame buffer
    glBegin(GL_TRIANGLES);
    glVertex2i(0,1);
    glVertex2i(-1,0);
    glVertex2i(1,0);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2d(2,-1);
    glVertex2d(4,-1);
    glVertex2d(4,1);
    glVertex2d(2,1);
    glEnd();
    glFlush();
    
}
