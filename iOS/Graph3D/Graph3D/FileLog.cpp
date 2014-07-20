//
//  FileLog.cpp
//  Graph3D
//
//  Created by 王 岳 on 14-7-15.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#include "FileLog.h"

FileLog * FileLog::sInstance = NULL;
char FileLog::PATH[] = "/Users/lichsword/Documents/workspace_apple/iOS/Graph3D/out/log.txt";

void FileLog::init(){
    lpFile = fopen(FileLog::PATH, "w+");
    if(NULL == lpFile){
            // log error.
    }// end if
}

void FileLog::e(char * log){
    if(NULL!=lpFile){
        fputs(log, lpFile);
        fflush(lpFile);
    }// end if
}

void FileLog::release(){
    if(NULL!=lpFile){
        fclose(lpFile);
    }// end if
}