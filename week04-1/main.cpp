#include <GL/glut.h> ///(0) �ϥ�GLUT�~��
int N=0, vx[3000], vy[3000];
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�M��

    glBegin(GL_LINE_LOOP);
    for(int i=0; i<N; i++){
        glVertex2f( (vx[i]-150)/150.0, -(vy[i]-150)/150.0 );
    }             ///��@�b,�A���@�b  ��@�b,�A���@�b,�[�t��
    glEnd();

    glutSwapBuffers();///�洫�⭿��buffers
}
void motion( int x, int y )
{///TODO2: mouse motion �b��ʥ�
    vx[N]=x; vy[N]=y; ///�� vx, vy ���Ȧs�_��
    N++;
    display();///���mouse motion, ��edisplay()
}
int main(int argc, char ** argv)
{
    glutInit( &argc, argv ); ///(1) GLUT��l�]�w
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///(2)��ܼҦ�
    glutCreateWindow("08160011�ڬO���_���p���P��");///(3)�}��

    glutDisplayFunc(display);///(4)���@�U�n��ܪ��禡
    glutMotionFunc( motion );///TODO2: mouse motion�b�ʮ@!!!!
    glutMainLoop();///(5)�D�n�j��
}
