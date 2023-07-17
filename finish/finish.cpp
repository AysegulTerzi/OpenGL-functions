#include <GL/glut.h> 

void display()
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
    glRasterPos2f(0.10f, 0.55f); // Set text position
    
    const char* text1 = "wroted after glFlush(),so nothing drawed";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }
    
    glFlush();
    glFinish(); // OpenGL pipeline'ı temizler

    // Draw a triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.0, -0.5);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(1.0, -0.5);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.5, 0.5);
    glEnd();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(1000, 880); 
    glutCreateWindow("glFlush"); 
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
    glutDisplayFunc(display); 
    glutMainLoop(); 
    return 0;
}
