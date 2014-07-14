    //
    //  Main.cpp
    //  Graph3D
    //
    //  Created by 王 岳 on 14-7-12.
    //  Copyright (c) 2014年 ___LICHSOWRD___. All rights reserved.
    //

#include "Main.h"

    // mac 的屏幕大小
int SCREEN_W = 1280;
int SCREEN_H = 800;

    // 主窗口大小
#define WIN_W 800
#define WIN_H 600

    // FreeType 字体库
FT_Library library;
FT_Face face;
FT_Matrix matrix;
FT_Vector delta;


GLYPHMETRICSFLOAT gmf[256];					// Storage For Information About Our Font

GLuint  base;
GLfloat	cnt1;			// 字体移动计数器1
GLfloat	cnt2;			// 字体移动计数器2

freeType::font_data our_font;

namespace freeType {
    inline int next_p2 (int a ){
        int rval=1;
            // rval<<=1 Is A Prettier Way Of Writing rval*=2;
        while(rval<a)
            rval<<=1;
        return rval;
    }
    
    void make_dlist(FT_Face face, char ch, GLuint list_base, GLuint * tex_base){
        GLint error;
        error = FT_Load_Glyph( face, FT_Get_Char_Index(face, ch), FT_LOAD_DEFAULT );
        if (error )
            return;                 /* ignore errors */
        
            // 保存轮廓对象
        FT_Glyph glyph;
        error = FT_Get_Glyph( face->glyph, &glyph );
        if ( error )
            return;                 /* ignore errors */
        
            // 把轮廓转化为位图
        FT_Glyph_To_Bitmap( &glyph, ft_render_mode_normal, 0, 1 );
        FT_BitmapGlyph bitmap_glyph = (FT_BitmapGlyph)glyph;
        
            // 保存位图
        FT_Bitmap& bitmap=bitmap_glyph->bitmap;
        
            // 转化为OpenGl可以使用的大小
        int width = next_p2( bitmap.width );
        int height = next_p2( bitmap.rows );
        
            // 保存位图数据
        GLubyte* expanded_data = new GLubyte[ 2 * width * height];
        
            // 这里我们使用8位表示亮度8位表示alpha值
        for(int j=0; j <height;j++) {
            for(int i=0; i < width; i++){
                expanded_data[2*(i+j*width)]= expanded_data[2*(i+j*width)+1] =
                (i>=bitmap.width || j>=bitmap.rows) ?
                0 : bitmap.buffer[i + bitmap.width*j];
            }
        }
        
            // 设置字体纹理的纹理过滤器
        glBindTexture( GL_TEXTURE_2D, tex_base[ch]);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
            // 邦定纹理
        glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
                     GL_LUMINANCE_ALPHA, GL_UNSIGNED_BYTE, expanded_data );
        
            // 释放分配的内存
        delete [] expanded_data;
        
            // 创建显示列表
        glNewList(list_base+ch,GL_COMPILE);
        glBindTexture(GL_TEXTURE_2D, tex_base[ch]);
        
            //首先我们向左移动一点
        glTranslatef(bitmap_glyph->left,0,0);
        
            //接着我们向下移动一点，这只队'g','y'之类的字符有用
            //它使得所有的字符都有一个基线
        glPushMatrix();
        glTranslatef(0,bitmap_glyph->top-bitmap.rows,0);
        
            // 计算位图中字符图像的宽度
        float x=(float)bitmap.width / (float)width,
        y=(float)bitmap.rows / (float)height;
        
            //绘制一个正方形，显示字符
        glBegin(GL_QUADS);
        glTexCoord2d(0,0);
        glVertex2f(0,bitmap.rows);
        glTexCoord2d(0,y);
        glVertex2f(0,0);
        glTexCoord2d(x,y);
        glVertex2f(bitmap.width,0);
        glTexCoord2d(x,0);
        glVertex2f(bitmap.width,bitmap.rows);
        
        glEnd();
        glPopMatrix();
        glTranslatef(face->glyph->advance.x >> 6 ,0,0);
        
