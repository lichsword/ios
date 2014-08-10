//
//  SkyBox.cpp
//  Graph3D
//
//  Created by 王 岳 on 14-8-9.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#include "SkyBox.h"

void SkyBox::a(int index, char * path){
    switch (this->type) {
        case SkyBox::TYPE_BOX:
            if (NULL==lpImages) {
                lpImages = new Image[SkyBox::SIZE_BOX];
            }// end if
            
            lpImages[index].loadImage(path);
            break;
        case SkyBox::TYPE_SPHERE:
                // TODOs
            break;
        default:
            break;
    }
}