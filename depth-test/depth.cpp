#include "../fonts/mainfonts.h"

#define OPENGL 0

#include <GLES2/gl2.h>
#include <GL/glut.h> 
#include <iostream>

#if OPENGL
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

    // first example
    glViewport(0, 0, 500, 800);
    glBegin(GL_TRIANGLES);
    glColor4f(1.0, 1.0, 0.0, 0.3f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glEnd();
   
    glBegin(GL_TRIANGLES);
    glColor4f(0.0, 1.0, 1.0, 0.3f);
    glVertex2f(-0.3f, -0.5f);
    glVertex2f(0.2f, 0.5f);
    glVertex2f(0.7f, -0.5f);
    glEnd();

    // second example
    glViewport(500, 0, 500, 800);
    glEnable(GL_DEPTH_TEST); 

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f); 
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(0.0f, 0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glEnd();
    
    glDepthFunc(GL_GREATER);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 1.0f); 
    glVertex3f(-0.3f, -0.5f, 0.0f);
    glVertex3f(0.2f, 0.5f, 0.0f);
    glVertex3f(0.7f, -0.5f, 0.0f);
    glEnd();
    
    glDisable(GL_DEPTH_TEST);

    // first text
    glViewport(0, 0, 500, 800);

    glColor3f(1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(0.0f, -0.60f); // Set text position
    
    const char* text = "DEFAULT";
    
    for (const char* c = text; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }

    glViewport(500, 0, 500, 800);
    // second text
    glColor3f(1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.3f, -0.60f); // Set text position
    
    const char* text1= " glDepthFunc(GL_GREATER)";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }


}
void display2(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

    glViewport(0, 0, 500, 800);

    // first example
    glBegin(GL_TRIANGLES);
    glColor4f(1.0, 1.0, 0.0, 0.3f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glEnd();
   
    glBegin(GL_TRIANGLES);
    glColor4f(0.0, 1.0, 1.0, 0.3f);
    glVertex2f(-0.3f, -0.5f);
    glVertex2f(0.2f, 0.5f);
    glVertex2f(0.7f, -0.5f);
    glEnd();

    // second example
    glViewport(500, 0, 500, 800);
    glEnable(GL_DEPTH_TEST); 

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f); 
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(0.0f, 0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glEnd();
    
    glDepthFunc(GL_LESS);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 1.0f); 
    glVertex3f(-0.3f, -0.5f, 0.0f);
    glVertex3f(0.2f, 0.5f, 0.0f);
    glVertex3f(0.7f, -0.5f, 0.0f);
    glEnd();
    
    glDisable(GL_DEPTH_TEST);

    // first text
    glViewport(0, 0, 500, 800);

    glColor3f(1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(0.0f, -0.60f); // Set text position
    
    const char* text = "DEFAULT";
    
    for (const char* c = text; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }

    glViewport(500, 0, 500, 800);
    // second text
    glColor3f(1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.2f, -0.60f); // Set text position
    
    const char* text1= " glDepthFunc(GL_LESS)";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); 
    glutInitWindowSize(1000, 800);
    glutCreateWindow("glDepthFunc(GL_GREATER)"); 
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
    glutDisplayFunc(display); 
     glutCreateWindow("glDepthFunc(GL_LESS)"); 
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
    glutDisplayFunc(display2); 
    glutMainLoop();
    return 0;
}

#else

const char* vertexShaderSource = R"(
attribute vec4 aPos;

void main()
{
    gl_Position = aPos;
}
)";

const char* fragmentShaderSource = R"(
uniform vec3 uColor;

void main()
{
    gl_FragColor = vec4(uColor, 0.3);
}
)";

GLuint shaderProgram;
GLuint vertexBuffer;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, -0.5f,
         0.5f, -0.5f, 0.0f,

        -0.3f, -0.5f, 0.0f,
         0.2f,  0.5f, 0.0f,
         0.7f, -0.5f, 0.0f,

         -0.5f, -0.5f, 0.0f,
         0.0f, 0.5f, -0.5f,
         0.5f, -0.5f, 0.0f,

         -0.3f, -0.5f, 0.0f,
         0.2f, 0.5f, 0.0f,
         0.7f, -0.5f, 0.0f
    };

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glUseProgram(shaderProgram);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnable(GL_DEPTH_TEST); 

    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 1.0f, 1.0f, 0.0f);
    glViewport(530, 0, 500, 800);

    glDrawArrays(GL_TRIANGLES, 6, 3);

    glDepthFunc(GL_LESS);

    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 1.0f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 9, 3);
    glDisable(GL_DEPTH_TEST);

    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 1.0f, 1.0f, 0.0f);
    glViewport(0, 0, 400, 800);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 1.0f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 3, 3);
    glEnable(GL_DEPTH_TEST); 
    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 1.0f, 1.0f, 0.0f);
    glViewport(250, 0, 500, 800);
    glDrawArrays(GL_TRIANGLES, 6, 3);
    
    glDepthFunc(GL_GREATER);

    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 1.0f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 9, 3);
    glDisable(GL_DEPTH_TEST);
    glFlush();


    //texts
    glViewport(-50, 250, 500, 800);
    vprint(0.0f, 0.0f, 7, "default");
    
    glViewport(200, 250, 500, 800);
    vprint(1.0f, 1.0f, 7, "GL_GREATER");
    
    glViewport(500, 250, 500, 800);
    vprint(1.0f, 1.0f, 7, "GL_LESS");

    //texts - end

    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glUseProgram(0);
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteProgram(shaderProgram);

    glutSwapBuffers();
    
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(1000, 800);

    glutCreateWindow("gl depth test");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);



    glutMainLoop();

    return 0;
}


#endif


// Written by Ayşegül Terzi - visit https://github.com/AysegulTerzi/openGL-functions for more