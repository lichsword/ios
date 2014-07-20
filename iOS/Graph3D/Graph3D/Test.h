    //
    //  Test.h
    //  Graph3D
    //
    //  Created by 王 岳 on 14-7-20.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    //

#ifndef __Graph3D__Test__
#define __Graph3D__Test__

#include <iostream>

class Test{
private:
    Test(){}
    ~Test(){}
    static Test * lpTest;
public:
    static Test * getInstance(){
        if(NULL==Test::lpTest){
            Test::lpTest = new Test();
        }// end if
        return Test::lpTest;
    }
};

#endif /* defined(__Graph3D__Test__) */