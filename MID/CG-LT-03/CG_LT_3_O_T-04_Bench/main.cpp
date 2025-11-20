#include <windows.h>
#include <GL/glut.h>

void bench(float x, float y, float size) {

    glPushMatrix();
        glTranslatef(x, y, 0.0f);

        // Legs

        // Leg-1 - Side-1
        glColor3ub(132, 62, 1);
        glBegin(GL_QUADS);
            glVertex2f(-0.09f * size, -0.09f * size); // T
            glVertex2f(-0.09f * size, -0.14f * size); // U
            glVertex2f(-0.08f * size, -0.14f * size); // V
            glVertex2f(-0.08f * size, -0.09f * size); // W
        glEnd();

        //Leg-1 - Side-2
        glColor3ub(64, 6, 5);
        glBegin(GL_QUADS);
            glVertex2f(-0.08f * size, -0.09f * size); // W
            glVertex2f(-0.08f * size, -0.14f * size); // V
            glVertex2f(-0.06f * size, -0.13f * size); // Z
            glVertex2f(-0.06f * size, -0.09f * size); // A1
        glEnd();

        // Leg-2 - Side-1
        glColor3ub(148, 80, 5);
        glBegin(GL_QUADS);
            glVertex2f(-0.02f * size, -0.08f * size); // J
            glVertex2f(-0.02f * size, -0.16f * size); // I
            glVertex2f(0.00f * size, -0.16f * size); // H
            glVertex2f(0.00f * size, -0.07f * size); // G
        glEnd();

        //Leg-2 - Side-2
        glColor3ub(230, 161, 86);
        glBegin(GL_QUADS);
            glVertex2f(0.00f * size, -0.07f * size); // G
            glVertex2f(0.00f * size, -0.16f * size); // H
            glVertex2f(0.02f * size, -0.14f * size); // L
            glVertex2f(0.02f * size, -0.06f * size); // K
        glEnd();

        // Leg-3 - Side-1
        glColor3ub(109, 46, 5);
        glBegin(GL_QUADS);
            glVertex2f(0.06f * size, -0.03f * size); // F1
            glVertex2f(0.06f * size, -0.04f * size); // E1
            glVertex2f(0.07f * size, -0.04f * size); // B1
            glVertex2f(0.07f * size, -0.02f * size); // G1
        glEnd();

        //Leg-3 - Side-2
        glColor3ub(116, 61, 2);
        glBegin(GL_QUADS);
            glVertex2f(0.07f * size, -0.02f * size); // G1
            glVertex2f(0.07f * size, -0.04f * size); // B1
            glVertex2f(0.08f * size, -0.03f * size); // C1
            glVertex2f(0.08f * size, -0.02f * size); // D1
        glEnd();

        // Leg-4 - Side-1
        glColor3ub(99, 35, 1);
        glBegin(GL_QUADS);
            glVertex2f(0.12f * size, 0.01f * size); // S
            glVertex2f(0.12f * size, -0.04f * size); // R
            glVertex2f(0.13f * size, -0.04f * size); // O
            glVertex2f(0.13f * size, 0.01f * size); // M
        glEnd();

        //Leg-4 - Side-2
        glColor3ub(231, 164, 94);
        glBegin(GL_QUADS);
            glVertex2f(0.13f * size, 0.01f * size); // M
            glVertex2f(0.13f * size, -0.04f * size); // O
            glVertex2f(0.14f * size, -0.03f * size); // P
            glVertex2f(0.14f * size, 0.02f * size); // Q
        glEnd();

        //Left Side
        glColor3ub(197, 119, 71);
        glBegin(GL_QUADS);
            glVertex2f(-0.13f * size, -0.06f * size); // C
            glVertex2f(-0.04f * size, -0.08f * size); // D
            glVertex2f(-0.04f * size, -0.10f * size); // E
            glVertex2f(-0.14f * size, -0.08f * size); // F
        glEnd();

        //Front Side
        glColor3ub(213, 148, 75);
        glBegin(GL_QUADS);
            glVertex2f(-0.04f * size, -0.10f * size); // E
            glVertex2f(-0.04f * size, -0.08f * size); // D
            glVertex2f(0.15f * size, 0.03f * size); // N
            glVertex2f(0.15f * size, 0.02f * size); // H1
        glEnd();

        //Base
        glColor3ub(240, 180, 132);
        glBegin(GL_QUADS);
            glVertex2f(0.15f * size, 0.03f * size); // N
            glVertex2f(-0.04f * size, -0.08f * size); // D
            glVertex2f(-0.13f * size, -0.06f * size); // C
            glVertex2f(0.09f * size, 0.04f * size); // I1
        glEnd();

        // back
        glColor3ub(128, 63, 8);
        glBegin(GL_QUADS);
            glVertex2f(-0.13f * size, -0.06f * size); // C
            glVertex2f(-0.18f * size, 0.10f * size); // P1
            glVertex2f(0.06f * size, 0.14f * size); // Q1
            glVertex2f(0.09f * size, 0.04f * size); // I1
        glEnd();

        // back left
        glColor3ub(254, 197, 152);
        glBegin(GL_POLYGON);
            glVertex2f(-0.13f * size, -0.06f * size); // C
            glVertex2f(-0.18f * size, 0.10f * size); // P1
            glVertex2f(-0.14f * size, -0.08f * size); // F
        glEnd();

    glPopMatrix();

}

void display() {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    bench(0.0f, 0.0f, 4.0f);

    glutSwapBuffers();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("CG_LT_3_O_T-03_Bench");
    glutDisplayFunc(display);
    gluOrtho2D(-1, 1, -1, 1); 
    glutMainLoop();
    return 0;
    
}