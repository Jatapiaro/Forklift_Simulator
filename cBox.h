#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include "freeglut.h"
#endif

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
// NATE ROBINS' OBJ MODEL LOADER (http://devernay.free.fr/hacks/glm/)
#include "glm.h"


class Box{
public:
    
    
    Box();
    ~Box();
    void draw();
    void addCoordinates(float x,float y,float z);
    
    GLMmodel *box;
    float x,y,z,size,angle;
    bool on_fork;
};
