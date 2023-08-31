#include "../fonts/mainfonts.h"

#define OPENGL 0

#include <GL/glut.h>
#include <GLES2/gl2.h>

#if OPENGL 
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // İlk üçgeni çiz
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.2f);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.0, 0.5);
    glEnd();
   
    // Render the text
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.55f, 0.55f); // Set text position
    
    const char* text = "glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA)";
    
    for (const char* c = text; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }
    // Çizimi ekrana gönder
    glutSwapBuffers();
}

void display2() {
    glClear(GL_COLOR_BUFFER_BIT);

    // İlk üçgeni çiz
    glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE);
    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.2f);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.0, 0.5);
    glEnd();
   
    // Render the text
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.7f, 0.55f); // Set text position
    
    const char* text = "glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE)";
    
    for (const char* c = text; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }
    // Çizimi ekrana gönder
    glutSwapBuffers();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_BLEND);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("glBlendFunc");
    init();
    glutDisplayFunc(display);
    init();
    glutCreateWindow("glBlendFuncSeparate");
    glutDisplayFunc(display2);
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

uniform vec4 uColor;
void main()
{
    gl_FragColor = uColor;
}
)";

GLuint shaderProgram;
GLuint vertexBuffer;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
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

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glUniform4f(glGetUniformLocation(shaderProgram, "uColor"), 1.0f, 0.0f, 0.0f,0.2f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisable(GL_BLEND);


    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE);

    glUniform4f(glGetUniformLocation(shaderProgram, "uColor"), 1.0f, 0.0f, 0.0f,0.2f);

    glDrawArrays(GL_TRIANGLES, 3, 3);
   
    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glUseProgram(0);
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteProgram(shaderProgram);

    vprint(-0.55f, 0.55f, 5, "default;");
    vprint(-0.1f, 0.55f, 4, " glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ONE);");
    

    glutSwapBuffers();
    glDisable(GL_BLEND);
}
    int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(1000, 800);

    glutCreateWindow("blend function seperate example");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);


    glutMainLoop();

    return 0;
}


#endif

// Written by Ayşegül Terzi - visit https://github.com/AysegulTerzi/openGL-functions for more