#include <windows.h>
#include <GL/glut.h>
void tree(float x, float y,float s) //s for size of tree
{
    glBegin(GL_QUADS);
    glColor3ub(51,102,0);

    glVertex2f(x-0.06f*s,y+0.13f*s);//p2
    glVertex2f(x-0.01f*s,y+0.1f*s);//v2
    glVertex2f(x+0.02f*s,y+0.13f*s);//o2
    glVertex2f(x+0.02f*s,y+0.16f*s);//q2

    glVertex2f(x-0.01f*s,y+0.1f*s);//v2
    glVertex2f(x+0.02f*s,y+0.16f*s);//q2
    glVertex2f(x+0.11f*s,y+0.13f*s);//z2
    glVertex2f(x+0.06f*s,y+0.1f*s);//w2

    glVertex2f(x+0.02f*s,y+0.13f*s);//o2
    glVertex2f(x-0.04f*s,y+0.17f*s);//l2
    glVertex2f(x+0.02f*s,y+0.2f*s);//m2
    glVertex2f(x+0.09f*s,y+0.17f*s);//n2

    glVertex2f(x+0.02f*s,y+0.18f*s);//j2
    glVertex2f(x-0.03f*s,y+0.21f*s);//i2
    glVertex2f(x+0.02f*s,y+0.23f*s);//c3
    glVertex2f(x+0.08f*s,y+0.21f*s);//k2

    glVertex2f(x-0.02f*s,y+0.25f*s);//e3
    glVertex2f(x+0.02f*s,y+0.22f*s);//h2
    glVertex2f(x+0.04f*s,y+0.22f*s);//g3
    glVertex2f(x+0.07f*s,y+0.25f*s);//f3

    glVertex2f(x+0.03f*s,y+0.28f*s);//a3
    glVertex2f(x+0.01f*s,y+0.24f*s);//b3
    glVertex2f(x+0.03f*s,y+0.23f*s);//c3
    glVertex2f(x+0.04f*s,y+0.24f*s);//d3
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(102,51,0);

    glVertex2f(x+0.01f*s,y+0.1f*s);//e2
    glVertex2f(x+0.04f*s,y+0.1f*s);//f2
    glVertex2f(x+0.05f*s,y+0.0f*s);//g2
    glVertex2f(x+0.0f*s,y+0.0f*s);//d2
    glEnd();

    glFlush();
}
void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    tree(0.0f,-0.2f,3);

    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(700,700);
    glutCreateWindow("Task_3");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
