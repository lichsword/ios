    //
    //  bezier.cpp
    //  Graph3D
    //
    //  Created by 王 岳 on 14-8-3.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    //

#include "bezier.h"
#include "math.h"

void makePoint(Point3D * point3d, GLdouble x, GLdouble y, GLdouble z){
    point3d->x = x;
    point3d->y = y;
    point3d->z = z;
}

/**
 * 两个向量相加
 * point3d_a = point3d_a + point3d_b;
 */
void point3dAdd(Point3D * result, Point3D * point3d_a, Point3D * point3d_b){
    result->x = point3d_a->x + point3d_b->x;
    result->y = point3d_a->y + point3d_b->y;
    result->z = point3d_a->z + point3d_b->z;
}

/**
 * 向量与标量相乘
 */
void point3dTimes(Point3D * result, Point3D * point3d, GLdouble c){
    result->x = point3d->x * c;
    result->y = point3d->y * c;
    result->z = point3d->z * c;
}

/**
 * 计算bezier方程，得到插值点
 */
void bezierCount(Point3D * result, float u, Point3D * point3dList){
    Point3D a, b, c, d;// 方程计算点
    Point3D m, n;// 相加点
    
    point3dTimes(&a, &point3dList[0], pow(u,3));
    point3dTimes(&b, &point3dList[1], 3*pow(u,2)*(1-u));
    point3dTimes(&c, &point3dList[2], 3*u*pow((1-u),2));
    point3dTimes(&d, &point3dList[3], pow((1-u),3));
    
    point3dAdd(&m, &a, &b);
    point3dAdd(&n, &c, &d);
    point3dAdd(result, &m, &n);

}

GLuint genBezier(BezierPatch * patch, int divs){
    int		u = 0, v;
	float		py, px, pyold;
	GLuint		drawlist = glGenLists(1);			// 创建显示列表
	Point3D	temp[4];
	Point3D	*last = new Point3D[divs+1];	// 更具每一条曲线的细分数，分配相应的内存
    
    if(NULL==patch){
        return NULL;
    }// end if
    
    // 如果显示列表存在则删除
	if (patch->dlBPatch!=NULL){
		glDeleteLists(patch->dlBPatch, 1);
    }// end if
    
    // 获得u方向的四个控制点
	temp[0] = patch->anchors[0][3];
	temp[1] = patch->anchors[1][3];
	temp[2] = patch->anchors[2][3];
	temp[3] = patch->anchors[3][3];
    
    // 根据细分数，创建各个分割点额参数
	for (v=0;v<=divs;v++) {
		px = ((float)v)/((float)divs);
            // 使用Bernstein函数求的分割点的坐标
        bezierCount(&last[v], px, temp);
	}
    
    // 创建一个新的显示列表
	glNewList(drawlist, GL_COMPILE);
    // 绑定纹理
	glBindTexture(GL_TEXTURE_2D, patch->texture);
    
	for (u=1;u<=divs;u++) {
        // 计算v方向上的细分点的参数
		py = ((float)u)/((float)divs);
        // 上一个v方向上的细分点的参数
		pyold = ((float)u-1.0f)/((float)divs);
        // 计算每个细分点v方向上贝塞尔曲面的控制点
        bezierCount(&temp[0], py, patch->anchors[0]);
        bezierCount(&temp[1], py, patch->anchors[1]);
        bezierCount(&temp[2], py, patch->anchors[2]);
        bezierCount(&temp[3], py, patch->anchors[3]);
        // 开始绘制三角形带
		glBegin(GL_TRIANGLE_STRIP);
		for (v=0;v<=divs;v++) {
            // 沿着u轴方向顺序绘制
			px = ((float)v)/((float)divs);
            // 设置纹理坐标
			glTexCoord2f(pyold, px);
            // 绘制一个顶点
			glVertex3d(last[v].x, last[v].y, last[v].z);
            // 创建下一个顶点
            bezierCount(&last[v], px, temp);
            // 设置纹理
			glTexCoord2f(py, px);
            // 绘制新的顶点
			glVertex3d(last[v].x, last[v].y, last[v].z);
		}
        // 结束三角形带的绘制
		glEnd();
	}
    
        // 显示列表绘制结束
	glEndList();
        // 释放分配的内存
	free(last);
        // 返回创建的显示列表
	return drawlist;
}

void initBezier(BezierPatch * bezier) {
    // 设置贝塞尔曲面的控制点
    makePoint(&bezier->anchors[0][0], -0.75, -0.75,	-0.50);
    makePoint(&bezier->anchors[0][1], -0.25, -0.75,	 0.00);
    makePoint(&bezier->anchors[0][2],  0.25, -0.75,  0.00);
    makePoint(&bezier->anchors[0][3],  0.75, -0.75, -0.50);
    makePoint(&bezier->anchors[1][0], -0.75, -0.25,	-0.75);
    makePoint(&bezier->anchors[1][1], -0.25, -0.25,  0.50);
    makePoint(&bezier->anchors[1][2],  0.25, -0.25,  0.50);
    makePoint(&bezier->anchors[1][3],  0.75, -0.25, -0.75);
    makePoint(&bezier->anchors[2][0], -0.75,  0.25,  0.00);
    makePoint(&bezier->anchors[2][1], -0.25,  0.25, -0.50);
    makePoint(&bezier->anchors[2][2],  0.25,  0.25, -0.50);
    makePoint(&bezier->anchors[2][3],  0.75,  0.25,  0.00);
    makePoint(&bezier->anchors[3][0], -0.75,  0.75, -0.50);
    makePoint(&bezier->anchors[3][1], -0.25,  0.75, -1.00);
    makePoint(&bezier->anchors[3][2],  0.25,  0.75, -1.00);
    makePoint(&bezier->anchors[3][3],  0.75,  0.75, -0.50);
    // 默认的显示列表为0
	bezier->dlBPatch = NULL;
}