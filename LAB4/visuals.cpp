#include <math.h>
#include <iostream>
#include <ctime>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "visuals.h"
#include <time.h>
#include "shader.hpp"
#include <vector>



#define PI 3.14159265359

#define mouseSpeed 0.00005f

#define cursor_speed 0.0018f
// units per second


// This will be used with shader
//GLuint VertexArrayID;
GLuint vertexbuffer, colorbuffer;
GLuint objvertexbuffer; // for obj
GLuint programID_1, programID_2;

int last_time, current_time;

GLuint MatrixID; // Handler Matrix for moving the cam
glm::mat4 MVP; // FInal Homogeneous Matrix

glm::mat4 MVP1,MVP2,MVP3,MVP4,MVP5, MODEL_EVERYTHING, MODEL_LEG_1, MODEL_LEG_2;
glm::mat4 Projection,View,Model;

// Variables for moving camera with mouse
int mouse_x = 800/2;
int mouse_y = 600/2;
int mouse_button =  GLUT_LEFT_BUTTON;
int mouse_state = GLUT_UP;
int sp_key =0;

float counter=0;
// Initial position : on +Z
glm::vec3 position = glm::vec3(5.63757, 1.7351, -2.19067 );
// Initial horizontal angle : toward -Z
float horizontalAngle = -1.07947;
// Initial vertical angle : none
float verticalAngle = -0.369055;
// Initial Field of View
float initialFoV = 45.0f;
glm::vec3 direction =  glm::vec3(0,0,0) - position;
glm::vec3 right  = glm::vec3(0,0,1) ;
glm::vec3 up = glm::vec3(0,1,0);



void MouseGL(int button, int state, int x, int y)
{
    if ( state == GLUT_DOWN) // if key is pressed
    {
        mouse_state=state; // save in global memomry

        // move point to the midle of screen
        glutWarpPointer(800/2, 600/2);
    }
    else
    {
        mouse_state=GLUT_UP;

    }
}

void Mouse_active(int x, int y)
{
    //save values in global memory
    mouse_x=x;
    mouse_y=y;

}


void Idle()
{

    current_time = glutGet(GLUT_ELAPSED_TIME);

    int dt = current_time - last_time;


    if (g_eCurrentScene >=3)
    {

        if(mouse_state ==  GLUT_DOWN)
        {

            horizontalAngle += mouseSpeed * float( 800/2 - mouse_x); // 800 = window width
            verticalAngle   += mouseSpeed * float(600/2 - mouse_y );// 600 = window height


            // Direction : Spherical coordinates to Cartesian coordinates conversion
            direction= glm::vec3(
                        cos(verticalAngle) * sin(horizontalAngle),
                        sin(verticalAngle),
                        cos(verticalAngle) * cos(horizontalAngle)
                        );

            // Right vector
            right = glm::vec3(
                        sin(horizontalAngle - PI/2.0f),
                        0,
                        cos(horizontalAngle - PI/2.0f)
                        );

            // Up vector
            up = glm::cross( right, direction );
        }

        //            // Move forward
        if (sp_key == GLUT_KEY_UP)
        {
            position += direction * (dt * cursor_speed);
        }
        // Move backward
        if (sp_key == GLUT_KEY_DOWN)
        {

            position -= direction * (dt * cursor_speed);
        }
        // Strafe right
        if (sp_key == GLUT_KEY_RIGHT)
        {

            position += right * (dt * cursor_speed);
        }
        // Strafe left
        if (sp_key== GLUT_KEY_LEFT)
        {

            position -= right * (dt * cursor_speed);
        }
        sp_key =0;

        // Camera matrix


        View       = glm::lookAt(
                    position, // Camera is at position, in World Space
                    position+direction, // and looks here : at the same position, plus "direction"
                    up                  // Head is up (set to 0,-1,0 to look upside-down)
                    );


        glutPostRedisplay();


        std::cout << position.x << " " << position.y <<  " " << position.z << std::endl;

    }
    if (false && g_eCurrentScene ==5)
    {

        counter =counter+0.002*dt;
        MODEL_EVERYTHING = glm::translate(MODEL_EVERYTHING,glm::vec3(0,0,0.0013*counter));


        MODEL_LEG_1 = glm::rotate(MODEL_LEG_1,float(cos(counter)),glm::vec3(1,0,0));


        MODEL_LEG_2 = glm::rotate(MODEL_LEG_2,float(-cos(counter)),glm::vec3(1,0,0));

    }
    last_time =current_time;// update when the last timer;
}


