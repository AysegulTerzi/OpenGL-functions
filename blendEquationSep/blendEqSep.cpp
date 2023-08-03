#include <GL/glut.h>
#include <GLES2/gl2.h>


void display() {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw another triangle (green with 30% transparency)
    glColor4f(0.0f, 1.0f, 0.0f, 0.2f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.0, 0.5);
    glEnd();
    glFlush();
    // Render the text
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.7f, 0.55f); // Set text position
    
    const char* text = "glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);";
    
    for (const char* c = text; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }
    glutSwapBuffers();
   
}

void display2() {
    
    glBlendEquationSeparate(GL_FUNC_ADD, GL_ONE);
   
    // Draw another triangle (green with 30% transparency)
    glColor4f(0.0f, 1.0f, 0.0f, 0.2f);
    glBegin(GL_TRIANGLES);
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
    
    const char* text = "glBlendEquationSeparate(GL_FUNC_ADD, GL_ONE);";
    
    for (const char* c = text; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }
    glutSwapBuffers();
    glDisable(GL_BLEND);

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);");


    glutDisplayFunc(display);
    glutCreateWindow("glBlendEquationSeparate(GL_FUNC_ADD, GL_ONE);");


    glutDisplayFunc(display2);
    glutMainLoop();

    return 0;
}



// Written by Ayşegül Terzi - visit https://github.com/AysegulTerzi/openGL-functions for more