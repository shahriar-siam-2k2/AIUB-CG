#include <GL/glut.h>
#include <cmath>
#include <cstdlib> 
#include <ctime>   

// --- Constants ---
const int ROWS = 15;
const int COLS = 15;
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const float SPEED = 0.1f;
const float GHOST_SPEED = 0.05f;

// --- Globals ---
int score = 0;
bool gameOver = false;
bool gameWon = false;
bool gameStarted = false; // Game starts on first input
bool gamePaused = false;  // Toggle with 'F'

// --- Coordinate-Based Map Data ---
struct Wall {
    float x, y, w, h;
};

struct Dot {
    float x, y;
    bool active;
};

const int MAX_WALLS = 100;
const int MAX_FOODS = 200;

Wall walls[MAX_WALLS];
int wallNums = 0;

Dot foods[MAX_FOODS];
int foodNums = 0;

// --- Structures ---
struct Entity {
    float x, y;     
    int dirX, dirY; 
    float r, g, b;  
};

// Start positions
Entity pacman = {1.0f, 1.0f, 0, 0, 1.0f, 1.0f, 0.0f}; 
Entity ghosts[3] = {
    {7.0f, 7.8f, 0, 1, 1.0f, 0.0f, 0.0f}, // Red 
    {6.5f, 7.0f, 0, 1, 0.0f, 1.0f, 1.0f}, // Cyan 
    {7.5f, 7.0f, 0, 1, 1.0f, 0.7f, 0.8f}  // Pink 
};

// --- Helper Functions ---

void addWall(float x, float y, float w, float h) {
    if (wallNums < MAX_WALLS) {
        walls[wallNums] = {x, y, w, h};
        wallNums++;
    }
}

// Added isPacman parameter to apply special collision rules for the player
bool checkWallCollision(float x, float y, bool isPacman = false) {
    float size = 0.65f; 
    
    // 1. Check Standard Walls
    for (int i = 0; i < wallNums; i++) {
        if (x < walls[i].x + walls[i].w &&
            x + size > walls[i].x &&
            y < walls[i].y + walls[i].h &&
            y + size > walls[i].y) {
            return true;
        }
    }

    // 2. Ghost House Gate Check (Only for Pacman)
    // The gate is the gap at the top of the box: x=6.5 to 8.5, y=8.8
    if (isPacman) {
        if (x < 8.5f && x + size > 6.5f &&
            y < 9.0f && y + size > 8.8f) {
            return true;
        }
    }

    return false;
}

