    //
    //  ErrorReport.cpp
    //  Graph3D
    //
    //  Created by 王 岳 on 14-8-11.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    //

#include "ErrorReport.h"
    //OpenGL 头文件
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/Glut.h>
    // File log class
#include "FileLog.h"

ErrorReport * ErrorReport::sInstance = NULL;

void ErrorReport::init(){
    FileLog::getInstance()->init();
}

void ErrorReport::release(){
    
}

void ErrorReport::print(char * tag){
    memset(buffer, 0, sizeof(ErrorReport::BUFFER_SIZE));
    
    GLenum errorCode = glGetError();
    switch (errorCode) {
        case GL_NO_ERROR:
            sprintf(buffer, "%s | GL_NO_ERROR\n", tag);
            break;
        case GL_INVALID_ENUM:
            sprintf(buffer, "%s | GL_INVALID_ENUM\n", tag);
            break;
        case GL_INVALID_VALUE:
            sprintf(buffer, "%s | GL_INVALID_VALUE\n", tag);
            break;
        case GL_INVALID_OPERATION:
            sprintf(buffer, "%s | GL_INVALID_OPERATION\n", tag);
            break;
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            sprintf(buffer, "%s | GL_INVALID_FRAMEBUFFER_OPERATION\n", tag);
            break;
        case GL_OUT_OF_MEMORY:
            sprintf(buffer, "%s | GL_OUT_OF_MEMORY\n", tag);
            break;
        default:
            sprintf(buffer, "%s | Unknown GL error.\n", tag);
            break;
    }
    
    return;
}