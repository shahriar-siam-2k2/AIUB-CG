#include <GL/glut.h>
#include <math.h>
#include <time.h>   

const int ROWS = 15;
const int COLS = 27; 
const int SCREEN_WIDTH = 1000; 
const int SCREEN_HEIGHT = 600;
const int MAX_WALLS = 250; 
const int MAX_DOTS = 400; 
const float PACMAN_SPEED = 0.1f;

int score = 0;
int wallNums = 0;
int foodNums = 0;
bool gameOver = false;
bool gameWon = false;
bool gameStarted = false; 
bool gamePaused = false;
int currentLevel = 1;     
float ghostSpeed = 0.05f; 
float pacManRotation = 0.0f; 
float mouthAngle = 0.0f;  
bool mouthOpen = true;    
unsigned long int nextRandom = 1;

int randomGenerator(void) {
    nextRandom = nextRandom * 1103515245 + 12345;
    return (unsigned int)(nextRandom / 65536) % 32768;
}

void startRandom(unsigned int start) {
    nextRandom = start;
}

struct Wall {
    float startX, startY, width, height;
};

struct Food {
    float startX, startY;
    bool active;
};

struct Character {
    float startX, startY;
    int dirX, dirY;
    float red, green, blue;  
};

Wall walls[MAX_WALLS];
Food foods[MAX_DOTS];

Character pacman = {1.0f, 1.0f, 0, 0, 1.0f, 1.0f, 0.0f}; 
Character ghosts[3] = {
    {13.5f, 7.5f, 0, 0, 1.0f, 0.0f, 0.0f}, // Red
    {12.9f, 6.5f, 0, 0, 0.0f, 1.0f, 1.0f}, // Cyan
    {13.9f, 6.5f, 0, 0, 1.0f, 0.7f, 0.8f}  // Pink
};

void addWall(float x, float y, float w, float h) {
    if (wallNums < MAX_WALLS) {
        walls[wallNums] = {x, y, w, h};
        wallNums++;
    }
}

bool wallCollision(float x, float y, bool isPacman) {
    float collArea = 0.15f; 
    float size = 0.7f;    
    
    for (int i = 0; i < wallNums; i++) {
        if (x + collArea < walls[i].startX + walls[i].width &&
            x + collArea + size > walls[i].startX &&
            y + collArea < walls[i].startY + walls[i].height &&
            y + collArea + size > walls[i].startY) {
            return true;
        }
    }

    if (isPacman) {
        if (x + collArea < 15.0f && x + collArea + size > 12.0f &&
            y + collArea < 9.0f && y + collArea + size > 8.8f) {
            return true;
        }
    }

    return false;
}

