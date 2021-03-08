#include <GL/glut.h> ///(0) 使用GLUT外掛
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清空

    glColor3ub(181, 212, 148);/// unsigned byte 是 0...255
    glBegin(GL_TRIANGLES);          ///錯了, 要 -1.0 ... +1.0, 太大了...縮小
                                    /// 0...300 都減掉150
                                    ///-150...+150 再除 150.0
                                    ///-1.0   +1.0
        glVertex2f( (149-150)/150.0,  -(116-150)/150.0);
        glVertex2f( (189-150)/150.0,  -(116-150)/150.0);
        glVertex2f( (176-150)/150.0,  -(144-150)/150.0);
    glEnd();
    glutSwapBuffers();///交換兩倍的buffers
}

int main(int argc, char ** argv) ///??? 以前是 int main()
{
    glutInit( &argc, argv ); ///(1) GLUT初始設定
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///(2)顯示模式
    glutCreateWindow("08160011我是神奇的小葉同學");///(3)開窗

    glutDisplayFunc(display);///(4)等一下要顯示的函式

    glutMainLoop();///(5)主要迴圈
}
