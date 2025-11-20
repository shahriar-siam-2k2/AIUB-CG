#include <windows.h>
#include <GL/glut.h>

void window(float x, float y, float size) {

    glPushMatrix();
        glTranslatef(x, y, 0.0f);

        glColor3ub(204,229,255);
        glBegin(GL_QUADS);
            glVertex2f(0.0f * size,0.0f * size);//e
            glVertex2f(0.0f * size,0.05f * size);//w
            glVertex2f(0.05f * size,0.05f * size);//e
            glVertex2f(0.05f * size,0.0f * size);//e
        glEnd();

        glColor3ub(204,229,255);
        glLineWidth(1);
        glBegin(GL_LINE_LOOP);
            glVertex2f(0.0f * size,0.0f * size);//d2
            glVertex2f(0.0f * size,0.05f * size);//g2
            glVertex2f(0.05f * size,0.05f * size);//f2
            glVertex2f(0.05f * size,0.0f * size);//e2
        glEnd();

        glLineWidth(1);
        glBegin(GL_LINES);
            glColor3ub(0,0,0);
            glVertex2f(0.0f * size,0.025f * size);//g1
            glVertex2f(0.05f * size,0.025f * size);//h1

            glVertex2f(0.025f * size,0.05f * size);//e1
            glVertex2f(0.025f * size,0.0f * size);//f1
        glEnd();
    glPopMatrix();

    glutSwapBuffers();
    glFlush();

}

void building(float x, float y, float size) {

    glPushMatrix();
        glTranslatef(x, y, 0.0f);

        glColor3ub(153,76,0);
        glBegin(GL_QUADS);
            glVertex2f(-0.3f * size,0.0f * size);//b
            glVertex2f(-0.3f * size,0.75f * size);//u
            glVertex2f(0.3f * size,0.75f * size);//v
            glVertex2f(0.3f * size,0.0f * size);//a
        glEnd();

        glColor3ub(102,51,0);
        glBegin(GL_QUADS);
            glVertex2f(-0.05f * size,0.1f * size);//l
            glVertex2f(0.05f * size,0.1f * size);//k
            glVertex2f(0.05f * size,0.0f * size);//j
            glVertex2f(-0.05f * size,0.0f * size);//i
        glEnd();

        glLineWidth(3);
        glColor3ub(0,0,0);
        glBegin(GL_LINES);
            glVertex2f(-0.3f * size,0.15f * size);//o
            glVertex2f(0.3f * size,0.15f * size);//u

            glVertex2f(-0.3f * size,0.3f * size);//r
            glVertex2f(0.3f * size,0.3f * size);//q

            glVertex2f(-0.3f * size,0.45f * size);//s
            glVertex2f(0.3f * size,0.45f * size);//t

            glVertex2f(-0.3f * size,0.6f * size);//c
            glVertex2f(0.3f * size,0.6f * size);//d

            glVertex2f(0.0f * size,0.1f * size);//f
            glVertex2f(0.0f * size,0.0f * size);//e
        glEnd();

        glLineWidth(7);
        glBegin(GL_LINES);
            glVertex2f(-0.32f * size,-0.01f * size);//r2
            glVertex2f(0.32f * size,-0.01f * size);//s2

            glVertex2f(-0.3f * size,0.76f * size);//t2
            glVertex2f(0.3f * size,0.76f * size);//s2
        glEnd();
    glPopMatrix();

    glutSwapBuffers();
    glFlush();

}

void buildingStructure(float x, float y, float size) {

    building(x, y, size);

    glPushMatrix();
        glTranslatef(x, y, 0.0f);

        window(-0.25f * size, 0.05f * size, size);//h
        window(-0.15f * size, 0.05f * size, size);//i1
        window(-0.25f * size, 0.2f * size, size);//l1
        window(-0.15f * size, 0.2f * size, size);//m1
        window(-0.25f * size, 0.35f * size, size);//p1
        window(-0.15f * size, 0.35f * size, size);//q1
        window(-0.25f * size, 0.5f * size, size);//t1
        window(-0.15f * size, 0.5f * size, size);//u1
        window(-0.25f * size, 0.65f * size, size);//z1
        window(-0.15f * size, 0.65f * size, size);//a2

        window(0.1f * size, 0.05f * size, size);//j1
        window(0.2f * size, 0.05f * size, size);//k1
        window(0.1f * size, 0.2f * size, size);//o1
        window(0.2f * size, 0.2f * size, size);//n1
        window(0.1f * size, 0.35f * size, size);//r1
        window(0.2f * size, 0.35f * size, size);//s1
        window(0.1f * size, 0.5f * size, size);//v1
        window(0.2f * size, 0.5f * size, size);//w1
        window(0.1f * size, 0.65f * size, size);//j1
        window(0.2f * size, 0.65f * size, size);//k1
    glPopMatrix();

    glutSwapBuffers();
    glFlush();

}

void display() {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    buildingStructure(0.0f, -0.8f, 2.0f);

    glutSwapBuffers();
    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("CG_LT_2_O_T-01_Building with windows and door");
    glutDisplayFunc(display);
    gluOrtho2D(-1, 1, -1, 1); 
    glutMainLoop();
    return 0;

}