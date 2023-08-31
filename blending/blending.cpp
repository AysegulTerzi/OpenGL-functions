//  glBlendFunc( sfactor (source factor), dfactor (destination factor))

//  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)
//  blended Color = (source_color * source_alpha) + (destination_color * (1 - source_alpha))
//  glColor4f(1.0, 0.0, 0.0, 0.3f) ->  (0.3f, 0.0f, 0.0f) + (1.0f * 0.7f, 1.0f * 0.7f, 1.0f * 0.7f) -> (1.0f, 0.7f, 0.7f) 

//  glBlendFunc(GL_ZERO, GL_ONE_MINUS_SRC_COLOR) //  glBlendFunc(GL_ZERO, GL_CONSTANT_COLOR)  //  glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR)

#include "../fonts/mainfonts.h"

#define OPENGL 0
#include "../fonts/mainfonts.h"

#include <GL/glut.h> // Include the GLUT header file
#include <GLES2/gl2.h>

#if OPENGL
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear color buffer

    // texts
    // first text
    glColor3f(0.0f, 0.0f, 0.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.55f, 0.92f); // Set text position
    
    const char* text = "DEFAULT";
    
    for (const char* c = text; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }
    // second text
    glColor3f(0.0f, 0.0f, 0.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(0.15f, 0.92f); // Set text position
    
    const char* text1 = "glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }   
    // third text
    glColor3f(0.0f, 0.0f, 0.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.85f, -0.05f); // Set text position
    
    const char* text2 = "glBlendFunc(GL_ZERO, GL_CONSTANT_COLOR)";
    
    for (const char* c = text2; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }   
    // fourth text
    glColor3f(0.0f, 0.0f, 0.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(0.15f, -0.05f); // Set text position
    
    const char* text3 = "glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR)";
    
    for (const char* c = text3; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }   
    
    glEnable(GL_BLEND); // Enable blending
    glBlendEquation(GL_FUNC_ADD);

    // first triangle
    glViewport(0, 400, 500, 400);
    glBegin(GL_TRIANGLES);
    glColor4f(1.0, 0.0, 0.0, 0.3f);
    glVertex2f(-0.8f, -0.8f);
    glColor4f(0.0, 1.0, 0.0,  0.3f);
    glVertex2f(0.0f, 0.8f);
    glColor4f(0.0, 0.0, 1.0,  0.3f);
    glVertex2f(0.8f, -0.8f);
    glEnd();

    glFlush();
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Set blending function

    // second triangle
    glViewport(500, 400, 500, 400);
    glBegin(GL_TRIANGLES);
    glColor4f(1.0, 0.0, 0.0,  0.3f);
    glVertex2f(-0.8f, -0.8f);
    glColor4f(0.0, 1.0, 0.0,  0.3f);
    glVertex2f(0.0f, 0.8f);
    glColor4f(0.0, 0.0, 1.0,  0.3f);
    glVertex2f(0.8f, -0.8f);
    glEnd();

    
    glBlendFunc(GL_ZERO, GL_CONSTANT_COLOR);
    

    // third triangle
    glViewport(0, 0, 500, 400);    
    glBegin(GL_TRIANGLES);
    glColor4f(1.0, 0.0, 0.0,1.0f);
    glVertex2f(-0.8f, -0.8f);
    glColor4f(0.0, 1.0, 0.0,1.0f);
    glVertex2f(0.0f, 0.8f);
    glColor4f(0.0, 0.0, 1.0,1.0f);
    glVertex2f(0.8f, -0.8f);
    glEnd();

    glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR);

    // fourth triangle
    glViewport(500, 0, 500, 400);
    glBegin(GL_TRIANGLES);
    glColor4f(1.0, 0.0, 0.0, 1.0f);
    glVertex2f(-0.8f, -0.8f);
    glColor4f(0.0, 1.0, 0.0, 1.0f);
    glVertex2f(0.0f, 0.8f);
    glColor4f(0.0, 0.0, 1.0, 1.0f);
    glVertex2f(0.8f, -0.8f);
    glEnd();

    glDisable(GL_BLEND); // Disable blending

    glFlush(); // Flush the OpenGL pipeline
    
    
    glutSwapBuffers();
}
void display2()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear color buffer

    // texts
    // first text
    glColor3f(0.0f, 0.0f, 0.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.55f, 0.92f); // Set text position
    
    const char* text = "DEFAULT";
    
    for (const char* c = text; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }
    // second text
    glColor3f(0.0f, 0.0f, 0.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(0.15f, 0.92f); // Set text position
    
    const char* text1 = "glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }   
    // third text
    glColor3f(0.0f, 0.0f, 0.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.85f, -0.05f); // Set text position
    
    const char* text2 = "glBlendFunc(GL_ZERO, GL_CONSTANT_COLOR)";
    
    for (const char* c = text2; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }   
    // fourth text
    glColor3f(0.0f, 0.0f, 0.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(0.15f, -0.05f); // Set text position
    
    const char* text3 = "glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR)";
    
    for (const char* c = text3; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }   
    
    glEnable(GL_BLEND); // Enable blending
    glBlendEquation(GL_FUNC_SUBTRACT);
   
    // first triangle
    glViewport(0, 400, 500, 400);
    glBegin(GL_TRIANGLES);
    glColor4f(1.0, 0.0, 0.0, 0.3f);
    glVertex2f(-0.8f, -0.8f);
    glColor4f(0.0, 1.0, 0.0, 0.3f);
    glVertex2f(0.0f, 0.8f);
    glColor4f(0.0, 0.0, 1.0, 0.3f);
    glVertex2f(0.8f, -0.8f);
    glEnd();

 
     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Set blending function


    // second triangle
    glViewport(500, 400, 500, 400);
    glBegin(GL_TRIANGLES);
    glColor4f(1.0, 0.0, 0.0,  0.3f);
    glVertex2f(-0.8f, -0.8f);
    glColor4f(0.0, 1.0, 0.0,  0.3f);
    glVertex2f(0.0f, 0.8f);
    glColor4f(0.0, 0.0, 1.0,  0.3f);
    glVertex2f(0.8f, -0.8f);
    glEnd();

    
    glBlendFunc(GL_ZERO, GL_CONSTANT_COLOR);
    

    // third triangle
    glViewport(0, 0, 500, 400);    
    glBegin(GL_TRIANGLES);
    glColor4f(1.0, 0.0, 0.0,1.0f);
    glVertex2f(-0.8f, -0.8f);
    glColor4f(0.0, 1.0, 0.0,1.0f);
    glVertex2f(0.0f, 0.8f);
    glColor4f(0.0, 0.0, 1.0,1.0f);
    glVertex2f(0.8f, -0.8f);
    glEnd();

    glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR);

    // fourth triangle
    glViewport(500, 0, 500, 400);
    glBegin(GL_TRIANGLES);
    glColor4f(1.0, 0.0, 0.0, 1.0f);
    glVertex2f(-0.8f, -0.8f);
    glColor4f(0.0, 1.0, 0.0, 1.0f);
    glVertex2f(0.0f, 0.8f);
    glColor4f(0.0, 0.0, 1.0, 1.0f);
    glVertex2f(0.8f, -0.8f);
    glEnd();

    glDisable(GL_BLEND); // Disable blending

    glFlush(); // Flush the OpenGL pipeline
    
    
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set up display mode
    glutInitWindowSize(1000, 800); // Set the window size
    glutCreateWindow("glBlendEquation(GL_FUNC_SUBTRACT)"); // Create the window
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc(display2); // Register display callback function
    
    glutCreateWindow("glBlendEquation(GL_FUNC_ADD)"); // Create the window
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc(display); // Register display callback function
    glutMainLoop(); // Enter the main loop
    return 0;
}

