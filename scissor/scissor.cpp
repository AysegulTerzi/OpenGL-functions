#include <GL/glut.h>
#include <cstdio>

void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Enable scissor testGLUT_BITMAP_TIMES_ROMAN_24
    glEnable(GL_SCISSOR_TEST);

    // Set the scissor region to half of the window
    glScissor(-1.0, -0.5, (glutGet(GLUT_WINDOW_WIDTH) / 4)*3, (glutGet(GLUT_WINDOW_HEIGHT)/4)*3);

    // FRAMES
    glColor3f(0.0f, 0.0f, 1.0f);
    glLineWidth(2.0f);  // Set the line width for the frame
    glBegin(GL_LINE_LOOP);
    glVertex2f(-1.0, -0.5);
    glVertex2f(0.0, -0.5);
    glVertex2f(0.0, 0.5);
    glVertex2f(-1.0, 0.5);
    glEnd();
      
    glColor3f(1.0f, 0.0f, 0.0f);
    glLineWidth(1.5f);  // Set the line width for the frame
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0, -0.5);
    glVertex2f(0.0, 0.5);
    glVertex2f(1.0, 0.5);
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



// Written by Ayşegül Terzi - visit https://github.com/AysegulTerzi/openGL-functions for more