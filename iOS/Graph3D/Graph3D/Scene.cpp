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
#include "Surface_01_BaseWindow.h"
#include "Surface_02_Quads.h"
#include "Surface_03_Colors.h"
#include "Surface_04_Rotate.h"

Button showFreetypeButton(10, 10, 150, 40);
Button showTrangleButton(10, 60, 150, 40);
Button showColorButton(10, 110, 150, 40);
Button showRotateButton(10, 160, 150, 40);
    // surfaces
Surface * currentSurface;
BaseWindowSurface baseWindowSurface;
QuadsSurface quadsSurface;
ColorsSurface colorsSurface;
RotateSurface rotateSurface;

void choose01(){
        //    FileLog::getInstance()->init();
        //    FileLog::getInstance()->e("press test click btn");
    currentSurface = &baseWindowSurface;
    currentSurface->onStart();
}

void choose02(){
    currentSurface = &quadsSurface;
    currentSurface->onStart();
}

void choose03(){
    currentSurface = &colorsSurface;
    currentSurface->onStart();
}

void choose04(){
    currentSurface = &rotateSurface;
    currentSurface->onStart();
}

Scene::Scene(){
    
}

void Scene::init(){
    showFreetypeButton.setText("show freetype2");
    showFreetypeButton.setBgColor(new GLubyte[3]{0, 0xff, 0x80},
                                  new GLubyte[3]{0, 0x75, 0x5e},
                                  new GLubyte[3]{0xac, 0xe1, 0xaf}
                                  );
    showFreetypeButton.setOnClickListener(choose01);
    showTrangleButton.setText("show triangle");
    showTrangleButton.setBgColor(new GLubyte[3]{0, 0xff, 0x80},
                                 new GLubyte[3]{0, 0x75, 0x5e},
                                 new GLubyte[3]{0xac, 0xe1, 0xaf}
                                 );
    showTrangleButton.setOnClickListener(choose02);
    showColorButton.setText("show colors");
    showColorButton.setBgColor(new GLubyte[3]{0, 0xff, 0x80},
                               new GLubyte[3]{0, 0x75, 0x5e},
                               new GLubyte[3]{0xac, 0xe1, 0xaf}
                               );
    showColorButton.setOnClickListener(choose03);
    showRotateButton.setText("show rotate");
    showRotateButton.setBgColor(new GLubyte[3]{0, 0xff, 0x80},
                                new GLubyte[3]{0, 0x75, 0x5e},
                                new GLubyte[3]{0xac, 0xe1, 0xaf}
                                );
    showRotateButton.setOnClickListener(choose04);
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
    showColorButton.display();
    showRotateButton.display();
    if(NULL!=currentSurface){
        currentSurface->display();
    }// end if
}

void Scene::onMouseEvent(int button, int state, int x, int y){
    showFreetypeButton.onMouseEvent(button, state, x, y);
    showTrangleButton.onMouseEvent(button, state, x, y);
    showColorButton.onMouseEvent(button, state, x, y);
    showRotateButton.onMouseEvent(button, state, x, y);
}

void Scene::onMotion(int x, int y){
    showFreetypeButton.onMotion(x, y);
    showTrangleButton.onMotion(x, y);
    showColorButton.onMotion(x, y);
    showRotateButton.onMotion(x, y);
}

void Scene::onPassiveMotion(int x, int y){
    showFreetypeButton.onPassiveMotion(x, y);
    showTrangleButton.onPassiveMotion(x, y);
    showColorButton.onPassiveMotion(x, y);
    showRotateButton.onPassiveMotion(x, y);
}

void Scene::onEntry(int state){
    
}