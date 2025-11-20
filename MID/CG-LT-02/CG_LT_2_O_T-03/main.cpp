#include <windows.h>
#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0f, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
        glVertex2f(0.0, 0.7);
        glVertex2f(0.3, 0.9);
        glVertex2f(0.4, 0.7);
        glVertex2f(0.7, 0.8);
        glVertex2f(0.5, 0.4);
        glVertex2f(1.2, 0.6);
        glVertex2f(3.0, 0.9);
        glVertex2f(2.5, -0.5);
        glVertex2f(1.5, 0.0);
        glVertex2f(0.0, -1.0);
    glEnd();

    glPushMatrix();
    glScalef(-1.0f, 1.0f, 1.0f);

    glBegin(GL_POLYGON);
        glVertex2f(0.0, 0.7);
        glVertex2f(0.3, 0.9);
        glVertex2f(0.4, 0.7);
        glVertex2f(0.7, 0.8);
        glVertex2f(0.5, 0.4);
        glVertex2f(1.2, 0.6);
        glVertex2f(3.0, 0.9);
        glVertex2f(2.5, -0.5);
        glVertex2f(1.5, 0.0);
        glVertex2f(0.0, -1.0);
    glEnd();

    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutCreateWindow("Batman Logo");
    glutInitWindowSize(320, 320);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-3, 3, -3, 3);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
