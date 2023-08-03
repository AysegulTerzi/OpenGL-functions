#include <iostream>
#include <GL/glut.h>
#include <vector>

std::vector<std::string> palette = {
    "#000000", "#111111", "#222222", "#333333",
    "#444444", "#555555", "#666666", "#777777",
    "#888888", "#999999", "#AAAAAA", "#BBBBBB",
    "#CCCCCC", "#DDDDDD", "#EEEEEE", "#FFFFFF"
};

void displayWithoutDither() {
    glClear(GL_COLOR_BUFFER_BIT);

    int xStep = glutGet(GLUT_WINDOW_WIDTH) / 8;
    int yStep = glutGet(GLUT_WINDOW_HEIGHT) / 8;

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            glColor3f((float)(x * 2 + y * 2) / 30.0f, (float)(x * 2 + y * 2) / 30.0f, (float)(x * 2 + y * 2) / 30.0f);
            glBegin(GL_QUADS);
            glVertex2f(x * xStep, y * yStep);
            glVertex2f((x + 1) * xStep, y * yStep);
            glVertex2f((x + 1) * xStep, (y + 1) * yStep);
            glVertex2f(x * xStep, (y + 1) * yStep);
            glEnd();
        }
    }

    glFlush();
}

void displayWithDither() {
    glClear(GL_COLOR_BUFFER_BIT);

    int xStep = glutGet(GLUT_WINDOW_WIDTH) / 8;
    int yStep = glutGet(GLUT_WINDOW_HEIGHT) / 8;

    glEnable(GL_DITHER); // Dithering'i etkinleştir

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            glColor3f((float)(x * 2 + y * 2) / 30.0f, (float)(x * 2 + y * 2) / 30.0f, (float)(x * 2 + y * 2) / 30.0f);
            glBegin(GL_QUADS);
            glVertex2f(x * xStep, y * yStep);
            glVertex2f((x + 1) * xStep, y * yStep);
            glVertex2f((x + 1) * xStep, (y + 1) * yStep);
            glVertex2f(x * xStep, (y + 1) * yStep);
            glEnd();
        }
    }

    glDisable(GL_DITHER); // Dithering'i devre dışı bırak

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);

    // İlk pencere
    glutCreateWindow("Without Dither");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 0, 600, -1, 1);
    glutDisplayFunc(displayWithoutDither);

    // İkinci pencere
    glutCreateWindow("With Dither");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 0, 600, -1, 1);
    glutDisplayFunc(displayWithDither);

    glutMainLoop();

    return 0;
}




// Written by Ayşegül Terzi - visit https://github.com/AysegulTerzi/openGL-functions for more