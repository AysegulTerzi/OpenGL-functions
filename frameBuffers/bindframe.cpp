//  Frame Bufferlar olmadan, render hedefi belirlememiş oluruz. Bu durumda, çizdiğiniz nesneler doğrudan ekranın varsayılan frame bufferına çizilir. 
//  Bu, istediğiniz gibi özelleştirilmiş bir görüntüleme ve render işlemi yapmanıza olanak tanımaz.
//  Frame Bufferlar Off-Screen Render (ekrana çizmeden önce render işlemleri) yapmamızı sağlar. 
//  glBindFramebuffer fonksiyonu, framebufferId isimli framebuffer nesnesini bağlamak için kullanılır
//  glBindFramebuffer(GL_FRAMEBUFFER, 0) kullanılarak framebuffer çözülür
//  glGenFramebuffers fonksiyonu framebuffer ID'sini oluşturmak için kullanılır 
//  glDeleteFramebuffers framebuffer kaynaklarını artık gerekmediğinde temizlemek için kullanılır.

#include <GL/glut.h>
#include <GLES2/gl2.h>
#include <chrono>
#include <thread>

GLuint framebufferId;

void display() {
    // Bind the framebuffer
    glBindFramebuffer(GL_FRAMEBUFFER, framebufferId);
    // Generate the framebuffer
    glGenFramebuffers(1, &framebufferId);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
    
    glFlush();

    // Wait for 3 seconds
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Unbind the framebuffer
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    // Clear the screen and draw text using standard OpenGL functions   
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glRasterPos2f(-0.15f, 0.0f);
    std::string text = "Hello, World!";
    for (char c : text) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }

    glFlush();

    // Clean up resources
    glDeleteFramebuffers(1, &framebufferId);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutCreateWindow("glBindFramebuffer");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
