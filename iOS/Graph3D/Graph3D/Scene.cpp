//
//  Scene.cpp
//  Graph3D
//
//  Created by 王 岳 on 14-7-16.
//  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
//

#include "Scene.h"
#include "Button.h"

namespace scene {
    
    button::button_data our_button;
    
    void scene_data::init(){
        our_button.set(50, 50, 100, 40);
        our_button.setText("demo");
    }
    
    void scene_data::finish(){
        
    }
    
    void scene_data::onCreate(){
        
    }
    
    void scene_data::onDestrory(){
        
    }
    
    void scene_data::display(){
        our_button.display();
    }
}