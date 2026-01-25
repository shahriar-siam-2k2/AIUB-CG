#include <GL/glut.h>
#include <math.h>

const int ROWS = 15;
const int COLS = 15;
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const int MAX_WALLS = 100;
const int MAX_DOTS = 200;

int score = 0;
int wallNums = 0;
int dotNums = 0;

struct Wall {
    float startX, startY, width, height;
};
struct Food {
    float startX, startY;
    bool active;
};
struct Character {
    float startX, startY;
    float red, green, blue;
};

Wall walls[MAX_WALLS];
Food dots[MAX_DOTS];
Character pacman = {1.0f, 1.0f, 1.0f, 1.0f, 0.0f};
Character ghosts[3] = {
    {7.0f, 7.5f, 1.0f, 0.0f, 0.0f}, // Red
    {6.5f, 6.5f, 0.0f, 1.0f, 1.0f}, // Cyan
    {7.5f, 6.5f, 1.0f, 0.7f, 0.8f}  // Pink
};

void addWall(float x, float y, float w, float h) {
    if (wallNums < MAX_WALLS) {
        walls[wallNums] = {x, y, w, h};
        wallNums++;
    }
}

bool wallCollision(float x, float y) {
    float size = 0.65f;

    for (int i = 0; i < wallNums; i++) {
        if (x < walls[i].startX + walls[i].width &&
            x + size > walls[i].startX &&
            y < walls[i].startY + walls[i].height &&
            y + size > walls[i].startY) {
            return true;
        }
    }
    return false;
}

void initializeGame() {
    wallNums = 0;
    dotNums = 0;

    // Walls

    // Outer
    addWall(0, 0, 15, 1);
    addWall(0, 14, 15, 1);
    addWall(0, 0, 1, 15);
    addWall(14, 0, 1, 15);

    // Inner
    addWall(2, 2, 2, 2);
    addWall(11, 2, 2, 2);
    addWall(2, 11, 2, 2);
    addWall(11, 11, 2, 2);

    // Ghost House

    // Bottom
    addWall(6, 6, 3, 0.2);

    // Top
    addWall(6, 8.8, 0.5, 0.2);
    addWall(8.5, 8.8, 0.5, 0.2);

    // Left
    addWall(6, 6, 0.2, 3);

    // Right
    addWall(8.8, 6, 0.2, 3);

    // Bottom Center
    addWall(6, 1, 3, 2);

    // Top Center
    addWall(6, 12, 3, 2);

    // Left mid strip
    addWall(1, 7, 2, 1);

    // Right mid strip
    addWall(12, 7, 2, 1);

    // Dots
    for (int y = 1; y < 14; y++) {

        for (int x = 1; x < 14; x++) {

            if (x >= 6 && x <= 8 && y >= 6 && y <= 8){
                continue; // skipping ghost house
            }

            if (!wallCollision((float)x, (float)y)) {
                if (dotNums < MAX_DOTS) {
                    dots[dotNums] = {(float)x, (float)y, true};
                    dotNums++;
                }
            }

        }

    }
}

void drawRectangle(float x, float y, float w, float h, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y + h);
        glVertex2f(x, y + h);
    glEnd();
}

void drawCircle(float cx, float cy, float r, int n, float red, float green, float blue) {
    glColor3f(red, green, blue);
    glBegin(GL_POLYGON);
        for (int i = 0; i < n; i++) {
            float theta = 2.0f * 3.1416f * float(i) / float(n);
            float x = r * cos(theta);
            float y = r * sin(theta);
            glVertex2f(x + cx, y + cy);
        }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Walls
    for (int i = 0; i < wallNums; i++) {
        drawRectangle(walls[i].startX, walls[i].startY, walls[i].width, walls[i].height, 0.1f, 0.1f, 0.6f);
    }

    // Ghost House Gate Line
    drawRectangle(6.5f, 8.85f, 2.0f, 0.1f, 1.0f, 0.7f, 0.8f);

    // Dots
    for (int i = 0; i < dotNums; i++) {
        if (dots[i].active) {
            drawRectangle(dots[i].startX + 0.4f, dots[i].startY + 0.4f, 0.2f, 0.2f, 1.0f, 1.0f, 1.0f);
        }
    }

    // Ghosts
    for (int i = 0; i < 3; i++) {
        // Body
        drawRectangle(ghosts[i].startX + 0.1f, ghosts[i].startY + 0.1f, 0.8f, 0.8f, ghosts[i].red, ghosts[i].green, ghosts[i].blue);

        // Eyes
        drawCircle(ghosts[i].startX + 0.35f, ghosts[i].startY + 0.65f, 0.12f, 10, 1.0f, 1.0f, 1.0f);
        drawCircle(ghosts[i].startX + 0.65f, ghosts[i].startY + 0.65f, 0.12f, 10, 1.0f, 1.0f, 1.0f);

        // Pupils
        drawCircle(ghosts[i].startX + 0.35f, ghosts[i].startY + 0.65f, 0.05f, 10, 0.0f, 0.0f, 1.0f);
        drawCircle(ghosts[i].startX + 0.65f, ghosts[i].startY + 0.65f, 0.05f, 10, 0.0f, 0.0f, 1.0f);
    }

    // Pacman
    float cx = pacman.startX + 0.5f;
    float cy = pacman.startY + 0.5f;
    float r = 0.4f;

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        for (int i = 30; i < 330; i++) {
            float theta1 = 3.1416f * (float)i / 180.0f;
            float theta2 = 3.1416f * (float)(i + 1) / 180.0f;

            glVertex2f(cx, cy);
            glVertex2f(cx + r * cos(theta1), cy + r * sin(theta1));
            glVertex2f(cx + r * cos(theta2), cy + r * sin(theta2));
        }
    glEnd();

    // Game
    glColor3f(1.0f, 1.0f, 1.0f);

    glutSwapBuffers();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow("Goriber PACMAN");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, COLS, 0, ROWS);

    initializeGame();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;

}
