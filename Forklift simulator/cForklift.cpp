#include "cForklift.h"
#include <math.h>

#define CONVERSION angle * (3.1416 / 180)

Forklift::Forklift(){
    
    forkModel = glmReadOBJ("/Users/jacobotapia/Desktop/Forklift_Simulator/cuerpo.obj");
    glmVertexNormals(forkModel, 45.0f, false);
    glmFacetNormals(forkModel);
    glmUnitize(forkModel);
    
    fork = glmReadOBJ("/Users/jacobotapia/Desktop/Forklift_Simulator/brazo.obj");
    glmVertexNormals(fork, 45.0f, false);
    glmFacetNormals(fork);
    glmUnitize(fork);
    
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
                wheels[i] = glmReadOBJ("/Users/jacobotapia/Desktop/Forklift_Simulator/rueda_trasera_derecha.obj");
                break;
            default:
                break;
        }
        glmVertexNormals(wheels[i], 45.0f, false);
        glmFacetNormals(wheels[i]);
        glmUnitize(wheels[i]);
    }
    
    x = y = z = 0;
    angle = wheels_angle = wheels_rotation = 0;
    fork_position = -0.3;
    xf = x-1.09;
    yf = fork_position;
    zf = 0;
    moving = true;
    with_box = false;
}

Forklift::~Forklift(){}

void Forklift::draw(){
    
    
    glPushMatrix();
    {
        glTranslatef(x, y, z);
        glRotatef((angle-90), 0, 1, 0);
        glmDraw(forkModel,GLM_MATERIAL | GLM_SMOOTH);
        
        glPushMatrix();
        {
            glTranslatef(-1.09,fork_position,0);
            float anglee = (angle*3.1416)/180;
            xf = x+1.09;
            yf = fork_position;
            zf = z;
            glmDraw(fork, GLM_MATERIAL | GLM_SMOOTH);
        }
        glPopMatrix();
        
        for(int i=0;i<4;i++){
            {
                glPushMatrix();
                {
                    switch (i) {
                        case 0:
                            glTranslatef(front_wheels_x,wheels_y,front_wheels_z);
                            glRotatef(wheels_angle, 0,1,0);
                            glmDraw(wheels[i],GLM_MATERIAL | GLM_SMOOTH);
                            break;
                        case 1:
                            glTranslatef(front_wheels_x,wheels_y,-front_wheels_z);
                            glRotatef(wheels_angle, 0, 1, 0);
                            if(moving){
                                
                            }
                            glmDraw(wheels[i],GLM_MATERIAL | GLM_SMOOTH);
                            break;
                        
                        case 2:
                            glTranslatef(back_wheels_x,wheels_y,-back_wheels_z);
                            if(moving){
                                
                            }
                            glmDraw(wheels[i],GLM_MATERIAL | GLM_SMOOTH);
                            break;
                        
                        case 3:
                            glTranslatef(back_wheels_x,wheels_y,back_wheels_z);
                            if(moving){
                                
                            }
                            glmDraw(wheels[i],GLM_MATERIAL | GLM_SMOOTH);
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
    moving = false;
    if(direction == 1){
        angle+=1;
        float cuadrante = (angle/360);
        angle = cuadrante*360;
        if(wheels_angle<=45){
            wheels_angle+=1;
        }
    }else{
        angle-=1;
        float cuadrante = (angle/360);
        angle = cuadrante*360;
        if(wheels_angle>=-45){
            wheels_angle-=1;
        }
    }
}

void Forklift::move_fork(int direction){
    if(direction==1){
        if(fork_position<=1){
            fork_position+=0.05;
        }
    }else{
        if(fork_position>=-1){
            fork_position-=0.05;
        }
    }
}

void Forklift::move(int direction){
    moving = true;
    if(direction == 1){
        z -= 0.05f * cos(CONVERSION);
        x -= 0.05f * sin(CONVERSION);
    }else{
        z += 0.05f * cos(CONVERSION);
        x += 0.05f * sin(CONVERSION);
    }
    if(wheels_angle!=0){
        if(wheels_angle<0){
            wheels_angle+=1;
        }else{
            wheels_angle-=1;
        }
    }
}


void Forklift::update(){}


