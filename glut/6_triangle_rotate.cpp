#include <iostream>

#include <GL/glu.h>
#include <GL/freeglut.h>
#include <unistd.h>

#define ESCAPE 27

int window; 

float rtri=0.0f;//三角形旋转角度
float rquad=0.0f;//四边形旋转角度

void init(){
    glClearColor(1.0f,0.0f,1.0f,0.0f);//红绿蓝alpha值
    glShadeModel(GL_SMOOTH);//色彩绘制模式
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-1.5f,0.0f,-6.0f);//平移

    glRotatef(rtri,0.0f,1.0f,0.0f);//绕Y轴旋转
    glBegin(GL_TRIANGLES);//图像绘制部分
    glColor3f(1.0f,0.0f,0.0f);			// 红色
    glVertex3f(0.0f,1.0f,0.0f);//点A（x,y,z）
    glColor3f(0.0f,1.0f,0.0f);			// 绿色
    glVertex3f(-1.0f,-1.0f,0.0f);//点B
    glColor3f(0.0f,0.0f,1.0f);			// 蓝色
    glVertex3f(1.0f,-1.0f,0.0f);//点C
    glEnd();
glLoadIdentity();
    glTranslatef(1.5f,0.0f,-6.0f);		        // 右移

  // 绘制正方形
glRotatef(rquad,1.0f,0.0f,0.0f);//绕X轴旋转
  glColor3f(0.5f,0.5f,1.0f);			// 蓝色
  glBegin(GL_QUADS);				// 开始绘图
  glVertex3f(-1.0f, 1.0f, 0.0f);		// 左上
  glVertex3f( 1.0f, 1.0f, 0.0f);		// 右上
  glVertex3f( 1.0f,-1.0f, 0.0f);		// 右下
  glVertex3f(-1.0f,-1.0f, 0.0f);		// 左下	
  glEnd();					// 结束

  rtri+=15.0f;
  rquad-=15.0f;
  // we need to swap the buffer to display our drawing.
  glutSwapBuffers();
    glFlush();//刷新缓冲区
}

// 窗口大小变化回调函数
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, static_cast<GLdouble>(w/h), 0.1, 100000.0);//设置长宽视景
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyPressed(unsigned char key, int x, int y) 
{
    usleep(100);

    if (key == ESCAPE) 
    { 
	/* 关闭窗口 */
	glutDestroyWindow(window); 
	
	exit(0);                   
    }
}

int main(int argc, const char * argv[]) {
    // 初始化显示模式
    glutInit(&argc, const_cast<char **>(argv));
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // 初始化窗口
    glutInitWindowSize(640, 480);//初始界面大小
    glutInitWindowPosition(100, 100);//界面初始位置
    window=glutCreateWindow(argv[0]);//创建界面，界面标题为argv[0]，即程序名称

    init();//opengl初始化
    glutIdleFunc(&display);
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);//回调函数
    glutKeyboardFunc(&keyPressed);

    // 开始主循环绘制
    glutMainLoop();
    return 0;
}
