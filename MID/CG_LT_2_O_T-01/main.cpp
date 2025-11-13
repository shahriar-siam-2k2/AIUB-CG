#include <windows.h>
#include <GL/glut.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.1416
#endif

void drawFlower(float x, float y, float r, float g, float b, float scale) {
    int numPetals = 5;
    
    glPushMatrix();
    
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    glColor3f(r, g, b);
    for (int i = 0; i < numPetals; i++) {
        glPushMatrix();
        glRotatef((360.0 / numPetals) * i, 0.0, 0.0, 1.0);
        
        glBegin(GL_POLYGON);
            glVertex2f(0.0, 0.0);
            glVertex2f(0.2, 0.4);
            glVertex2f(0.0, 0.8);
            glVertex2f(-0.2, 0.4);
        glEnd();
        
        glPopMatrix();
    }

    glColor3f(0.9f, 0.7f, 0.2f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 16; i++) {
        float angle = 2.0 * M_PI * i / 16.0;
        glVertex2f(cos(angle) * 0.2, sin(angle) * 0.2);
    }
    glEnd();
    
    glPopMatrix();
}

void drawLeaf(float x1, float y1, float x2, float y2, float x3, float y3) {
    glColor3f(0.0f, 0.5f, 0.2f);
    glBegin(GL_POLYGON);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.70f, 0.48f, 0.88f);
    glBegin(GL_POLYGON);
        glVertex2f(0.0, -2.5);
        glVertex2f(0.7, -2.5);
        glVertex2f(1.0, -1.8);
        glVertex2f(0.6, -0.8);
        glVertex2f(0.0, -0.8);
    glEnd();

    glColor3f(0.82f, 0.62f, 0.94f);
    glBegin(GL_POLYGON);
        glVertex2f(0.0, -2.5);
        glVertex2f(-0.7, -2.5);
        glVertex2f(-1.0, -1.8);
        glVertex2f(-0.6, -0.8);
        glVertex2f(0.0, -0.8);
    glEnd();

    glColor3f(0.0f, 0.5f, 0.2f);
    glLineWidth(4.0f);
    
    glBegin(GL_LINES);
        glVertex2f(0.0, -0.8);
        glVertex2f(0.0, 1.2);
        
        glVertex2f(0.0, -0.8);
        glVertex2f(-1.0, 1.0);
        
        glVertex2f(0.0, -0.8);
        glVertex2f(1.0, 1.0);
        
        glVertex2f(0.0, -0.8);
        glVertex2f(-1.5, 0.4);
        
        glVertex2f(0.0, -0.8);
        glVertex2f(1.5, 0.4);
    glEnd();
    glLineWidth(1.0f);

    drawLeaf(-0.2, 0.0, -0.8, 0.5, -0.4, 0.2);
    drawLeaf(0.2, 0.0, 0.8, 0.5, 0.4, 0.2);
    drawLeaf(-0.1, 0.5, -0.5, 0.8, -0.2, 0.6);

    drawFlower(0.0, 1.5, 1.0f, 0.41f, 0.70f, 0.8f);
    drawFlower(-1.0, 1.2, 0.8f, 0.6f, 1.0f, 0.7f);
    drawFlower(1.0, 1.2, 1.0f, 0.41f, 0.70f, 0.7f);
    drawFlower(-1.6, 0.5, 1.0f, 0.25f, 0.5f, 0.6f);
    drawFlower(1.6, 0.5, 1.0f, 0.25f, 0.5f, 0.6f);

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
    
    glutInitWindowSize(320, 320);
    glutCreateWindow("Flowers in a Vase");
    
    glClearColor(0.94f, 0.925f, 0.898f, 1.0f); 

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluOrtho2D(-3.0, 3.0, -3.0, 3.0); 

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glutDisplayFunc(display);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glutMainLoop(); 
    return 0;
}