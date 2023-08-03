#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer with the clear color
   
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glVertex2f(0.0f, 0.5f);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glVertex2f(0.5f, -0.5f);
    glEnd();

    glFlush(); // Flush the OpenGL pipeline
    // Render the text
    glColor3f(1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); 
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.3f, 0.55f); 
    
    const char* text1 = "changed background with glClearColor()";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); 
    }
    
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set up the display mode
    glutInitWindowSize(1000, 800); // Set the window size
    glutCreateWindow("Triangles with Clear Color"); 

    glClearColor(1.0f, 0.3f, 0.2f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); 

    glutDisplayFunc(display); 

    glutMainLoop(); 

    return 0;
}




// Written by Ayşegül Terzi - visit https://github.com/AysegulTerzi/openGL-functions for more