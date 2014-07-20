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
private:
    void (* onClickFunc)(void);
    void onClick();
protected:
    int left;
    int top;
    int width;
    int height;
    
    int pressed;
    
public:
    View();
    ~View();
    virtual int inArea(int x, int y);
    virtual void display();
    virtual void setOnClickListener(void (*func)());
        // mouse callback.
    virtual void onMouseEvent(int button, int state, int x, int y);
    virtual void onMotion(int x, int y);
    virtual void onPassiveMotion(int x, int y);
};

#endif /* defined(__Graph3D__View__) */
