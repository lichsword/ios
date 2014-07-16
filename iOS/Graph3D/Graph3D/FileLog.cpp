//
//  FileLog.cpp
//  Graph3D
//
//  Created by 王 岳 on 14-7-15.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#include "FileLog.h"

namespace filelog {
    
    void filelog_data::init(){
        lpFile = fopen(PATH, "w+");
        if(NULL == lpFile){
                // log error.
        }// end if
    }
    
    void filelog_data::e(char * log){
        if(NULL!=lpFile){
            fputs(log, lpFile);
            fflush(lpFile);
        }// end if
    }
    
    void filelog_data::release(){
        if(NULL!=lpFile){
            fclose(lpFile);
        }// end if
    }
}