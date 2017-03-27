#include "cForklift.h"
#include <math.h>

#define CONVERSION angle * (3.1416 / 180)

Forklift::Forklift(){
    forkModel = glmReadOBJ("/Users/jacobotapia/Desktop/Forklift_Simulator/ForkLift.obj");
    glmVertexNormals(forkModel, 45.0f, false);
    glmFacetNormals(forkModel);
    glmUnitize(forkModel);
    x = y = z = 0;
    angle = 0;
}

Forklift::~Forklift(){}

void Forklift::draw(){
    glPushMatrix();
    {
        glTranslated(x, y, z);
        glRotatef(angle, 0, 1, 0);
        glmDraw(forkModel,GLM_MATERIAL | GLM_SMOOTH);
    }
    glPopMatrix();
}

void Forklift::rotate(int direction){
    if(direction == 1){
        angle+=1;
    }else{
        angle-=1;
    }
}

void Forklift::move(int direction){
    if(direction == 1){
        z -= 0.05f * cos(CONVERSION);
        x -= 0.05f * sin(CONVERSION);
    }else{
        z += 0.05f * cos(CONVERSION);
        x += 0.05f * sin(CONVERSION);
    }
}


void Forklift::update(){}


