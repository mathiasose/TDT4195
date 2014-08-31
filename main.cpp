//#include <GL/glut.h>
#include <iostream>
#include <GL/freeglut.h>

void draw(void) {

    // Black background
    glClearColor(0.0f,0.0f,0.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    //Draw i
    glFlush();

}

//Main program

int main(int argc, char **argv) {

    glutInit(&argc, argv);

    /*Setting up  The Display
      /    -RGB color model + Alpha Channel = GLUT_RGBA
      /    -RGB color model + Alpha Channel = GLUT_RGBA
      */
    glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);

    //Configure Window Postion
    glutInitWindowPosition(500, 250);

    //Configure Window Size
    glutInitWindowSize(480,480);

    //Create Window
    glutCreateWindow("Hello OpenGL");

    //Call to the drawing function
    glutDisplayFunc(draw);

    // Loop require by OpenGL
    std::cout << glGetString(GL_VERSION) << '\n';
    glutMainLoop();
    return 0;
}
