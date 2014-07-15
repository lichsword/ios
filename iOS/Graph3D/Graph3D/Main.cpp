    //
    //  Main.cpp
    //  Graph3D
    //
    //  Created by 王 岳 on 14-7-12.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    //
#include "Main.h"
#include "FileLog.h"
#include "FreeType2.h"
#include "Screen.h"
#include "Button.h"

    // mac 的屏幕大小
int SCREEN_W = 1280;
int SCREEN_H = 800;

    // 主窗口大小
#define WIN_W 800
#define WIN_H 600

    //缓冲区大小
#define BUF_SIZE 1024

    // FreeType 字体库
FT_Library library;
FT_Face face;
FT_Matrix matrix;
FT_Vector delta;


GLYPHMETRICSFLOAT gmf[256];					// Storage For Information About Our Font

GLuint  base;
GLfloat	cnt1;			// 字体移动计数器1
GLfloat	cnt2;			// 字体移动计数器2

filelog::filelog_data our_log;
freeType2::font_data our_font;
screen::screen_data our_screen;
button::button_data our_button;
char buffer[BUF_SIZE];

GLvoid glPrint(const char *fmt, ...){
    float		length=0;				// Used To Find The Length Of The Text
	char		text[256];				// Holds Our String
	va_list		ap;					// Pointer To List Of Arguments
    if (fmt == NULL)					// If There's No Text
		return;						// Do Nothing
    va_start(ap, fmt);					// Parses The String For Variables
    vsprintf(text, fmt, ap);				// And Converts Symbols To Actual Numbers
	va_end(ap);						// Results Are Stored In Text
    for (unsigned int loop=0;loop<(strlen(text));loop++)	// Loop To Find Text Length
	{
		length+=gmf[text[loop]].gmfCellIncX;		// Increase Length By Each Characters Width
	}
    glTranslatef(-length/2,0.0f,0.0f);			// Center Our Text On The Screen
    glPushAttrib(GL_LIST_BIT);				// Pushes The Display List Bits
	glListBase(base);					// Sets The Base Character to 0
    glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);	// Draws The Display List Text
	glPopAttrib();						// Pops The Display List Bits
}

void initApp(){
    our_log.init();
    our_font.init("/Library/Fonts/Arial.ttf", 16);
    our_button.set(50, 50, 100, 40);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glEnable(GL_FLAT);
    glPushMatrix();
    glLoadIdentity();
	glTranslatef(0.0f,0.0f,-1.0f);
    glBegin(GL_POLYGON);
    
        // 白色文字
    if(our_button.pressed){
        glColor3ub(0, 0xff, 0);
    }else{
        glColor3ub(0xff, 0, 0);
    }
    SCREENPOSITION screen_position;
    our_screen.map(&screen_position, our_button.left, our_button.top, our_button.width, our_button.height);
    glVertex2f(screen_position.left, screen_position.top);
    glVertex2f(screen_position.right, screen_position.top);
    glVertex2f(screen_position.right, screen_position.bottom);
    glVertex2f(screen_position.left, screen_position.bottom);
        //    glVertex2f(-0.5, -0.5);
        //    glVertex2f(-0.5, 0.5);
        //    glVertex2f(0.5, 0.5);
        //    glVertex2f(0.5, -0.5);
    glPopMatrix();

    
        // 蓝色文字
//    glColor3ub(0,0,0xff);
    
        // 绘制WGL文字
//    glRasterPos2f(-0.40f, 0.35f);
//    glPrint("Active WGL Bitmap Text With NeHe - %7.2f", cnt1);
    
        // 红色文字
//    glColor3ub(0xff,0,0);
    
//    glPushMatrix();
//    glLoadIdentity();
//    glRotatef(cnt1,0,0,1);
//    glScalef(1,.8+.3*cos(cnt1/5),1);
//    glTranslatef(-180,0,0);
        //绘制freetype文字
//    freeType2::print(our_font, 320, 200, "Active FreeType Text*中文显示为空格*- %7.2f", cnt1);
//    glPopMatrix();
    
//    cnt1+=0.51f;
//    cnt2+=0.005f;
    glutPostRedisplay();
    glEnd();
    glFlush();
}

void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 'q':
            exit(0);
            break;
        default:
            break;
    }
}

void mouse(int button , int state, int x, int y){
    memset(buffer, 0, BUF_SIZE);
    sprintf(buffer, "state=%d, x=%d, y=%d\n", state, x, y);
    our_log.e(buffer);

    if(our_button.inArea(x, y)){
        our_button.pressed = 1;
    }else{
        our_button.pressed = 0;
    }
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Xcode Glut Demo");
    glutReshapeWindow(WIN_W, WIN_H);
    glutPositionWindow((SCREEN_W- WIN_W)/2,(SCREEN_H - WIN_H)/2);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    
    initApp();
    glutMainLoop();
        // release res.
    our_log.release();
    our_font.clean();
}
