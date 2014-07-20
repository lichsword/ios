//
//  FileLog.h
//  Graph3D
//
//  Created by 王 岳 on 14-7-15.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#ifndef __Graph3D__FileLog__
#define __Graph3D__FileLog__

#include <iostream>

#include<stdlib.h>
#include<stdio.h>
    //STL 头文件
#include <vector>
#include <string>
#include <math.h>
    //STL异常类
#include <stdexcept>

class FileLog{
public:
    static FileLog * getInstance(){
        if(NULL==sInstance){
            sInstance = new FileLog();
        }// end if
        return sInstance;
    }
    void init();
    void e(char * log);
    void release();
private:
    static FileLog * sInstance;
    static char PATH[];
    FILE * lpFile;
};

#endif /* defined(__Graph3D__FileLog__) */