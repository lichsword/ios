//
//  FreeType2.h
//  Graph3D
//
//  Created by 王 岳 on 14-7-15.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#ifndef __Graph3D__FreeType2__
#define __Graph3D__FreeType2__

//#include <iostream>

    //FreeType 头文件
#include <ft2build.h>
#include <freetype/freetype.h>
#include <freetype/ftglyph.h>
#include <freetype/ftoutln.h>
#include <freetype/fttrigon.h>
    //OpenGL 头文件
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/Glut.h>
    //STL 头文件
#include <vector>
#include <string>
#include <math.h>
    //STL异常类
#include <stdexcept>

using std::vector;
using std::string;

class FreeType2{
private:
    static FreeType2 * sInstance;// 单例对象指针
    static char FONT_PATH[];// 字体所在库的路径
    static int FONT_SIZE_H;// 字符高度
    float h; // 字体的高度
    GLuint * textures; // 使用的纹理
    GLuint list_base; // 显示列表的值
private:
    FreeType2();
    ~FreeType2();
        // 初始化结构
    void init(const char * fname, unsigned int h);
        // 清楚所有的资源
    void clean();
private:
    inline int next_p2 (int a );
    inline void pushScreenCoordinateMatrix();
    inline void pop_projection_matrix();
    void make_dlist(FT_Face face, char ch, GLuint list_base, GLuint * tex_base);
public:
    static FreeType2 * getInstance(){
        if(NULL==sInstance){
            sInstance = new FreeType2();
        }// end if
        return sInstance;
    }
        // 把字符输出到屏幕
    void print(float x, float y, const char *fmt, ...);
};

#endif /* defined(__Graph3D__FreeType2__) */