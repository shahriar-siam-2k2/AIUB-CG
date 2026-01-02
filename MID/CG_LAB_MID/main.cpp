#include <windows.h>
#include <GL/glut.h>
#include <math.h>

float PIE = 3.1416;

void circle(float r) {

    glBegin(GL_POLYGON);
        for(int i = 0; i < 360; i++) {

            float rad = i * PIE / 180.0;
            float x = r * cos(rad);
            float y = r * sin(rad);
            glVertex2f(x, y);

        }
    glEnd();

}

void nose() {

    glPushMatrix();
        glTranslatef(0.0f, -0.05f, 0.0f);
        glColor3ub(20, 20, 20);
        circle(0.04f);
    glPopMatrix();

}

void mouth() {

    glPushMatrix();
         glTranslatef(0.0f, -0.1f, 0.0f);
         glColor3ub(0, 0, 0);
         glLineWidth(2.0f);
         glBegin(GL_LINES);
             glVertex2f(-0.05f, 0.02f);
             glVertex2f(0.0f, -0.01f);

             glVertex2f(0.0f, -0.01f);
             glVertex2f(0.05f, 0.02f);
         glEnd();
    glPopMatrix();

}

void eyes() {

    glPushMatrix();
        glTranslatef(-0.12f, 0.05f, 0.0f);
        glRotatef(-30.0f, 0.0f, 0.0f, 1.0f);
        glColor3ub(30, 30, 30);
        circle(0.06f);

        glTranslatef(0.02f, 0.01f, 0.0f);
        glColor3ub(255, 255, 255);
        circle(0.02f);

        glColor3ub(0, 0, 0);
        circle(0.008f);
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.12f, 0.05f, 0.0f);
        glRotatef(30.0f, 0.0f, 0.0f, 1.0f);
        glColor3ub(30, 30, 30);
        circle(0.06f);

        glTranslatef(-0.02f, 0.01f, 0.0f);
        glColor3ub(255, 255, 255);
        circle(0.02f);

        glColor3ub(0, 0, 0);
        circle(0.008f);
    glPopMatrix();

}

void ears() {

    glColor3ub(30, 30, 30);
    glPushMatrix();
        glTranslatef(-0.22f, 0.35f, 0.0f);
        circle(0.07f);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.22f, 0.35f, 0.0f);
        circle(0.07f);
    glPopMatrix();

}

void face() {

    glColor3ub(255, 255, 255);
    glPushMatrix();
        glTranslatef(0.0f, 0.15f, 0.0f);
        circle(0.3f);
        eyes();
        nose();
        mouth();
    glPopMatrix();

}

void hands() {

    glColor3ub(30, 30, 30);
    glPushMatrix();
        glTranslatef(-0.3f, -0.05f, 0.0f);
        glRotatef(20.0f, 0.0f, 0.0f, 1.0f);
        circle(0.1f);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.3f, -0.05f, 0.0f);
        glRotatef(-20.0f, 0.0f, 0.0f, 1.0f);
        circle(0.1f);
    glPopMatrix();

}

void legs() {

    glColor3ub(30, 30, 30);
    glPushMatrix();
        glTranslatef(-0.15f, -0.8f, 0.0f);
        circle(0.09f);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0.15f, -0.8f, 0.0f);
        circle(0.09f);
    glPopMatrix();

}

void chest() {

    glColor3ub(30, 30, 30);
    glPushMatrix();
        glTranslatef(0.0f, -0.05f, 0.0f);
        circle(0.3f);
    glPopMatrix();

}

void belly() {

    glColor3ub(255, 255, 255);
    glPushMatrix();
        glTranslatef(0.0f, -0.45f, 0.0f);
        circle(0.28f);
    glPopMatrix();

}

void pant() {

    glColor3ub(85, 107, 47);
    glPushMatrix();
        glTranslatef(0.0f, -0.7f, 0.0f);
        glBegin(GL_QUADS);
            glVertex2f(-0.26f, 0.1f);
            glVertex2f(0.26f, 0.1f);
            glVertex2f(0.24f, -0.1f);
            glVertex2f(-0.24f, -0.1f);
        glEnd();
    glPopMatrix();

}

void panda() {

    chest();
    belly();
    ears();
    face();
    hands();
    legs();
    pant();

}

void display() {

    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    panda();

    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutCreateWindow("Kung Fu Panda");
    glutDisplayFunc(display);
    gluOrtho2D(-1, 1, -1, 1);
    glutMainLoop();
    return 0;

}
