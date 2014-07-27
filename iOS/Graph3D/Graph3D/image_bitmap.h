    //
    //  image_bitmap.h
    //  Graph3D
    //
    //  Created by 王 岳 on 14-7-27.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    //

#ifndef __Graph3D__image_bitmap__
#define __Graph3D__image_bitmap__

#include <iostream>

    // bitmap 文件头
typedef struct{
    unsigned long size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned long offset;
}BitmapFileHeader;

    // bitmap 信息头
typedef struct{
    unsigned long size;
    long width;
    long height;
    unsigned short planes;
    unsigned short bitCount;
    unsigned long compression;
    unsigned long sizeImage;
    long XPelsPerMeter;
    long YPelsPerMeter;
    unsigned long ctrlUsed;
    unsigned long ctrlImportant;
}BitmapInfoHeader;

    // rgb 四元数
typedef struct{
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
}RGBQuad;

//typedef struct{
//    int width;
//    int height;
//    int channels;
//    unsigned char * imageData;
//}Image;

class Image{
private:
    int width;
    int height;
    int channels;
    unsigned char * imageData;
public:
    int loadImage(char * path);
};

#endif /* defined(__Graph3D__image_bitmap__) */