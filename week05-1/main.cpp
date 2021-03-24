#include <GL/glut.h> ///(0) 使用GLUT外掛 (忘了裝 GLUT)
int N=0, vx[3000], vy[3000];
float angle=0; ///TODO:
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清空

    glPushMatrix();///TODO: 備份矩陣
        glRotatef(angle, 0, 0, 1);///TODO: 旋轉, 對Z軸轉
        glBegin(GL_LINE_LOOP);
        for(int i=0; i<N; i++){
            glVertex2f( (vx[i]-150)/150.0, -(vy[i]-150)/150.0 );
        }             ///減一半,再除一半  減一半,再除一半,加負號
        glEnd();
    glPopMatrix(); ///TODO: 還原矩陣
    glutSwapBuffers();///交換兩倍的buffers
}
void keyboard( unsigned char key, int x, int y )
{
    angle++;///TODO:
    display();///TODO:
}
void motion( int x, int y )
{///TODO2: mouse motion 在拖動它
    vx[N]=x; vy[N]=y; ///把 vx, vy 的值存起來
    N++;
    display();///邊動mouse motion, 邊畫display()
}
int main(int argc, char ** argv)
{
    glutInit( &argc, argv ); ///(1) GLUT初始設定
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///(2)顯示模式
    glutCreateWindow("08160011我是神奇的小葉同學");///(3)開窗

    glutDisplayFunc(display);///(4)等一下要顯示的函式
    glutKeyboardFunc( keyboard );///TODO: 按按鍵, 它就會轉動!!!!
    glutMotionFunc( motion );///TODO2: mouse motion在動哦!!!!
    glutMainLoop();///(5)主要迴圈
}
