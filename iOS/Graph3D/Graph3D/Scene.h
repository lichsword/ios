    //
    //  Scene.h
    //  Graph3D
    //
    //  Created by 王 岳 on 14-7-16.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    //

#ifndef __Graph3D__Scene__
#define __Graph3D__Scene__

#include <iostream>

class Scene{

public:
    Scene();
    void onCreate();
    void onDestrory();
    void init();
    void finish();
    void display();
    void onMouseEvent(int button, int state, int x, int y);
    void onMotion(int x, int y);
    void onPassiveMotion(int x, int y);
    void onEntry(int state);
};

#endif /* defined(__Graph3D__Scene__) */
