#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_STENCIL_TEST);
    // Dikdörtgen sınırı belirle
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    glStencilFunc(GL_ALWAYS, 1, 0xFF);
    glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
    glBegin(GL_QUADS);
    glVertex2f(-0.4f, -0.4f);
    glVertex2f(0.4f, -0.4f);
    glVertex2f(0.4f, 0.4f);
    glVertex2f(-0.4f, 0.4f);
    glEnd();
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    
    glColor3f(0.0f, 0.0f, 1.0f);
    glLineWidth(2.0f);  // Set the line width for the frame
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.4f, -0.4f);
    glVertex2f(0.4f, -0.4f);
    glVertex2f(0.4f, 0.4f);
    glVertex2f(-0.4f, 0.4f);
    glEnd();

    // İçindeki üçgeni çiz
    glStencilFunc(GL_EQUAL, 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
    
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glVertex2f(0.0f, 0.5f);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glVertex2f(0.5f, -0.5f);
    glEnd();

    
    glDisable(GL_STENCIL_TEST);
    glutSwapBuffers();
}
void display2() {
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_STENCIL_TEST);
    // Dikdörtgen sınırı belirle
    glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
    glStencilFunc(GL_ALWAYS, 1, 0xFF);
    glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
    glBegin(GL_QUADS);
    glVertex2f(-0.4f, -0.4f);
    glVertex2f(0.4f, -0.4f);
    glVertex2f(0.4f, 0.4f);
    glVertex2f(-0.4f, 0.4f);
    glEnd();
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    
    glColor3f(0.0f, 0.0f, 1.0f);
    glLineWidth(2.0f);  // Set the line width for the frame
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.4f, -0.4f);
    glVertex2f(0.4f, -0.4f);
    glVertex2f(0.4f, 0.4f);
    glVertex2f(-0.4f, 0.4f);
    glEnd();

    // İçindeki üçgeni çiz
    glStencilFunc(GL_EQUAL, 1, 0xFF);
    glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
    
    glBegin(GL_TRIANGLES);
     glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glVertex2f(0.0f, 0.5f);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glVertex2f(0.5f, -0.5f);
    glEnd();

    
    glDisable(GL_STENCIL_TEST);
    glutSwapBuffers();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_STENCIL | GLUT_DEPTH);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("Stencil Test");

    glutDisplayFunc(display);

     glutCreateWindow("Stencil Test");

    glutDisplayFunc(display2);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutMainLoop();

    return 0;
}
