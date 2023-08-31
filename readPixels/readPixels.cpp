#include "../fonts/mainfonts.h"

#define OPENGL 0

#include <GLES2/gl2.h>
#include <GL/glut.h>
#include <iostream>


#if OPENGL

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw a colorful triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
    
    // Read pixel data from the specified region
    GLint x = 0;
    GLint y = 0;
    GLsizei width = 10;
    GLsizei height = 10;
    GLubyte pixels[3 * 20 * 20]; // RGB format, 3 components per pixel
    
    // Draw a frame around the reading area
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the frame

    // Bottom line
    glVertex2i(x, y);
    glVertex2i(10, y);
    // Right line
    glVertex2i(10, y);
    glVertex2i(10, 10);
    // Top line
    glVertex2i(10, 10-5);
    glVertex2i(x, 10-5);
    // Left line
    glVertex2i(x, 10);
    glVertex2i(x, y);
    glEnd();
    
    glFlush();
    glReadPixels(x, y, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);

    // Print the pixel data (for demonstration purposes)
    for (int i = 0; i < width * height * 3; i += 3) {
        std::cout << "R: " << (int)pixels[i] << " G: " << (int)pixels[i + 1]
                  << " B: " << (int)pixels[i + 2] << std::endl;
    }

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("glReadPixels Example");

    glutDisplayFunc(display);

    glClearColor(1.0, 1.0, 1.0, 1.0);

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

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, -0.5f,
         0.0f, 0.5f, 0.0f,

         0.0f,0.0f,0.0f,
         10.0f, 0.0f,0.0f,

         10.0f,0.0f,0.0f,
         10.0f,10.0f,0.0f,
         
         10.0f,5.0f,0.0f,
         0.0f,5.0f,0.0f,
        
         0.0f,10.0f,0.0f,
         0.0f,0.0f,0.0f
             };

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glUseProgram(shaderProgram);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 1.0f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glLineWidth(4.0f); 
    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 1.0f, 0.0f, 0.0f);
    glDrawArrays(GL_LINES, 3, 2);

    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 1.0f, 0.0f, 0.0f);
    glDrawArrays(GL_LINES, 5, 2);
    
    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 1.0f, 0.0f, 0.0f);
    glDrawArrays(GL_LINES, 7, 2); 
    
    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 1.0f, 0.0f, 0.0f);
    glDrawArrays(GL_LINES, 9, 2);

    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    vprint(1.0f,1.0f,7,"glReadPixels()");

    glUseProgram(0);
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteProgram(shaderProgram);

    glutSwapBuffers();

    GLint x = 0;
    GLint y = 0;
    GLsizei width = 10;
    GLsizei height = 10;
    GLubyte pixels[3 * 20 * 20]; // RGB format, 3 components per pixel
    
    glReadPixels(x, y, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);

    // Print the pixel data (for demonstration purposes)
    for (int i = 0; i < width * height * 3; i += 3) {
        std::cout << "R: " << (int)pixels[i] << " G: " << (int)pixels[i + 1]
                  << " B: " << (int)pixels[i + 2] << std::endl;
    }
}
    int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("readPixels");
    glClearColor(1.0f,1.0f,1.0f, 1.0f);
    glutDisplayFunc(display);


    glutMainLoop();

    return 0;
}
#endif