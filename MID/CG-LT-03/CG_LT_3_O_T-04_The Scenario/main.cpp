#include <windows.h>
#include <GL/glut.h>
#include <math.h>

int FAN_SPEED = 5;
float ROTATION = 0.0f;
float PIE = 3.1416f;

void window(float x, float y, float size) {

    glPushMatrix();
        glTranslatef(x, y, 0.0f);

        glColor3ub(204,229,255);
        glBegin(GL_QUADS);
            glVertex2f(0.0f * size, 0.0f * size);
            glVertex2f(0.0f * size, 0.05f * size);
            glVertex2f(0.05f * size, 0.05f * size);
            glVertex2f(0.05f * size, 0.0f * size);
        glEnd();

        glColor3ub(204,229,255);
        glLineWidth(1);
        glBegin(GL_LINE_LOOP);
            glVertex2f(0.0f * size, 0.0f * size);
            glVertex2f(0.0f * size, 0.05f * size);
            glVertex2f(0.05f * size, 0.05f * size);
            glVertex2f(0.05f * size, 0.0f * size);
        glEnd();

        glLineWidth(1);
        glBegin(GL_LINES);
            glColor3ub(0,0,0);

            glVertex2f(0.0f * size, 0.025f * size);
            glVertex2f(0.05f * size, 0.025f * size);

            glVertex2f(0.025f * size, 0.05f * size);
            glVertex2f(0.025f * size, 0.0f * size);
        glEnd();
    glPopMatrix();
}
void building(float x, float y, float size) {

    glPushMatrix();
        glTranslatef(x, y, 0.0f);

        glColor3ub(153,76,0);
        glBegin(GL_QUADS);
            glVertex2f(-0.3f * size, 0.0f * size);
            glVertex2f(-0.3f * size, 0.75f * size);
            glVertex2f(0.3f * size, 0.75f * size);
            glVertex2f(0.3f * size, 0.0f * size);
        glEnd();

        // Door
        glColor3ub(102,51,0);
        glBegin(GL_QUADS);
            glVertex2f(-0.05f * size, 0.1f * size);
            glVertex2f(0.05f * size, 0.1f * size);
            glVertex2f(0.05f * size, 0.0f * size);
            glVertex2f(-0.05f * size, 0.0f * size);
        glEnd();

        // Building Outline
        glLineWidth(3);
        glColor3ub(0,0,0);
        glBegin(GL_LINES);
            glVertex2f(-0.3f * size, 0.15f * size);
            glVertex2f(0.3f * size, 0.15f * size);

            glVertex2f(-0.3f * size, 0.3f * size);
            glVertex2f(0.3f * size, 0.3f * size);

            glVertex2f(-0.3f * size, 0.45f * size);
            glVertex2f(0.3f * size, 0.45f * size);

            glVertex2f(-0.3f * size, 0.6f * size);
            glVertex2f(0.3f * size, 0.6f * size);

            // Door Outline
            glVertex2f(0.0f * size, 0.1f * size);
            glVertex2f(0.0f * size, 0.0f * size);
        glEnd();

        // Roof and Floor Line
        glLineWidth(7);
        glBegin(GL_LINES);
            glVertex2f(-0.32f * size, -0.01f * size);
            glVertex2f(0.32f * size, -0.01f * size);

            glVertex2f(-0.3f * size, 0.76f * size);
            glVertex2f(0.3f * size, 0.76f * size);
        glEnd();
    glPopMatrix();

}
void buildingStructure(float x, float y, float size) {

    building(x, y, size);

    glPushMatrix();
        glTranslatef(x, y, 0.0f);

        window(-0.25f * size, 0.2f * size, size);
        window(-0.25f * size, 0.35f * size, size);
        window(-0.25f * size, 0.5f * size, size);
        window(-0.25f * size, 0.65f * size, size);

        window(-0.15f * size, 0.2f * size, size);
        window(-0.15f * size, 0.35f * size, size);
        window(-0.15f * size, 0.5f * size, size);
        window(-0.15f * size, 0.65f * size, size);

        window(0.10f * size, 0.2f * size, size);
        window(0.10f * size, 0.35f * size, size);
        window(0.10f * size, 0.5f * size, size);
        window(0.10f * size, 0.65f * size, size);

        window(0.20f * size, 0.2f * size, size);
        window(0.20f * size, 0.35f * size, size);
        window(0.20f * size, 0.5f * size, size);
        window(0.20f * size, 0.65f * size, size);

    glPopMatrix();

}

