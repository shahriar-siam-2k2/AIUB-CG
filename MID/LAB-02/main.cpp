#include <GL/glut.h>
#include <windows.h>

void drawRectangle(float x1, float y1, float x2, float y2) {
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    float totalHeight = 2.0;
    float stripeHeight = totalHeight / 3.0;

    float x_left = -1.5f;
    float x_right = 1.5f;

    float y_top = 1.0f;
    float y_middle = y_top - stripeHeight;
    float y_bottom = y_middle - stripeHeight;
    float y_floor = -1.0f;

    glColor3f(0.0f, 0.6f, 0.2f); //green
    drawRectangle(x_left, y_middle, x_right, y_top);

    glColor3f(1.0f, 1.0f, 1.0f); //white
    drawRectangle(x_left, y_bottom, x_right, y_middle);

    glColor3f(0.0f, 0.3f, 0.7f); //blue
    drawRectangle(x_left, y_floor, x_right, y_bottom);

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitWindowSize(600, 400);
    glutCreateWindow("Flag of Sierra Leone");

    glMatrixMode(GL_PROJECTION);

    gluOrtho2D(-1.5, 1.5, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
