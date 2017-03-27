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


#define NUM_CUBES 8
#define NUM_CYLINDERS 18

class Forklift{
public:
    
    Forklift();
    ~Forklift();
    
    void draw();
    void update();
    
    GLMmodel *forkModel;
    GLfloat	*mat0_specular;
    GLfloat	*mat0_diffuse;
    GLfloat *mat0_shininess;
    GLfloat *light0_position;
    
};
