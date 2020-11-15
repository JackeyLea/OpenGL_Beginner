#include <GL/glut.h>
#include <stdio.h>

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Version");

    const GLubyte *name = glGetString(GL_VENDOR); //返回负责当前OpenGL实现厂商的名字
    const GLubyte *flag = glGetString(GL_RENDERER); //返回一个渲染器标识符，通常是个硬件平台
    const GLubyte *OpenGLVersion = glGetString(GL_VERSION);   //返回当前OpenGL实现的版本号
    const GLubyte *gluVersion    = gluGetString(GLU_VERSION); //返回当前GLU工具库版本

    printf("OpenGL实现厂商的名字：%s\n", name);
    printf("渲染器标识符：%s\n", flag);
    printf("OpenGL实现的版本号：%s\n", OpenGLVersion);
    printf("OGLU工具库版本：%s\n", gluVersion);
    return 0;
}