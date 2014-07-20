//
//  View.h
//  Graph3D
//
//  Created by 王 岳 on 14-7-17.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#ifndef __Graph3D__View__
#define __Graph3D__View__

#include <iostream>
#include "FreeType2.h"

class View{
public:
    View();
    ~View();
    virtual int inArea(int x, int y);
    virtual void setBgColor(GLubyte bgColorDefault[3], GLubyte bgColorHover[3], GLubyte bgColorPressed[3]);
    virtual void display();
    virtual void setOnClickListener(void (*func)());
        // mouse callback.
    virtual void onMouseEvent(int button, int state, int x, int y);
    virtual void onMotion(int x, int y);
    virtual void onPassiveMotion(int x, int y);
private:
    void (* onClickFunc)(void);
    void onClick();
protected:
    void drawBg();
protected:
    int left;
    int top;
    int width;
    int height;
    
    int hover;
    int pressed;// 鼠标按下状态
    
    GLubyte bgColor[3];
    GLubyte bgColorHover[3];
    GLubyte bgColorPressed[3];
private:
    static const GLint COLOR_NONE;
};

#endif /* defined(__Graph3D__View__) */
