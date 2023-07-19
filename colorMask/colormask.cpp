#include <GL/glut.h> // Include the GLUT header file

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear color buffer
    glClearColor(0.0, 0.0, 0.0, 1.0);

    // texts
    // first text
    glColor3f(1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.85f, 0.92f); // Set text position
    
    const char* text = "glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE)";
    
    for (const char* c = text; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }
    // second text
    glColor3f(1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(0.15f, 0.92f); // Set text position
    
    const char* text1 = "glColorMask(GL_FALSE, GL_FALSE, GL_TRUE, GL_TRUE)";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }   
    // third text
    glColor3f(1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.85f, -0.05f); // Set text position
    
    const char* text2 = "glColorMask(GL_FALSE, GL_TRUE, GL_FALSE, GL_TRUE)";
    
    for (const char* c = text2; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }   
    // fourth text
    glColor3f(1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(0.15f, -0.05f); // Set text position
    
    const char* text3 = "glColorMask(GL_TRUE,GL_FALSE, GL_FALSE,  GL_TRUE)";
    
    for (const char* c = text3; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }   
    
    
    glutSwapBuffers();


    // Enable red and green color channels, disable blue and alpha channels
    glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
    glViewport(0, 400, 500, 400);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(0.0f, 0.8f);
    glVertex2f(0.8f, -0.8f);
    glEnd();

    // Enable blue and alpha channels, disable red and green channels
    glColorMask(GL_FALSE, GL_FALSE, GL_TRUE, GL_TRUE);
    glViewport(500, 400, 500, 400);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(0.0f, 0.8f);
    glVertex2f(0.8f, -0.8f);
    glEnd();

    glColorMask(GL_FALSE, GL_TRUE, GL_FALSE, GL_TRUE);
    glViewport(0, 0, 500, 400);    
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(0.0f, 0.8f);
    glVertex2f(0.8f, -0.8f);
    glEnd();

    glColorMask(GL_TRUE,GL_FALSE, GL_FALSE,  GL_TRUE);
    glViewport(500, 0, 500, 400);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(0.0f, 0.8f);
    glVertex2f(0.8f, -0.8f);
    glEnd();



    glFlush(); // Flush the OpenGL pipeline
    
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set up display mode
    glutInitWindowSize(1000, 800); // Set the window size
    glutCreateWindow("Color Masking Example"); // Create the window
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set the clear color to white
    glutDisplayFunc(display); // Register display callback function
    glutMainLoop(); // Enter the main loop
    return 0;
}
