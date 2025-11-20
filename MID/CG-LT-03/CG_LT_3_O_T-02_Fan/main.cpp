#include <windows.h>
#include <GL/glut.h>
#include <math.h>

float ROTATION = 0.0f;
float PIE = 3.1416f;

void fanBlades(float fanSize) {

    glPushMatrix();
        glRotatef(ROTATION, 0.0f, 0.0f, 1.0f); 

        // blades
        glColor3ub(200, 200, 255);
        for (int i = 0; i < 3; i++) {

            glPushMatrix();
                glRotatef(i * 120.0f, 0.0f, 0.0f, 1.0f); 

                glBegin(GL_QUADS); 
                    glVertex2f(0.05f * fanSize, -0.05f * fanSize); // M
                    glVertex2f(0.3f * fanSize, -0.05f * fanSize); // L
                    glVertex2f(0.3f * fanSize, 0.05f * fanSize); // K
                    glVertex2f(0.05f * fanSize, 0.05f * fanSize); // J
                glEnd();

            glPopMatrix();

        }
    glPopMatrix();

}

void fan(float x, float y, float standSize, float fanSize) {

    glPushMatrix();
        glTranslatef(x, y, 0.0f);

        float baseTop = -standSize;
        float baseBottom = -standSize - (0.05f * fanSize);

        // Fan Base
        glColor3ub(100, 100, 100);
        glBegin(GL_QUADS);
            glVertex2f(-0.2f * fanSize, baseBottom); // D
            glVertex2f(0.2f * fanSize, baseBottom); // C
            glVertex2f(0.2f * fanSize, baseTop); // B
            glVertex2f(-0.2f * fanSize, baseTop); // A
        glEnd();

        // Fan Stand
        glBegin(GL_QUADS);
            glVertex2f(-0.02f * fanSize, baseTop); // E
            glVertex2f(0.02f * fanSize, baseTop); // F
            glVertex2f(0.02f * fanSize, 0.0f); // G
            glVertex2f(-0.02f * fanSize, 0.0f); // H
        glEnd();

        // Fan Center
        glColor3ub(80, 80, 80);
        float c = 0.1f; // I
        glBegin(GL_POLYGON);
            for(int i = 0; i < 360; i++) {
                float rad = i * PIE / 180.0;
                float r = c * fanSize;
                float xx = r * cos(rad);
                float yy = r * sin(rad);
                glVertex2f(xx, yy);
            }
        glEnd();

        fanBlades(fanSize);
    glPopMatrix();
}

void update(int value) {
    
    ROTATION -= 5.0f;

    if(ROTATION < -360.0) {

        ROTATION += 360.0;

    }

    glutPostRedisplay();
    glutTimerFunc(15, update, 0);

}

void display() {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    fan(0.0f, 0.1f, 0.35f, 1.0f);
    
    glutSwapBuffers();

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
    glutInitWindowSize(500, 500);
    glutCreateWindow("CG_LT_3_O_T-02_Fan (ON)");
    glutDisplayFunc(display);
    gluOrtho2D(-1, 1, -1, 1); 
    glutTimerFunc(15, update, 0); 
    glutMainLoop();
    return 0;
    
}