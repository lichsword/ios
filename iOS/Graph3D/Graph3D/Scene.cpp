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
#include "Surface_28_Bezier.h"
#include "Surface_34_HeightMap.h"
#include "Surface_11_Wave.h"
#include "Surface_51_SkyBox.h"

Button showFreetypeButton(10, 10, 150, 40);
Button showTrangleButton(10, 60, 150, 40);
Button showColorButton(10, 110, 150, 40);
Button showRotateButton(10, 160, 150, 40);
Button showCube3DButton(10, 210, 150, 40);
Button showTextureMapButton(10, 260, 150, 40);
Button showLightButton(10, 310, 150, 40);
Button showBezierButton(10, 360, 150, 40);
Button showHeightMapButton(10, 410, 150, 40);
Button showWaveButton(10, 460, 150, 40);
Button showSkyBoxButton(10, 510, 150, 40);
    // surfaces
Surface * currentSurface;
BaseWindowSurface baseWindowSurface;
QuadsSurface quadsSurface;
ColorsSurface colorsSurface;
RotateSurface rotateSurface;
Cube3DSurface cube3DSurface;
TextureMapSurface textureMapSurface;
LightSurface lightSurface;
BezierSurface bezierSurface;
HeightMapSurface heightMapSurface;
WaveSurface waveSurface;
SkyBoxSurface skyBoxSurface;

Scene::Scene(){
    enableUnitTest = 1;
    currentSurface = &textureMapSurface;
    currentSurface->onStart();
}

void choose01(){
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

void choose11(){
    currentSurface = &waveSurface;
    currentSurface->onStart();
}

void choose28(){
    currentSurface = &bezierSurface;
    currentSurface->onStart();
}

void choose34(){
    currentSurface = &heightMapSurface;
    currentSurface->onStart();
}

void choose51(){
    currentSurface = &skyBoxSurface;
    currentSurface->onStart();
}

void Scene::init(){
    /**
     * 启用了单元测试，则不再加载混合的模块样例
     */
    if (enableUnitTest) {
        return;
    }// end if
    
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
        //
    showWaveButton.setText("show Wave");
    showWaveButton.setBgColor(new GLubyte[3]{0, 0xff, 0x80},
                              new GLubyte[3]{0, 0x75, 0x5e},
                              new GLubyte[3]{0xac, 0xe1, 0xaf}
                              );
    showWaveButton.setOnClickListener(choose11);
        //
    showBezierButton.setText("show Bezier");
    showBezierButton.setBgColor(new GLubyte[3]{0, 0xff, 0x80},
                                new GLubyte[3]{0, 0x75, 0x5e},
                                new GLubyte[3]{0xac, 0xe1, 0xaf}
                                );
    showBezierButton.setOnClickListener(choose28);
        //
    showHeightMapButton.setText("show HeightMap");
    showHeightMapButton.setBgColor(new GLubyte[3]{0, 0xff, 0x80},
                                   new GLubyte[3]{0, 0x75, 0x5e},
                                   new GLubyte[3]{0xac, 0xe1, 0xaf}
                                   );
    showHeightMapButton.setOnClickListener(choose34);
        //
    showSkyBoxButton.setText("show SkyBox");
    showSkyBoxButton.setBgColor(new GLubyte[3]{0, 0xff, 0x80},
                                   new GLubyte[3]{0, 0x75, 0x5e},
                                   new GLubyte[3]{0xac, 0xe1, 0xaf}
                                   );
    showSkyBoxButton.setOnClickListener(choose51);
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
    
    if (enableUnitTest) {
        return;
    }// end if
    
    showFreetypeButton.display();
    showTrangleButton.display();
    showColorButton.display();
    showRotateButton.display();
    showCube3DButton.display();
    showTextureMapButton.display();
    showLightButton.display();
    showBezierButton.display();
    showHeightMapButton.display();
    showWaveButton.display();
    showSkyBoxButton.display();
}

void Scene::onMouseEvent(int button, int state, int x, int y){
    if(NULL!=currentSurface){
        currentSurface->onMouseEvent(button, state, x, y);
    }// end if
    
    if (enableUnitTest) {
        return;
    }// end if
    
    showFreetypeButton.onMouseEvent(button, state, x, y);
    showTrangleButton.onMouseEvent(button, state, x, y);
    showColorButton.onMouseEvent(button, state, x, y);
    showRotateButton.onMouseEvent(button, state, x, y);
    showCube3DButton.onMouseEvent(button, state, x, y);
    showTextureMapButton.onMouseEvent(button, state, x, y);
    showLightButton.onMouseEvent(button, state, x, y);
    showBezierButton.onMouseEvent(button, state, x, y);
    showHeightMapButton.onMouseEvent(button, state, x, y);
    showWaveButton.onMouseEvent(button, state, x, y);
    showSkyBoxButton.onMouseEvent(button, state, x, y);
}

void Scene::onMotion(int x, int y){
    if(NULL!=currentSurface){
        currentSurface->onMotion(x, y);
    }// end if
    
    if (enableUnitTest) {
        return;
    }// end if
    
    showFreetypeButton.onMotion(x, y);
    showTrangleButton.onMotion(x, y);
    showColorButton.onMotion(x, y);
    showRotateButton.onMotion(x, y);
    showCube3DButton.onMotion(x, y);
    showTextureMapButton.onMotion(x, y);
    showLightButton.onMotion(x, y);
    showBezierButton.onMotion(x, y);
    showHeightMapButton.onMotion(x, y);
    showWaveButton.onMotion(x, y);
    showSkyBoxButton.onMotion(x, y);
}

void Scene::onPassiveMotion(int x, int y){
    if(NULL!=currentSurface){
//        currentSurface->onPassiveMotion(x, y);
    }// end if
    
    if (enableUnitTest) {
        return;
    }// end if
    
    showFreetypeButton.onPassiveMotion(x, y);
    showTrangleButton.onPassiveMotion(x, y);
    showColorButton.onPassiveMotion(x, y);
    showRotateButton.onPassiveMotion(x, y);
    showCube3DButton.onPassiveMotion(x, y);
    showTextureMapButton.onPassiveMotion(x, y);
    showLightButton.onPassiveMotion(x, y);
    showBezierButton.onPassiveMotion(x, y);
    showHeightMapButton.onPassiveMotion(x, y);
    showWaveButton.onPassiveMotion(x, y);
    showSkyBoxButton.onPassiveMotion(x, y);
}

void Scene::onEntry(int state){
    
}

void Scene::keyboard(unsigned char key, int x, int y){
    if(NULL!=currentSurface){
        currentSurface->keyboard(key, x, y);
    }// end if
}