#include <GL/glut.h> ///(0) �ϥ�GLUT�~��
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///�M��

    glColor3ub(181, 212, 148);/// unsigned byte �O 0...255
    glBegin(GL_TRIANGLES);          ///���F, �n -1.0 ... +1.0, �Ӥj�F...�Y�p
                                    /// 0...300 ���150
                                    ///-150...+150 �A�� 150.0
                                    ///-1.0   +1.0
        glVertex2f( (149-150)/150.0,  -(116-150)/150.0);
        glVertex2f( (189-150)/150.0,  -(116-150)/150.0);
        glVertex2f( (176-150)/150.0,  -(144-150)/150.0);
    glEnd();
    glutSwapBuffers();///�洫�⭿��buffers
}

int main(int argc, char ** argv) ///??? �H�e�O int main()
{
    glutInit( &argc, argv ); ///(1) GLUT��l�]�w
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///(2)��ܼҦ�
    glutCreateWindow("08160011�ڬO���_���p���P��");///(3)�}��

    glutDisplayFunc(display);///(4)���@�U�n��ܪ��禡

    glutMainLoop();///(5)�D�n�j��
}
