#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include "freeglut.h"
#endif

#include <stdio.h>
#include <math.h>// NATE ROBINS' OBJ MODEL LOADER (http://devernay.free.fr/hacks/glm/)
#include "glm.h"

#define front_wheels_y -1.1
#define front_wheels_x -0.65
#define wheels_z 0.55


class Forklift{
public:
    
    Forklift();
    ~Forklift();
    void draw();
    void update();
    
    void move(int direction);
    void rotate(int direction);
    
    float x,y,z;
    float angle;
    
    GLMmodel *forkModel;
    GLMmodel *fork;
    GLMmodel *wheels[4];
    GLfloat	*mat0_specular;
    GLfloat	*mat0_diffuse;
    GLfloat *mat0_shininess;
    GLfloat *light0_position;
    
};