void initLevel() {
    wallNums = 0;
    foodNums = 0;

    // 1. Define Walls (x, y, width, height)
    // Outer Borders
    addWall(0, 0, 15, 1);   
    addWall(0, 14, 15, 1);  
    addWall(0, 0, 1, 15);   
    addWall(14, 0, 1, 15);  

    // Inner Obstacles
    addWall(2, 2, 2, 2);
    addWall(11, 2, 2, 2);
    addWall(2, 11, 2, 2);
    addWall(11, 11, 2, 2);
    
    // Ghost House (Hollow Box)
    // Bottom
    addWall(6, 6, 3, 0.2);   
    
    // Top - OPENING A WIDER GAP (6.5 to 8.5 is open now)
    addWall(6, 8.8, 0.5, 0.2);   // Short Top Left piece
    addWall(8.5, 8.8, 0.5, 0.2); // Short Top Right piece
    
    // Sides
    addWall(6, 6, 0.2, 3);   // Left
    addWall(8.8, 6, 0.2, 3); // Right
    
    addWall(6, 1, 3, 2); // Bottom Center
    addWall(6, 12, 3, 2); // Top Center
    
    addWall(1, 7, 2, 1); // Left mid strip
    addWall(12, 7, 2, 1); // Right mid strip

    // 2. Generate foods
    for (int y = 1; y < 14; y++) {
        for (int x = 1; x < 14; x++) {
            // Skip ghost house area
            if (x >= 6 && x <= 8 && y >= 6 && y <= 8) continue;

            if (!checkWallCollision((float)x, (float)y)) {
                if (foodNums < MAX_FOODS) {
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
    
    pacman.x = 1.0f; pacman.y = 1.0f;
    pacman.dirX = 0; pacman.dirY = 0;

    ghosts[0] = {7.0f, 7.0f, 0, 1, 1.0f, 0.0f, 0.0f};
    ghosts[1] = {6.5f, 7.0f, 0, 1, 0.0f, 1.0f, 1.0f};
    ghosts[2] = {7.5f, 7.0f, 0, 1, 1.0f, 0.7f, 0.8f};

    for(int i=0; i<foodNums; i++) {
        foods[i].active = true;
    }
}

void drawRect(float x, float y, float w, float h, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + w, y);
    glVertex2f(x + w, y + h);
    glVertex2f(x, y + h);
    glEnd();
}

void drawCircle(float cx, float cy, float r, int segments, float red, float green, float blue) {
    glColor3f(red, green, blue);
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
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

void drawScoreText(float x, float y, int value) {
    glRasterPos2f(x, y);
    const char* label = "Score: ";
    for (const char* c = label; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
    
    if (value == 0) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');
        return;
    }
    
    char buffer[20];
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

// --- Main Game Logic ---

void update(int value) {
    // Stop updates if game hasn't started, is paused, or ended
    if (!gameStarted || gamePaused || gameOver) {
        glutPostRedisplay(); 
        glutTimerFunc(100, update, 0); 
        return;
    }

    // --- Update Pacman ---
    float newX = pacman.x + pacman.dirX * SPEED;
    float newY = pacman.y + pacman.dirY * SPEED;

    // Pass true for isPacman to check against the Ghost House Gate
    if (!checkWallCollision(newX, newY, true)) {
        pacman.x = newX;
        pacman.y = newY;
    }

    // Eat foods
    float pCenterX = pacman.x + 0.5f;
    float pCenterY = pacman.y + 0.5f;

    for (int i = 0; i < foodNums; i++) {
        if (foods[i].active) {
            float dx = pCenterX - (foods[i].x + 0.5f);
            float dy = pCenterY - (foods[i].y + 0.5f);
            float dist = sqrt(dx*dx + dy*dy);

            if (dist < 0.5f) { 
                foods[i].active = false;
                score += 2;
                
                // Check Victory
                bool allEaten = true;
                for(int j=0; j<foodNums; j++) {
                    if(foods[j].active) {
                        allEaten = false;
                        break;
                    }
                }
                
                if (allEaten) {
                    gameWon = true;
                    gameOver = true;
                }
            }
        }
    }

    // --- Update Ghosts ---
    for (int i = 0; i < 3; i++) {
        
        // 1. EXIT HOUSE LOGIC
        bool inBox = (ghosts[i].x > 6.0f && ghosts[i].x < 9.0f && ghosts[i].y > 6.0f && ghosts[i].y < 9.0f);
        
        if (inBox) {
            // Funnel them to the center X (7.5) then move UP
            if (ghosts[i].x < 7.2f) {
                ghosts[i].dirX = 1; ghosts[i].dirY = 0;
            }
            else if (ghosts[i].x > 7.8f) {
                ghosts[i].dirX = -1; ghosts[i].dirY = 0;
            }
            else {
                ghosts[i].dirX = 0; ghosts[i].dirY = 1; // UP towards exit
            }
        }
        else {
            // 2. STANDARD RANDOM MOVEMENT
            float nextX = ghosts[i].x + ghosts[i].dirX * GHOST_SPEED;
            float nextY = ghosts[i].y + ghosts[i].dirY * GHOST_SPEED;
            
            // Pass false for isPacman (Ghosts can ignore the gate)
            if (checkWallCollision(nextX, nextY, false) || (rand() % 40 == 0)) {
                int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
                int randIdx = rand() % 4;
                ghosts[i].dirX = dirs[randIdx][0];
                ghosts[i].dirY = dirs[randIdx][1];
            }
        }

        // Apply Movement
        float finalX = ghosts[i].x + ghosts[i].dirX * GHOST_SPEED;
        float finalY = ghosts[i].y + ghosts[i].dirY * GHOST_SPEED;
        
        // Check collision (isPacman = false)
        if (!checkWallCollision(finalX, finalY, false)) {
            ghosts[i].x = finalX;
            ghosts[i].y = finalY;
        }

        // Collision with Pacman
        float dx = pacman.x - ghosts[i].x;
        float dy = pacman.y - ghosts[i].y;
        float dist = sqrt(dx*dx + dy*dy);
        
        if (dist < 0.8f) {
            gameOver = true;
            gameWon = false;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0); 
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // --- Draw Game Render ---

    // Walls
    for (int i = 0; i < wallNums; i++) {
        drawRect(walls[i].x, walls[i].y, walls[i].w, walls[i].h, 0.1f, 0.1f, 0.6f); 
    }

    // Ghost House Gate Line
    drawRect(6.5f, 8.85f, 2.0f, 0.1f, 1.0f, 0.7f, 0.8f); 

    // foods
    for (int i = 0; i < foodNums; i++) {
        if (foods[i].active) {
            drawRect(foods[i].x + 0.4f, foods[i].y + 0.4f, 0.2f, 0.2f, 1.0f, 1.0f, 1.0f); 
        }
    }

    // Ghosts
    for (int i = 0; i < 3; i++) {
        // Body
        drawRect(ghosts[i].x + 0.1f, ghosts[i].y + 0.1f, 0.8f, 0.8f, ghosts[i].r, ghosts[i].g, ghosts[i].b);
        
        // Eyes (Whites)
        drawCircle(ghosts[i].x + 0.35f, ghosts[i].y + 0.65f, 0.12f, 10, 1.0f, 1.0f, 1.0f);
        drawCircle(ghosts[i].x + 0.65f, ghosts[i].y + 0.65f, 0.12f, 10, 1.0f, 1.0f, 1.0f);

        // Pupils (Blue) - Fixed position
        drawCircle(ghosts[i].x + 0.35f, ghosts[i].y + 0.65f, 0.05f, 10, 0.0f, 0.0f, 1.0f);
        drawCircle(ghosts[i].x + 0.65f, ghosts[i].y + 0.65f, 0.05f, 10, 0.0f, 0.0f, 1.0f);
    }

    // Pacman
    drawCircle(pacman.x + 0.5f, pacman.y + 0.5f, 0.4f, 20, 1.0f, 1.0f, 0.0f);

    // UI
    glColor3f(1.0f, 1.0f, 1.0f);
    drawScoreText(0.5f, ROWS - 0.8f, score);

    // Pause Hint (Top Middle)
    glColor3f(0.8f, 0.8f, 0.8f);
    drawText(4.5f, 14.5f, "Press F key to Pause the game");

    // --- Overlays ---

    // 1. Start Screen
    if (!gameStarted) {
        // Draw overlay box
        glColor4f(0.0f, 0.0f, 0.0f, 0.75f);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glRectf(3, 5, 12, 10);
        glDisable(GL_BLEND);

        // Draw Text
        glColor3f(1.0f, 1.0f, 0.0f); 
        drawText(5.5f, 9.0f, "Goriber PACMAN");
        
        glColor3f(1.0f, 1.0f, 1.0f);
        drawText(3.5f, 7.0f, "Press W, A, S, D key to start");
        drawText(4.5f, 6.0f, "Press ESC key to Exit");
    }
    // 2. Pause Overlay
    else if (gamePaused) {
        glColor3f(1.0f, 1.0f, 0.0f);
        drawText(6.5f, 7.5f, "PAUSED");
    }
    // 3. Game Over Overlay
    else if (gameOver) {
        glColor4f(0.0f, 0.0f, 0.0f, 0.75f);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glRectf(3, 5, 12, 10);
        glDisable(GL_BLEND);

        if (gameWon) {
            glColor3f(0.0f, 1.0f, 0.0f); // Green for Win
            drawText(5.8f, 9.0f, "YOU WIN!");
        } else {
            glColor3f(1.0f, 0.0f, 0.0f); // Red for Loss
            drawText(5.5f, 9.0f, "GAME OVER");
        }
        
        glColor3f(1.0f, 1.0f, 1.0f);
        drawText(4.5f, 7.5f, "Press 'R' to Play Again");

        // Show Final Score below text
        drawScoreText(5.5f, 6.0f, score);
    }

    glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
    // Controls moved to WASD in keyboard() function
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 27) exit(0); // ESC to Exit

    // --- Start Game Logic ---
    if (!gameStarted) {
        if (key == 'w' || key == 'W' || key == 'a' || key == 'A' || 
            key == 's' || key == 'S' || key == 'd' || key == 'D') {
            gameStarted = true;
            // Don't return, allow the key to set direction below
        } else {
            return; // Ignore other keys on start screen
        }
    }

    // --- Game Controls ---
    if (gameStarted) {
        // Toggle Pause
        if (key == 'f' || key == 'F') {
            gamePaused = !gamePaused;
        }

        // Restart
        if ((key == 'r' || key == 'R') && gameOver) {
            resetGame();
        }

        // Movement (Only if playing)
        if (!gameOver && !gamePaused) {
            switch (key) {
                case 'w': case 'W': pacman.dirX = 0; pacman.dirY = 1; break;
                case 's': case 'S': pacman.dirX = 0; pacman.dirY = -1; break;
                case 'a': case 'A': pacman.dirX = -1; pacman.dirY = 0; break;
                case 'd': case 'D': pacman.dirX = 1; pacman.dirY = 0; break;
            }
        }
    }
}

void init() {
    srand(time(0)); 
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, COLS, 0, ROWS); 

    initLevel(); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    glutCreateWindow("Simple Pacman");

    init();

    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);

    glutMainLoop();
    return 0;
}