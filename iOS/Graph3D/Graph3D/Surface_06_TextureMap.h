//
//  Surface_06_TextureMap.h
//  Graph3D
//
//  Created by 王 岳 on 14-7-27.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#ifndef __Graph3D__Surface_06_TextureMap__
#define __Graph3D__Surface_06_TextureMap__

#include <iostream>
#include "Surface.h"
#include "image_bitmap.h"

class TextureMapSurface : public Surface{
private:
    Image image;
public:
    virtual void onStart();
    virtual void display();
};

#endif /* defined(__Graph3D__Surface_06_TextureMap__) */
