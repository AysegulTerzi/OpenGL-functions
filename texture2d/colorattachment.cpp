#include <GL/glut.h>
#include <GLES2/gl2.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <stdio.h>
#include <iostream>

GLuint textureId; // Texture ID
int imageWidth, imageHeight, numChannels;
GLuint framebufferId;

void loadTexture(const char* filename) {
    unsigned char* image = stbi_load(filename, &imageWidth, &imageHeight, &numChannels, 0);
    if (!image) {
        printf("Failed to load image.\n");
        exit(EXIT_FAILURE);
    }

    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(image);
}

void display() {
    // Bind the framebuffer
    glBindFramebuffer(GL_FRAMEBUFFER, framebufferId);

    // Unbind the framebuffer
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureId);

    // Draw the square with the texture applied from the framebuffer
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(-0.5f, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(0.5f, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(0.5f, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(-0.5f, 0.5f);
    glEnd();

    // Draw the triangle directly to the screen
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f(0.0f, -0.2f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
    
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, -0.2f);
    glVertex2f(1.0f, -0.2f);
    glVertex2f(0.5f, 0.5f);
    glEnd();

    glutSwapBuffers();
}
void display2() {
    // Bind the framebuffer
    glBindFramebuffer(GL_FRAMEBUFFER, framebufferId);

    glClear(GL_COLOR_BUFFER_BIT);

    // Unbind the framebuffer
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureId);

    // Draw the square with the texture applied from the framebuffer
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex2f(-0.5f, -0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex2f(0.5f, -0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex2f(0.5f, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex2f(-0.5f, 0.5f);
    glEnd();

    // Draw the triangle directly to the screen
    glBegin(GL_TRIANGLES);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f(0.0f, -0.2f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
    
    glDisable(GL_TEXTURE_2D);
    
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, -0.2f);
    glVertex2f(1.0f, -0.2f);
    glVertex2f(0.5f, 0.5f);
    glEnd();

    glutSwapBuffers();
     if (glIsFramebuffer(framebufferId)) {
        printf("~framebufferId is a frame buffer\n");
    } 
    GLint attachmentType;
    GLint attachmentTextureName;
    GLint attachmentTextureLevel;
    GLint attachmentTextureCubeMapFace;
    GLint attachmentTextureLayer;
    GLint attachmentColorEncoding;

    glGetFramebufferAttachmentParameteriv(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE, &attachmentType);
    glGetFramebufferAttachmentParameteriv(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME, &attachmentTextureName);
    glGetFramebufferAttachmentParameteriv(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL, &attachmentTextureLevel);
    glGetFramebufferAttachmentParameteriv(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE, &attachmentTextureCubeMapFace);
    glGetFramebufferAttachmentParameteriv(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER, &attachmentTextureLayer);
    glGetFramebufferAttachmentParameteriv(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING, &attachmentColorEncoding);

    // Print the query results
    std::cout << "Color Attachment Parameters:" << std::endl;
    std::cout << "Attachment Type: " << (attachmentType == GL_TEXTURE ? "GL_TEXTURE" : "Unknown") << std::endl;
    std::cout << "Attachment Texture Name: " << attachmentTextureName << std::endl;
    std::cout << "Attachment Texture Level: " << attachmentTextureLevel << std::endl;
    std::cout << "Attachment Texture CubeMap Face: " << attachmentTextureCubeMapFace << std::endl;
    std::cout << "Attachment Texture Layer: " << attachmentTextureLayer << std::endl;
    std::cout << "Attachment Color Encoding: " << (attachmentColorEncoding == GL_LINEAR ? "GL_LINEAR" : "Unknown") << std::endl;

}

int main(int argc, char** argv) {
  

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("Color attachment");

    // Load the image texture
    loadTexture("textures/drkwood2.jpg");

    // Create the framebuffer
    glGenFramebuffers(1, &framebufferId);
    glBindFramebuffer(GL_FRAMEBUFFER, framebufferId);

    // Create a texture and attach it to the framebuffer
    GLuint framebufferTextureId;
    glGenTextures(1, &framebufferTextureId);
    glBindTexture(GL_TEXTURE_2D, framebufferTextureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1000, 800, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 , GL_TEXTURE_2D, framebufferTextureId, 0);
    // glFramebufferTexture2D(GL_FRAMEBUFFER,  GL_DEPTH_ATTACHMENT , GL_TEXTURE_2D, framebufferTextureId, 0);
    // glFramebufferTexture2D(GL_FRAMEBUFFER,  GL_STENCIL_ATTACHMENT, GL_TEXTURE_2D, framebufferTextureId, 0);

    // Framebuffer check
    GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if (status != GL_FRAMEBUFFER_COMPLETE) {
        printf("Framebuffer creation error\n");
        exit(EXIT_FAILURE);
    }

    // Unbind the framebuffer
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    glutDisplayFunc(display);

    glutInitWindowSize(1000, 800);
    glutCreateWindow("Color attachment");

    // Load the image texture
    loadTexture("textures/texture.jpg");

    // Create the framebuffer
    glGenFramebuffers(1, &framebufferId);
    glBindFramebuffer(GL_FRAMEBUFFER, framebufferId);

    // Create a texture and attach it to the framebuffer
    GLuint framebufferTextureId2;
    glGenTextures(1, &framebufferTextureId2);
    glBindTexture(GL_TEXTURE_2D, framebufferTextureId2);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1000, 800, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, framebufferTextureId2, 0);
    

    // Framebuffer check
    GLenum status2 = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if (status2 != GL_FRAMEBUFFER_COMPLETE) {
        printf("Framebuffer creation error\n");
        exit(EXIT_FAILURE);
    }

    // Unbind the framebuffer
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    glutDisplayFunc(display2);
    glutMainLoop();
     

    return 0;
}



// Written by Ayşegül Terzi - visit https://github.com/AysegulTerzi/openGL-functions for more