#include <GL/glut.h> 

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

    // first example
    glViewport(0, 0, 500, 800);
    glBegin(GL_TRIANGLES);
    glColor4f(1.0, 1.0, 0.0, 0.3f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glEnd();
   
    glBegin(GL_TRIANGLES);
    glColor4f(0.0, 1.0, 1.0, 0.3f);
    glVertex2f(-0.3f, -0.5f);
    glVertex2f(0.2f, 0.5f);
    glVertex2f(0.7f, -0.5f);
    glEnd();

    // second example
    glViewport(500, 0, 500, 800);
    glEnable(GL_DEPTH_TEST); 

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f); 
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(0.0f, 0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glEnd();
    
    glDepthFunc(GL_GREATER);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 1.0f); 
    glVertex3f(-0.3f, -0.5f, 0.0f);
    glVertex3f(0.2f, 0.5f, 0.0f);
    glVertex3f(0.7f, -0.5f, 0.0f);
    glEnd();
    
    glDisable(GL_DEPTH_TEST);

    // first text
    glViewport(0, 0, 500, 800);

    glColor3f(1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(0.0f, -0.60f); // Set text position
    
    const char* text = "DEFAULT";
    
    for (const char* c = text; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }

    glViewport(500, 0, 500, 800);
    // second text
    glColor3f(1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.3f, -0.60f); // Set text position
    
    const char* text1= " glDepthFunc(GL_GREATER)";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }


}
void display2(){

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

    glViewport(0, 0, 500, 800);

    // first example
    glBegin(GL_TRIANGLES);
    glColor4f(1.0, 1.0, 0.0, 0.3f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glEnd();
   
    glBegin(GL_TRIANGLES);
    glColor4f(0.0, 1.0, 1.0, 0.3f);
    glVertex2f(-0.3f, -0.5f);
    glVertex2f(0.2f, 0.5f);
    glVertex2f(0.7f, -0.5f);
    glEnd();

    // second example
    glViewport(500, 0, 500, 800);
    glEnable(GL_DEPTH_TEST); 

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f); 
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(0.0f, 0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glEnd();
    
    glDepthFunc(GL_LESS);

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 1.0f); 
    glVertex3f(-0.3f, -0.5f, 0.0f);
    glVertex3f(0.2f, 0.5f, 0.0f);
    glVertex3f(0.7f, -0.5f, 0.0f);
    glEnd();
    
    glDisable(GL_DEPTH_TEST);

    // first text
    glViewport(0, 0, 500, 800);

    glColor3f(1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(0.0f, -0.60f); // Set text position
    
    const char* text = "DEFAULT";
    
    for (const char* c = text; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }

    glViewport(500, 0, 500, 800);
    // second text
    glColor3f(1.0f, 1.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1); // Set orthographic projection
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRasterPos2f(-0.2f, -0.60f); // Set text position
    
    const char* text1= " glDepthFunc(GL_LESS)";
    
    for (const char* c = text1; *c; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c); // Render each character
    }

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // GLUT'u başlatır
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); // Görüntüleme modunu ayarlar
    glutInitWindowSize(1000, 800); // Pencere boyutunu ayarlar
    glutCreateWindow("glDepthFunc(GL_GREATER)"); // Pencereyi oluşturur
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Temizleme rengini ayarlar
    glutDisplayFunc(display); // Görüntüleme geri çağırma işlevini kaydeder
     glutCreateWindow("glDepthFunc(GL_LESS)"); // Pencereyi oluşturur
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Temizleme rengini ayarlar
    glutDisplayFunc(display2); // Görüntüleme geri çağırma işlevini kaydeder
    glutMainLoop(); // Ana döngüye girer
    return 0;
}




// Written by Ayşegül Terzi - visit https://github.com/AysegulTerzi/openGL-functions for more