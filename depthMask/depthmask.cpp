#include <GL/glut.h> // Include the GLUT header file

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the color and depth buffers


    // Draw the first triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-1.0, -0.5);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.0, -0.5);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-0.5, 0.5);
    glEnd();

    // Draw a smaller triangle on top
    
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f); // Blue color
    glVertex2f(-1.0f, -0.3f);
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(-0.7f, 0.3f);
    glEnd();

    glEnable(GL_DEPTH_TEST); // Enable depth testing
    glDepthMask(GL_TRUE); // Enable depth buffer writing

    // Draw another triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.0, -0.5);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(1.0, -0.5);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.5, 0.5);
    glEnd();


    glDepthMask(GL_FALSE); // Disable depth buffer writing

    // Draw a smaller triangle on top
    
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
    glVertex2f(0.0f, -0.3f);
    glVertex2f(0.6f, -0.3f);
    glVertex2f(0.3f, 0.3f);
    glEnd();

    glFlush(); // Flush the OpenGL pipeline
    
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
    glRasterPos2f(0.20f, 0.55f); // Set text position
    
    const char* text1 = "after making glDepthMask(GL_FALSE)";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }
    
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // Set up the display mode
    glutInitWindowSize(1000, 800); // Set the window size
    glutCreateWindow("glDepthMask()"); // Create the window
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set the clear color to white
    glutDisplayFunc(display); // Register the display callback function
    glutMainLoop(); // Enter the main loop
    return 0;
}
