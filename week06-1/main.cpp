#include <GL/glut.h>
float angle=0;///TODO:
void hand(){
    glPushMatrix();
        glScalef(0.5, 0.1, 0.1);///細長的
        glColor3f(0,0,1);///藍色的
        glutSolidCube(1);///方塊
    glPopMatrix();
}
void display() ///容易出錯的地方: glPushMatrix() & glPopMatrix()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1); glutSolidCube(0.5);///大的身體
    glPushMatrix();///右半邊
        glTranslatef(0.25, 0.25, 0);///(3) 整個移到右上角掛著
        glRotatef( angle, 0,0,1); ///(2) 對中心轉動
        glTranslatef(0.25, 0, 0); ///(1) 把關節移到中心
        hand();///細長的藍色的上手臂
        glPushMatrix();
            glTranslatef(0.25, 0, 0); ///(3)往右拉過去
            glRotatef( angle, 0,0,1); ///(2)
            glTranslatef(0.25, 0, 0); ///(1)
            hand();///下手臂/手肘
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///左半邊
        glTranslatef(-0.25, 0.25, 0);///(3) 整個移到左上角掛著
        glRotatef( -angle, 0,0,1); ///(2) 對中心轉動
        glTranslatef(-0.25, 0, 0); ///(1) 把關節移到中心
        hand();///細長的藍色的上手臂
        glPushMatrix();
            glTranslatef(-0.25, 0, 0); ///(3)往左拉過去
            glRotatef( -angle, 0,0,1); ///(2)
            glTranslatef(-0.25, 0, 0); ///(1)
            hand();///下手臂/手肘
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    angle++;///TODO:
}
int main(int argc, char ** argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("08160011我是神奇的小葉同學");

    glutDisplayFunc(display);
    glutIdleFunc(display); ///TODO: 閒閒有空時,就重畫畫面!!!!
    glutMainLoop();
}
