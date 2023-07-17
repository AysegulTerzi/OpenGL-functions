#include <GL/glut.h> // GLUT kütüphanesini dahil eder

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Renk ve derinlik tamponlarını temizler

    glEnable(GL_DEPTH_TEST); // Derinlik testini etkinleştirir


    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.75, -0.5);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(-0.25, -0.5);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-0.50, 0.5);
    glEnd();
    
   
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.55, -0.5);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.0, -0.5);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-0.25, 0.5);
    glEnd();
   

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); 
    glVertex3f(0.25f, -0.5f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f); 
    glVertex3f(0.75f, -0.5f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f); 
    glVertex3f(0.5f, 0.5f, -1.0f);
    glEnd();

    glDepthFunc(GL_GREATER);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); 
    glVertex3f(0.5f, -0.5f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f); 
    glVertex3f(1.0f, -0.5f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f); 
    glVertex3f(0.75f, 0.5f, -1.0f);
    glEnd();

    glDisable(GL_DEPTH_TEST); 

    glFlush(); // OpenGL pipeline'ını temizler

    // Render the text
    glColor3f(1.0f, 1.0f, 1.0f); // Set text color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.55f, 0.55f); // Set text position
    
    const char* text = "triangles added in order";
    
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
    glRasterPos2f(0.0f, 0.55f); // Set text position
    
    const char* text1 = "after adding first triangle, used glDepthFunc(GL_GREATER)";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c); // Render each character
    }
     glutSwapBuffers();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // GLUT'u başlatır
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // Görüntüleme modunu ayarlar
    glutInitWindowSize(1000, 800); // Pencere boyutunu ayarlar
    glutCreateWindow("glDepthFunc()"); // Pencereyi oluşturur
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Temizleme rengini ayarlar
    glutDisplayFunc(display); // Görüntüleme geri çağırma işlevini kaydeder
    glutMainLoop(); // Ana döngüye girer
    return 0;
}
