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

void Init(){
    // L’écran est effacé en noir.
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
    // Le tampon Z est effacé à 1.
    glClearDepth( 1.0f );
    // On active le tampon Z.
    glEnable( GL_DEPTH_TEST );
}

void Reshape( int width, int height ){

    // multipliée par une matrice de perspective.
//    gluPerspective( 60.0, (double)width / height, 0.1, 100.0 );
    // On retourne en mode matrice model view.
    glMatrixMode( GL_MODELVIEW );
    // On ajuste la nouvelle taille du viewport.
    glViewport( 0, 0, width, height );
    // Mode matrice de projection.
    glMatrixMode( GL_PROJECTION );
    // La matrice de projection est la matrice identitée…
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

void Display(){
    glClearColor(0,0,0,0); // selectionne la couleur noire (qui est celle par défaut)
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

int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
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
    return 0;
}