            //结束显示列表的绘制
        glEndList();
    }
    
    void font_data::init(const char *fname, unsigned int h) {
        
        	// 保存纹理ID.
        textures = new GLuint[128];
        this->h=h;
        
            // 创建FreeType库
        FT_Library library;
        if (FT_Init_FreeType( &library ))
            throw std::runtime_error("FT_Init_FreeType failed");
        
            // 在FreeType库中保存字体信息的类叫做face
        FT_Face face;
        
            // 使用你输入的Freetype字符文件初始化face类
        if (FT_New_Face( library, fname, 0, &face ))
            throw std::runtime_error("FT_New_Face failed (there is probably a problem with your font file)");
        
            // 在FreeType中使用1/64作为一个像素的高度所以我们需要缩放h来满足这个要求
        FT_Set_Char_Size( face, h << 6, h << 6, 96, 96);
        
            // 创建128个显示列表
        this->list_base = glGenLists(128);
        glGenTextures( 128, textures );
        for(unsigned char i=0;i<128;i++)
            make_dlist(face,i,list_base,textures);
            // 释放face类
        FT_Done_Face(face);
        
            // 释放FreeType库
        FT_Done_FreeType(library);
    }
    
    void font_data::clean() {
        glDeleteLists(list_base,128);
        glDeleteTextures(128,textures);
        delete [] textures;
    }
    
    inline void pushScreenCoordinateMatrix() {
        glPushAttrib(GL_TRANSFORM_BIT);
        GLint   viewport[4];
        glGetIntegerv(GL_VIEWPORT, viewport);
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(viewport[0],viewport[2],viewport[1],viewport[3]);
        glPopAttrib();
    }
    
    inline void pop_projection_matrix() {
        glPushAttrib(GL_TRANSFORM_BIT);
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glPopAttrib();
    }
    
    FT_ULong font_data::utf8tounicode(char *s, int size) {
        char uc[] = {0x7f,0x3f,0x1f,0x0f,0x07,0x03};
        
        FT_ULong data = 0;
        FT_ULong tmp = 0;
        int count = 0;
        
        char *p = s;
        while (count < size)
        {
            char c = (*p);
            tmp = c;
            
            if (count == 0)
            {
                tmp &= uc[size - 1];
            }
            else
            {
                tmp &= 0x3f;
            }
            
            tmp = tmp << (6 * (size - count - 1));
            data |= tmp;
            
            p++;
            count++;
        }
        
        return data;
    }
    
    int font_data::getUtf8Size(char c)
    {
        char t = 1 << 7;
        char r = c;
        int count = 0;
        while (r & t)
        {
            r = r << 1;
            count++;
        }
        return count;
    }
    
    int font_data::getULongList(const string &line, vector<FT_ULong> &list){
        if (line == "")
            return 0;
        
        char buff[256];
        
        unsigned int len = line.size();
        
        unsigned int i = 0;
        FT_ULong tmpdata = 0;
        
        while(i < len)
        {
            char c = line[i];
            int size = getUtf8Size(c);
            
            if (size > 0)
            {
                memset(buff, 0, 256);
                unsigned int count = i + size;
                unsigned int k = 0;
                while (i < count)
                {
                    buff[k]     = line[i];
                    k++;
                    i++;
                }
                
                tmpdata = utf8tounicode(buff,size);
            }
            else
            {
                tmpdata = line[i];
                i++;
            }
            list.push_back(tmpdata);
        } // while
        return 0;
    }
    

        // 把字符输出到屏幕
    void print(const font_data &ft_font, float x, float y, const char *fmt, ...){

        char buff[256];
            // 保存当前矩阵
        pushScreenCoordinateMatrix();
        
        GLuint font = ft_font.list_base;
            float h = ft_font.h/.63f;
        char	text[256];
        va_list	ap;
        
        if (fmt == NULL)
            *text=0;
        else {
            va_start(ap, fmt);
            vsprintf(text, fmt, ap);
            va_end(ap);
        }
       
            // 把输入的字符串按回车分割
        const char *start_line=text;
        vector<string> lines;
        {
            const char *c;
            for(c=text;*c;c++) {
                
                
                if(*c=='\n') {
                    string line;
                    for(const char *n=start_line;n<c;n++) line.append(1,*n);
                    lines.push_back(line);
                    start_line=c+1;
                }
            }
            
            if(start_line) {
                string line;
                
                for(const char *n = start_line; n<c; n++)
                    line.append(1, *n);
                lines.push_back(line);
            }
        }
        
        glPushAttrib(GL_LIST_BIT | GL_CURRENT_BIT | GL_ENABLE_BIT | GL_TRANSFORM_BIT);
        glMatrixMode(GL_MODELVIEW);
        glDisable(GL_LIGHTING);
        glEnable(GL_TEXTURE_2D);
        glDisable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        
        glListBase(font);
        
        float modelview_matrix[16];
        glGetFloatv(GL_MODELVIEW_MATRIX, modelview_matrix);
        
            // 下面的代码完成具体的绘制过程
        for(int i=0;i<lines.size();i++) {
            glPushMatrix();
            glLoadIdentity();
            glTranslatef(x,y-h*i,0);
            glMultMatrixf(modelview_matrix);
            
//            vector<FT_ULong> ftlist;
//            font_data::getULongList(lines[i], ftlist);
//            drawlinetext(ftlist);
//            glPopMatrix();

                //调用显示列表绘制
            glCallLists(lines[i].length(), GL_UNSIGNED_BYTE, lines[i].c_str());
            glPopMatrix();
        }
        
        glPopAttrib();
        
        pop_projection_matrix();
    }
    
}

