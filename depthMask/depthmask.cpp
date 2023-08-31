#include "../fonts/mainfonts.h"

#define OPENGL 0

#include <GLES2/gl2.h>
#include <GL/glut.h> // Include the GLUT header file

#if OPENGL
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the color and depth buffers


    // Draw the first triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-1.0, -0.5);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.0, -0.5);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-0.5, 0.5);
    glEnd();

    // Draw a smaller triangle on top
    
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f); // Blue color
    glVertex2f(-1.0f, -0.3f);
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.7f, 0.3f);
    glEnd();

    glEnable(GL_DEPTH_TEST); // Enable depth testing
    glDepthMask(GL_TRUE); // Enable depth buffer writing

    // Draw another triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.0, -0.5);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(1.0, -0.5);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.5, 0.5);
    glEnd();


    glDepthMask(GL_FALSE); // Disable depth buffer writing

    // Draw a smaller triangle on top
    
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
    glVertex2f(0.0f, -0.3f);
    glVertex2f(0.6f, -0.3f);
    glVertex2f(0.3f, 0.3f);
    glEnd();

    glFlush(); // Flush the OpenGL pipeline
    
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
    glRasterPos2f(0.20f, 0.55f); // Set text position
    
    const char* text1 = "after making glDepthMask(GL_FALSE)";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }
    
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // Set up the display mode
    glutInitWindowSize(1000, 800); // Set the window size
    glutCreateWindow("glDepthMask()"); // Create the window
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set the clear color to white
    glutDisplayFunc(display); // Register the display callback function
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

        -1.0f, -0.3f, 0.0f,
         -0.4f, -0.3f, 0.0f,
         -0.7f, 0.3f, 0.0f,

         0.0, -0.5, 0.0f,
         1.0, -0.5, -0.5f,
         0.5, 0.5, 0.0f,

         0.0f, -0.3f, 0.0f,
         0.6f, -0.3f, 0.0f,
         0.3f, 0.3f, 0.0f
    };

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glUseProgram(shaderProgram);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 1.0f, 1.0f, 0.0f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glEnable(GL_DEPTH_TEST); 
    glDepthMask(GL_TRUE); 

    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 1.0f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 3, 3);
    

    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 1.0f, 1.0f, 0.0f);
    glDrawArrays(GL_TRIANGLES, 6, 3);
    
    glDepthMask(GL_FALSE); 


    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 1.0f, 1.0f);
    glDrawArrays(GL_TRIANGLES, 9, 3);

    glDisable(GL_DEPTH_TEST);


    // texts
    glViewport(80,600,100,100);
    vprint(0.5f, 0.5f, 7, "glDepthMask(GL_TRUE);");

    glViewport(580,600,100,100);
    vprint(0.5f, 0.5f, 7, "glDepthMask(GL_FALSE);");

    // texts end

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

    glutCreateWindow("depth mask example");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);


    glutMainLoop();

    return 0;
}

    



#endif


// Written by Ayşegül Terzi - visit https://github.com/AysegulTerzi/openGL-functions for more