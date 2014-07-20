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

namespace filelog {
    using std::vector;
    using std::string;
    
    const char PATH[] = "/Users/lichsword/Documents/workspace_apple/iOS/Graph3D/out/log.txt";
    
    struct filelog_data{
        FILE * lpFile;

        void init();
        void e(char * log);
        void release();
    };
}

#endif /* defined(__Graph3D__FileLog__) */
