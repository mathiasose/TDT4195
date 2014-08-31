
//-------- Variables -------------------------------

extern int g_iWindowWidth;
extern int g_iWindowHeight;
extern int g_iGLUTWindowHandle;
extern int g_iErrorCode ;

extern unsigned char g_eCurrentScene;


//-------- Functions --------------------------------
// Cleanup : This is the exist function.
void Cleanup( int exitCode, bool bExit = true );



// SetupGL :  Set up the OpenGL state machine and create a light source
void SetupGL();


// DisplayGL :  The function responsible for drawing everything in the
// OpenGL context associated to a window.
void DisplayGL();

// KeyboardGL :  This functions is called whenever the keyboard is used
// inside the opengl window
void KeyboardGL( unsigned char c, int x, int y );


// MouseGL :  This functions is called whenever the mouse is used
// inside the opengl window
void MouseGL( int button, int state, int x, int y );


// Handle the window size changes and define the world coordinate
// system and projection type
void ReshapeGL( int w, int h );


// Functions called to draw different scenes
void RenderScene1();
void RenderScene2();
void RenderScene3();
void RenderScene4();
void RenderScene5();
