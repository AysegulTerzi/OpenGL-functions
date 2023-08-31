#include "../fonts/mainfonts.h"

#define OPENGL 0

#include <GLES2/gl2.h>
#include <GL/glut.h> // Include the GLUT header file

#if OPENGL 
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear color buffer
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // texts
    // first text
    glColor3f(1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.85f, 0.92f); // Set text position
    
    const char* text = "glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE)";
    
    for (const char* c = text; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }
    // second text
    glColor3f(1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(0.15f, 0.92f); // Set text position
    
    const char* text1 = "glColorMask(GL_FALSE, GL_FALSE, GL_TRUE, GL_TRUE)";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }   
    // third text
    glColor3f(1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.85f, -0.05f); // Set text position
    
    const char* text2 = "glColorMask(GL_FALSE, GL_TRUE, GL_FALSE, GL_TRUE)";
    
    for (const char* c = text2; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }   
    // fourth text
    glColor3f(1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(0.15f, -0.05f); // Set text position
    
    const char* text3 = "glColorMask(GL_TRUE,GL_FALSE, GL_FALSE,  GL_TRUE)";
    
    for (const char* c = text3; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }   
    
    
    glutSwapBuffers();


    // Enable red and green color channels, disable blue and alpha channels
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    glViewport(0, 400, 500, 400);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(0.0f, 0.8f);
    glVertex2f(0.8f, -0.8f);
    glEnd();

    // Enable blue and alpha channels, disable red and green channels
    glColorMask(GL_FALSE, GL_FALSE, GL_TRUE, GL_TRUE);
    glViewport(500, 400, 500, 400);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(0.0f, 0.8f);
    glVertex2f(0.8f, -0.8f);
    glEnd();

    glColorMask(GL_FALSE, GL_TRUE, GL_FALSE, GL_TRUE);
    glViewport(0, 0, 500, 400);    
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(0.0f, 0.8f);
    glVertex2f(0.8f, -0.8f);
    glEnd();

    glColorMask(GL_TRUE,GL_FALSE, GL_FALSE,  GL_TRUE);
    glViewport(500, 0, 500, 400);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(0.0f, 0.8f);
    glVertex2f(0.8f, -0.8f);
    glEnd();



    glFlush(); // Flush the OpenGL pipeline
    
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set up display mode
    glutInitWindowSize(1000, 800); // Set the window size
    glutCreateWindow("Color Masking Example"); // Create the window
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set the clear color to white
    glutDisplayFunc(display); // Register display callback function
    glutMainLoop(); // Enter the main loop
    return 0;
}

#else // OPENGL ES 2.0

#include <GL/glut.h>
#include <iostream>

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
        -0.7f, -0.7f,
         0.0f,  0.7f,
         0.7f, -0.7f
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



    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    glViewport(0, 400, 500, 400);
    glUniform4f(glGetUniformLocation(shaderProgram, "uColor"), 1.0f, 1.0f, 1.0f,0.0f);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glColorMask(GL_FALSE, GL_FALSE, GL_TRUE, GL_TRUE);
    glViewport(500, 400, 500, 400);
    glUniform4f(glGetUniformLocation(shaderProgram, "uColor"), 1.0f, 1.0f, 1.0f,0.0f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glColorMask(GL_FALSE, GL_TRUE, GL_FALSE, GL_TRUE);
    glViewport(0, 0, 500, 400); 
    glUniform4f(glGetUniformLocation(shaderProgram, "uColor"), 1.0f, 1.0f, 1.0f,0.0f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glColorMask(GL_TRUE,GL_FALSE, GL_FALSE,  GL_TRUE);
    glViewport(500, 0, 500, 400);
    glUniform4f(glGetUniformLocation(shaderProgram, "uColor"), 1.0f, 1.0f, 1.0f,0.0f);
    glDrawArrays(GL_TRIANGLES, 0, 3);
   
    //texts
    glColorMask(GL_TRUE,GL_TRUE, GL_TRUE,  GL_TRUE);

    glViewport(100, 650, 50, 200);
    vprint(0.0f, 0.0f, 4, "glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);");
    
    glViewport(500, 650, 200, 200);
    vprint(0.0f, 0.0f, 4, "glColorMask(GL_FALSE, GL_FALSE, GL_TRUE, GL_TRUE);");
    
    glViewport(600, 250, 50, 200);
    vprint(0.0f, 0.0f, 4, "glColorMask(GL_FALSE, GL_TRUE, GL_FALSE, GL_TRUE);");
    
    glViewport(100, 250, 50, 200);
    vprint(0.0f, 0.0f, 4, "glColorMask(GL_TRUE,GL_FALSE, GL_FALSE,  GL_TRUE);");
    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glutSwapBuffers();
}

void compile(){
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
        -0.8f, -0.8f,
         0.0f,  0.8f,
         0.8f, -0.8f
    };

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("colorMask Example");
    compile();
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}


#endif

// Written by Ayşegül Terzi - visit https://github.com/AysegulTerzi/openGL-functions for more