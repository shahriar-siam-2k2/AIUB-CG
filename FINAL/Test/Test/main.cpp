// main.cpp
// 2-D Bike Racing – OpenGL 3.3 Core, GLUT, gamma correct
// Code::Blocks project, relative paths only
//----------------------------------------------------------
#include <GL/glew.h>          // will be found in ./include/GL/
#include <GL/freeglut.h>      // ditto
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// ---------- build-time linking for CB convenience ----------
#ifdef _WIN32
#pragma comment(lib,"lib/glew32.lib")
#pragma comment(lib,"lib/freeglut.lib")
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"winmm.lib")      // freeglut needs it
#pragma comment(lib,"gdi32.lib")
#endif

// ---------- config ----------
constexpr int WIN_W = 800;
constexpr int WIN_H = 600;
constexpr float ROAD_V = 0.15f;
constexpr float GRAV   = 0.35f;
constexpr float JUMP_V = -12.0f;
constexpr float MAX_SPD = 12.0f;
// ----------------------------

struct Sprite {
    GLuint vao=0,vbo=0,tex=0;
    int w=0,h=0;
    void load(const char* file);
    void draw(const glm::mat4& mvp) const;
};

struct Bike {
    glm::vec2 pos{0.0f,-0.75f};
    glm::vec2 vel{0.0f,0.0f};
    int lane=1;
    bool grounded=true;
    Sprite* sprite=nullptr;
    void update(float dt);
    glm::mat4 model() const;
};

struct Obstacle {
    glm::vec2 pos;
    Sprite* sprite=nullptr;
    bool alive=true;
    glm::mat4 model() const;
};

// ---------- globals ----------
GLuint prog;
glm::mat4 proj;
Bike player;
std::vector<Obstacle> obs;
float worldSpeed=6.0f;
int score=0;
float roadOff=0.0f;
// ----------------------------

static void chk(const char* op){
    GLenum err=glGetError();
    if(err!=GL_NO_ERROR){ fprintf(stderr,"[%s] GL err 0x%x\n",op,err); exit(1); }
}

static GLuint makeShader(GLenum type,const char* src){
    GLuint s=glCreateShader(type);
    glShaderSource(s,1,&src,nullptr);
    glCompileShader(s);
    GLint ok; glGetShaderiv(s,GL_COMPILE_STATUS,&ok);
    if(!ok){ char log[512]; glGetShaderInfoLog(s,512,nullptr,log); fputs(log,stderr); exit(1); }
    return s;
}

static void createProgram(){
    const char* vsrc=R"(
#version 330 core
layout(location=0) in vec2 aPos;
layout(location=1) in vec2 aUV;
uniform mat4 uMVP;
out vec2 vUV;
void main(){
    gl_Position=uMVP*vec4(aPos,0.0,1.0);
    vUV=aUV;
})";
    const char* fsrc=R"(
#version 330 core
in vec2 vUV;
uniform sampler2D uTex;
out vec4 frag;
void main(){
    vec4 c=texture(uTex,vUV);
    frag=vec4(c.rgb,c.a);
})";
    GLuint vs=makeShader(GL_VERTEX_SHADER,vsrc);
    GLuint fs=makeShader(GL_FRAGMENT_SHADER,fsrc);
    prog=glCreateProgram();
    glAttachShader(prog,vs); glAttachShader(prog,fs);
    glLinkProgram(prog);
    glDeleteShader(vs); glDeleteShader(fs);
    glUseProgram(prog);
}

void Sprite::load(const char* file){
    int comp;
    unsigned char* data=stbi_load(file,&w,&h,&comp,4);
    if(!data){ fprintf(stderr,"Cannot load %s\n",file); exit(1); }
    glGenTextures(1,&tex);
    glBindTexture(GL_TEXTURE_2D,tex);
    glTexImage2D(GL_TEXTURE_2D,0,GL_SRGB8_ALPHA8,w,h,0,GL_RGBA,GL_UNSIGNED_BYTE,data);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);

    float verts[]={
        -0.5f,-0.5f, 0,1,
         0.5f,-0.5f, 1,1,
         0.5f, 0.5f, 1,0,
        -0.5f, 0.5f, 0,0
    };
    glGenVertexArrays(1,&vao);
    glGenBuffers(1,&vbo);
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glBufferData(GL_ARRAY_BUFFER,sizeof(verts),verts,GL_STATIC_DRAW);
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,4*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,4*sizeof(float),(void*)(2*sizeof(float)));
    glEnableVertexAttribArray(1);
}

void Sprite::draw(const glm::mat4& mvp) const {
    glBindTexture(GL_TEXTURE_2D,tex);
    glUniformMatrix4fv(glGetUniformLocation(prog,"uMVP"),1,GL_FALSE,&mvp[0][0]);
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLE_FAN,0,4);
}

