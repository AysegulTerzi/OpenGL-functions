#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Render the text
    glColor3f(1.0f, 0.0f, 0.0f); // Set text color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.50f, 0.05f); // Set text position
    
    const char* text1 = "glViewport(0, 0, 500, 400);";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }

    // Set the viewport to the whole screen
    glViewport(0, 0, 500, 400);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
    // Draw the frame around the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);

    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.99f, -0.99f);
    glVertex2f(-0.99f, 0.99f);
    
    glVertex2f(-0.99f, 0.99f);
    glVertex2f(0.99f, 0.99f);
    
    glVertex2f(0.99f, 0.99f);
    glVertex2f(0.99f, -0.99f);
    
    glVertex2f(0.99f, -0.99f);
    glVertex2f(-0.99f, -0.99f);
    glEnd();
   
    glFlush();
}

#include <GL/glut.h>

void display2() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Render the text
    glColor3f(1.0f, 0.0f, 0.0f); // Set text color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(0.05f, -0.05f); // Set text position
    
    const char* text1 = "glViewport(500, 400, 500, 400);";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }

    // Set the viewport to the whole screen
    glViewport(500, 400, 500, 400);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
    // Draw the frame around the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);

    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.99f, -0.99f);
    glVertex2f(-0.99f, 0.99f);
    
    glVertex2f(-0.99f, 0.99f);
    glVertex2f(0.99f, 0.99f);
    
    glVertex2f(0.99f, 0.99f);
    glVertex2f(0.99f, -0.99f);
    
    glVertex2f(0.99f, -0.99f);
    glVertex2f(-0.99f, -0.99f);
    glEnd();
   
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("Viewport Frame Example");

    glutDisplayFunc(display);

    glutCreateWindow("Viewport Frame Example");

    glutDisplayFunc(display2);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);

    glutMainLoop();
    return 0;
}
