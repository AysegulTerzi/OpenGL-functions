#define OPENGL 0

#include <GLES2/gl2.h>
#include <GL/glut.h> 
#include <stdio.h>
#include <iostream>

#if OPENGL
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);

    GLboolean depthTestEnabled;
    glGetBooleanv(GL_DEPTH_TEST, &depthTestEnabled);

    if (depthTestEnabled) {
        // Depth test is enabled, draw a red triangle
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glEnd();
        // Render the text
        glColor3f(0.0f, 0.0f, 0.0f); 
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-1, 1, -1, 1, -1, 1); 
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRasterPos2f(-0.3f, 0.55f); 
    
        const char* text1 = "Depth Test is Enabled right now";
        
        for (const char* c = text1; *c; ++c) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); 
        }
    
    } else {
        // Depth test is disabled, draw a green triangle
        glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glEnd();
        // Render the text
        glColor3f(0.0f, 0.0f, 0.0f); 
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-1, 1, -1, 1, -1, 1); 
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRasterPos2f(-0.3f, 0.55f); 
    
        const char* text1 = "Depth Test is Disabled right now";
        
        for (const char* c = text1; *c; ++c) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); 
        }
    }
    GLboolean depthTestEnabledD = glIsEnabled(GL_DEPTH_TEST);
    printf("-------------------------------------------------------\n");

    if (depthTestEnabledD) {
        std::cout << "Depth Test is Enabled!" << std::endl;
    } else {
        std::cout << "Depth Test is Disabled!" << std::endl;
    }
    
    GLint maxTextureSize;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxTextureSize);
    printf("-------------------------------------------------------\n");


    std::cout << "Maximum Texture Size: " << maxTextureSize << std::endl;
    printf("-------------------------------------------------------\n");

    GLfloat currentColor[4];
    glGetFloatv(GL_CURRENT_COLOR, currentColor);

    std::cout << "Current color: (" << currentColor[0] << ", " << currentColor[1] << ", " << currentColor[2] << ", " << currentColor[3] << ")" << std::endl;
    printf("-------------------------------------------------------\n");

    const GLubyte* vendor = glGetString(GL_VENDOR);
    const GLubyte* renderer = glGetString(GL_RENDERER);
    const GLubyte* version = glGetString(GL_VERSION);
    const GLubyte* shadingLanguageVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
    const GLubyte* extensions = glGetString(GL_EXTENSIONS);

    std::cout << "Vendor: " << vendor << std::endl;
    printf("-------------------------------------------------------\n");
    std::cout << "Renderer: " << renderer << std::endl;
    printf("-------------------------------------------------------\n");
    std::cout << "Version: " << version << std::endl;
    printf("-------------------------------------------------------\n");
    std::cout << "Shading Language Version: " << shadingLanguageVersion << std::endl;
    printf("-------------------------------------------------------\n");
    std::cout << "Extensions:" << std::endl;
    printf("-------------------------------------------------------\n");
    std::cout << extensions << std::endl; 
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("glGetBooleanv");

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    
   
    return 0;
}

#else // OPENGL ES 2.0 

const char* vertexShaderSource = R"(
attribute vec4 aPos;

void main()
{
    gl_Position = aPos;
}
)";

const char* fragmentShaderSource = R"(
uniform vec3 uColor;

void main()
{
    gl_FragColor = vec4(uColor, 0.3);
}
)";

GLuint shaderProgram;
GLuint vertexBuffer;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);
    GLboolean depthTestEnabled;
    glGetBooleanv(GL_DEPTH_TEST, &depthTestEnabled);


    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);


    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, -0.5f,
         0.0f, 0.5f, 0.0f,
    };

    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glUseProgram(shaderProgram);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
     if (depthTestEnabled) {
        glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 1.0f, 0.0f, 0.0f);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }else{
        glUniform3f(glGetUniformLocation(shaderProgram, "uColor"), 0.0f, 0.0f, 1.0f);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
    glDisableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glUseProgram(0);
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteProgram(shaderProgram);

    glutSwapBuffers();
     GLboolean depthTestEnabledD = glIsEnabled(GL_DEPTH_TEST);
    printf("-------------------------------------------------------\n");

    if (depthTestEnabledD) {
        std::cout << "Depth Test is Enabled!" << std::endl;
    } else {
        std::cout << "Depth Test is Disabled!" << std::endl;
    }
    
    GLint maxTextureSize;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxTextureSize);
    printf("-------------------------------------------------------\n");


    std::cout << "Maximum Texture Size: " << maxTextureSize << std::endl;
    printf("-------------------------------------------------------\n");

    GLfloat currentColor[4];
    glGetFloatv(GL_CURRENT_COLOR, currentColor);

    std::cout << "Current color: (" << currentColor[0] << ", " << currentColor[1] << ", " << currentColor[2] << ", " << currentColor[3] << ")" << std::endl;
    printf("-------------------------------------------------------\n");

    const GLubyte* vendor = glGetString(GL_VENDOR);
    const GLubyte* renderer = glGetString(GL_RENDERER);
    const GLubyte* version = glGetString(GL_VERSION);
    const GLubyte* shadingLanguageVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
    const GLubyte* extensions = glGetString(GL_EXTENSIONS);

    std::cout << "Vendor: " << vendor << std::endl;
    printf("-------------------------------------------------------\n");
    std::cout << "Renderer: " << renderer << std::endl;
    printf("-------------------------------------------------------\n");
    std::cout << "Version: " << version << std::endl;
    printf("-------------------------------------------------------\n");
    std::cout << "Shading Language Version: " << shadingLanguageVersion << std::endl;
    printf("-------------------------------------------------------\n");
    std::cout << "Extensions:" << std::endl;
    printf("-------------------------------------------------------\n");
    std::cout << extensions << std::endl; 
    glFlush();
}

    

    int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("glGetBooleanv");
    glClearColor(1.0f,1.0f,1.0f, 1.0f);
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}

#endif

// Written by Ayşegül Terzi - visit https://github.com/AysegulTerzi/openGL-functions for more