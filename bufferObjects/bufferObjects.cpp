#include "../fonts/mainfonts.h"

#include <GLES2/gl2.h>
#include <GL/glut.h>

GLfloat vertices[] = {
    -1.0f, -0.5f, 0.0f,
     0.0f, -0.5f, 0.0f,
     -0.5f,  0.5f, 0.0f
};


GLfloat vertices2[] = {
    0.0f, -0.5f, 0.0f,
     1.0f, -0.5f, 0.0f,
     0.5f,  0.5f, 0.0f
};

GLuint vertexBuffer;

void display() {
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0); // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    vprint(0.15f, 0.5f, 7, "glBufferData(vertices1);");

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glEnableVertexAttribArray(0); // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glViewport(0,150,150,400);
    glDisableVertexAttribArray(0);
    vprint(0.15f, 0.5f, 7, "glBufferData(vertices2);");

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &vertexBuffer);

    glutSwapBuffers();

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("glBufferData Example");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