// ---------------- physics ----------------
glm::mat4 Bike::model() const {
    glm::mat4 m(1.0f);
    m=glm::translate(m,glm::vec3(pos,0.0f));
    float sx=0.25f*sprite->w/float(WIN_W), sy=0.25f*sprite->h/float(WIN_H);
    m=glm::scale(m,glm::vec3(sx,sy,1.0f));
    return m;
}
void Bike::update(float dt){
    if(!grounded){
        vel.y+=GRAV*dt*60.0f;
        pos.y+=vel.y*dt;
        if(pos.y>=-0.75f){ pos.y=-0.75f; vel.y=0; grounded=true; }
    }
}
glm::mat4 Obstacle::model() const {
    glm::mat4 m(1.0f);
    m=glm::translate(m,glm::vec3(pos,0.0f));
    float sx=0.25f*sprite->w/float(WIN_W), sy=0.25f*sprite->h/float(WIN_H);
    m=glm::scale(m,glm::vec3(sx,sy,1.0f));
    return m;
}

static Sprite roadSpr, bikeSpr, obsSpr;

// ---------------- GLUT ----------------
void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    roadOff+=ROAD_V*worldSpeed/6.0f; if(roadOff>1.0f) roadOff-=1.0f;
    glm::mat4 m=glm::scale(glm::mat4(1.0f),glm::vec3(2.0f,2.0f,1.0f));
    m=glm::translate(m,glm::vec3(0.0f,-roadOff,0.0f));
    roadSpr.draw(proj*m);

    bikeSpr.draw(proj*player.model());

    for(auto& o:obs) if(o.alive) obsSpr.draw(proj*o.model());

    glutSwapBuffers();
}
void timer(int){
    static int last=glutGet(GLUT_ELAPSED_TIME);
    int now=glutGet(GLUT_ELAPSED_TIME);
    float dt=(now-last)/1000.0f; last=now;

    // input
    if(GetAsyncKeyState(VK_ESCAPE)&0x8000) exit(0);
    if(GetAsyncKeyState(VK_LEFT)&0x8000  && player.lane>0)
        { player.lane--; player.pos.x=-0.5f+player.lane*0.5f; Sleep(150); }
    if(GetAsyncKeyState(VK_RIGHT)&0x8000 && player.lane<2)
        { player.lane++; player.pos.x=-0.5f+player.lane*0.5f; Sleep(150); }
    if(GetAsyncKeyState(VK_SPACE)&0x8000 && player.grounded)
        { player.vel.y=JUMP_V; player.grounded=false; Sleep(150); }

    player.update(dt);

    for(auto& o:obs){
        o.pos.y+=worldSpeed*dt;
        if(o.pos.y>1.2f){ o.pos.y=-1.2f-(rand()%100)/100.0f; o.pos.x=-0.5f+(rand()%3)*0.5f; score+=10; }
        // AABB
        float bw=0.5f*0.25f*bikeSpr.w/float(WIN_W),bh=0.5f*0.25f*bikeSpr.h/float(WIN_H);
        float ow=0.5f*0.25f*obsSpr.w/float(WIN_W),oh=0.5f*0.25f*obsSpr.h/float(WIN_H);
        bool hit=std::abs(player.pos.x-o.pos.x)<(bw+ow) && std::abs(player.pos.y-o.pos.y)<(bh+oh);
        if(hit){ score=0; player.pos.y=-0.75f; player.vel.y=0; player.grounded=true; o.pos.y=1.5f; }
    }
    worldSpeed=std::min(worldSpeed+0.02f*dt,MAX_SPD);

    glutPostRedisplay();
    glutTimerFunc(16,timer,0);
}

int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(WIN_W,WIN_H);
    glutCreateWindow("BikeRaceGL – Code::Blocks GLUT");
    glewExperimental=GL_TRUE; glewInit();
    createProgram();
    proj=glm::ortho(-1.0f,1.0f,-1.0f,1.0f,-1.0f,1.0f);

    roadSpr.load("assets/road.png");
    bikeSpr.load("assets/bike.png");
    obsSpr.load("assets/obstacle.png");
    for(int i=0;i<6;++i){
        Obstacle o;
        o.pos.y=-1.0f-i*0.3f; o.pos.x=-0.5f+(rand()%3)*0.5f;
        o.sprite=&obsSpr; obs.push_back(o);
    }
    player.sprite=&bikeSpr;

    glEnable(GL_FRAMEBUFFER_SRGB);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

    glutDisplayFunc(display);
    glutTimerFunc(16,timer,0);
    glutMainLoop();
    return 0;
}
