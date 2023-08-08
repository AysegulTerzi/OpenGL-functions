#include <GLES2/gl2.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Vertex array nesnesi oluştur
    GLuint vertexArray;
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);
    
    // Vertex buffer nesnesi oluştur ve bağla
    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    
    // Üçlü (x, y, z) koordinatı yükle
    GLfloat position[] = { 0.5f, 0.5f, 0.0f };
    glVertexAttrib3f(0, position[0], position[1], position[2]);
    glEnableVertexAttribArray(0);

    // Çizimi yap
    glDrawArrays(GL_POINTS, 0, 1);

    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("glVertexAttrib3f Example");

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
        return 1;
    }

    glutDisplayFunc(display);

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);

    glutMainLoop();
    return 0;
}
