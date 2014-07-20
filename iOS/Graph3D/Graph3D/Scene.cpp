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

void testClickBtn(){
    FileLog::getInstance()->init();
    FileLog::getInstance()->e("press test click btn");
}

Scene::Scene(){
    
}

void Scene::init(){
    showFreetypeButton.setText("show freetype2");
    showFreetypeButton.setBgColor(new GLubyte[3]{0, 0xff, 0x80},
                                  new GLubyte[3]{0, 0x75, 0x5e},
                                  new GLubyte[3]{0xac, 0xe1, 0xaf}
                                  );
    showFreetypeButton.setOnClickListener(testClickBtn);
    showTrangleButton.setText("show triangle");
    showTrangleButton.setBgColor(new GLubyte[3]{0, 0xff, 0x80},
                                 new GLubyte[3]{0, 0xff, 0x80},
                                 new GLubyte[3]{0, 0xff, 0x80}
                                 );
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
    showFreetypeButton.onMotion(x, y);
    showTrangleButton.onMotion(x, y);
}

void Scene::onPassiveMotion(int x, int y){
    showFreetypeButton.onPassiveMotion(x, y);
    showTrangleButton.onPassiveMotion(x, y);
}

void Scene::onEntry(int state){
    
}