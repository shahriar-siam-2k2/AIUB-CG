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

        glVertex2f(x+0.05f*s, y+0.03f*s); //+G1
        glVertex2f(x+0.03f*s, y+0.00f*s); //+Z
        glVertex2f(x+0.04f*s, y+0.06f*s); //+A1
        glVertex2f(x+0.06f*s, y+0.06f*s); //+F1

        glVertex2f(x+0.06f*s, y+0.06f*s); //+F1
        glVertex2f(x+0.04f*s, y+0.06f*s); //+A1
        glVertex2f(x+0.08f*s, y+0.14f*s); //+B1
        glVertex2f(x+0.10f*s, y+0.13f*s); //+E1

        glVertex2f(x+0.10f*s, y+0.13f*s); //+E1
        glVertex2f(x+0.08f*s, y+0.14f*s); //+B1
        glVertex2f(x+0.14f*s, y+0.21f*s); //+C1
        glVertex2f(x+0.15f*s, y+0.20f*s); //+D1

    glEnd();

    // Right Trunk-2

    glColor3f(0.18431f, 0.12941f, 0.60392f);

    glBegin(GL_QUADS);

        glVertex2f(x+0.03f*s, y+0.00f*s); //+Z
        glVertex2f(x+0.04f*s, y+0.00f*s); //+O1
        glVertex2f(x+0.05f*s, y+0.02f*s); //+N1
        glVertex2f(x+0.05f*s, y+0.03f*s); //+G1

        glVertex2f(x+0.05f*s, y+0.03f*s); //+G1
        glVertex2f(x+0.05f*s, y+0.02f*s); //+N1
        glVertex2f(x+0.10f*s, y+0.07f*s); //+M1
        glVertex2f(x+0.10f*s, y+0.08f*s); //+H1

        glVertex2f(x+0.10f*s, y+0.08f*s); //+H1
        glVertex2f(x+0.10f*s, y+0.07f*s); //+M1
        glVertex2f(x+0.16f*s, y+0.10f*s); //+L1
        glVertex2f(x+0.16f*s, y+0.11f*s); //+I1

        glVertex2f(x+0.16f*s, y+0.11f*s); //+I1
        glVertex2f(x+0.16f*s, y+0.10f*s); //+L1
        glVertex2f(x+0.21f*s, y+0.11f*s); //+K1
        glVertex2f(x+0.21f*s, y+0.12f*s); //+J1

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

    // Leaf - Trunk-2 - Left

    glColor3f(0.00392f, 0.74902f, 0.60000f);

    glBegin(GL_QUADS);

        glVertex2f(x-0.08f*s, y+0.05f*s); //K3
        glVertex2f(x-0.13f*s, y+0.08f*s); //S3
        glVertex2f(x-0.16f*s, y+0.08f*s); //R3
        glVertex2f(x-0.12f*s, y+0.03f*s); //L3

        glVertex2f(x-0.12f*s, y+0.03f*s); //L3
        glVertex2f(x-0.16f*s, y+0.08f*s); //R3
        glVertex2f(x-0.20f*s, y+0.07f*s); //Q3
        glVertex2f(x-0.16f*s, y+0.02f*s); //M3

        glVertex2f(x-0.16f*s, y+0.02f*s); //M3
        glVertex2f(x-0.20f*s, y+0.03f*s); //O3
        glVertex2f(x-0.22f*s, y+0.05f*s); //P3
        glVertex2f(x-0.20f*s, y+0.07f*s); //Q3

    glEnd();

    // Leaf - Trunk-2 - Right

    glColor3f(0.00392f, 0.74902f, 0.60000f);

    glBegin(GL_QUADS);

        glVertex2f(x+0.08f*s, y+0.05f*s); //+K3
        glVertex2f(x+0.13f*s, y+0.08f*s); //+S3
        glVertex2f(x+0.16f*s, y+0.08f*s); //+R3
        glVertex2f(x+0.12f*s, y+0.03f*s); //+L3

        glVertex2f(x+0.12f*s, y+0.03f*s); //+L3
        glVertex2f(x+0.16f*s, y+0.08f*s); //+R3
        glVertex2f(x+0.20f*s, y+0.07f*s); //+Q3
        glVertex2f(x+0.16f*s, y+0.02f*s); //+M3

        glVertex2f(x+0.16f*s, y+0.02f*s); //+M3
        glVertex2f(x+0.20f*s, y+0.03f*s); //+O3
        glVertex2f(x+0.22f*s, y+0.05f*s); //+P3
        glVertex2f(x+0.20f*s, y+0.07f*s); //+Q3

    glEnd();



    // Flowers


    // Middle Flower

    glColor3f(1.00000f, 0.20784f, 0.73333f);

    glBegin(GL_POLYGON);

        glVertex2f(x-0.04f*s, y+0.32f*s); //K4
        glVertex2f(x-0.10f*s, y+0.38f*s); //U4
        glVertex2f(x-0.10f*s, y+0.42f*s); //W4
        glVertex2f(x-0.09f*s, y+0.43f*s); //Z4
        glVertex2f(x-0.06f*s, y+0.42f*s); //A5
        glVertex2f(x-0.04f*s, y+0.40f*s); //B5
        glVertex2f(x-0.03f*s, y+0.44f*s); //C5
        glVertex2f(x-0.01f*s, y+0.46f*s); //D5
        glVertex2f(x-0.00f*s, y+0.47f*s); //E5
        glVertex2f(x+0.01f*s, y+0.46f*s); //F5
        glVertex2f(x+0.03f*s, y+0.44f*s); //G5
        glVertex2f(x+0.04f*s, y+0.40f*s); //H5
        glVertex2f(x+0.06f*s, y+0.42f*s); //I5
        glVertex2f(x+0.08f*s, y+0.43f*s); //J5
        glVertex2f(x+0.09f*s, y+0.43f*s); //K5
        glVertex2f(x+0.10f*s, y+0.42f*s); //L5
        glVertex2f(x+0.10f*s, y+0.38f*s); //M5
        glVertex2f(x+0.04f*s, y+0.32f*s); //V4
        
    glEnd();

    // Right Upper Flower

    glColor3f(1.00000f, 0.20784f, 0.73333f);

    glBegin(GL_POLYGON);

        glVertex2f(x+0.15f*s, y+0.26f*s); //I6
        glVertex2f(x+0.14f*s, y+0.29f*s); //V6
        glVertex2f(x+0.13f*s, y+0.31f*s); //W6
        glVertex2f(x+0.14f*s, y+0.34f*s); //Z6
        glVertex2f(x+0.15f*s, y+0.36f*s); //A7
        glVertex2f(x+0.17f*s, y+0.38f*s); //B7
        glVertex2f(x+0.19f*s, y+0.37f*s); //C7
        glVertex2f(x+0.20f*s, y+0.35f*s); //D7
        glVertex2f(x+0.21f*s, y+0.32f*s); //E7
        glVertex2f(x+0.23f*s, y+0.34f*s); //F7
        glVertex2f(x+0.25f*s, y+0.35f*s); //G7
        glVertex2f(x+0.27f*s, y+0.34f*s); //H7
        glVertex2f(x+0.28f*s, y+0.33f*s); //I7
        glVertex2f(x+0.28f*s, y+0.30f*s); //J7
        glVertex2f(x+0.27f*s, y+0.28f*s); //K7
        glVertex2f(x+0.30f*s, y+0.28f*s); //L7
        glVertex2f(x+0.32f*s, y+0.27f*s); //M7
        glVertex2f(x+0.33f*s, y+0.26f*s); //N7
        glVertex2f(x+0.32f*s, y+0.24f*s); //O7
        glVertex2f(x+0.28f*s, y+0.21f*s); //P7
        glVertex2f(x+0.24f*s, y+0.20f*s); //Q7
        glVertex2f(x+0.21f*s, y+0.21f*s); //T6
        
    glEnd();

    // Left Upper Flower Dark Lavender

    glColor3f(0.74118f, 0.33725f, 0.90196f);

    glBegin(GL_POLYGON);

        glVertex2f(x-0.20f*s, y+0.22f*s); //J2
        glVertex2f(x-0.21f*s, y+0.21f*s); //H2
        glVertex2f(x-0.26f*s, y+0.21f*s); //Q2
        glVertex2f(x-0.30f*s, y+0.22f*s); //R2
        glVertex2f(x-0.33f*s, y+0.26f*s); //S2
        glVertex2f(x-0.32f*s, y+0.28f*s); //T2
        glVertex2f(x-0.30f*s, y+0.28f*s); //U2
        glVertex2f(x-0.26f*s, y+0.28f*s); //V2
        glVertex2f(x-0.27f*s, y+0.32f*s); //W2
        glVertex2f(x-0.27f*s, y+0.34f*s); //Z2
        glVertex2f(x-0.26f*s, y+0.35f*s); //A3
        glVertex2f(x-0.24f*s, y+0.34f*s); //B3
        glVertex2f(x-0.20f*s, y+0.32f*s); //C3
        glVertex2f(x-0.18f*s, y+0.28f*s); //J3
        glVertex2f(x-0.18f*s, y+0.25f*s); //L2
        
    glEnd();

    // Left Upper Flower Light Lavender

    glColor3f(0.89412f, 0.50980f, 0.95294f);

    glBegin(GL_POLYGON);

        glVertex2f(x-0.18f*s, y+0.25f*s); //L2
        glVertex2f(x-0.18f*s, y+0.28f*s); //J3
        glVertex2f(x-0.20f*s, y+0.32f*s); //C3
        glVertex2f(x-0.20f*s, y+0.35f*s); //D3
        glVertex2f(x-0.18f*s, y+0.37f*s); //E3
        glVertex2f(x-0.17f*s, y+0.37f*s); //F3
        glVertex2f(x-0.15f*s, y+0.36f*s); //G3
        glVertex2f(x-0.13f*s, y+0.32f*s); //H3
        glVertex2f(x-0.14f*s, y+0.28f*s); //I3
        glVertex2f(x-0.15f*s, y+0.26f*s); //O2
        
    glEnd();

    // Left Bottom Flower

    glColor3f(1.00000f, 0.14118f, 0.39216f);

    glBegin(GL_POLYGON);

        glVertex2f(x-0.24f*s, y+0.10f*s); //Q1
        glVertex2f(x-0.27f*s, y+0.08f*s); //F2
        glVertex2f(x-0.30f*s, y+0.08f*s); //E2
        glVertex2f(x-0.32f*s, y+0.08f*s); //D2
        glVertex2f(x-0.33f*s, y+0.10f*s); //C2
        glVertex2f(x-0.30f*s, y+0.13f*s); //B2
        glVertex2f(x-0.33f*s, y+0.16f*s); //A2
        glVertex2f(x-0.31f*s, y+0.18f*s); //Z1
        glVertex2f(x-0.28f*s, y+0.18f*s); //W1
        glVertex2f(x-0.24f*s, y+0.16f*s); //V1
        glVertex2f(x-0.23f*s, y+0.14f*s); //N3
        
    glEnd();
    
    // Right Bottom Flower

    glColor3f(1.00000f, 0.14118f, 0.39216f);

    glBegin(GL_POLYGON);

        glVertex2f(x+0.24f*s, y+0.10f*s); //+Q1
        glVertex2f(x+0.27f*s, y+0.08f*s); //+F2
        glVertex2f(x+0.30f*s, y+0.08f*s); //+E2
        glVertex2f(x+0.32f*s, y+0.08f*s); //+D2
        glVertex2f(x+0.33f*s, y+0.10f*s); //+C2
        glVertex2f(x+0.30f*s, y+0.13f*s); //+B2
        glVertex2f(x+0.33f*s, y+0.16f*s); //+A2
        glVertex2f(x+0.31f*s, y+0.18f*s); //+Z1
        glVertex2f(x+0.28f*s, y+0.18f*s); //+W1
        glVertex2f(x+0.24f*s, y+0.16f*s); //+V1
        glVertex2f(x+0.23f*s, y+0.14f*s); //+N3
        
    glEnd();
    

    // Sepals



    // Middle Pink Flower Sepal

    glColor3f(0.56471f, 0.13333f, 0.87059f);

    glBegin(GL_POLYGON);

        glVertex2f(x-0.01f*s, y+0.28f*s); //U
        glVertex2f(x+0.01f*s, y+0.28f*s); //V
        glVertex2f(x+0.04f*s, y+0.32f*s); //V4
        glVertex2f(x+0.04f*s, y+0.33f*s); //T4
        glVertex2f(x+0.03f*s, y+0.34f*s); //S4
        glVertex2f(x+0.02f*s, y+0.33f*s); //R4
        glVertex2f(x+0.01f*s, y+0.34f*s); //Q4
        glVertex2f(x-0.00f*s, y+0.34f*s); //P4
        glVertex2f(x-0.01f*s, y+0.34f*s); //O4
        glVertex2f(x-0.02f*s, y+0.33f*s); //N4
        glVertex2f(x-0.03f*s, y+0.34f*s); //M4
        glVertex2f(x-0.04f*s, y+0.33f*s); //L4
        glVertex2f(x-0.04f*s, y+0.32f*s); //K4

    glEnd();

    // Left Pink Flower Sepal

    glColor3f(0.56471f, 0.13333f, 0.87059f);

    glBegin(GL_POLYGON);

        glVertex2f(x-0.21f*s, y+0.11f*s); //K1
        glVertex2f(x-0.21f*s, y+0.12f*s); //J1
        glVertex2f(x-0.22f*s, y+0.14f*s); //J1
        glVertex2f(x-0.24f*s, y+0.15f*s); //T1
        glVertex2f(x-0.25f*s, y+0.13f*s); //S1
        glVertex2f(x-0.25f*s, y+0.12f*s); //R1
        glVertex2f(x-0.24f*s, y+0.10f*s); //Q1
        glVertex2f(x-0.22f*s, y+0.10f*s); //P1

    glEnd();

    // Right Pink Flower Sepal

    glColor3f(0.56471f, 0.13333f, 0.87059f);

    glBegin(GL_POLYGON);

        glVertex2f(x+0.21f*s, y+0.11f*s); //+K1
        glVertex2f(x+0.21f*s, y+0.12f*s); //+J1
        glVertex2f(x+0.22f*s, y+0.14f*s); //+J1
        glVertex2f(x+0.24f*s, y+0.15f*s); //+T1
        glVertex2f(x+0.25f*s, y+0.13f*s); //+S1
        glVertex2f(x+0.25f*s, y+0.12f*s); //+R1
        glVertex2f(x+0.24f*s, y+0.10f*s); //+Q1
        glVertex2f(x+0.22f*s, y+0.10f*s); //+P1

    glEnd();

    // Left Purple Flower Sepal

    glColor3f(0.56471f, 0.13333f, 0.87059f);

    glBegin(GL_POLYGON);

        glVertex2f(x-0.15f*s, y+0.20f*s); //D1
        glVertex2f(x-0.14f*s, y+0.21f*s); //C1
        glVertex2f(x-0.14f*s, y+0.24f*s); //P2
        glVertex2f(x-0.14f*s, y+0.26f*s); //O2
        glVertex2f(x-0.16f*s, y+0.27f*s); //N2
        glVertex2f(x-0.18f*s, y+0.26f*s); //M2
        glVertex2f(x-0.18f*s, y+0.25f*s); //L2
        glVertex2f(x-0.20f*s, y+0.25f*s); //K2
        glVertex2f(x-0.20f*s, y+0.22f*s); //J2
        glVertex2f(x-0.21f*s, y+0.22f*s); //I2
        glVertex2f(x-0.21f*s, y+0.21f*s); //H2
        glVertex2f(x-0.18f*s, y+0.20f*s); //G2

    glEnd();

    // Right Purple Flower Sepal

    glColor3f(0.56471f, 0.13333f, 0.87059f);

    glBegin(GL_POLYGON);

        glVertex2f(x+0.15f*s, y+0.20f*s); //+D1
        glVertex2f(x+0.14f*s, y+0.21f*s); //+C1
        glVertex2f(x+0.14f*s, y+0.24f*s); //+P2
        glVertex2f(x+0.14f*s, y+0.26f*s); //+O2
        glVertex2f(x+0.16f*s, y+0.27f*s); //+N2
        glVertex2f(x+0.18f*s, y+0.26f*s); //+M2
        glVertex2f(x+0.18f*s, y+0.25f*s); //+L2
        glVertex2f(x+0.20f*s, y+0.25f*s); //+K2
        glVertex2f(x+0.20f*s, y+0.22f*s); //+J2
        glVertex2f(x+0.21f*s, y+0.22f*s); //+I2
        glVertex2f(x+0.21f*s, y+0.21f*s); //+H2
        glVertex2f(x+0.18f*s, y+0.20f*s); //+G2

    glEnd();

    
    glFlush();

}

void display() {

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    vase(0.0f, -0.1f, 2);

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
