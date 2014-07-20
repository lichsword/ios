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
Button showFreetypeButton(50, 50, 100, 40);
Button showTrangleButton(50, 100, 100, 40);
filelog::filelog_data our_log;

void testClickBtn(){
    our_log.init();
    our_log.e("press test click btn");
}

Scene::Scene(){
    
}

void Scene::init(){
    showFreetypeButton.setText("demo");
    showFreetypeButton.setOnClickListener(testClickBtn);
    showTrangleButton.setOnClickListener(testClickBtn);
    our_surface.init();
}

void Scene::finish(){
    
}

void Scene::onCreate(){
    
}

void Scene::onDestrory(){
    
}

void Scene::display(){
    showFreetypeButton.display();
    showTrangleButton.display();
    our_surface.display();
}

void Scene::onMouseEvent(int button, int state, int x, int y){
    showFreetypeButton.onMouseEvent(button, state, x, y);
    showTrangleButton.onMouseEvent(button, state, x, y);
}

void Scene::onMotion(int x, int y){
    
}

void Scene::onPassiveMotion(int x, int y){
    
}

void Scene::onEntry(int state){
    
}