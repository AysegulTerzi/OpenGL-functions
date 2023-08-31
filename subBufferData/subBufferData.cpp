#include <GLES2/gl2.h>
#include <GL/glut.h>

GLfloat vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};
GLfloat newColors[] = {
        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f
};
GLuint vertexBuffer;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glEnableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexPointer(3, GL_FLOAT, 0, 0);

    // Önceden yüklenen üçgeni çiz
    glColor3f(1.0f, 0.0f, 0.0f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glFlush();
}
void display2(){
    
    glClear(GL_COLOR_BUFFER_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexPointer(3, GL_FLOAT, 0, 0);

    // glBufferSubData ile üçgenin rengini yeşile değiştir
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(vertices), sizeof(newColors), newColors);

    // Yeniden çiz
    // glColor3f(0.0f, 1.0f, 0.0f);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableClientState(GL_VERTEX_ARRAY);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);

    // First Window
    glutCreateWindow("glBufferData");
    glutDisplayFunc(display);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);

    // Buffer nesnesini oluştur
    glGenBuffers(1, &vertexBuffer);

    // Buffer nesnesine verileri yükle
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
     
    // Second Window
    glutCreateWindow("glBufferSubData");
    glutDisplayFunc(display2);
    glClearColor(0.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);

    // Buffer nesnesini oluştur
    glGenBuffers(1, &vertexBuffer);

    // Buffer nesnesine verileri yükle
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glutMainLoop();
    return 0;
}
