
#include "../fonts/mainfonts.h"

#define OPENGL 0

#include <GL/glut.h>
#include <GLES2/gl2.h>


#if OPENGL
void renderTexts(){
     // Render the text
    glColor3f(1.0f, 0.0f, 0.0f); // Set text color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.50f, 0.05f); // Set text position
    
    const char* text1 = "glViewport(0, 0, 500, 400);";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }
    
    // Render the text
    glColor3f(1.0f, 0.0f, 0.0f); // Set text color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(0.05f, -0.05f); // Set text position
    
    const char* text2 = "glViewport(500, 400, 500, 400);";
    
    for (const char* c = text2; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    renderTexts();
    // Set the viewport to the whole screen
    glViewport(0, 0, 500, 400);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
    // Draw the frame around the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);

    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.99f, -0.99f);
    glVertex2f(-0.99f, 0.99f);
    
    glVertex2f(-0.99f, 0.99f);
    glVertex2f(0.99f, 0.99f);
    
    glVertex2f(0.99f, 0.99f);
    glVertex2f(0.99f, -0.99f);
    
    glVertex2f(0.99f, -0.99f);
    glVertex2f(-0.99f, -0.99f);
    glEnd();

     glViewport(500, 400, 500, 400);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
    // Draw the frame around the viewport
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);

    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.99f, -0.99f);
    glVertex2f(-0.99f, 0.99f);
    
    glVertex2f(-0.99f, 0.99f);
    glVertex2f(0.99f, 0.99f);
    
    glVertex2f(0.99f, 0.99f);
    glVertex2f(0.99f, -0.99f);
    
    glVertex2f(0.99f, -0.99f);
    glVertex2f(-0.99f, -0.99f);
    glEnd();
   
   
    glFlush();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
     glClearColor(0.0, 0.0, 0.0, 0.0);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("Viewport Frame Example");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


#else // OPENGL ES 2.0

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    GLfloat triangleVertices[] = {
        -0.5f, -0.5f,
         0.5f, -0.5f,
         0.0f,  0.5f
    };

    GLfloat frameVertices[] = {
        -0.99f, -0.99f,
        -0.99f,  0.99f,
         0.99f,  0.99f,
         0.99f, -0.99f
    };

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, triangleVertices);

    // Set the viewport to the first region
    glViewport(0, 0, 500, 400);

    
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Draw the frame around the viewport
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, frameVertices);

    
    glDrawArrays(GL_LINE_LOOP, 0, 4);

    // Set the viewport to the second region
    glViewport(500, 400, 500, 400);

     glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, triangleVertices);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    // Draw the frame around the viewport
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, frameVertices);


    glDrawArrays(GL_LINE_LOOP, 0, 4);

    //texts

    glViewport(0,350,100,100);
    vprint(0.5f, 0.5f, 7, "glViewport(0, 0, 500, 400);");

    glViewport(500,300,100,100);
    vprint(0.5f, 0.5f, 7, "glViewport(500, 400, 500, 400);");

    glDisableVertexAttribArray(0);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("Viewport Frame Example");
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}

#endif