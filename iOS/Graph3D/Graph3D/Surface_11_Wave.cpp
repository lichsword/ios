    //
    //  Surface_11_wave.cpp
    //  Graph3D
    //
    //  Created by 王 岳 on 14-8-7.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    //

#include "Surface_11_Wave.h"
#include "Screen.h"

void WaveSurface::loadTexture2D(GLuint id, Image image){
        // 上下文绑定纹理(一般在glTexImage2D之后调用)
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // 线形滤波
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // 线形滤波
    
        // 加载纹理数据
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.getWidth(), image.getHeight(), 0, GL_BGR, GL_UNSIGNED_BYTE, image.getImageDataRef());
}

void WaveSurface::onStart(){
        // 使用2D纹理
	glEnable(GL_TEXTURE_2D);
        // 使用平滑着色
	glShadeModel(GL_SMOOTH);
        // 设置黑色背景
	glClearColor(0.05f, 0.05f, 0.05f, 0.5f);
        // 设置深度缓存
	glClearDepth(1.0f);
        // 使用深度缓存
	glEnable(GL_DEPTH_TEST);
        // 设置深度方程
	glDepthFunc(GL_LEQUAL);
        // 精细透视修正
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    
    lpImages = new Image();
    lpImages->loadImage(bmp_file_1);
    lpTextures = new GLuint[1];
    glGenTextures(1, lpTextures);
    glBindTexture(GL_TEXTURE_2D, lpTextures[0]);
        // 载入纹理
    loadTexture2D(lpTextures[0], *lpImages);
    
    /**
     * func: 设置纹理的环境参数
     * use GL_MODULATE instead of GL_REPLACE if lighting is being used GL_REPLACE
     */
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    
    glMatrixMode(GL_PROJECTION);// 选择投影矩阵
	glLoadIdentity(); // 重置投影矩阵
    
	gluPerspective(45.0f, (GLfloat)real_w/(GLfloat)real_h, 0.1f, 100.0f);// 设置视口的大小
	glMatrixMode(GL_MODELVIEW); // 选择模型观察矩阵
	glLoadIdentity(); // 重置模型观察矩阵
    
        // 沿X平面循环
	for(int x=0; x<45; x++){
            // 沿Y平面循环
		for(int y=0; y<45; y++){
                // 向表面添加波浪效果
			points[x][y][0]=float((x/5.0f)-4.5f);
			points[x][y][1]=float((y/5.0f)-4.5f);
			points[x][y][2]=float(sin((((x/5.0f)*40.0f)/360.0f)*3.141592654*2.0f));
		}
	}
}

void WaveSurface::display(){
        // 用来将旗形的波浪分割成很小的四边形
	float float_x;
    float float_y;
    float float_xb;
    float float_yb;
    
        // 设置深度缓冲值为1.0f
    glClearDepth(1.0f);
        // 清除颜色缓冲区 和 深度缓冲区
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        // 上下文绑定纹理
    glBindTexture(GL_TEXTURE_2D, lpTextures[0]);
    
        // 保护原栈
    glPushMatrix();
    
    glLoadIdentity();
        // 偏移和旋转
    glTranslatef(this->x, this->y, this->z);
    glRotatef(rotX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotZ, 0.0f, 0.0f, 1.0f);
    
    glPolygonMode( GL_BACK, GL_FILL );			// 后表面完全填充
	glPolygonMode( GL_FRONT, GL_LINE );			// 前表面使用线条绘制
    

        // 四边形绘制开始
    glBegin(GL_QUADS);
        // 沿 X 平面 0-44 循环(45点)
	for(int x = 0; x < 44; x++ ){
            // 沿 Y 平面 0-44 循环(45点)
		for(int y = 0; y < 44; y++ ){
                // 生成X浮点值
            float_x = float(x)/44.0f;
                // 生成Y浮点值
			float_y = float(y)/44.0f;
                // X浮点值+0.0227f
			float_xb = float(x+1)/44.0f;
                // Y浮点值+0.0227f
			float_yb = float(y+1)/44.0f;
                // 第一个纹理坐标 (左下角)
            glTexCoord2f( float_x, float_y);				glVertex3f(points[x][y][0], points[x][y][1], points[x][y][2]);
                // 第二个纹理坐标 (左上角)
			glTexCoord2f( float_x, float_yb );
			glVertex3f( points[x][y+1][0], points[x][y+1][1], points[x][y+1][2] );
                // 第三个纹理坐标 (右上角)
			glTexCoord2f(float_xb, float_yb );
			glVertex3f( points[x+1][y+1][0], points[x+1][y+1][1], points[x+1][y+1][2] );
                // 第四个纹理坐标 (右下角)
			glTexCoord2f( float_xb, float_y );
			glVertex3f( points[x+1][y][0], points[x+1][y][1], points[x+1][y][2]);
		}
	}
    glEnd();
    glPopMatrix();
    
        // 下一帧位移与旋转参数增加
    if(rotateLeft){
        rotX += 1.0f;
        rotY -= 2.0f;
    }else{
        rotX -= 1.0f;
        rotY += 2.0f;
    }
}

void WaveSurface::keyboard(unsigned char key, int x, int y){
    switch (key) {
//        case 'L':
//        case 'l':
//            if (light) {
//                light = 0;
//            }else{
//                light = 1;
//            }
//            
//            memset(buffer, 0, 128);
//            sprintf(buffer, "curren light = %d", light);
//            FileLog::getInstance()->e(buffer);
//            break;
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