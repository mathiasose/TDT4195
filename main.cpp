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
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    //glutInitContextVersion(3, 2);
    //glutInitContextProfile(GLUT_CORE_PROFILE);

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

    printf("%s\n%s\n", 
            glGetString(GL_RENDERER),  // e.g. Intel HD Graphics 3000 OpenGL Engine
            glGetString(GL_VERSION)    // e.g. 3.2 INTEL-8.0.61
            );

    // Loop require by OpenGL
    glutMainLoop();
    return 0;
}
