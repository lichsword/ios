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
    // 替换默认的对齐4字节为对齐1字节
#pragma pack(push)  /* push current alignment to stack */
#pragma pack(1)     /* set alignment to 1 byte boundary */
typedef struct{
    unsigned short type;// 2 bytes
    unsigned int size;// 4 bytes
    unsigned short reserved1;// 2 bytes
    unsigned short reserved2;// 2 bytes
    unsigned int offset;// 4 bytes
}BitmapFileHeader;
#pragma pack(pop)   /* restore original alignment from stack */

    // bitmap 信息头
    // 替换默认的对齐4字节为对齐1字节
#pragma pack(push)  /* push current alignment to stack */
#pragma pack(1)     /* set alignment to 1 byte boundary */
typedef struct{
    unsigned int size;
    unsigned int width;
    unsigned int height;
    unsigned short planes;
    unsigned short bitCount;
    unsigned int compression;
    unsigned int sizeImage;
    unsigned int XPelsPerMeter;
    unsigned int YPelsPerMeter;
    unsigned int ctrlUsed;
    unsigned int ctrlImportant;
}BitmapInfoHeader;
#pragma pack(pop)   /* restore original alignment from stack */

    // rgb 四元数
typedef struct{
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
}RGBQuad;

class Image{
private:
    int width;
    int height;
    int channels;
    unsigned char * data;
public:
    Image(){
        width = 0;
        height = 0;
        channels = 0;
        data = NULL;
    }
    int getWidth(){return width;}
    int getHeight(){return height;}
    unsigned char * getImageDataRef(){
        return data;
    }
public:
    int loadImage(char * path);
};

#endif /* defined(__Graph3D__image_bitmap__) */