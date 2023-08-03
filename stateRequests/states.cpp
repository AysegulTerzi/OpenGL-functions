#include <GL/glut.h> 
#include <stdio.h>
#include <iostream>


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



// Written by Ayşegül Terzi - visit https://github.com/AysegulTerzi/openGL-functions for more