void initializeGame(int level) {
    wallNums = 0;
    foodNums = 0;

    addWall(0, 0, COLS, 1);          
    addWall(0, ROWS - 1, COLS, 1);   
    addWall(0, 0, 1, ROWS);          
    addWall(COLS - 1, 0, 1, ROWS);   

    float ghostX = 12.0f;
    float ghostY = 6.0f;
    addWall(ghostX, ghostY, 3.0, 0.2); 
    addWall(ghostX, ghostY, 0.2, 3.0); 
    addWall(ghostX + 2.8f, ghostY, 0.2, 3.0); 
    addWall(ghostX, ghostY + 2.8f, 0.5, 0.2); 
    addWall(ghostX + 2.5f, ghostY + 2.8f, 0.5, 0.2); 

    if (level == 1) { 
        addWall(2, 2, 4, 2); 
        addWall(COLS - 6, 2, 4, 2);
        addWall(2, ROWS - 4, 4, 2);
        addWall(COLS - 6, ROWS - 4, 4, 2);
    } 
    else if (level == 2) {
        addWall(2, 2, 3, 2); 
        addWall(COLS - 5, 2, 3, 2);
        addWall(2, ROWS - 4, 3, 2);
        addWall(COLS - 5, ROWS - 4, 3, 2);
        addWall(6, 2, 1, 4); 
        addWall(COLS - 7, 2, 1, 4);
        addWall(6, 9, 1, 4); 
        addWall(COLS - 7, 9, 1, 4);
        addWall(2, 7, 3, 1); 
        addWall(COLS - 5, 7, 3, 1);
        addWall(9, 2, 9, 1);  
        addWall(9, 12, 9, 1); 
        addWall(13, 10, 1, 2); 
    } 
    else if (level == 3) {
        addWall(2, 2, 2, 2); 
        addWall(4, 2, 1, 3); 
        addWall(COLS - 4, 2, 2, 2);
        addWall(COLS - 5, 2, 1, 3);
        addWall(2, ROWS - 4, 2, 2);
        addWall(4, ROWS - 5, 1, 3);
        addWall(COLS - 4, ROWS - 4, 2, 2);
        addWall(COLS - 5, ROWS - 5, 1, 3);
        addWall(7, 2, 1, 4); 
        addWall(COLS - 8, 2, 1, 4);
        addWall(7, 9, 1, 4); 
        addWall(COLS - 8, 9, 1, 4);
        addWall(10, 4, 7, 1); 
        addWall(10, 10, 7, 1); 
        addWall(2, 7, 2, 1); 
        addWall(COLS - 4, 7, 2, 1);
        addWall(10, 6, 1, 3);
        addWall(16, 6, 1, 3);
        addWall(12, 2, 3, 1);
        addWall(12, 12, 3, 1);
    }

    for (int y = 1; y < ROWS - 1; y++) {
        for (int x = 1; x < COLS - 1; x++) {
            if (x >= 12 && x <= 15 && y >= 6 && y <= 9) continue;

            if (!wallCollision((float)x, (float)y, false)) {
                if (foodNums < MAX_DOTS) {
                    foods[foodNums] = {(float)x, (float)y, true};
                    foodNums++;
                }
            }
        }
    }
}

void resetGame() {
    score = 0;
    gameOver = false;
    gameWon = false;
    gamePaused = false;
    
    if (currentLevel == 1) {
        ghostSpeed = 0.04f;
    }      
    else if (currentLevel == 2) {
        ghostSpeed = 0.06f; 
    }
    else {
        ghostSpeed = 0.085f;
    }                   

    initializeGame(currentLevel); 

    pacman.startX = 1.0f; pacman.startY = 1.0f;
    pacman.dirX = 0; pacman.dirY = 0;
    pacManRotation = 0.0f; 

    ghosts[0].startX = 13.5f; ghosts[0].startY = 7.5f; 
    ghosts[1].startX = 12.9f; ghosts[1].startY = 6.5f; 
    ghosts[2].startX = 13.9f; ghosts[2].startY = 6.5f; 

    for(int i=0; i<3; i++) {
        ghosts[i].dirX = 0; ghosts[i].dirY = 0;
    }

    for(int i=0; i<foodNums; i++) {
        foods[i].active = true;
    }
}

void drawRectangle(float x, float y, float w, float h, float r, float g, float b) {
    glColor3f(r, g, b);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y + h);
        glVertex2f(x, y + h);
    glEnd();
}

void drawCircle(float cx, float cy, float r, int n, float red, float green, float blue) {
    glColor3f(red, green, blue);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
        for (int i = 0; i < n; i++) {
            float theta = 2.0f * 3.1416f * float(i) / float(n);
            float x = r * cos(theta);
            float y = r * sin(theta);
            glVertex2f(x + cx, y + cy);
        }
    glEnd();
}

void drawText(float x, float y, const char* text) {
    glRasterPos2f(x, y);
    for (const char* c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void drawScore(float x, float y, int value) {
    glRasterPos2f(x, y);
    const char* label = "Score: ";
    for (const char* c = label; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
    
    char buffer[20];
    if (value == 0) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
    }
    else {
        int i = 0;
        int temp = value;
        while (temp > 0) {
            buffer[i++] = (temp % 10) + '0';
            temp /= 10;
        }
        while (i > 0) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, buffer[--i]);
        }
    }
}

