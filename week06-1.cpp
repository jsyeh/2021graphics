#include <GL/glut.h>
float angle=0;///TODO2
void hand()
{
    glPushMatrix();
        glScalef(0.5, 0.1, 0.1);///�ӲӪ�����
        glutSolidCube(1);///���
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///���b��
        glTranslatef(-0.25, 0,0);///(3)���u,���W�h�����`
        glRotatef(angle, 0,0,1);///(2)���
        glTranslatef(-0.25, 0,0);///(1)�N���त��,��b������
        hand();///�W���u
        glPushMatrix();
            glTranslatef(-0.25, 0, 0);///(3)�⥿�T��ʪ���y,���b�y���`
            glRotatef(angle, 0,0,1);///(2)���
            glTranslatef(-0.25, 0, 0);///(1)�N���त��,��b������
            hand();///�U��y
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///�k�b��
        glTranslatef(+0.25, 0,0);///(3)���u,���W�h�����`
        glRotatef(-angle, 0,0,1);///(2)���
        glTranslatef(+0.25, 0,0);///(1)�N���त��,��b������
        hand();///�W���u
        glPushMatrix();
            glTranslatef(+0.25, 0, 0);///(3)�⥿�T��ʪ���y,���b�y���`
            glRotatef(-angle, 0,0,1);///(2)���
            glTranslatef(+0.25, 0, 0);///(1)�N���त��,��b������
            hand();///�U��y
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    angle++;
}
int main(int argc, char ** argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///(2)��ܼҦ�
    glutCreateWindow("08160011�ڬO���_���p���P��");///(3)�}��

    glutIdleFunc(display);///TODO2:idle�ܶ����ɭ�,�N���e��
    glutDisplayFunc(display);
    glutMainLoop();
}
