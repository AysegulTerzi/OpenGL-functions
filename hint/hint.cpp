#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    glPointSize(150.0f);

    glBegin(GL_POINTS);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex2f(-0.5f, 0.5f); // Vertex 1
    glEnd();
    // Set up the projection matrix for 2D rendering
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    // Set up the modelview matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Enable point smoothing
    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);

    glBegin(GL_POINTS); 
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glVertex2f(0.5f, 0.5f); // Vertex 3
    glEnd();

    glDisable(GL_POINT_SMOOTH);

    glFlush(); // Flush the OpenGL pipeline
    // Render the text
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.63f, 0.20f); // Set text position
    
    const char* text = "no glHint used";
    
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
    glRasterPos2f(0.10f, 0.20f); // Set text position
    
    const char* text1 = "glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }
    
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set up the display mode
    glutInitWindowSize(1000, 800); // Set the window size
    glutCreateWindow("glHint()"); // Create the window

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set the clear color to a dark gray

    glutDisplayFunc(display); // Register the display callback function

    glutMainLoop(); // Enter the main loop

    return 0;
}
