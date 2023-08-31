
#define GLEW_STATIC
#include <GL/glew.h>
#include "fonts.h"
#include <GLFW/glfw3.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <iostream>

using namespace std;

#define windowWidth 600
#define windowWidth 600


fonts* fghFontByID( int font )
{
    if( font == 1)
        return &fgFontFixed8x13;
    if( font == 2)
        return &fgFontFixed9x15;
    if( font == 3)
        return &fgFontHelvetica10;
    if( font == 4)
        return &fgFontHelvetica12;
    if( font == 5)
        return &fgFontHelvetica18;
    if( font == 6)
        return &fgFontTimesRoman10;
    if( font == 7)
        return &fgFontTimesRoman24;


    return 0;
}




void myBitmap(int fontID, int character )
{
    const GLubyte* face;
    fonts* font;
    font = fghFontByID( fontID );
    if (!font)
    {
        cout << "Girilen fontID geçersiz. Lütfen [1,7] aralığında bir sayı giriniz." <<endl;
        return; //eğer fontID geçersizse fonksiyon sonlanır
    }
    /*
     * çizilmek istenen karakteri bulur
     */
    face = font->Characters[ character ];


#ifdef GL_VERSION_1_1   //kullanılan OpenGL versiyonuyla ilgili işlemler
    glPushClientAttrib( GL_CLIENT_PIXEL_STORE_BIT );
#else
        {
        GLint swbytes, lsbfirst, rowlen, skiprows, skippix, align;


        glGetIntegerv(GL_UNPACK_SWAP_BYTES, &swbytes);
        glGetIntegerv(GL_UNPACK_LSB_FIRST, &lsbfirst);
        glGetIntegerv(GL_UNPACK_ROW_LENGTH, &rowlen);
        glGetIntegerv(GL_UNPACK_SKIP_ROWS, &skiprows);
        glGetIntegerv(GL_UNPACK_SKIP_PIXELS, &skippix);
        glGetIntegerv(GL_UNPACK_ALIGNMENT, &align);
#endif


    glPixelStorei( GL_UNPACK_SWAP_BYTES,  GL_FALSE );
    glPixelStorei( GL_UNPACK_LSB_FIRST,   GL_FALSE );
    glPixelStorei( GL_UNPACK_ROW_LENGTH,  0        );
    glPixelStorei( GL_UNPACK_SKIP_ROWS,   0        );
    glPixelStorei( GL_UNPACK_SKIP_PIXELS, 0        );
    glPixelStorei( GL_UNPACK_ALIGNMENT,   1        );




    glBitmap(
        face[ 0 ], font->Height,      /* Bitmap'in genişliği ve yüksekliği */
        font->xorig, font->yorig,     /* Font glyph'inin orijini  */
        ( float )( face[ 0 ] ), 0.0,  /* Raster'ın renderdan sonraki hareketi */
        ( face + 1 )                  /* Bitmap verisi     */
    );
#ifdef GL_VERSION_1_1
    glPopClientAttrib();
#else
        glPixelStorei(GL_UNPACK_SWAP_BYTES, swbytes);
        glPixelStorei(GL_UNPACK_LSB_FIRST, lsbfirst);
        glPixelStorei(GL_UNPACK_ROW_LENGTH, rowlen);
        glPixelStorei(GL_UNPACK_SKIP_ROWS, skiprows);
        glPixelStorei(GL_UNPACK_SKIP_PIXELS, skippix);
        glPixelStorei(GL_UNPACK_ALIGNMENT, align);
        }
#endif
}






void vprint(float x, float y, int font, char *string, ...)
{
    va_list ap; 
        va_start(ap, string);   //Kullanılacak değişkenleri ilk argümana göre konumlandırır
        char str[1024]; //myBitmap fonksiyonu harf harf aldığı için harflerin tutulacağı array
        vsprintf(str, string, ap);  //string değişkeni içerisindeki harfleri tek tek array'e yazar
        va_end(ap); 
        int len, i; //for döngüsü için argümanlar
        glRasterPos2f(x, y);    //Renderlanacak metnin ekrandaki pozisyonunu ayarlar
        len = (int)strlen(str);
        for (i = 0; i<len; i++)
        {
                myBitmap(font, str[i]);
        }
}




