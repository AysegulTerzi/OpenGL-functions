#include "../fonts/mainfonts.h"

#define OPENGL 0

#include <GLES2/gl2.h>
#include <GL/glut.h>

#if OPENGL 
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glPointSize(150.0f);

    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(-0.5f, 0.5f); // Vertex 1
    glEnd();
    // Set up the projection matrix for 2D rendering
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Enable point smoothing
    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);

    glBegin(GL_POINTS); 
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glVertex2f(0.5f, 0.5f); // Vertex 3
    glEnd();

    glDisable(GL_POINT_SMOOTH);

    glFlush(); // Flush the OpenGL pipeline
    // Render the text
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.63f, 0.20f); // Set text position
    
    const char* text = "no glHint used";
    
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
    glRasterPos2f(0.10f, 0.20f); // Set text position
    
    const char* text1 = "glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }
    
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set up the display mode
    glutInitWindowSize(1000, 800); // Set the window size
    glutCreateWindow("glHint()"); // Create the window

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set the clear color to a dark gray

    glutDisplayFunc(display); // Register the display callback function

    glutMainLoop(); // Enter the main loop

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

#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
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
    GLfloat vertices[] = {
        -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, // Vertex 1, Red color
         0.5f, 0.5f, 0.0f, 0.0f, 1.0f, // Vertex 3, Blue color
    };

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
     glUseProgram(shaderProgram);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));

    glPointSize(150.0f);
    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 1.0f, 0.0f, 0.0f);

    glDrawArrays(GL_POINTS, 0, 1);

    glEnable(GL_POINT_SMOOTH);

    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);

    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 1.0f, 0.0f);

    glDrawArrays(GL_POINTS, 1, 1);

    glDisable(GL_POINT_SMOOTH);

    // texts 
    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 1.0f, 1.0f, 1.0f);

    glViewport(420,280,100,100);
    vprint(1.5f, 0.5f, 4, "glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);");

    glViewport(120,280,100,100);
    vprint(1.5f, 0.5f, 4, "default");


    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    glDeleteBuffers(1, &vbo);

    glFlush(); // Flush the OpenGL pipeline

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Without glBegin and glEnd");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


#endif


// Written by Ayşegül Terzi - visit https://github.com/AysegulTerzi/openGL-functions for more