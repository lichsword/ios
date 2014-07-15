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

namespace freeType2{
        // 使用vector和string名字空间
    using std::vector;
    using std::string;
    
    struct font_data
    {
        float h; // 字体的高度
        GLuint * textures; // 使用的纹理
        GLuint list_base; // 显示列表的值
        
            // 初始化结构
        void init(const char * fname, unsigned int h);
            // 清楚所有的资源
        void clean();
            // 判断utf8字符长度
        int getUtf8Size(char c);
            // utf8转为unicode
        FT_ULong utf8tounicode(char *s, int size);
        
        int getULongList(const string& line, vector<FT_ULong> &list);
    };
    
        // 把字符输出到屏幕
    void print(const font_data &ft_font, float x, float y, const char *fmt, ...);
}


#endif /* defined(__Graph3D__FreeType2__) */
