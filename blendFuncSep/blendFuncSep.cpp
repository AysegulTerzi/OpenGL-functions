#include <GL/glut.h>
#include <GLES2/gl2.h>

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



// Written by Ayşegül Terzi - visit https://github.com/AysegulTerzi/openGL-functions for more