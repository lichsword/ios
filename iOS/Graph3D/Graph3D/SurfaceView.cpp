    //
    //  SurfaceView.cpp
    //  Graph3D
    //
    //  Created by 王 岳 on 14-7-16.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    //

#include "SurfaceView.h"
#include "FreeType2.h"

namespace surfaceview {
    GLuint  base;
    GLfloat	cnt1;			// 字体移动计数器1
    GLfloat	cnt2;			// 字体移动计数器2
    
    void surfaceview_data::init(){
        
    }
    
    void surfaceview_data::display(){
            // 红色文字
        glColor3ub(0xff,0,0);
        
        glPushMatrix();
        glLoadIdentity();
        glRotatef(cnt1,0,0,1);
        glScalef(1,.8+.3*cos(cnt1/5),1);
        glTranslatef(-180,0,0);
            //绘制freetype文字
        FreeType2::getInstance()->print(300, 200, "Active FreeType Text- %7.2f", cnt1);
        glPopMatrix();
        
        cnt1+=2.0f;
        cnt2+=0.005f;
    }
    
}