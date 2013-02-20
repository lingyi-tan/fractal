//
//  main.cpp
//  GlutProject
//
//  Created by Bunny on 12/24/12.
//  Copyright (c) 2012 Bunny. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/glu.h>
#include <Carbon/Carbon.h>

void RenderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void SetupRC (void) {
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Simple");
    glutDisplayFunc(RenderScene);
    SetupRC();
    glutMainLoop();
    

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

