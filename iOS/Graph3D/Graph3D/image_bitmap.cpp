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
    unsigned short fileType;
    BitmapFileHeader bitmapFileHeader;
    BitmapInfoHeader bitmapInfoHeader;
    int channels = 1;
    long dataSize = 0;
    int step = 0;
    int offset = 0;
    unsigned char pixelValue;
    RGBQuad * quad;
    
        // start load work.
    lpFile = fopen(path, "rb");
    if(!lpFile){
            // error
        return NULL;
    }// end if
    
    fread(&fileType, sizeof(unsigned short), 1, lpFile);
    if(fileType != 0x4d42){
            // not bitmap.
        return NULL;
    }// end if
    
    fseek(lpFile, 0, SEEK_SET);
    memset(&bitmapFileHeader, 0, sizeof(BitmapFileHeader));
    fread(&bitmapFileHeader, sizeof(BitmapFileHeader), 1, lpFile);
    fseek(lpFile, 14, SEEK_SET);
    memset(&bitmapInfoHeader, 0, sizeof(BitmapInfoHeader));
    fread(&bitmapInfoHeader, sizeof(BitmapInfoHeader), 1, lpFile);
    
    this->bitCount = bitmapInfoHeader.bitCount;
    if(bitmapInfoHeader.bitCount == 8){
            // 8 位，有调色板
        width = bitmapInfoHeader.width;
        height = bitmapInfoHeader.height;
        
        if(NULL!=data){
            delete data;
        }// end if
        
            // read image data.
        dataSize = width * height * 1;// 8 位 is 1 byte
        data = (unsigned char *) alloca(dataSize);
        memset(data, 0, dataSize);
        
        int lineBytes = width * 1;
        int colBytes = 1;
        
        int fileOffset = bitmapFileHeader.offset;
        int memOffset = 0;
        
        for(int line = 0; line < height; line++){
            for(int col = 0; col < width; col ++){
                fseek(lpFile, fileOffset, SEEK_SET);
                fread(data + memOffset, 1, 1, lpFile);
                fileOffset += colBytes;
                memOffset += colBytes;
            }
        }
        
    }else if(bitmapInfoHeader.bitCount == 24){
            // 24 位，RGB 3色
        width = bitmapInfoHeader.width;
        height = bitmapInfoHeader.height;
        
        if(NULL!= data){
            delete data;
        }// end if
        
            // read image data.
        dataSize = width * height * 3;// 24位 is 3 bytes
        data = (unsigned char *)alloca(dataSize);
        memset(data, 0, dataSize);
        
        int lineBytes = width * 3;
        int colBytes = 3;
        
        int fileOffset = bitmapFileHeader.offset;
        int memOffset = 0;
        for(int line=0; line<height; line++) {
            for(int col=0; col<width; col++) {
                    //----------
                fseek(lpFile, (fileOffset + 2), SEEK_SET);          fread((data + memOffset + 2), 1, 1, lpFile);
                fseek(lpFile, (fileOffset +1), SEEK_SET);           fread((data + memOffset + 1), 1, 1, lpFile);
                fseek(lpFile, fileOffset, SEEK_SET);                fread((data + memOffset), 1, 1, lpFile);
//--------
//                *(data + memOffset) = 0xff;
//                *(data + memOffset + 1) = 0x00;
//                *(data + memOffset + 2) = 0x00;
                
                fileOffset +=colBytes;
                memOffset+= colBytes;
            }
        }
    }// end if
    
    if(NULL!=lpFile){
        fclose(lpFile);
        lpFile = NULL;
    }// end if
    
    return 1;
}