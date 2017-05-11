#include "cBox.h"
#include <time.h>
#include <stdlib.h>


Box::Box(){
    box = glmReadOBJ("/Users/jacobotapia/Desktop/Forklift_Simulator/WoodenBox02.obj");
    glmVertexNormals(box, 45.0f, false);
    glmFacetNormals(box);
    size = 0.8;
    glmScale(box, size);
    on_fork = false;
    angle = 0;
}

Box::~Box(){}

void Box::addCoordinates(float xi, float yi, float zi){
    x=xi;
    y=yi;
    z=zi;
}

void Box::draw(){
    glPushMatrix();
    {
        
        glTranslatef(x,y,z);
        glmDraw(box,GLM_MATERIAL | GLM_SMOOTH);
        glRotatef(angle, 0, 1, 0);
        
    }
    glPopMatrix();
}



