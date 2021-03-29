#include <GL/glut.h>
float angle=0;///TODO2
void hand()
{
    glPushMatrix();
        glScalef(0.5, 0.1, 0.1);///細細長長的
        glutSolidCube(1);///方塊
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///左半邊
        glTranslatef(-0.25, 0,0);///(3)手臂,掛上去肩關節
        glRotatef(angle, 0,0,1);///(2)轉動
        glTranslatef(-0.25, 0,0);///(1)將旋轉中心,放在正中心
        hand();///上手臂
        glPushMatrix();
            glTranslatef(-0.25, 0, 0);///(3)把正確轉動的手肘,掛在肘關節
            glRotatef(angle, 0,0,1);///(2)轉動
            glTranslatef(-0.25, 0, 0);///(1)將旋轉中心,放在正中心
            hand();///下手肘
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///右半邊
        glTranslatef(+0.25, 0,0);///(3)手臂,掛上去肩關節
        glRotatef(-angle, 0,0,1);///(2)轉動
        glTranslatef(+0.25, 0,0);///(1)將旋轉中心,放在正中心
        hand();///上手臂
        glPushMatrix();
            glTranslatef(+0.25, 0, 0);///(3)把正確轉動的手肘,掛在肘關節
            glRotatef(-angle, 0,0,1);///(2)轉動
            glTranslatef(+0.25, 0, 0);///(1)將旋轉中心,放在正中心
            hand();///下手肘
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    angle++;
}
int main(int argc, char ** argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///(2)顯示模式
    glutCreateWindow("08160011我是神奇的小葉同學");///(3)開窗

    glutIdleFunc(display);///TODO2:idle很閒的時候,就重畫面
    glutDisplayFunc(display);
    glutMainLoop();
}