GLvoid glPrint(const char *fmt, ...){
    float		length=0;				// Used To Find The Length Of The Text
	char		text[256];				// Holds Our String
	va_list		ap;					// Pointer To List Of Arguments
    if (fmt == NULL)					// If There's No Text
		return;						// Do Nothing
    va_start(ap, fmt);					// Parses The String For Variables
    vsprintf(text, fmt, ap);				// And Converts Symbols To Actual Numbers
	va_end(ap);						// Results Are Stored In Text
    for (unsigned int loop=0;loop<(strlen(text));loop++)	// Loop To Find Text Length
	{
		length+=gmf[text[loop]].gmfCellIncX;		// Increase Length By Each Characters Width
	}
    glTranslatef(-length/2,0.0f,0.0f);			// Center Our Text On The Screen
    glPushAttrib(GL_LIST_BIT);				// Pushes The Display List Bits
	glListBase(base);					// Sets The Base Character to 0
    glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);	// Draws The Display List Text
	glPopAttrib();						// Pops The Display List Bits
}

void initApp(){
    our_font.init("/Library/Fonts/Arial.ttf", 16);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_BITMAP);
        //    glVertex2f(-0.5, -0.5);
        //    glVertex2f(-0.5, 0.5);
        //    glVertex2f(0.5, 0.5);
        //    glVertex2f(0.5, -0.5);
    
    glLoadIdentity();
	glTranslatef(0.0f,0.0f,-1.0f);
    
        // 蓝色文字
    glColor3ub(0,0,0xff);
    
        // 绘制WGL文字
    glRasterPos2f(-0.40f, 0.35f);
    glPrint("Active WGL Bitmap Text With NeHe - %7.2f", cnt1);
    
        // 红色文字
    glColor3ub(0xff,0,0);
    
    glPushMatrix();
    glLoadIdentity();
    glRotatef(cnt1,0,0,1);
    glScalef(1,.8+.3*cos(cnt1/5),1);
    glTranslatef(-180,0,0);
        //绘制freetype文字
    freeType::print(our_font, 320, 200, "Active FreeType Text*中文显示为空格*- %7.2f", cnt1);
    glPopMatrix();
    
    cnt1+=0.51f;
    cnt2+=0.005f;
    glutPostRedisplay();
    glEnd();
    glFlush();
}

void keyboard(unsigned char key, int x, int y){
    switch (key) {
        case 'q':
            exit(0);
            break;
        default:
            break;
    }
}

void mouse(int button , int state, int x, int y){
    
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Xcode Glut Demo");
    glutReshapeWindow(WIN_W, WIN_H);
    glutPositionWindow((SCREEN_W- WIN_W)/2,(SCREEN_H - WIN_H)/2);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    
    initApp();
    glutMainLoop();
        // release res.
    our_font.clean();
}
