    //
    //  Scene.cpp
    //  Graph3D
    //
    //  Created by 王 岳 on 14-7-16.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    //

#include "FileLog.h"
#include "Scene.h"
#include "Button.h"
#include "SurfaceView.h"

surfaceview::surfaceview_data our_surface;
Button our_button(50, 50, 100, 40);
filelog::filelog_data our_log;

//void testClickBtn(){
//    our_log.init();
//    our_log.e("press test click btn");
//}

Scene::Scene(int param){
    
}

void Scene::init(){
    our_button.setText("demo");
//    our_button.setOnClickListener(testClickBtn);
    our_surface.init();
}

void Scene::finish(){
    
}

void Scene::onCreate(){
    
}

void Scene::onDestrory(){
    
}

void Scene::display(){
    our_button.display();
    our_surface.display();
}

void Scene::onMouseEvent(int button, int state, int x, int y){
    our_button.onMouseEvent(button, state, x, y);
}

void Scene::onMotion(int x, int y){
    
}

void Scene::onPassiveMotion(int x, int y){
    
}

void Scene::onEntry(int state){
    
}