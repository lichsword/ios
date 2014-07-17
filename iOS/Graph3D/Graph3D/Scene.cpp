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

namespace scene {
    
    surfaceview::surfaceview_data our_surface;
    button::button_data our_button;
    filelog::filelog_data our_log;
    
    void testClickBtn(){
        our_log.init();
        our_log.e("press test click btn");
    }
    
    void scene_data::init(){
        our_button.set(50, 50, 100, 40);
        our_button.setText("demo");
        our_button.setOnClickFunc(testClickBtn);
        our_surface.init();
    }
    
    void scene_data::finish(){
        
    }
    
    void scene_data::onCreate(){
        
    }
    
    void scene_data::onDestrory(){
        
    }
    
    void scene_data::display(){
        our_button.display();
        our_surface.display();
    }
    
    void scene_data::onMouseEvent(int button, int state, int x, int y){
        if(our_button.inArea(x, y)){
            our_button.pressed = 1;
            our_button.onClick();
        }else{
            our_button.pressed = 0;
        }
    }
    
}