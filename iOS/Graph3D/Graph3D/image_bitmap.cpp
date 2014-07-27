//
//  image_bitmap.cpp
//  Graph3D
//
//  Created by 王 岳 on 14-7-27.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#include "image_bitmap.h"
#include "stdio.h"

int Image::loadImage(char *path){
    FILE * lpFile;
    BitmapFileHeader bitmapFileHeader;
    BitmapInfoHeader bitmapInfoHeader;
    int channels = 1;
    int width = 0;
    int height = 0;
    int step = 0;
    int offset = 0;
    unsigned char pixelValue;
    RGBQuad * quad;
    int i;
    int j;
    int k;
    
        // start load work.
    lpFile = fopen(path, "rb");
    if(!lpFile){
            // error
        return NULL;
    }// end if
    
        // TODO
    return 1;
}