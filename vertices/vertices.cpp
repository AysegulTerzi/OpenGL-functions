#include "../fonts/mainfonts.h"

#include <GLES2/gl2.h>
#include <stdio.h>
#include <GL/glut.h>

GLuint vertexArray;

static void RenderSceneCB()
{
    GLfloat Vertices[] = {
        -0.5f, -0.5f, 0.0f, // Vertex 1
         0.5f, -0.5f, 0.0f, // Vertex 2
         0.0f,  0.5f, 0.0f  // Vertex 3
    };

    glGenBuffers(1, &vertexArray);
    glBindBuffer(GL_ARRAY_BUFFER, vertexArray);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

    glClear(GL_COLOR_BUFFER_BIT);

    glBindBuffer(GL_ARRAY_BUFFER, vertexArray);

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("vertices");

 
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glutDisplayFunc(RenderSceneCB);

    glutMainLoop();

    return 0;
}
