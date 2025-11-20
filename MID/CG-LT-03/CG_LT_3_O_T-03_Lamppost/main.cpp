#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void circle(float xx,float yy,float r,int red, int green,int blue) {
    
    float pi = 3.1416;

    glColor3ub(red,green,blue);
	glBegin(GL_POLYGON);
        for(int i=0; i<200; i++) {
            float A = (i*2*pi) / 200;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x + xx, y + yy);
        }
	glEnd();

}

void lamp(float x, float y,float s) {

    glColor3ub(127,174,35);
    glBegin(GL_QUADS);
        glVertex2f(x+0.0f*s,y+0.0f*s);//e
        glVertex2f(x+0.08f*s,y+0.0f*s);//g
        glVertex2f(x+0.07f*s,y+0.215f*s);//h
        glVertex2f(x+0.01f*s,y+0.215f*s);//f

        glVertex2f(x+0.02f*s,y+0.215f*s);//k
        glVertex2f(x+0.06f*s,y+0.215f*s);//l
        glVertex2f(x+0.05f*s,y+0.6f*s);//m
        glVertex2f(x+0.03f*s,y+0.6f*s);//n

        glVertex2f(x+0.0f*s,y+0.6f*s);//p
        glVertex2f(x+0.08f*s,y+0.6f*s);//o
        glVertex2f(x+0.11f*s,y+0.75f*s);//q
        glVertex2f(x-0.03f*s,y+0.75f*s);//r

        glVertex2f(x+0.035f*s,y+0.815f*s);//b1
        glVertex2f(x+0.03f*s,y+0.8f*s);//w
        glVertex2f(x+0.05f*s,y+0.8f*s);//z
        glVertex2f(x+0.045f*s,y+0.815f*s);//a1

        glVertex2f(x+0.025f*s,y+0.825f*s);//c1
        glVertex2f(x+0.04f*s,y+0.81f*s);//a
        glVertex2f(x+0.055f*s,y+0.825f*s);//d1
        glVertex2f(x+0.04f*s,y+0.855f*s);//e1
    glEnd();

    glLineWidth(3*s);
    glColor3ub(127,174,35);
    glBegin(GL_LINES);
        glVertex2f(x-0.04f*s,y+0.754f*s);//u
        glVertex2f(x+0.12f*s,y+0.754f*s);//v

        glVertex2f(x-0.014f*s,y+0.61f*s);//n1
        glVertex2f(x+0.094f*s,y+0.61f*s);//o

        glVertex2f(x-0.024f*s,y+0.002f*s);//c
        glVertex2f(x+0.102f*s,y+0.002f*s);//d
    glEnd();

    circle(x+0.04f*s,y+0.74f*s,0.066f*s,127,174,34);

    glColor3ub(255,223,153);
    glBegin(GL_QUADS);
        glVertex2f(x-0.02f*s,y+0.74f*s);//f1
        glVertex2f(x+0.035f*s,y+0.74f*s);//g1
        glVertex2f(x+0.035f*s,y+0.615f*s);//j1
        glVertex2f(x+0.005f*s,y+0.615f*s);//k1

        glVertex2f(x+0.045f*s,y+0.74f*s);//h1
        glVertex2f(x+0.045f*s,y+0.615f*s);//l1
        glVertex2f(x+0.075f*s,y+0.615f*s);//m1
        glVertex2f(x+0.1f*s,y+0.74f*s);//i1
    glEnd();

}

void display() {

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    lamp(-0.1f,-0.8f,2);

    glFlush();

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitWindowSize(700,700);
    glutCreateWindow("CG_LT_3_O_T-03_Lamp post");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;

}