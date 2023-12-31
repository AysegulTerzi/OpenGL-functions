#include "../fonts/mainfonts.h"

#define OPENGL 0

#include <GLES2/gl2.h>
#include <stdio.h>
#include <GL/glut.h>

#if OPENGL

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Çizimi yapılan üçgen
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f); 
    glVertex2f(-0.9f, -0.375f);
    glVertex2f(-0.4f, -0.375f);
    glVertex2f(-0.65f, 0.375f);
    glEnd();

    glBlendColor(1.0f, 1.0f, 0.0f, 0.2f); 

   
    glBlendFunc(GL_CONSTANT_COLOR, GL_ONE_MINUS_CONSTANT_COLOR);

   
    glEnable(GL_BLEND);
    glBlendEquation(GL_FUNC_ADD);

   
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f); 
    glVertex2f(-0.3f, -0.375f);
    glVertex2f(0.2f, -0.375f);
    glVertex2f(-0.05f, 0.375f);
    glEnd();

    glBlendColor(1.0f, 0.0f, 1.0f, 0.2f);
    glBlendFunc(GL_CONSTANT_COLOR, GL_ONE_MINUS_CONSTANT_COLOR);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 1.0f); 
    glVertex2f(0.4f, -0.375f);
    glVertex2f(0.9f, -0.375f);
    glVertex2f(0.65f, 0.375f);
    glEnd();

   
    glDisable(GL_BLEND);

     // Render the text
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.70f, 0.4f); // Set text position
    
    const char* text = "default;";
    
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
    glRasterPos2f(-0.3f, 0.4f); // Set text position
    
    const char* text1 = " glBlendColor(1.0f, 1.0f, 0.0f, 0.2f); ";

    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }

     // Render the text
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(0.4f, 0.4f); // Set text position
    
    const char* text2 = "glBlendColor(1.0f, 0.0f, 1.0f, 0.2f)";

    for (const char* c = text2; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }
        glFlush();
        glutSwapBuffers();

}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("glBlendColor()");
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}



#else //OPENGLES20

GLuint vertexBufferObject;


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    GLfloat Vertices[] = {
        -0.9f, -0.375f, 1.0f, 0.0f, 0.0f,
        -0.4f, -0.375f, 1.0f, 0.0f, 0.0f,
        -0.65f, 0.375f, 1.0f, 0.0f, 0.0f,

        -0.3f, -0.375f, 0.0f, 1.0f, 0.0f,
        0.2f, -0.375f, 0.0f, 1.0f, 0.0f,
        -0.05f, 0.375f, 0.0f, 1.0f, 0.0f,

        0.4f, -0.375f, 0.0f, 0.0f, 1.0f,
        0.9f, -0.375f, 0.0f, 0.0f, 1.0f,
        0.65f, 0.375f, 0.0f, 0.0f, 1.0f
    };
    

    glGenBuffers(1, &vertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0); // Position attribute
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void*)0);
    
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glEnable(GL_BLEND);
    glBlendColor(1.0f, 1.0f, 0.0f, 0.2f);
    glBlendFunc(GL_CONSTANT_COLOR, GL_ONE_MINUS_CONSTANT_COLOR);

    glDrawArrays(GL_TRIANGLES, 3, 3);
    
    glBlendColor(1.0f, 0.0f, 1.0f, 0.2f);
    glDrawArrays(GL_TRIANGLES, 6, 3);

    glDisable(GL_BLEND);
    glDisableVertexAttribArray(0);

    vprint(-0.70f, 0.4f, 5, "default;");
    vprint(-0.3f, 0.4f, 5, "glBlendColor(1.0f, 1.0f, 0.0f, 0.2f);");
    vprint(0.4f, 0.4f, 5, "glBlendColor(1.0f, 0.0f, 1.0f, 0.2f);");


    glutSwapBuffers();
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &vertexBufferObject);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(1000, 800);

    glutCreateWindow("glBlendColor()");
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}


#endif

// Written by Ayşegül Terzi - visit https://github.com/AysegulTerzi/openGL-functions for more