#include <GL/glut.h> // Include the GLUT header file

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear color buffer

    // Draw the first rectangle
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);// Red color for corner 1
    glVertex2f(-0.8f, -0.4f);
    glColor3f(1.0f, 0.0f, 0.0f); // Green color for corner 2
    glVertex2f(-0.2f, -0.4f);
    glColor3f(1.0f, 1.0f, 0.0f);  // Blue color for corner 3
    glVertex2f(-0.2f, 0.6f);
    glColor3f(0.0f, 1.0f, 0.0f); // Yellow color for corner 4
    glVertex2f(-0.8f, 0.6f);
    glEnd();
    
     // Render the text
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.55f, 0.7f); // Set text position
    
    const char* text = "default";
    
    for (const char* c = text; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }

    glEnable(GL_DITHER);

    // Draw the second rectangle
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color for corner 1
    glVertex2f(0.2f, -0.4f);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color for corner 2
    glVertex2f(0.8f, -0.4F);
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color for corner 3
    glVertex2f(0.8f, 0.6f);
    glColor3f(0.0f, 1.0f, 0.0f); // Green color for corner 4
    glVertex2f(0.2f, 0.6f);
    glEnd();


    // Render the text
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(0.27f, 0.7f); // Set text position
    
    const char* text1 = "with enabling GL_DITHER";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }

    glDisable(GL_DITHER);

    glFlush(); // Flush the OpenGL pipeline
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set up display mode
    glutInitWindowSize(1000, 800); // Set the window size
    glutCreateWindow("Rectangles with Different Corner Colors"); // Create the window
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set the clear color to white
    glutDisplayFunc(display); // Register display callback function
    glutMainLoop(); // Enter the main loop
    return 0;
}
