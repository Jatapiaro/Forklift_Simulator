#include "cForklift.h"

Forklift::Forklift(){
    forkModel = glmReadOBJ("/Users/jacobotapia/Documents/Forklift_Simulator/ForkLift.obj");
    glmVertexNormals(forkModel, 45.0f, false);
    glmFacetNormals(forkModel);
}

Forklift::~Forklift(){}

void Forklift::draw(){
    glPushMatrix();
    {
        glmDraw(forkModel,GLM_MATERIAL | GLM_SMOOTH);
    }
    glPopMatrix();
}
