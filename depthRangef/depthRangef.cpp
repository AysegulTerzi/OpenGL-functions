#include <GLES2/gl2.h>
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set the depth range for the near and far clipping planes
    glDepthRangef(0.0f, 1.0f);

    // Draw a red square near the near clipping plane
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, 0.1f);
    glVertex3f(0.5f, -0.5f, 0.1f);
    glVertex3f(0.5f, 0.5f, 0.1f);
    glVertex3f(-0.5f, 0.5f, 0.1f);
    glEnd();

    // Set a different depth range for the far clipping plane
    glDepthRangef(0.5f, 1.0f);

    // Draw a blue square near the far clipping plane
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("glDepthRangef Example");

    glutDisplayFunc(display);

    glClearColor(1.0, 1.0, 1.0, 1.0);

    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
    return 0;
}
