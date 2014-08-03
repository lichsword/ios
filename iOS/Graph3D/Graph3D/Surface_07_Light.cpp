    //
    //  Surface_07_Light.cpp
    //  Graph3D
    //
    //  Created by 王 岳 on 14-8-3.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    // (1)注意要设置法线，用于光源反射
    // (2)设置1号光源，开启光源
    // (3)每帧要清理颜色缓冲区和深度缓冲区
    // (4)操作:
    //    z 拉近;
    //    Z:拉远;
    //    a/A:左移;
    //    d/D:右移;
    //    w/W:上移;
    //    s/S:下移
    //    l/L:开关灯光
    //    r/R:旋转方向反转
    //

#include "Surface_07_Light.h"
#include "Screen.h"
#include "FileLog.h"
#include "FreeType2.h"

void LightSurface::keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 'L':
        case 'l':
            if (light) {
                light = 0;
            }else{
                light = 1;
            }
            
            memset(buffer, 0, 128);
            sprintf(buffer, "curren light = %d", light);
            FileLog::getInstance()->e(buffer);
            break;
        case 'Z':
            this->z -= 0.5f;
            break;
        case 'z':
            this->z += 0.5f;
            break;
        case 'a':
        case 'A':
            this->x -= 0.5f;
            break;
        case 'd':
        case 'D':
            this->x += 0.5f;
            break;
        case 'w':
        case 'W':
            this->y += 0.5f;
            break;
        case 's':
        case 'S':
            this->y -= 0.5f;
            break;
        case 'r':
        case 'R':
            if(rotateLeft){
                rotateLeft =0;
            }else{
                rotateLeft = 1;
            }
            break;
        default:
            break;
    }
}

void LightSurface::loadTexture2D(GLuint id, Image image){
        // 上下文绑定纹理(一般在glTexImage2D之后调用)
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // 线形滤波
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 线形滤波
    
        // 加载纹理数据
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.getWidth(), image.getHeight(), 0, GL_BGR, GL_UNSIGNED_BYTE, image.getImageDataRef());
}


void LightSurface::onStart(){
    lpImages = new Image[3];
        // 加载位图
    lpImages[0].loadImage(this->bmp_file_3);
    
    lpTextureID = new GLuint[3];
        // 开启2D纹理
    glEnable(GL_TEXTURE_2D);
        // 生成纹理对象索引,赋值给变量
    glGenTextures(2, lpTextureID);
        // 加载纹理
    loadTexture2D(lpTextureID[0], lpImages[0]);
        // 设置环境光
    glLightfv(GL_LIGHT0, GL_AMBIENT, LightAmbient);
        // 设置光源位置
    glLightfv(GL_LIGHT0, GL_POSITION,LightPosition);
        // 启用0号光源
    glEnable(GL_LIGHT0);
    
    /**
     * func: 设置纹理的环境参数
     * use GL_MODULATE instead of GL_REPLACE if lighting is being used GL_REPLACE
     */
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
    glMatrixMode(GL_PROJECTION);// 选择投影矩阵
	glLoadIdentity(); // 重置投影矩阵
    
	gluPerspective(45.0f, (GLfloat)real_w/(GLfloat)real_h, 0.1f, 100.0f);// 设置视口的大小
	glMatrixMode(GL_MODELVIEW); // 选择模型观察矩阵
	glLoadIdentity(); // 重置模型观察矩阵
    
}

void LightSurface::display(){
    
    if(light){
            // 开启光源
        glEnable(GL_LIGHTING);
            // 开启0号光源
            //        glEnable(GL_LIGHT0);
    }else{
            // 关闭光源
        glDisable(GL_LIGHTING);
            // 关闭0号光源
            //        glDisable(GL_LIGHT0);
    }// endif
    
        // 设置深度缓冲值为1.0f
    glClearDepth(1.0f);
        // 清除颜色缓冲区 和 深度缓冲区
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // 上下文绑定纹理
    glBindTexture(GL_TEXTURE_2D, lpTextureID[0]);
    
        // 开启深度测试
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    
    /**
     * bug: print了字符，则立方体就不显示。
     */
        //    glColor3ub(255, 255, 0);
        //    memset(buffer, 0, sizeof(buffer));
        //    sprintf(buffer, "'Z' z++; 'z' z--; ");
        //    FreeType2::getInstance()->print(250, real_h - 50, buffer);
    
        // 保护原栈
    glPushMatrix();
    
    glLoadIdentity();
        // 偏移和旋转
    glTranslatef(x, y, z);
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    
        // 开始编制
    glBegin(GL_QUADS);
    
        // 前面
    glNormal3f( 0.0f, 0.0f, 1.0f);					// 法线指向观察者
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);// 纹理和四边形的左下
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);// 纹理和四边形的左上
    
        // 后面
    glNormal3f( 0.0f, 0.0f,-1.0f);					// 法线背向观察者
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);// 纹理和四边形的左下
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);// 纹理和四边形的左下
    
        // 顶面
    glNormal3f( 0.0f, 1.0f, 0.0f);					// 法线向上
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);// 纹理和四边形的左上
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);// 纹理和四边形的左下
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, 1.0f, 1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);// 纹理和四边形的右上
    
        // 底面
    glNormal3f( 0.0f,-1.0f, 0.0f);					// 法线朝下
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);// 纹理和四边形的左上
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);// 纹理和四边形的左下
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);// 纹理和四边形的右下
    
        // 右面
    glNormal3f( 1.0f, 0.0f, 0.0f);					// 法线朝右
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f, 1.0f, -1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, 1.0f, 1.0f);// 纹理和四边形的左上
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, 1.0f);// 纹理和四边形的左下
    
        // 左面
    glNormal3f(-1.0f, 0.0f, 0.0f);					// 法线朝左
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 纹理和四边形的左下
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);// 纹理和四边形的右下
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);// 纹理和四边形的右上
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);// 纹理和四边形的左上
    
    glEnd();
    glPopMatrix();
    
        // 下一帧位移与旋转参数增加
    if(rotateLeft){
        xRot += 1.0f;
        yRot -= 2.0f;
    }else{
        xRot -= 1.0f;
        yRot += 2.0f;
    }
    
}