//
//  ErrorReport.h
//  Graph3D
//
//  Created by 王 岳 on 14-8-11.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#ifndef __Graph3D__ErrorReport__
#define __Graph3D__ErrorReport__

#include <iostream>

class ErrorReport{
public:
    static ErrorReport * getInstance(){
        if(NULL==sInstance){
            sInstance = new ErrorReport();
        }// end if
        return sInstance;
    }
    void init();
    void print(char * tag);
    void release();
private:
    static const int BUFFER_SIZE = 256;
    char buffer[BUFFER_SIZE];
private:
    ErrorReport(){
        init();
    }
    static ErrorReport * sInstance;
};

#endif /* defined(__Graph3D__ErrorReport__) */
