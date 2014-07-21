    //
    //  Main.cpp
    //  Graph3D
    //
    //  Created by 王 岳 on 14-7-12.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    //
#include "Main.h"
#include "Test.h"
#include "FileLog.h"
#include "FreeType2.h"
#include "Scene.h"
//#include "Screen.h"
//#include "Button.h"


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

GLuint base;

//filelog::filelog_data our_log;
Scene our_scene;

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
//    our_log.init();
    our_scene.init();

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    our_scene.display();

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
    switch (button) {
        case GLUT_LEFT_BUTTON:
            break;
        case GLUT_MIDDLE_BUTTON:
            break;
        case GLUT_RIGHT_BUTTON:
            break;
        default:
            break;
    }
    
    switch (state) {
        case GLUT_UP:
            break;
        case GLUT_DOWN:
            break;
        default:
            break;
    }
    
//    memset(buffer, 0, BUF_SIZE);
//    sprintf(buffer, "button=%d, state=%d, x=%d, y=%d\n", state, x, y);
//    our_log.e(buffer);
    our_scene.onMouseEvent(button, state, x, y);
}

/* 鼠标移动，且有按钮被按下 */
void motion(int x, int y){
    our_scene.onMotion(x, y);
}

/* 鼠标移动，无论是否有按钮按下 */
void passiveMotion(int x, int y){
    our_scene.onPassiveMotion(x, y);
}

void entry(int state){
    switch (state) {
        case GLUT_LEFT:
                // 离开窗口
            break;
        case GLUT_ENTERED:
                // 进入窗口
            break;
        default:
            break;
    }
}

int main(int argc, char ** argv)
{
    Test::getInstance();
    
    glutInit(&argc, argv);
    glutCreateWindow("Xcode Glut Demo");
    glutReshapeWindow(WIN_W, WIN_H);
    glutPositionWindow((SCREEN_W- WIN_W)/2, (SCREEN_H - WIN_H)/2);
        //    glutPositionWindow((SCREEN_W- WIN_W)/2 + 400,(SCREEN_H - WIN_H)/2 + 400);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutPassiveMotionFunc(passiveMotion);
    glutEntryFunc(entry);
    
    initApp();
    glutMainLoop();
        // release res.
//    our_log.release();
//    our_font.clean();
}