void fanBlades(float fanSize) {
    glPushMatrix();
        glRotatef(ROTATION, 0.0f, 0.0f, 1.0f); 
        glColor3ub(200, 200, 255);

        for (int i = 0; i < 3; i++) {
            glPushMatrix();
                glRotatef(i * 120.0f, 0.0f, 0.0f, 1.0f); 
                glBegin(GL_QUADS); 
                    glVertex2f(0.05f * fanSize, -0.05f * fanSize); 
                    glVertex2f(0.3f * fanSize, -0.05f * fanSize); 
                    glVertex2f(0.3f * fanSize, 0.05f * fanSize); 
                    glVertex2f(0.05f * fanSize, 0.05f * fanSize); 
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
            glVertex2f(-0.2f * fanSize, baseBottom); 
            glVertex2f(0.2f * fanSize, baseBottom); 
            glVertex2f(0.2f * fanSize, baseTop); 
            glVertex2f(-0.2f * fanSize, baseTop); 
        glEnd();

        // Fan Stand
        glBegin(GL_QUADS);
            glVertex2f(-0.02f * fanSize, baseTop); 
            glVertex2f(0.02f * fanSize, baseTop); 
            glVertex2f(0.02f * fanSize, 0.0f); 
            glVertex2f(-0.02f * fanSize, 0.0f); 
        glEnd();

        // Fan Center
        glColor3ub(80, 80, 80);
        float c = 0.1f; 
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
    glutTimerFunc(FAN_SPEED, update, 0);

}

void bench(float x, float y, float size) {

    glPushMatrix();
        glTranslatef(x, y, 0.0f);

        // Leg-1 - Side-1
        glColor3ub(132, 62, 1);
        glBegin(GL_QUADS);
            glVertex2f(-0.09f * size, -0.09f * size);
            glVertex2f(-0.09f * size, -0.14f * size);
            glVertex2f(-0.08f * size, -0.14f * size);
            glVertex2f(-0.08f * size, -0.09f * size);
        glEnd();

        //Leg-1 - Side-2
        glColor3ub(64, 6, 5);
        glBegin(GL_QUADS);
            glVertex2f(-0.08f * size, -0.09f * size);
            glVertex2f(-0.08f * size, -0.14f * size);
            glVertex2f(-0.06f * size, -0.13f * size);
            glVertex2f(-0.06f * size, -0.09f * size);
        glEnd();

        // Leg-2 - Side-1
        glColor3ub(148, 80, 5);
        glBegin(GL_QUADS);
            glVertex2f(-0.02f * size, -0.08f * size);
            glVertex2f(-0.02f * size, -0.16f * size);
            glVertex2f(0.00f * size, -0.16f * size);
            glVertex2f(0.00f * size, -0.07f * size);
        glEnd();

        //Leg-2 - Side-2
        glColor3ub(230, 161, 86);
        glBegin(GL_QUADS);
            glVertex2f(0.00f * size, -0.07f * size);
            glVertex2f(0.00f * size, -0.16f * size);
            glVertex2f(0.02f * size, -0.14f * size);
            glVertex2f(0.02f * size, -0.06f * size);
        glEnd();

        // Leg-3 - Side-1
        glColor3ub(109, 46, 5);
        glBegin(GL_QUADS);
            glVertex2f(0.06f * size, -0.03f * size);
            glVertex2f(0.06f * size, -0.04f * size);
            glVertex2f(0.07f * size, -0.04f * size);
            glVertex2f(0.07f * size, -0.02f * size);
        glEnd();

        //Leg-3 - Side-2
        glColor3ub(116, 61, 2);
        glBegin(GL_QUADS);
            glVertex2f(0.07f * size, -0.02f * size);
            glVertex2f(0.07f * size, -0.04f * size);
            glVertex2f(0.08f * size, -0.03f * size);
            glVertex2f(0.08f * size, -0.02f * size);
        glEnd();

        // Leg-4 - Side-1
        glColor3ub(99, 35, 1);
        glBegin(GL_QUADS);
            glVertex2f(0.12f * size, 0.01f * size);
            glVertex2f(0.12f * size, -0.04f * size);
            glVertex2f(0.13f * size, -0.04f * size);
            glVertex2f(0.13f * size, 0.01f * size);
        glEnd();

        //Leg-4 - Side-2
        glColor3ub(231, 164, 94);
        glBegin(GL_QUADS);
            glVertex2f(0.13f * size, 0.01f * size);
            glVertex2f(0.13f * size, -0.04f * size);
            glVertex2f(0.14f * size, -0.03f * size);
            glVertex2f(0.14f * size, 0.02f * size);
        glEnd();

        //Left Side
        glColor3ub(197, 119, 71);
        glBegin(GL_QUADS);
            glVertex2f(-0.13f * size, -0.06f * size);
            glVertex2f(-0.04f * size, -0.08f * size);
            glVertex2f(-0.04f * size, -0.10f * size);
            glVertex2f(-0.14f * size, -0.08f * size);
        glEnd();

        //Front Side
        glColor3ub(213, 148, 75);
        glBegin(GL_QUADS);
            glVertex2f(-0.04f * size, -0.10f * size);
            glVertex2f(-0.04f * size, -0.08f * size);
            glVertex2f(0.15f * size, 0.03f * size);
            glVertex2f(0.15f * size, 0.02f * size);
        glEnd();

        //Base
        glColor3ub(240, 180, 132);
        glBegin(GL_QUADS);
            glVertex2f(0.15f * size, 0.03f * size);
            glVertex2f(-0.04f * size, -0.08f * size);
            glVertex2f(-0.13f * size, -0.06f * size);
            glVertex2f(0.09f * size, 0.04f * size);
        glEnd();

        // back
        glColor3ub(128, 63, 8);
        glBegin(GL_QUADS);
            glVertex2f(-0.13f * size, -0.06f * size);
            glVertex2f(-0.18f * size, 0.10f * size);
            glVertex2f(0.06f * size, 0.14f * size);
            glVertex2f(0.09f * size, 0.04f * size);
        glEnd();

        // back left
        glColor3ub(254, 197, 152);
        glBegin(GL_POLYGON);
            glVertex2f(-0.13f * size, -0.06f * size);
            glVertex2f(-0.18f * size, 0.10f * size);
            glVertex2f(-0.14f * size, -0.08f * size);
        glEnd();
    glPopMatrix();

}

void lampCircle(float xx,float yy,float r,int red, int green,int blue) {

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
void lampPost(float x, float y,float s) {

    glPushMatrix();
        glTranslatef(x, y, 0.0f);
    
        glColor3ub(127,174,35);
        glBegin(GL_QUADS);
            glVertex2f(0.0f*s,0.0f*s);
            glVertex2f(0.08f*s,0.0f*s);
            glVertex2f(0.07f*s,0.215f*s);
            glVertex2f(0.01f*s,0.215f*s);

            glVertex2f(0.02f*s,0.215f*s);
            glVertex2f(0.06f*s,0.215f*s);
            glVertex2f(0.05f*s,0.6f*s);
            glVertex2f(0.03f*s,0.6f*s);

            glVertex2f(0.0f*s,0.6f*s);
            glVertex2f(0.08f*s,0.6f*s);
            glVertex2f(0.11f*s,0.75f*s);
            glVertex2f(-0.03f*s,0.75f*s);

            glVertex2f(0.035f*s,0.815f*s);
            glVertex2f(0.03f*s,0.8f*s);
            glVertex2f(0.05f*s,0.8f*s);
            glVertex2f(0.045f*s,0.815f*s);

            glVertex2f(0.025f*s,0.825f*s);
            glVertex2f(0.04f*s,0.81f*s);
            glVertex2f(0.055f*s,0.825f*s);
            glVertex2f(0.04f*s,0.855f*s);
        glEnd();

        glLineWidth(3*s);
        glColor3ub(127,174,35);
        glBegin(GL_LINES);
            glVertex2f(-0.04f*s,0.754f*s);
            glVertex2f(0.12f*s,0.754f*s);

            glVertex2f(-0.014f*s,0.61f*s);
            glVertex2f(0.094f*s,0.61f*s);

            glVertex2f(-0.024f*s,0.002f*s);
            glVertex2f(0.102f*s,0.002f*s);
        glEnd();

        lampCircle(0.04f*s,0.74f*s,0.066f*s,127,174,34);

        glColor3ub(255,223,153);
        glBegin(GL_QUADS);
            glVertex2f(-0.02f*s,0.74f*s);
            glVertex2f(0.035f*s,0.74f*s);
            glVertex2f(0.035f*s,0.615f*s);
            glVertex2f(0.005f*s,0.615f*s);

            glVertex2f(0.045f*s,0.74f*s);
            glVertex2f(0.045f*s,0.615f*s);
            glVertex2f(0.075f*s,0.615f*s);
            glVertex2f(0.1f*s,0.74f*s);
        glEnd();
    
    glPopMatrix();
}

void display() {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    buildingStructure(0.23f, -0.7f, 2.0f);
    lampPost(-0.73f, -0.7f, 0.55f);
    fan(-0.52f, -0.55f, 0.16f, 0.3f);
    bench(-0.72f, -0.7f, 1.3f);

    glutSwapBuffers();

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutCreateWindow("CG_LT_3_O_T-04_The Scenario");
    glutDisplayFunc(display);
    gluOrtho2D(-1, 1, -1, 1); 
    glutTimerFunc(FAN_SPEED, update, 0); 
    glutMainLoop();
    return 0;
    
}