#include "cForklift.h"
#include <math.h>

#define CONVERSION angle * (3.1416 / 180)

Forklift::Forklift(){
    
    forkModel = glmReadOBJ("/Users/jacobotapia/Desktop/Forklift_Simulator/cuerpo.obj");
    glmVertexNormals(forkModel, 45.0f, false);
    glmFacetNormals(forkModel);
    glmUnitize(forkModel);
    
    for(int i=0;i<4;i++){
        switch (i) {
            case 0:
                wheels[i] = glmReadOBJ("/Users/jacobotapia/Desktop/Forklift_Simulator/rueda_delantera_derecha.obj");
                break;
            case 1:
                wheels[i] = glmReadOBJ("/Users/jacobotapia/Desktop/Forklift_Simulator/rueda_delantera_izquierda.obj");
                break;
            case 2:
                wheels[i] = glmReadOBJ("/Users/jacobotapia/Desktop/Forklift_Simulator/rueda_trasera_derecha.obj");
                break;
            case 3:
                wheels[i] = glmReadOBJ("/Users/jacobotapia/Desktop/Forklift_Simulator/rueda_trasera_izquierda.obj");
                break;
            default:
                break;
        }
        glmVertexNormals(wheels[i], 45.0f, false);
        glmFacetNormals(wheels[i]);
        glmUnitize(wheels[i]);
    }
    
    x = y = z = 0;
    angle = 0;
}

Forklift::~Forklift(){}

void Forklift::draw(){
    
    
    glPushMatrix();
    {
        glTranslated(x, y, z);
        glRotatef((angle-90), 0, 1, 0);
        glmDraw(forkModel,GLM_MATERIAL | GLM_SMOOTH);
        
        for(int i=0;i<2;i++){
            {
                glPushMatrix();
                {
                    
                    switch (i) {
                        case 0:
                            glTranslatef(front_wheels_x,front_wheels_y,wheels_z);
                            glmDraw(wheels[i],GLM_MATERIAL | GLM_SMOOTH);
                            break;
                        
                        case 1:
                            glTranslatef(front_wheels_x,front_wheels_y,-wheels_z);
                            glmDraw(wheels[i],GLM_MATERIAL | GLM_SMOOTH);
                            break;
                            
                        default:
                            break;
                    }
                    
                }
                glPopMatrix();
            }
        }
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


