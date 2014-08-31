//#include <GL/glut.h>
#include <stdio.h>
#include <GL/freeglut.h>
#include "visuals.h"

//Main program

int main(int argc, char **argv) {

    glutInit(&argc, argv);

    /*Setting up  The Display
      /    -RGB color model + Alpha Channel = GLUT_RGBA
      */
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);

    //Configure Window Postion
    glutInitWindowPosition(500, 250);

    //Configure Window Size
    glutInitWindowSize(480,480);

    //Create Window
    glutCreateWindow("Hello OpenGL");

    Setup();

    //Call to the drawing function
    glutDisplayFunc(Render);

    glutReshapeFunc(Resize);

    // Loop require by OpenGL
    glutMainLoop();
    return 0;
}
