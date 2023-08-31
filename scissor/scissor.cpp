#include "../fonts/mainfonts.h"

#define OPENGL 0

#include <GLES2/gl2.h>
#include <GL/glut.h>

#if OPENGL 
void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

   
    glEnable(GL_SCISSOR_TEST);
    glScissor(-1.0, -0.5, 750, 600);

    // FRAMES
    glColor3f(0.0f, 0.0f, 1.0f);
    glLineWidth(2.0f);  // Set the line width for the frame
    glBegin(GL_LINE_LOOP);
    glVertex2f(-1.0, -0.5);//
    glVertex2f(0.0, -0.5);
    glVertex2f(0.0, 0.5);
    glVertex2f(-1.0, 0.5);//
    glEnd();
      
    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(1.5f);  // Set the line width for the frame
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0, -0.5);
    glVertex2f(0.0, 0.5);//
    glVertex2f(1.0, 0.5);//
    glVertex2f(1.0, -0.5);
    glEnd();

    // Draw a triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-1.0, -0.5);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.0, -0.5);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-0.5, 0.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.0, -0.5);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(1.0, -0.5);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.5, 0.5);
    glEnd();

    // Disable scissor test
    glDisable(GL_SCISSOR_TEST);

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
    
    const char* text1 = "cutted from half with glScissor()";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }
    
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Scissor Test");
    glOrtho(-1, 1, -1, 1, -1, 1);
    glutDisplayFunc(display);
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

    GLfloat vertices[] = {
        -1.0, -0.5, 0.0f,
         0.0, -0.5, -0.5f,
         -0.5, 0.5, 0.0f,

         0.0, -0.5, 0.0f,
         1.0, -0.5, -0.5f,
          0.5, 0.5, 0.0f,

        -1.0, -0.5 ,0.0f,
        -1.0, 0.5 ,0.0f,
        
        -1.0, 0.5 ,0.0f,
        1.0, 0.5 ,0.0f,

        1.0, 0.5 ,0.0f,
        1.0, -0.5 ,0.0f,

        1.0, -0.5 ,0.0f,
        -1.0, -0.5 ,0.0f
   
    };

    glLineWidth(5.0f); 

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glUseProgram(shaderProgram);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);


    glEnable(GL_SCISSOR_TEST);
    glScissor(-1.0, -0.5, 800, 600);

    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 1.0f, 0.0f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 1.0f, 0.0f);
    glDrawArrays(GL_TRIANGLES, 3, 3);

    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 0.0f, 1.0f);
    glDrawArrays(GL_LINES, 6, 2);
    
    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 0.0f, 1.0f);
    glDrawArrays(GL_LINES, 8, 2);

    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 0.0f, 1.0f);
    glDrawArrays(GL_LINES, 10, 2);

    glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 0.0f, 1.0f);
    glDrawArrays(GL_LINES, 12, 2);

    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
   
    glViewport(200,650,100,100);
    vprint(0.5f, 0.5f, 7, "Scissor Box");
    
    glViewport(400,580,100,100);

    vprint(0.5f, 0.5f, 7, "glScissor(-1.0, -0.5, 800, 600);");

    glUseProgram(0);
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteProgram(shaderProgram);
    glDisable(GL_SCISSOR_TEST);

    glutSwapBuffers();
}
    int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1000, 800);

    glutCreateWindow("scissor test example");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);


    glutMainLoop();

    return 0;
}


#endif

// Written by Ayşegül Terzi - visit https://github.com/AysegulTerzi/openGL-functions for more