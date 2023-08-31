#include "../fonts/mainfonts.h"

#define OPENGL 0

#include <GLES2/gl2.h>
#include <GL/glut.h>

#if OPENGL

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glEnable(GL_STENCIL_TEST);
    // Dikdörtgen sınırı belirle
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    glStencilFunc(GL_ALWAYS, 1, 0xFF);
    glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
    glBegin(GL_QUADS);
    glVertex2f(-0.4f, -0.4f);
    glVertex2f(0.4f, -0.4f);
    glVertex2f(0.4f, 0.4f);
    glVertex2f(-0.4f, 0.4f);
    glEnd();
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    
    glColor3f(0.0f, 0.0f, 1.0f);
    glLineWidth(2.0f);  // Set the line width for the frame
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.4f, -0.4f);
    glVertex2f(0.4f, -0.4f);
    glVertex2f(0.4f, 0.4f);
    glVertex2f(-0.4f, 0.4f);
    glEnd();

    // İçindeki üçgeni çiz
    glStencilFunc(GL_EQUAL, 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
    
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glVertex2f(0.0f, 0.5f);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glVertex2f(0.5f, -0.5f);
    glEnd();

    
    glDisable(GL_STENCIL_TEST);
    glutSwapBuffers();
}
void display2() {
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_STENCIL_TEST);
    // Dikdörtgen sınırı belirle
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    glStencilFunc(GL_ALWAYS, 1, 0xFF);
    glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
    glBegin(GL_QUADS);
    glVertex2f(-0.4f, -0.4f);
    glVertex2f(0.4f, -0.4f);
    glVertex2f(0.4f, 0.4f);
    glVertex2f(-0.4f, 0.4f);
    glEnd();
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    
    glColor3f(0.0f, 0.0f, 1.0f);
    glLineWidth(2.0f);  // Set the line width for the frame
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.4f, -0.4f);
    glVertex2f(0.4f, -0.4f);
    glVertex2f(0.4f, 0.4f);
    glVertex2f(-0.4f, 0.4f);
    glEnd();

    // İçindeki üçgeni çiz
    glStencilFunc(GL_EQUAL, 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
    
    glBegin(GL_TRIANGLES);
     glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glVertex2f(0.0f, 0.5f);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glVertex2f(0.5f, -0.5f);
    glEnd();

    
    glDisable(GL_STENCIL_TEST);
    glutSwapBuffers();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_STENCIL | GLUT_DEPTH);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("Stencil Test");

    glutDisplayFunc(display);

     glutCreateWindow("Stencil Test");

    glutDisplayFunc(display2);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutMainLoop();

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
uniform vec3 uColor;

void main()
{
    gl_FragColor = vec4(uColor, 0.3);
}
)";

GLuint shaderProgram;
GLuint vertexBuffer;
GLfloat vertices[] = {
       

        // TRIANGLE
        -0.5f, -0.5f,0.0f,
        0.0f, 0.5f,0.0f,
        0.5f, -0.5f, 0.0f,
        
        // QUAD
        -0.4f, -0.4f, 0.0f,
        0.4f, -0.4f, 0.0f,

        0.4f, -0.4f, 0.0f,
        0.4f, 0.4f, 0.0f,
        
        0.4f, 0.4f, 0.0f,
        -0.4f, 0.4f, 0.0f,

        -0.4f, 0.4f, 0.0f,
        -0.4f, -0.4f, 0.0f


};

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

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

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glUseProgram(shaderProgram);

     glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glLineWidth(2.0f);  // Set the line width for the frame
    glViewport(500,0,500,800);

    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 1.0f, 0.0f);
    glDrawArrays(GL_LINES, 3, 8);
    glViewport(0,0,500,800);
    // Draw the lines
    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 1.0f, 0.0f);
    glDrawArrays(GL_LINES, 3, 8);

    // Enable stencil testing
    glEnable(GL_STENCIL_TEST);
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    glStencilFunc(GL_ALWAYS, 1, 0xFF);
    glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);

    // Draw the quads and fill the stencil buffer
    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 1.0f, 0.0f);
    glDrawArrays(GL_QUADS, 3, 8);

    // Restore color writing and set stencil testing conditions
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    glStencilFunc(GL_EQUAL, 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

    // Draw the triangles where stencil buffer is filled
    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 0.0f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // SECOND

    // Draw the lines
    glViewport(500,0,500,800);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glLineWidth(2.0f);  // Set the line width for the frame
    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 1.0f, 0.0f);
    glDrawArrays(GL_LINES, 3, 8);

    // Enable stencil testing
    glEnable(GL_STENCIL_TEST);
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    glStencilFunc(GL_ALWAYS, 1, 0xFF);
    glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);

    // Draw the quads and fill the stencil buffer
    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 1.0f, 0.0f);
    glDrawArrays(GL_QUADS, 3, 8);

    // Restore color writing and set stencil testing conditions
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

    // Draw the triangles where stencil buffer is filled
    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 0.0f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // texts
    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 1.0f, 1.0f, 1.0f);

    glViewport(0,580,100,100);
    vprint(0.5f, 0.5f, 7, "glStencilFunc(GL_EQUAL, 1, 0xFF);");
    
    glViewport(450,580,100,100);
    vprint(0.5f, 0.5f, 7, "glStencilFunc(GL_NOTEQUAL, 1, 0xFF);");


    glDisableVertexAttribArray(0);
    glDeleteProgram(shaderProgram);
    glDeleteBuffers(1, &vertexBuffer);

    glDisable(GL_STENCIL_TEST);
    
    glutSwapBuffers();
}




int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_STENCIL);
    glutInitWindowSize(1000, 800);

    glutCreateWindow("glStencilFunc();");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}

    

#endif


// Written by Ayşegül Terzi - visit https://github.com/AysegulTerzi/openGL-functions for more