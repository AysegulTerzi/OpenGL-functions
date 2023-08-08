#include <GL/glut.h>
#include <iostream>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Draw a colorful triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
    
    // Read pixel data from the specified region
    GLint x = 0;
    GLint y = 0;
    GLsizei width = 10;
    GLsizei height = 10;
    GLubyte pixels[3 * 20 * 20]; // RGB format, 3 components per pixel
    
    // Draw a frame around the reading area
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // Black color for the frame

    // Bottom line
    glVertex2i(x, y);
    glVertex2i(10, y);
    // Right line
    glVertex2i(10, y);
    glVertex2i(10, 10);
    // Top line
    glVertex2i(10, 10-5);
    glVertex2i(x, 10-5);
    // Left line
    glVertex2i(x, 10);
    glVertex2i(x, y);
    glEnd();
    
    glFlush();
    glReadPixels(x, y, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);

    // Print the pixel data (for demonstration purposes)
    for (int i = 0; i < width * height * 3; i += 3) {
        std::cout << "R: " << (int)pixels[i] << " G: " << (int)pixels[i + 1]
                  << " B: " << (int)pixels[i + 2] << std::endl;
    }

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("glReadPixels Example");

    glutDisplayFunc(display);

    glClearColor(1.0, 1.0, 1.0, 1.0);

    glutMainLoop();
    return 0;
}
