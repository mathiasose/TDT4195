#include <math.h>
#include <iostream>
#include <ctime>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glm/glm.hpp"
#include "visuals.h"

#pragma comment(lib, "glew32.lib")
#define GLEW_STATIC
//--------- Global Variables
int g_iWindowWidth = 512;
int g_iWindowHeight = 512;
int g_iGLUTWindowHandle = 0;
int g_iErrorCode = 0;


unsigned char g_eCurrentScene = 1;

//---------- Main program
int main(int argc, char **argv) {

    glutInit(&argc, argv);

    //Setting up  The Display
    //   -RGB color model + Alpha Channel = GLUT_RGBA
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);

    // Configure Window Position
    int iScreenWidth = glutGet(GLUT_SCREEN_WIDTH);
    int iScreenHeight = glutGet(GLUT_SCREEN_HEIGHT);
    int w = 512;
    int h = w;

    glutInitDisplayMode( GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE | GLUT_DEPTH );

    glutInitWindowPosition((iScreenWidth - w)/2, (iScreenHeight - h)/2);
    glutInitWindowSize(w, h);

    g_iGLUTWindowHandle = glutCreateWindow( "OpenGL" );

    SetupGL();

    //Call to the drawing function
    glutDisplayFunc(DisplayGL);
    glutReshapeFunc(ReshapeGL);
    // Loop require by OpenGL
    glutMainLoop();
    return 0;
}
//-----------------------------------------------------------