void update(int value) {
    if (!gameStarted || gamePaused || gameOver) {
        glutPostRedisplay();
        glutTimerFunc(16, update, 0);
        return;
    }

    if (pacman.dirX == 1) {
        pacManRotation = 0.0f;
    }
    else if (pacman.dirX == -1) {
        pacManRotation = 180.0f;
    }
    else if (pacman.dirY == 1) {
        pacManRotation = 90.0f;
    }
    else if (pacman.dirY == -1) {
        pacManRotation = 270.0f;
    }

    if (pacman.dirX != 0 || pacman.dirY != 0) {
        if (mouthOpen) {
            mouthAngle += 5.0f;
            if (mouthAngle >= 45.0f) mouthOpen = false;
        }
        else {
            mouthAngle -= 5.0f;
            if (mouthAngle <= 0.0f) mouthOpen = true;
        }
    }

    float newX = pacman.startX + pacman.dirX * PACMAN_SPEED;
    float newY = pacman.startY + pacman.dirY * PACMAN_SPEED;

    if (!wallCollision(newX, newY, true)) {
        pacman.startX = newX;
        pacman.startY = newY;
    }
    else {
        float gridX = round(pacman.startX);
        float gridY = round(pacman.startY);
        if (fabs(pacman.startX - gridX) < 0.1f) pacman.startX = gridX;
        if (fabs(pacman.startY - gridY) < 0.1f) pacman.startY = gridY;
    }

    float pCenterX = pacman.startX + 0.5f;
    float pCenterY = pacman.startY + 0.5f;
    float rad = pacManRotation * 3.14159f / 180.0f;
    float mouthX = pCenterX + 0.4f * cos(rad);
    float mouthY = pCenterY + 0.4f * sin(rad);

    for (int i = 0; i < foodNums; i++) {
        if (foods[i].active) {
            float dotCx = foods[i].startX + 0.5f;
            float dotCy = foods[i].startY + 0.5f;
            float dx = mouthX - dotCx;
            float dy = mouthY - dotCy;
            float dist = sqrt(dx*dx + dy*dy);

            if (dist < 0.3f) {
                foods[i].active = false;
                score += 2;
                bool allEaten = true;
                for(int j=0; j<foodNums; j++) {
                    if(foods[j].active) { allEaten = false; break; }
                }
                if (allEaten) {
                    gameWon = true; gameOver = true;
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        bool inBox = (ghosts[i].startX > 12.0f && ghosts[i].startX < 15.0f && ghosts[i].startY > 6.0f && ghosts[i].startY < 9.0f);
        
        if (inBox) {
            if (ghosts[i].startX < 13.4f) { ghosts[i].dirX = 1; ghosts[i].dirY = 0; }
            else if (ghosts[i].startX > 13.6f) { ghosts[i].dirX = -1; ghosts[i].dirY = 0; }
            else { ghosts[i].dirX = 0; ghosts[i].dirY = 1; }
        }
        else {
            float nextX = ghosts[i].startX + ghosts[i].dirX * ghostSpeed;
            float nextY = ghosts[i].startY + ghosts[i].dirY * ghostSpeed;
            bool blocked = wallCollision(nextX, nextY, false);
            
            if (blocked || (randomGenerator() % 60 == 0)) {
                int validDirs[4][2];
                int count = 0;
                int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
                
                for(int d=0; d<4; d++) {
                    float testX = ghosts[i].startX + dirs[d][0] * 0.1f;
                    float testY = ghosts[i].startY + dirs[d][1] * 0.1f;
                    if (!wallCollision(testX, testY, false)) {
                        if (dirs[d][0] == -ghosts[i].dirX && dirs[d][1] == -ghosts[i].dirY && count > 0) continue;
                        validDirs[count][0] = dirs[d][0];
                        validDirs[count][1] = dirs[d][1];
                        count++;
                    }
                }

                if (count > 0) {
                    int randIdx = randomGenerator() % count;
                    ghosts[i].dirX = validDirs[randIdx][0];
                    ghosts[i].dirY = validDirs[randIdx][1];
                }
                else {
                    ghosts[i].dirX = -ghosts[i].dirX;
                    ghosts[i].dirY = -ghosts[i].dirY;
                }
            }
        }

        float finalX = ghosts[i].startX + ghosts[i].dirX * ghostSpeed;
        float finalY = ghosts[i].startY + ghosts[i].dirY * ghostSpeed;
        
        if (!wallCollision(finalX, finalY, false)) {
            ghosts[i].startX = finalX;
            ghosts[i].startY = finalY;
        }
        else {
            ghosts[i].startX = round(ghosts[i].startX);
            ghosts[i].startY = round(ghosts[i].startY);
        }

        float dx = pacman.startX - ghosts[i].startX;
        float dy = pacman.startY - ghosts[i].startY;
        float dist = sqrt(dx*dx + dy*dy);
        
        if (dist < 0.8f) { gameOver = true; gameWon = false; }
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL); 
    glShadeModel(GL_SMOOTH); 

    GLfloat light0_position[] = { pacman.startX + 0.5f, pacman.startY + 0.5f, 2.0f, 1.0f };
    GLfloat ambient[] = { 0.01f, 0.01f, 0.01f, 1.0f };  
    GLfloat diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };  
    
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.1f);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.2f);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.1f);
    
    // Walls & Food
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);
    
    for (int i = 0; i < wallNums; i++) {
        drawRectangle(walls[i].startX, walls[i].startY, walls[i].width, walls[i].height, 0.5f, 0.5f, 0.5f); 
    }
    drawRectangle(12.5f, 8.85f, 2.0f, 0.1f, 1.0f, 0.7f, 0.8f); 

    for (int i = 0; i < foodNums; i++) {
        if (foods[i].active) {
            drawRectangle(foods[i].startX + 0.4f, foods[i].startY + 0.4f, 0.2f, 0.2f, 1.0f, 1.0f, 1.0f); 
        }
    }
    glPopMatrix();

    // Characters
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.1f); 

    for (int i = 0; i < 3; i++) {
        drawRectangle(ghosts[i].startX + 0.1f, ghosts[i].startY + 0.1f, 0.8f, 0.8f, ghosts[i].red, ghosts[i].green, ghosts[i].blue);
    }
    
    float cx = pacman.startX + 0.5f;
    float cy = pacman.startY + 0.5f;
    float r = 0.4f;
    glColor3f(1.0f, 1.0f, 0.0f);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
        for (int i = (int)mouthAngle; i <= 360 - (int)mouthAngle; i++) {
            float rad = 3.1416f / 180.0f;
            float theta1 = (i + pacManRotation) * rad;
            float theta2 = (i + 1 + pacManRotation) * rad;
            glVertex2f(cx, cy);
            glVertex2f(cx + r * cos(theta1), cy + r * sin(theta1));
            glVertex2f(cx + r * cos(theta2), cy + r * sin(theta2));
        }
    glEnd();
    glPopMatrix();

    // Ghost Eyes
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.2f); 
    for (int i = 0; i < 3; i++) {
        drawCircle(ghosts[i].startX + 0.35f, ghosts[i].startY + 0.65f, 0.12f, 10, 1.0f, 1.0f, 1.0f);
        drawCircle(ghosts[i].startX + 0.65f, ghosts[i].startY + 0.65f, 0.12f, 10, 1.0f, 1.0f, 1.0f);
    }
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.3f); 
    
    glDisable(GL_LIGHTING);
    for (int i = 0; i < 3; i++) {
        drawCircle(ghosts[i].startX + 0.35f, ghosts[i].startY + 0.65f, 0.05f, 10, 0.0f, 0.0f, 0.0f);
        drawCircle(ghosts[i].startX + 0.65f, ghosts[i].startY + 0.65f, 0.05f, 10, 0.0f, 0.0f, 0.0f);
    }
    glEnable(GL_LIGHTING);
    
    glPopMatrix();

    // Game
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST); 

    glColor3f(1.0f, 1.0f, 1.0f);
    drawScore(0.5f, ROWS - 0.8f, score);

    glColor3f(0.8f, 0.8f, 0.8f);
    drawText(COLS - 4.0f, ROWS - 0.8f, "[F] Pause"); 

    if (!gameStarted) {
        glColor4f(0.0f, 0.0f, 0.0f, 0.9f);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glRectf(COLS/2 - 7, 3, COLS/2 + 7, 12);
        glDisable(GL_BLEND);
        
        glColor3f(1.0f, 1.0f, 0.0f);
        drawText(COLS/2 - 2.5f, 10.0f, "Goriber PACMAN");
        
        glColor3f(1.0f, 1.0f, 1.0f);
        drawText(COLS/2 - 3.0f, 8.5f, "SELECT LEVEL:");
        drawText(COLS/2 - 3.0f, 7.5f, "[1] EASY");
        drawText(COLS/2 - 3.0f, 6.5f, "[2] MEDIUM");
        drawText(COLS/2 - 3.0f, 5.5f, "[3] HARD");
        
        glColor3f(0.7f, 0.7f, 0.7f);
        drawText(COLS/2 - 4.5f, 4.0f, "Press 1, 2, or 3 to Start");
    }
    else if (gameOver) {
        glColor4f(0.0f, 0.0f, 0.0f, 0.85f);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glRectf(COLS/2 - 5, 5, COLS/2 + 5, 10);
        glDisable(GL_BLEND);

        if (gameWon) {
            glColor3f(0.0f, 1.0f, 0.0f);
            drawText(COLS/2 - 1.5f, 9.0f, "YOU WIN!");
        }
        else {
            glColor3f(1.0f, 0.0f, 0.0f);
            drawText(COLS/2 - 2.0f, 9.0f, "GAME OVER");
        }

        glColor3f(1.0f, 1.0f, 1.0f);
        drawText(COLS/2 - 4.0f, 7.5f, "Press [R] to Restart Level");
        drawText(COLS/2 - 4.0f, 6.5f, "Press [M] for Menu");
        drawScore(COLS/2 - 1.0f, 5.5f, score);
    }
    else if (gamePaused) {
        glColor3f(1.0f, 1.0f, 0.0f);
        drawText(COLS/2 - 1.0f, 7.5f, "PAUSED");
    }

    glutSwapBuffers();
    glEnable(GL_DEPTH_TEST);
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 27) exit(0);

    if (!gameStarted) {
        if (key == '1') {
            currentLevel = 1;
            resetGame();
            gameStarted = true;
        }
        else if (key == '2') {
            currentLevel = 2;
            resetGame();
            gameStarted = true;
        }
        else if (key == '3') {
            currentLevel = 3;
            resetGame();
            gameStarted = true;
        }
        return;
    }

    if (gameStarted) {
        if (key == 'f' || key == 'F') {
            gamePaused = !gamePaused;
        }
        
        if (gameOver) {
            if (key == 'r' || key == 'R') {
                resetGame(); 
            }
            else if (key == 'm' || key == 'M') {
                gameStarted = false; 
            }
        }

        if (!gameOver && !gamePaused) {
            switch (key) {
                case 'w': case 'W': 
                    pacman.dirX = 0;
                    pacman.dirY = 1;
                    break;
                case 's': case 'S':
                    pacman.dirX = 0;
                    pacman.dirY = -1;
                    break;
                case 'a': case 'A': 
                    pacman.dirX = -1;
                    pacman.dirY = 0;
                    break;
                case 'd': case 'D':
                    pacman.dirX = 1;
                    pacman.dirY = 0;
                    break;
            }
        }
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow("Goriber PACMAN");
    
    startRandom(time(0)); 
    glClearColor(0.0f, 0.0f, 0.2f, 1.0f); 
    
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, COLS, 0, ROWS); 

    glShadeModel(GL_SMOOTH); 

    initializeGame(1); 

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}