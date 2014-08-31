#include <math.h>
#include <iostream>
#include <ctime>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glm/glm.hpp"
#include "visuals.h"

#include "shader.hpp"
#define PI 3.14159265359

// This will be used with shader
//GLuint VertexArrayID;
GLuint vertexbuffer;
GLuint programID;

void ReshapeGL( int w, int h )
{
    std::cout << "ReshapGL( " << w << ", " << h << " );" << std::endl;

    if ( h == 0)                                        // Prevent a divide-by-zero error
    {
        h = 1;                                      // Making Height Equal One
    }

    g_iWindowWidth = w;
    g_iWindowHeight = h;

    glViewport( 0, 0, g_iWindowWidth, g_iWindowHeight );


    // Setup viewing volume
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    //         L,      R,      B,     T,     N,      F
    glOrtho (-50.0f, 50.0f, -50.0f, 50.0f, 100.0f, -100.0f);

}


void KeyboardGL( unsigned char c, int x, int y )
{
    // Store the current scene so we can test if it has changed later.
    unsigned char currentScene = g_eCurrentScene;

    switch ( c )
    {
    case '1':
    {
        glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );                         // White background
        g_eCurrentScene = 1;
    }
        break;
    case '2':
    {
        glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );                         // Black background
        g_eCurrentScene = 2;
    }
        break;
    case '3':
    {
        glClearColor( 0.27f, 0.27f, 0.27f, 1.0f );                      // Dark-Gray background
        g_eCurrentScene = 3;
    }
        break;
    case '4':
    {
        glClearColor( 0.4f, 0.4f, 0.4f, 1.0f );                      // Light-Gray background
        g_eCurrentScene = 4;
    }
        break;
    case '5':
    {
        glClearColor( 0.7f, 0.7f, 0.7f, 1.0f );                      // Light-Gray background
        g_eCurrentScene = 5;
    }
        break;
    case 's':
    case 'S':
    {
        std::cout << "Shade Model: GL_SMOOTH" << std::endl;
        // Switch to smooth shading model
        glShadeModel( GL_SMOOTH );
    }
        break;
    case 'f':
    case 'F':
    {
        std::cout << "Shade Model: GL_FLAT" << std::endl;
        // Switch to flat shading model
        glShadeModel( GL_FLAT );
    }
        break;
    case '\033': // escape quits
    case '\015': // Enter quits
    case 'Q':    // Q quits
    case 'q':    // q (or escape) quits
    {
        // Cleanup up and quit
        Cleanup(0);
    }
        break;

    case '\72': //arrow up
    {

    }
        break;


    }


    if ( currentScene != g_eCurrentScene )
    {
        std::cout << "Changed Render Scene: " << int( g_eCurrentScene ) << std::endl;
    }

    glutPostRedisplay();
}


void Cleanup( int errorCode, bool bExit )
{
    if ( g_iGLUTWindowHandle != 0 )
    {
        glutDestroyWindow( g_iGLUTWindowHandle );
        g_iGLUTWindowHandle = 0;
    }

    if ( bExit )
    {
        exit( errorCode );
    }
}


void DisplayGL()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clean up the colour of the window
    // and the depth buffer

    switch ( g_eCurrentScene )
    {
    case 1:
    {
        RenderScene1();
    }
        break;
    case 2:
    {
        RenderScene2();
    }
        break;
    case 3:
    {
        RenderScene3();
    }
        break;
    case 4:
    {
        RenderScene4();
    }
        break;
    case 5:
    {
        RenderScene5();
    }
        break;
    }


    glutSwapBuffers();
    // All drawing commands applied to the
    // hidden buffer, so now, bring forward
    // the hidden buffer and hide the visible one

}

void RenderScene1()
{

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0, 0.5, 0.2);							   // Set drawing colour = orange
    glutSolidCube(20.0 );							   // Draw a built-in primitive



}

void RenderScene2()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0, 0.5, 0.2);							   // Set drawing colour = orange
    glutWireTeapot(20.0);


}

