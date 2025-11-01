#include <windows.h>
#include <GL/glut.h>

const float SQ_SIZE = 1.5;
const float START_POINT = -3.0;

void drawSq() {
    glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(SQ_SIZE, 0.0f);
        glVertex2f(SQ_SIZE, SQ_SIZE);
        glVertex2f(0.0f, SQ_SIZE);
    glEnd();
}

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    for(int i=0; i<4; i++) {

        for(int j=0; j<4; j++) {

            float x = START_POINT + (j * SQ_SIZE);
            float y = START_POINT + (i * SQ_SIZE);

            if((i + j) % 2 == 0) {
                glColor3f(1.0, 1.0, 1.0);
            }
            else {
                glColor3f(0.0, 0.0, 0.0);
            }

            drawSq();
            glPopMatrix();

        }

        glutSwapBuffers();
        glFlush();

    }
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutCreateWindow("4X4 Chess Board");
    glutInitWindowSize(320, 320);
    glutDisplayFunc(display);

    return 0;
}
