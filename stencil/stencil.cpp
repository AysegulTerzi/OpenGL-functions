#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_STENCIL_TEST);
    // Dikdörtgen sınırı belirle
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    glStencilFunc(GL_ALWAYS, 1, 0xFF);
    glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
    glBegin(GL_QUADS);
    glVertex2f(0.2f, -0.5f);
    glVertex2f(0.8f, -0.5f);
    glVertex2f(0.8f, 0.0f);
    glVertex2f(0.2f, 0.0f);
    glEnd();
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    
    glColor3f(0.0f, 0.0f, 1.0f);
    glLineWidth(2.0f);  // Set the line width for the frame
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.2f, -0.5f);
    glVertex2f(0.8f, -0.5f);
    glVertex2f(0.8f, 0.0f);
    glVertex2f(0.2f, 0.0f);
    glEnd();

    // İçindeki üçgeni çiz
    glStencilFunc(GL_NOTEQUAL, 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
    glColor3f(1.0f, 0.0f, 0.0f); // Kırmızı renk
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
    glRasterPos2f(0.35f, 0.55f); // Set text position
    
    
    const char* text1 = "with glStencilFun()";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }

    // Render the text
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(0.40f, -0.60f); // Set text position
    
    const char* text2 = "stencil area";
    
    for (const char* c = text2; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }
    
    
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_STENCIL | GLUT_DEPTH);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("Stencil Test");

    glutDisplayFunc(display);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutMainLoop();

    return 0;
}