void RenderScene3()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0, 0.5, 0.2);							   // Set drawing colour = orange
    glutSolidSphere(20.0,90,124);


}
void RenderScene4()
{
    glMatrixMode( GL_MODELVIEW );                                           // Switch to modelview matrix mode
    glLoadIdentity();                                                       // Load the identity matrix

    glTranslatef( -1.5f, 1.0f, -6.0f );                                     // Translate back and to the left
    // Draw a triangle with different colors on each vertex
    glBegin( GL_TRIANGLES );
    glColor3f( 1.0f, 0.0f, 0.0f );                                      // Red
    glVertex2f( 0.0f, 1.0f );                                           // Top-Center

    glColor3f( 0.0f, 1.0f, 0.0f );                                      // Green
    glVertex2f( -1.0f, -1.0f );                                         // Bottom-Left

    glColor3f( 0.0f, 0.0f, 1.0f );                                      // Blue
    glVertex2f( 1.0f, -1.0f );                                          // Bottom-Right
    glEnd();

    glTranslatef( 3.0f, 0.0f, 0.0f );                                       // Translate right
    // Draw a rectangle with different colors on each vertex
    glBegin( GL_QUADS );
    glColor3f( 1.0f, 0.0f, 0.0f );                                      // Red
    glVertex2f( -1.0f, 1.0f );                                          // Top-Left

    glColor3f( 0.0f, 1.0f, 0.0f );                                      // Green
    glVertex2f( 1.0f, 1.0f );                                           // Top-Right

    glColor3f( 0.0f, 0.0f, 1.0f );                                      // Blue
    glVertex2f( 1.0f, -1.0f );                                          // Bottom-Right

    glColor3f( 1.0f, 1.0f, 1.0f );                                      // White
    glVertex2f( -1.0f, -1.0f );                                         // Bottom-Left
    glEnd();

    glTranslatef( -1.5f, -3.0f, 0.0f );                                     // Back to center and lower screen

    // Draw a circle with blended red/blue vertices.
    const float step = PI / 16;
    const float radius = 1.0f;

    glBegin( GL_TRIANGLE_FAN );
    glColor3f( 1.0f, 1.0f, 1.0f );
    glVertex2f(0.0f, 0.0f);
    for ( float angle = 0.0f; angle < ( 2.0f * PI ); angle += step )
    {
        float fSin = sinf(angle);
        float fCos = cosf(angle);

        glColor3f( ( fCos + 1.0f ) * 0.5f, ( fSin + 1.0f ) * 0.5f , 0.0f);
        glVertex2f( radius * fSin, radius * fCos );
    }
    glColor3f( 1.0f, 0.5f, 0.0f );
    glVertex2f( 0.0f, radius ); // One more vertex to close the circle
    glEnd();
}

void RenderScene5()
{
    // Use our shader
    glUseProgram(programID);

    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
                0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                3,                  // size
                GL_FLOAT,           // type
                GL_FALSE,           // normalized?
                0,                  // stride
                (void*)0            // array buffer offset
                );

    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle

    glDisableVertexAttribArray(0);

}




void SetupGL() //
{

    //Parameter handling
    glShadeModel (GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);

    // polygon rendering mode
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );

    //Set up light source
    GLfloat light_position[] = { 0.0, 30.0,-50.0,0.0 };

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // Black background
    glClearColor(0.0f,0.0f,0.0f,1.0f);

    // Register GLUT callbacks
    glutDisplayFunc(DisplayGL);
    glutKeyboardFunc(KeyboardGL);
    glutReshapeFunc(ReshapeGL);

    // Setup initial GL State
    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
    glClearDepth( 1.0f );

    //
    // Init GLEW
    if ( glewInit() != GLEW_OK )
    {
        std::cerr << "Failed to initialize GLEW." << std::endl;
        exit(-1);
    }

    // Setup initial GL State
    glClearColor( 1.0f, 1.0f, 1.0f, 1.0f );
    glClearDepth( 1.0f );

    std::cout << "Initialise OpenGL: Success!" << std::endl;

    //VAO
    //        glGenVertexArrays(1, &VertexArrayID);
    //        glBindVertexArray(VertexArrayID);
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );

    //VBO
    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
    };

    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &vertexbuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}
