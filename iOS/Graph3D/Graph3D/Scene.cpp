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
#include "Surface_05_Cube3D.h"
#include "Surface_06_TextureMap.h"
#include "Surface_07_Light.h"

Button showFreetypeButton(10, 10, 150, 40);
Button showTrangleButton(10, 60, 150, 40);
Button showColorButton(10, 110, 150, 40);
Button showRotateButton(10, 160, 150, 40);
Button showCube3DButton(10, 210, 150, 40);
Button showTextureMapButton(10, 260, 150, 40);
Button showLightButton(10, 310, 150, 40);
    // surfaces
Surface * currentSurface;
BaseWindowSurface baseWindowSurface;
QuadsSurface quadsSurface;
ColorsSurface colorsSurface;
RotateSurface rotateSurface;
Cube3DSurface cube3DSurface;
TextureMapSurface textureMapSurface;
LightSurface lightSurface;

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

void choose05(){
    currentSurface = &cube3DSurface;
    currentSurface->onStart();
}

void choose06(){
    currentSurface = &textureMapSurface;
    currentSurface->onStart();
}

void choose07(){
    currentSurface = &lightSurface;
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
        //
    showTrangleButton.setText("show triangle");
    showTrangleButton.setBgColor(new GLubyte[3]{0, 0xff, 0x80},
                                 new GLubyte[3]{0, 0x75, 0x5e},
                                 new GLubyte[3]{0xac, 0xe1, 0xaf}
                                 );
    showTrangleButton.setOnClickListener(choose02);
        //
    showColorButton.setText("show colors");
    showColorButton.setBgColor(new GLubyte[3]{0, 0xff, 0x80},
                               new GLubyte[3]{0, 0x75, 0x5e},
                               new GLubyte[3]{0xac, 0xe1, 0xaf}
                               );
    showColorButton.setOnClickListener(choose03);
        //
    showRotateButton.setText("show rotate");
    showRotateButton.setBgColor(new GLubyte[3]{0, 0xff, 0x80},
                                new GLubyte[3]{0, 0x75, 0x5e},
                                new GLubyte[3]{0xac, 0xe1, 0xaf}
                                );
    showRotateButton.setOnClickListener(choose04);
        //
    showCube3DButton.setText("show Cube 3D");
    showCube3DButton.setBgColor(new GLubyte[3]{0, 0xff, 0x80},
                                new GLubyte[3]{0, 0x75, 0x5e},
                                new GLubyte[3]{0xac, 0xe1, 0xaf}
                                );
    showCube3DButton.setOnClickListener(choose05);
        //
    showTextureMapButton.setText("show Texture");
    showTextureMapButton.setBgColor(new GLubyte[3]{0, 0xff, 0x80},
                                new GLubyte[3]{0, 0x75, 0x5e},
                                new GLubyte[3]{0xac, 0xe1, 0xaf}
                                );
    showTextureMapButton.setOnClickListener(choose06);
        //
    showLightButton.setText("show Light");
    showLightButton.setBgColor(new GLubyte[3]{0, 0xff, 0x80},
                                    new GLubyte[3]{0, 0x75, 0x5e},
                                    new GLubyte[3]{0xac, 0xe1, 0xaf}
                                    );
    showLightButton.setOnClickListener(choose07);
}

void Scene::finish(){
    
}

void Scene::onCreate(){
    
}

void Scene::onDestrory(){
    
}

void Scene::display(){
    if(NULL!=currentSurface){
        currentSurface->display();
    }// end if
    showFreetypeButton.display();
    showTrangleButton.display();
    showColorButton.display();
    showRotateButton.display();
    showCube3DButton.display();
    showTextureMapButton.display();
    showLightButton.display();
}

void Scene::onMouseEvent(int button, int state, int x, int y){
    showFreetypeButton.onMouseEvent(button, state, x, y);
    showTrangleButton.onMouseEvent(button, state, x, y);
    showColorButton.onMouseEvent(button, state, x, y);
    showRotateButton.onMouseEvent(button, state, x, y);
    showCube3DButton.onMouseEvent(button, state, x, y);
    showTextureMapButton.onMouseEvent(button, state, x, y);
    showLightButton.onMouseEvent(button, state, x, y);
}

void Scene::onMotion(int x, int y){
    showFreetypeButton.onMotion(x, y);
    showTrangleButton.onMotion(x, y);
    showColorButton.onMotion(x, y);
    showRotateButton.onMotion(x, y);
    showCube3DButton.onMotion(x, y);
    showTextureMapButton.onMotion(x, y);
    showLightButton.onMotion(x, y);
}

void Scene::onPassiveMotion(int x, int y){
    showFreetypeButton.onPassiveMotion(x, y);
    showTrangleButton.onPassiveMotion(x, y);
    showColorButton.onPassiveMotion(x, y);
    showRotateButton.onPassiveMotion(x, y);
    showCube3DButton.onPassiveMotion(x, y);
    showTextureMapButton.onPassiveMotion(x, y);
    showLightButton.onPassiveMotion(x, y);
}

void Scene::onEntry(int state){
    
}