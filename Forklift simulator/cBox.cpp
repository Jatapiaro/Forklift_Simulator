# include "cBox.h"

Box::Box(){
    box = glmReadOBJ("/Users/jacobotapia/Desktop/Forklift_Simulator/WoodenBox02.obj");
    glmVertexNormals(box, 45.0f, false);
    glmFacetNormals(box);
    glmScale(box, 0.8);
}

Box::~Box(){}

void Box::draw(){
    glPushMatrix();
    {
        glTranslated(2,-1,1);
        glmDraw(box,GLM_MATERIAL | GLM_SMOOTH);
    }glPopMatrix();
}

void Box::update(){

}