void ReshapeGL( int w, int h )
{
    std::cout << "ReshapGL( " << w << ", " << h << " );" << std::endl;

    if ( h == 0)                                        // Prevent a divide-by-zero error
    {
        h = 1;                                      // Making Height Equal One
    }

    g_iWindowWidth = w;
    g_iWindowHeight = h;

    glViewport( 0, 0, 800, 600 );

}

void Specialkey(int c, int x, int y )
{
    sp_key =c;
}

void KeyboardGL( unsigned char c, int x, int y )
{
    // Store the current scene so we can test if it has changed later.
    unsigned char currentScene = g_eCurrentScene;

    switch ( c )
    {
    case '1':
    {
        glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );                         // Black background
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
        // THIS MODEL WILL BE APPLIED TO THE WHOLE SCENE 5
        MODEL_EVERYTHING=glm::mat4(1.0f); // Identity


        // THIS MODEL WILL BE APPLIED TO LEG 1
        MODEL_LEG_1=glm::mat4(1.0f);


        // THIS MODEL WILL BE APPLIED TO LEG 2
        MODEL_LEG_2=glm::mat4(1.0f);
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
{    // Disable depth test
    glDisable(GL_DEPTH_TEST);
    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    // Camera matrix
    View       = glm::lookAt(
                glm::vec3(5.63757, 1.7351, -2.19067), // Camera is at (4,3,-3), in World Space
                glm::vec3(0,0,0), // and looks at the origin
                glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                );
    // Model matrix : an identity matrix (model will be at the origin)
    Model      = glm::mat4(1.0f);
    // Our ModelViewProjection : multiplication of our 3 matrices
    MVP        = Projection * View * Model; // Remember, matrix multiplication is the other way around
    // Use our shader
    glUseProgram(programID_1);
    // Send our transformation to the currently bound shader,
    // in the "MVP" uniform
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
                0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
                3,                  // size
                GL_FLOAT,           // type
                GL_FALSE,           // normalized?
                0,                  // stride
                (void*)0            // array buffer offset
                );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glVertexAttribPointer(
                1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                3,                                // size
                GL_FLOAT,                         // type
                GL_FALSE,                         // normalized?
                0,                                // stride
                (void*)0                          // array buffer offset
                );

    // Draw the triangles
    glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12*3 indices starting at 0 -> 12 triangles
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

void RenderScene2()
{
    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
    // Camera matrix
    View       = glm::lookAt(
                glm::vec3(5.63757, 1.7351, -2.19067), // Camera is at (4,3,-3), in World Space
                glm::vec3(0,0,0), // and looks at the origin
                glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                );
    // Model matrix : an identity matrix (model will be at the origin)
    Model      = glm::mat4(1.0f);
    // Our ModelViewProjection : multiplication of our 3 matrices
    MVP        = Projection * View * Model; // Remember, matrix multiplication is the other way around
    // Use our shader
    glUseProgram(programID_1);
    // Send our transformation to the currently bound shader,
    // in the "MVP" uniform
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    // Use our shader
    glUseProgram(programID_1);
    // Send our transformation to the currently bound shader,
    // in the "MVP" uniform
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
                0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
                3,                  // size
                GL_FLOAT,           // type
                GL_FALSE,           // normalized?
                0,                  // stride
                (void*)0            // array buffer offset
                );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glVertexAttribPointer(
                1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                3,                                // size
                GL_FLOAT,                         // type
                GL_FALSE,                         // normalized?
                0,                                // stride
                (void*)0                          // array buffer offset
                );

    // Draw the triangles
    glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12*3 indices starting at 0 -> 12 triangles
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

void RenderScene3()
{
    // Disable Back Face Culling
    glDisable(GL_CULL_FACE);
    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.01f, 1000.0f);
    // Model matrix : an identity matrix (model will be at the origin)
    Model      = glm::mat4(1.0f);
    // Our ModelViewProjection : multiplication of our 3 matrices
    MVP        = Projection * View * Model; // Remember, matrix multiplication is the other way around
    // Use our shader
    glUseProgram(programID_1);
    // Send our transformation to the currently bound shader,
    // in the "MVP" uniform
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
                0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
                3,                  // size
                GL_FLOAT,           // type
                GL_FALSE,           // normalized?
                0,                  // stride
                (void*)0            // array buffer offset
                );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glVertexAttribPointer(
                1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                3,                                // size
                GL_FLOAT,                         // type
                GL_FALSE,                         // normalized?
                0,                                // stride
                (void*)0                          // array buffer offset
                );

    // Draw the triangles
    glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12*3 indices starting at 0 -> 12 triangles
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}
void RenderScene4()
{
    // Enable bac-face culling
    glEnable(GL_CULL_FACE);
    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.01f, 1000.0f);
    // Model matrix : an identity matrix (model will be at the origin)
    Model      = glm::mat4(1.0f);
    // Our ModelViewProjection : multiplication of our 3 matrices
    MVP        = Projection * View * Model; // Remember, matrix multiplication is the other way around
    // Use our shader
    glUseProgram(programID_1);
    // Send our transformation to the currently bound shader,
    // in the "MVP" uniform
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
                0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
                3,                  // size
                GL_FLOAT,           // type
                GL_FALSE,           // normalized?
                0,                  // stride
                (void*)0            // array buffer offset
                );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glVertexAttribPointer(
                1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
                3,                                // size
                GL_FLOAT,                         // type
                GL_FALSE,                         // normalized?
                0,                                // stride
                (void*)0                          // array buffer offset
                );

    // Draw the triangles
    glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12*3 indices starting at 0 -> 12 triangles
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);



}

