#include <windows.h>
#include <GL/glut.h>

void vase(float x, float y, float s) {

    //vase - upper part

    glColor3f(0.89412f, 0.50980f, 0.95294f);

    glBegin(GL_QUADS);
        glVertex2f(x-0.10f*s, y+0.00f*s); //D
        glVertex2f(x-0.07f*s, y-0.04f*s); //F
        glVertex2f(x+0.08f*s, y-0.04f*s); //Q
        glVertex2f(x+0.10f*s, y-0.00f*s); //E

        glVertex2f(x-0.07f*s, y-0.04f*s); //F
        glVertex2f(x-0.06f*s, y-0.07f*s); //G
        glVertex2f(x+0.07f*s, y-0.07f*s); //P
        glVertex2f(x+0.08f*s, y-0.04f*s); //Q

        glVertex2f(x-0.06f*s, y-0.07f*s); //G
        glVertex2f(x-0.08f*s, y-0.11f*s); //R
        glVertex2f(x+0.08f*s, y-0.11f*s); //S
        glVertex2f(x+0.07f*s, y-0.07f*s); //P

        glVertex2f(x-0.08f*s, y-0.11f*s); //R
        glVertex2f(x-0.10f*s, y-0.13f*s); //H
        glVertex2f(x+0.10f*s, y-0.13f*s); //O
        glVertex2f(x+0.08f*s, y-0.11f*s); //S

        glVertex2f(x-0.10f*s, y-0.13f*s); //H
        glVertex2f(x-0.15f*s, y-0.20f*s); //I
        glVertex2f(x+0.15f*s, y-0.20f*s); //N
        glVertex2f(x+0.10f*s, y-0.13f*s); //O

        glVertex2f(x-0.15f*s, y-0.20f*s); //I
        glVertex2f(x-0.12f*s, y-0.22f*s); //Z8
        glVertex2f(x-0.08f*s, y-0.24f*s); //A9
        glVertex2f(x+0.15f*s, y-0.20f*s); //N

        glVertex2f(x+0.15f*s, y-0.20f*s); //N
        glVertex2f(x-0.08f*s, y-0.24f*s); //A9
        glVertex2f(x-0.04f*s, y-0.25f*s); //B9
        glVertex2f(x-0.00f*s, y-0.25f*s); //F9

        glVertex2f(x-0.00f*s, y-0.25f*s); //F9
        glVertex2f(x+0.04f*s, y-0.25f*s); //C9
        glVertex2f(x+0.08f*s, y-0.24f*s); //D9
        glVertex2f(x+0.15f*s, y-0.20f*s); //N
    glEnd();

    //vase - Lower Part

    glColor3f(0.74118f, 0.33725f, 0.89804f);

    glBegin(GL_QUADS);
        glVertex2f(x-0.15f*s, y-0.20f*s); //I
        glVertex2f(x-0.12f*s, y-0.22f*s); //Z8
        glVertex2f(x-0.08f*s, y-0.24f*s); //A9
        glVertex2f(x-0.15f*s, y-0.27f*s); //J

        glVertex2f(x-0.15f*s, y-0.27f*s); //J
        glVertex2f(x-0.08f*s, y-0.24f*s); //A9
        glVertex2f(x-0.04f*s, y-0.25f*s); //B9
        glVertex2f(x-0.00f*s, y-0.27f*s); //E9

        glVertex2f(x-0.00f*s, y-0.27f*s); //E9
        glVertex2f(x-0.04f*s, y-0.25f*s); //B9
        glVertex2f(x+0.04f*s, y-0.25f*s); //C9
        glVertex2f(x+0.15f*s, y-0.27f*s); //M

        glVertex2f(x+0.15f*s, y-0.20f*s); //N
        glVertex2f(x+0.08f*s, y-0.24f*s); //D9
        glVertex2f(x+0.04f*s, y-0.25f*s); //C9
        glVertex2f(x+0.15f*s, y-0.27f*s); //M

        glVertex2f(x-0.15f*s, y-0.27f*s); //J
        glVertex2f(x-0.10f*s, y-0.37f*s); //K
        glVertex2f(x+0.10f*s, y-0.37f*s); //L
        glVertex2f(x+0.15f*s, y-0.27f*s); //M
    glEnd();

    //trunk

    // Main Trunk (Mid)

    glColor3f(0.18431f, 0.12941f, 0.60392f);

    glBegin(GL_QUADS);

        glVertex2f(x-0.01f*s, y+0.00f*s); //T
        glVertex2f(x-0.01f*s, y+0.28f*s); //U
        glVertex2f(x+0.01f*s, y+0.28f*s); //V
        glVertex2f(x+0.01f*s, y+0.00f*s); //W

    glEnd();

    // Left Trunk-1

    glColor3f(0.18431f, 0.12941f, 0.60392f);

    glBegin(GL_QUADS);

        glVertex2f(x-0.05f*s, y+0.03f*s); //G1
        glVertex2f(x-0.03f*s, y+0.00f*s); //Z
        glVertex2f(x-0.04f*s, y+0.06f*s); //A1
        glVertex2f(x-0.06f*s, y+0.06f*s); //F1

        glVertex2f(x-0.06f*s, y+0.06f*s); //F1
        glVertex2f(x-0.04f*s, y+0.06f*s); //A1
        glVertex2f(x-0.08f*s, y+0.14f*s); //B1
        glVertex2f(x-0.10f*s, y+0.13f*s); //E1

        glVertex2f(x-0.10f*s, y+0.13f*s); //E1
        glVertex2f(x-0.08f*s, y+0.14f*s); //B1
        glVertex2f(x-0.14f*s, y+0.21f*s); //C1
        glVertex2f(x-0.15f*s, y+0.20f*s); //D1

    glEnd();

    // Left Trunk-2

    glColor3f(0.18431f, 0.12941f, 0.60392f);

    glBegin(GL_QUADS);

        glVertex2f(x-0.03f*s, y+0.00f*s); //Z
        glVertex2f(x-0.04f*s, y+0.00f*s); //O1
        glVertex2f(x-0.05f*s, y+0.02f*s); //N1
        glVertex2f(x-0.05f*s, y+0.03f*s); //G1

        glVertex2f(x-0.05f*s, y+0.03f*s); //G1
        glVertex2f(x-0.05f*s, y+0.02f*s); //N1
        glVertex2f(x-0.10f*s, y+0.07f*s); //M1
        glVertex2f(x-0.10f*s, y+0.08f*s); //H1

        glVertex2f(x-0.10f*s, y+0.08f*s); //H1
        glVertex2f(x-0.10f*s, y+0.07f*s); //M1
        glVertex2f(x-0.16f*s, y+0.10f*s); //L1
        glVertex2f(x-0.16f*s, y+0.11f*s); //I1

        glVertex2f(x-0.16f*s, y+0.11f*s); //I1
        glVertex2f(x-0.16f*s, y+0.10f*s); //L1
        glVertex2f(x-0.21f*s, y+0.11f*s); //K1
        glVertex2f(x-0.21f*s, y+0.12f*s); //J1

    glEnd();

    // Right Trunk-1

    glColor3f(0.18431f, 0.12941f, 0.60392f);

    glBegin(GL_QUADS);

        glVertex2f(x-0.03f*s, y+0.00f*s); //Z

    glEnd();


    // Leaves

    // Leaf - Trunk-1 - Left

    glColor3f(0.00392f, 0.74902f, 0.60000f);

    glBegin(GL_QUADS);

        glVertex2f(x-0.01f*s, y+0.13f*s); //T3
        glVertex2f(x-0.01f*s, y+0.19f*s); //B4
        glVertex2f(x-0.04f*s, y+0.24f*s); //A4
        glVertex2f(x-0.08f*s, y+0.18f*s); //U3

        glVertex2f(x-0.08f*s, y+0.18f*s); //U3
        glVertex2f(x-0.10f*s, y+0.21f*s); //V3
        glVertex2f(x-0.10f*s, y+0.27f*s); //W3
        glVertex2f(x-0.04f*s, y+0.24f*s); //A4

    glEnd();

    // Leaf - Trunk-1 - Right

    glColor3f(0.00392f, 0.74902f, 0.60000f);

    glBegin(GL_QUADS);

        glVertex2f(x+0.01f*s, y+0.19f*s); //C4
        glVertex2f(x+0.01f*s, y+0.10f*s); //J4
        glVertex2f(x+0.08f*s, y+0.17f*s); //I4
        glVertex2f(x+0.09f*s, y+0.20f*s); //H4

        glVertex2f(x+0.09f*s, y+0.20f*s); //H4
        glVertex2f(x+0.08f*s, y+0.27f*s); //F4
        glVertex2f(x+0.04f*s, y+0.24f*s); //E4
        glVertex2f(x+0.01f*s, y+0.19f*s); //C4

    glEnd();

    glFlush();

}

void display() {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    vase(0.0f, 0.0f, 2);

    glFlush();

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("CG_LT_2_O_T-01 | Vase");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;

}
