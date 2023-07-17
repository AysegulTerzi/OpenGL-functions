#include <GL/glut.h> // Include the GLUT header file

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear color buffer
     
    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.1f);
    glVertex2f(-1.0, -0.5); 
    glVertex2f(0.0, -0.5);
    glVertex2f(-0.5, 0.5);
    glEnd();

    glEnable(GL_BLEND); // Enable blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Set blending function

    glBegin(GL_TRIANGLES);
    glColor4f(1.0f, 0.0f, 0.0f, 0.3f);
    glVertex2f(0.0, -0.5);  
    glVertex2f(1.0, -0.5);  
    glVertex2f(0.5, 0.5);
    glEnd();

    glDisable(GL_BLEND); // Disable blending

    glFlush(); // Flush the OpenGL pipeline
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
    glRasterPos2f(0.25f, 0.55f); // Set text position
    
    const char* text1 = "made transperent with glBlendFunc()";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }
    
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set up display mode
    glutInitWindowSize(1000, 800); // Set the window size
    glutCreateWindow("Blending Example"); // Create the window
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set the clear color
    glutDisplayFunc(display); // Register display callback function
    glutMainLoop(); // Enter the main loop
    return 0;
}