void RenderScene5()
{
    // THIS MODEL IS APPLIED TO THE WHOLE SCENE 5
    //    MODEL_EVERYTHING = IT is initalized as identity matrix

    // THIS MODEL WILL BE APPLIED TO LEG 1
    //    MODEL_LEG_1= IT is initalized as identity matrix

    // THIS MODEL WILL BE APPLIED TO LEG 2
    //    MODEL_LEG_2= IT is initalized as identity matrix

    //Enable back-Face culling
    glEnable(GL_CULL_FACE);
    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
    Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.01f, 1000.0f);

    // =================================================================================
    // ========== HIP
    // =================================================================================
    // Transform CUBE
    Model      = glm::scale(glm::mat4(1.0f),glm::vec3(1,0.1,0.1)); //cube --> parallelepiped
    // Our ModelViewProjection : multiplication of our 3 matrices
    MVP1        = Projection * View* MODEL_EVERYTHING * Model ;
    // Use our shader
    glUseProgram(programID_1);
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP1[0][0]);
    // 1rst attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,0,(void*)0);
    // Draw the trinagles
    //glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12*3 indices starting at 0 -> 12 triangles

    // =================================================================================
    // ========== HIP JOINT 1
    // =================================================================================
    //transform the cube
    Model      = glm::translate(glm::mat4(1.0f),glm::vec3(1,0,0));
    Model      = glm::scale(Model,glm::vec3(0.2,0.2,0.2));
    // MVP
    MVP2        = Projection * View * MODEL_EVERYTHING * MODEL_LEG_2 * Model;
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP2[0][0]);
    // Draw the trinagles
    //glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12*3 indices starting at 0 -> 12 triangles

    // =================================================================================
    // ========== HIP JOINT 2
    // =================================================================================
    // Transform the cube
    Model      = glm::translate(glm::mat4(1.0f),glm::vec3(-1,0,0));
    Model      = glm::scale(Model,glm::vec3(0.2,0.2,0.2));
    // MVP
    MVP3        = Projection * View * MODEL_EVERYTHING * MODEL_LEG_1 * Model;
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP3[0][0]);
    // Draw the trinagles
    //glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12*3 indices starting at 0 -> 12 triangles

    // =================================================================================
    // ========== LEG 1
    // =================================================================================
    // transform the cube
    Model      = glm::mat4(1.0f);
    Model      = glm::scale(Model,glm::vec3(0.2,0.2,0.2));
    // MVP
    MVP4        = Projection * View * MODEL_EVERYTHING* MODEL_LEG_1* Model;
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP4[0][0]);
    // Draw the trinagles
    glDrawArrays(GL_TRIANGLES, 12*3, 300); // 12*3 indices starting at 0 -> 12 triangles

    // =================================================================================
    // ========== LEG 2
    // =================================================================================
    // Transform the cube
    Model      = glm::rotate(glm::mat4(1.0f),-90.0f,glm::vec3(0,0,1));
    Model      = glm::scale(Model,glm::vec3(1,0.1,0.1));
    Model      = glm::translate(Model,glm::vec3(1,10,0));
    // MVP
    MVP5        = Projection * View *MODEL_EVERYTHING* MODEL_LEG_2* Model;
    //glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP5[0][0]);
    // Draw the trinagles
    //glDrawArrays(GL_TRIANGLES, 12*3, 12*3*2); // 12*3 indices starting at 0 -> 12 triangles
    //END
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

}




