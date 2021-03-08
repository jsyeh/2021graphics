# 2021graphics

這裡有我在2021電腦圖學寫的程式。

Week03-1
---------
```C
///把第1個範例 OpenGL, 拿來亂改
///把第1個Project變 *粗黑色* Active
#include <stdio.h>
int main( int argc, char** argv)
{
    printf("現在的 argc是:%d\n", argc);
    for(int i=0; i<argc; i++ ){
        printf("argv[%d]是:%s\n", i, argv[i] );
    }
}

```



Week03-2
----------
```C++
///留下精華
#include <GL/glut.h> ///(1) 使用 GLUT外掛
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glBegin(GL_TRIANGLES);

                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f,   1.0f);
                glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f,  -0.5f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);

            glEnd();
    glutSwapBuffers();
}

int main(int argc, char *argv[]) ///我們只要留 main()裡面的 5行
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");

    glutDisplayFunc(display);

    glutMainLoop();
}

```


Week03-3
---------
```C++
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


```