#else // OPENGL ES 2.0 

const char* vertexShaderSource = R"(
attribute vec4 aPos;

void main()
{
    gl_Position = aPos;
}
)";

const char* fragmentShaderSource = R"(
uniform vec4 uColor;

void main()
{
    gl_FragColor = uColor;
}
)";


GLuint vertexBuffer;
GLuint shaderProgram;


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    // Compile and link shaders
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Set up vertex buffer
    GLfloat vertices[] = {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f

    };

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Use shader program
    glUseProgram(shaderProgram);

    // Bind vertex buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnable(GL_BLEND); // Enable blending
    glBlendEquation(GL_FUNC_ADD);


    // texts 
    glViewport(50, 450, 100, 540);
    vprint(0.0, 0.0, 4, "default");

    glViewport(180, 450, 100, 540);
    vprint(0.0, 0.0, 4, "GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA");

    glViewport(0, 50, 100, 540);
    vprint(0.0, 0.0, 4, "GL_ZERO, GL_CONSTANT_COLOR");

    glViewport(180, 30, 100, 540);
    vprint(0.0, 0.0, 4, "GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR");

    //
    
    glViewport(550, 450, 100, 540);
    vprint(0.0, 0.0, 4, "default");

    glViewport(650, 450, 100, 540);
    vprint(0.0, 0.0, 4, "GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA");
    
    glViewport(450, 50, 100, 540);
    vprint(0.0, 0.0, 4, "GL_ZERO, GL_CONSTANT_COLOR");

    glViewport(650, 30, 100, 540);
    vprint(0.0, 0.0, 4, "GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR");


    // texts end

    glViewport(0, 400, 250, 400);
    glUniform4f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 0.0f, 1.0f,0.3f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glViewport(250, 400, 250, 400);
    glUniform4f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 0.0f, 1.0f,0.3f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBlendFunc(GL_ZERO, GL_CONSTANT_COLOR);

    glViewport(0, 0, 250, 400);
    glUniform4f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 0.0f, 1.0f,0.3f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR);

    glViewport(250, 0, 250, 400);
    glUniform4f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 0.0f, 1.0f,0.3f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    ///////////////////////////////////////////////
    
    glEnable(GL_BLEND); // Enable blending
    glBlendEquation(GL_FUNC_SUBTRACT);

    glViewport(500, 400, 250, 400);
    glUniform4f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 0.0f, 1.0f,0.3f);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glFlush();
    
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glViewport(750, 400, 250,400);
    glUniform4f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 0.0f, 1.0f,0.3f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBlendFunc(GL_ZERO, GL_CONSTANT_COLOR);

    glViewport(500, 0, 250, 400);
    glUniform4f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 0.0f, 1.0f,0.3f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR);

    glViewport(750, 0, 250, 400);
    glUniform4f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 0.0f, 1.0f,0.3f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glDisable(GL_BLEND); // Disable blending

    glFlush(); // Flush the OpenGL pipeline
    glutSwapBuffers();
}

void compile(){
     
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("blending Example");
    compile();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}



#endif


// Written by Ayşegül Terzi - visit https://github.com/AysegulTerzi/openGL-functions for more