void SetupGL() //
{

    //Parameter handling
    glShadeModel (GL_SMOOTH);


    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);
    // polygon rendering mode
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );

    //Set up light source
    GLfloat light_position[] = { 0.0, 30.0,-50.0,0.0 };

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    // Black background
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );   // Black background

    // Register GLUT callbacks
    glutDisplayFunc(DisplayGL);
    glutKeyboardFunc(KeyboardGL);
    glutSpecialFunc(Specialkey);
    glutReshapeFunc(ReshapeGL);
    glutMouseFunc(MouseGL);
    glutMotionFunc(Mouse_active);

    //Call to the drawing function
    glutIdleFunc(Idle);
    last_time = glutGet(GLUT_ELAPSED_TIME);

    // Setup initial GL State
    glClearDepth( 1.0f );

    //
    // Init GLEW
    if ( glewInit() != GLEW_OK )
    {
        std::cerr << "Failed to initialize GLEW." << std::endl;
        exit(-1);
    }

    // Setup initial GL State
    glClearDepth( 1.0f );

    std::cout << "Initialise OpenGL: Success!" << std::endl;

    //VAO
    //        glGenVertexArrays(1, &VertexArrayID);
    //        glBindVertexArray(VertexArrayID);

    // Create and compile our GLSL program from the shaders
    programID_1 = LoadShaders( "TransformVertexShader.vertexshader", "ColorFragmentShader.fragmentshader" );



    //VBO -- VERTEX
    static const GLfloat g_vertex_buffer_data[] = {
        -1,-1,-1,
        -1,-1, 1,
        -1, 1, 1,
        1, 1,-1,
        -1,-1,-1,
        -1, 1,-1,
        1,-1, 1,
        -1,-1,-1,
        1,-1,-1,
        1, 1,-1,
        1,-1,-1,
        -1,-1,-1,
        -1,-1,-1,
        -1, 1, 1,
        -1, 1,-1,
        1,-1, 1,
        -1,-1, 1,
        -1,-1,-1,
        -1, 1, 1,
        -1,-1, 1,
        1,-1, 1,
        1, 1, 1,
        1,-1,-1,
        1, 1,-1,
        1,-1,-1,
        1, 1, 1,
        1,-1, 1,
        1, 1, 1,
        1, 1,-1,
        -1, 1,-1,
        1, 1, 1,
        -1, 1,-1,
        -1, 1, 1,
        1, 1, 1,
        -1, 1, 1,
        1,-1, 1,

        -4,  1, -3,
         1,  0, -3,
        -4, -3, -3,

        -4, -3, -3,
         1,  0, -3,
         1, -2, -3,

        -4, -3, -3,
         1, -2, -3,
         1, -2,  0,

         1, -2,  0,
         1, -2, -3,
        -4, -3,  0,

         1, -2,  0,
         1, -2, -3,
         1,  0, -3,

         1, -2,  0,
         1,  0, -3,
         1,  0,  0,

         1,  0, -3,
         1,  0,  0,
        -4,  1, -3,

         1,  0,  0,
        -4,  1, -3,
        -4,  1,  0,

        -4,  1, -3,
        -4,  1,  0,
        -4, -3, -3,

        -4,  1,  0,
        -4, -3, -3,
        -4, -3,  0,

        -4,  1,  0,
        -4, -3,  0,
         1,  0,  0,

        -4, -3,  0,
         1,  0,  0,
        -2,  0, 10,

         0, -1,  0,
        -1,  0,  0,
         0, -1, 10,

        -1,  0,  0,
         0, -1, 10,
        -1,  0, 10,

        -1,  0,  0,
        -2,  0,  0,
        -1,  0, 10,

        -2,  0,  0,
        -1,  0, 10,
        -2,  0, 10,

        -2,  0,  0,
        -2,  0, 10,
        -3, -1, 10,

        -3, -1,  0,
        -2,  0, 10,
        -3, -1, 10,

        -3, -1,  0,
        -3, -1, 10,
        -2, -2, 10,

        -3, -1, 10,
        -2, -2,  0,
        -2, -2, 10,

        -2, -2, 10,
        -2, -2,  0,
        -1, -2,  0,

        -1, -2,  0,
        -2, -2, 10,
        -1, -2, 10,

        -1, -2,  0,
        -1, -2, 10,
         0, -1,  0,

        -1, -2, 10,
         0, -1,  0,
         0, -1, 10,
    };
    static const GLfloat g_color_buffer_data[] = {
        0.583f,  0.771f,  0.014f,
        0.609f,  0.115f,  0.436f,
        0.327f,  0.483f,  0.844f,
        0.822f,  0.569f,  0.201f,
        0.435f,  0.602f,  0.223f,
        0.310f,  0.747f,  0.185f,
        0.597f,  0.770f,  0.761f,
        0.559f,  0.436f,  0.730f,
        0.359f,  0.583f,  0.152f,
        0.483f,  0.596f,  0.789f,
        0.559f,  0.861f,  0.639f,
        0.195f,  0.548f,  0.859f,
        0.014f,  0.184f,  0.576f,
        0.771f,  0.328f,  0.970f,
        0.406f,  0.615f,  0.116f,
        0.676f,  0.977f,  0.133f,
        0.971f,  0.572f,  0.833f,
        0.140f,  0.616f,  0.489f,
        0.997f,  0.513f,  0.064f,
        0.945f,  0.719f,  0.592f,
        0.543f,  0.021f,  0.978f,
        0.279f,  0.317f,  0.505f,
        0.167f,  0.620f,  0.077f,
        0.347f,  0.857f,  0.137f,
        0.055f,  0.953f,  0.042f,
        0.714f,  0.505f,  0.345f,
        0.783f,  0.290f,  0.734f,
        0.722f,  0.645f,  0.174f,
        0.302f,  0.455f,  0.848f,
        0.225f,  0.587f,  0.040f,
        0.517f,  0.713f,  0.338f,
        0.053f,  0.959f,  0.120f,
        0.393f,  0.621f,  0.362f,
        0.673f,  0.211f,  0.457f,
        0.820f,  0.883f,  0.371f,
        0.982f,  0.099f,  0.879f,

        1,0,0,
        1,0,0,
        1,0,0,
        0,1,0,
        0,1,0,
        0,1,0,
        0,0,1,
        0,0,1,
        0,0,1,

        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,

        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,

        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
        1,1,1,
    };



    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &vertexbuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &colorbuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);



}
