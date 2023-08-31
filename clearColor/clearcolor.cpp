#include "../fonts/mainfonts.h"

#define OPENGL 0

#include <GLES2/gl2.h>
#include <GL/glut.h>

#if OPENGL
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer with the clear color
   
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glVertex2f(0.0f, 0.5f);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glVertex2f(0.5f, -0.5f);
    glEnd();

    glFlush(); // Flush the OpenGL pipeline
    // Render the text
    glColor3f(1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.3f, 0.55f); 
    
    const char* text1 = "changed background with glClearColor()";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); 
    }
    
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set up the display mode
    glutInitWindowSize(1000, 800); // Set the window size
    glutCreateWindow("Triangles with Clear Color"); 

    glClearColor(1.0f, 0.3f, 0.2f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); 

    glutDisplayFunc(display); 

    glutMainLoop(); 

    return 0;
}

#else 

const char* vertexShaderSource = R"(
    #version 330 core
    layout (location = 0) in vec2 position;
    void main()
    {
        gl_Position = vec4(position, 0.0, 1.0);
    }
)";

const char* fragmentShaderSource = R"(
    #version 330 core
    out vec4 FragColor;
    void main()
    {
        FragColor = vec4(0.0, 0.0, 1.0, 1.0); // White color
    }
)";

GLuint vertexBufferObject;
GLuint shaderProgram;


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

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

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    GLfloat vertices[] = {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };

    glGenBuffers(1, &vertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void*)0);

    glUseProgram(shaderProgram);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glViewport(250, 520, 200, 200);
    vprint(0.0f, 1.0f, 7, "glClearColor(1.0f, 0.3f, 0.2f, 1.0f);");

    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glutSwapBuffers();

    
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1000, 800);

    glutCreateWindow("clearColor");
    glClearColor(1.0f, 0.3f, 0.2f, 1.0f);
    
    glutDisplayFunc(display);
    
    glutMainLoop();

    return 0;

}


#endif


// Written by Ayşegül Terzi - visit https://github.com/AysegulTerzi/openGL-functions for more