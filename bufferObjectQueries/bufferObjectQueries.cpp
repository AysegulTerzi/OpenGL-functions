#include <GL/glut.h>
#include <GLES2/gl2.h>
#include <iostream>

GLfloat vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

GLuint vertexBuffer;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    
    if (glIsBuffer(vertexBuffer)) {
        std::cout << "vertexBuffer is a valid buffer " << std::endl;

        GLint bufferSize;
        glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &bufferSize);
        std::cout << "Buffer size: " << bufferSize << std::endl;

        GLint bufferUsage;
        glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_USAGE, &bufferUsage);
        std::cout << "Buffer usage: " << bufferUsage << std::endl;

        GLint mapped;
        glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_MAPPED, &mapped);
        std::cout << "Is buffer mapped: " << (mapped ? "Yes" : "No") << std::endl;

        GLint mapOffset;
        glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_MAP_OFFSET, &mapOffset);
        std::cout << "Mapped offset: " << mapOffset << std::endl;

        GLint mapLength;
        glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_MAP_LENGTH, &mapLength);
        std::cout << "Mapped length: " << mapLength << std::endl;
    }
    else {
        std::cout << "Buffer is not valid!" << std::endl;
    }

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glEnableVertexAttribArray(0); // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &vertexBuffer);

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("glGetBufferParameteriv Example");

    glutDisplayFunc(display);

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glutMainLoop();
    return 0;
}
