#include <GL/glut.h>

void displayWithClear()
{
    glClear(GL_COLOR_BUFFER_BIT); 
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-1.0, -0.5);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.0, -0.5);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-0.5, 0.5);
    glEnd();


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
    glColor3f(1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(0.30f, 0.55f); 
    
    const char* text1 = " without using glClear()";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); 
    }
    
    glutSwapBuffers();
}

void displayWithoutClear()
{
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.0, -0.5);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(1.0, -0.5);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.5, 0.5);
    glEnd();

    glFlush(); 

    
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(1000, 800); 
    glutCreateWindow("glClear"); 
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutDisplayFunc(displayWithoutClear); 
    glutDisplayFunc(displayWithClear); 
   

    glutMainLoop(); 

    return 0;
}



// Written by Ayşegül Terzi - visit https://github.com/AysegulTerzi/openGL-functions for more