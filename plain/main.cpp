#include <iostream>

#include <GL/glew.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <GL/freeglut.h>

using namespace std;

void init(){
    glClearColor(1.0f,1.0f,4.0f,0.0f);
    glShadeModel(GL_SMOOTH);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(1.0f,1.0f,-6.0f);

    glBegin(GL_TRIANGLES);
    glEnd();

    glFlush();
}

// 窗口大小变化回调函数
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, static_cast<GLdouble>(w/h), 0.1, 100000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, const char * argv[]) {
    // 初始化显示模式
    glutInit(&argc, const_cast<char **>(argv));
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // 初始化窗口
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    // 开始主循环绘制
    glutMainLoop();
    return 0;
}
