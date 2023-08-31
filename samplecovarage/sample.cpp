#include "../fonts/mainfonts.h"

#define OPENGL 0

#include <GLES2/gl2.h>
#include <GL/glut.h>

#if OPENGL
void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-1.0, -0.5);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.0, -0.5);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-0.5, 0.5);
    glEnd();

    glEnable(GL_MULTISAMPLE);
    // Set the sample coverage parameters to increase coverage
    // coverage value is set to 0.5, indicating that 50% of the samples within each pixel will be considered covered. We disable the inversion of the coverage value (GL_FALSE).
    glSampleCoverage(0.5, GL_FALSE);

    // Draw a triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.0, -0.5);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(1.0, -0.5);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.5, 0.5);
    glEnd();

    glDisable(GL_MULTISAMPLE);

    glFlush();
    // Render the text
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.55f, 0.55f); // Set text position
    
    const char* text = "default";
    
    for (const char* c = text; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }

    // Render the text
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(0.30f, 0.55f); // Set text position
    
    const char* text1 = " with glSampleCoverage()";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }
    
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_MULTISAMPLE);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Multisample Fragment Operations");
    glOrtho(-1, 1, -1, 1, -1, 1);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

#else  // OPENGL ES 2.0

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
        -1.0, -0.5, 0.0f,
         0.0, -0.5, -0.5f,
         -0.5, 0.5, 0.0f,

         0.0, -0.5, 0.0f,
         1.0, -0.5, -0.5f,
         0.5, 0.5, 0.0f
    };
    

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glUseProgram(shaderProgram);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);


    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 0.0f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glEnable(GL_MULTISAMPLE);

    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 0.0f, 1.0f);
    glSampleCoverage(0.5 ,GL_TRUE);

    glDrawArrays(GL_TRIANGLES, 3, 3);
    
    glDisable(GL_MULTISAMPLE);

    // texts 
    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 1.0f, 1.0f, 1.0f);

    glViewport(160,570,100,100);
    vprint(0.5f, 0.5f, 7, "default");
    
    glViewport(500,570,100,100);
    vprint(0.5f, 0.5f, 7, "glSampleCoverage(0.5 ,GL_TRUE);");

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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE); // Enable multisampling
    glutInitWindowSize(1000, 800);

    glutCreateWindow("sample covarage");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

    

#endif


// Written by Ayşegül Terzi - visit https://github.com/AysegulTerzi/openGL-functions for more