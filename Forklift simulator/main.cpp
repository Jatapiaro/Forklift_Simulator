
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include "freeglut.h"
#endif

#include <stdio.h>
#include <math.h>
// NATE ROBINS' OBJ MODEL LOADER (http://devernay.free.fr/hacks/glm/)
#include "glm.h"
#include "cForklift.h"
#include "cBox.h"
#include <time.h>
#include <stdlib.h>
#include <vector>

GLfloat		rotationY = 0.0f;
GLfloat		rotationX = 0.0f;

GLfloat*	mat0_specular;
GLfloat*	mat0_diffuse;
GLfloat*	mat0_shininess;
GLfloat*    mat1_diffuse;
GLfloat*	light0_position;
GLfloat*	light0_diffuse;
GLfloat*	light0_specular;
GLfloat*	light0_ambient;
GLfloat*	light1_position; //<-------------------------------------Light 1 - location
GLfloat*	light1_diffuse; //<--------------------------------------Light 1 - diffuse
GLfloat*	light1_specular; //<-------------------------------------Light 1 - specular
GLfloat*	light1_ambient; //<--------------------------------------Light 1 - ambient
GLfloat*	light2_position;
GLfloat*	light2_diffuse;
GLfloat*	light2_specular;
GLfloat*	light2_ambient;

float deltaX, deltaY;
Forklift *forklift;
Box *box;
Box* boxes;


int nBoxes;

void init(void)
{
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glClearColor(0.2, 0.2, 0.2, 1.0);
    
    light0_position = new GLfloat[4];
    light0_position[0] =   0.0f;
    light0_position[1] =   2.0f;
    light0_position[2] =   0.0f;
    light0_position[3] =   0.0f; // POINT LIGHT
    
    light0_ambient		= new GLfloat[4]; //<------------------------Reserve memory
    light0_ambient[0]	= 1.0f; //<----------------------------------L1Ar
    light0_ambient[1]	= 1.0f; //<----------------------------------L1Ag
    light0_ambient[2]	= 1.0f; //<----------------------------------L1Ab
    light0_ambient[3]	= 1.0f; //<----------------------------------L1Aa
    
    
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    glLightfv( GL_LIGHT0, GL_AMBIENT, light0_ambient);
    
    
    light1_position		= new GLfloat[4]; //<------------------------Reserve memory
    light1_position[0]	= -2.0f; //<---------------------------------L1x
    light1_position[1]	=  2.0f; //<---------------------------------L1y
    light1_position[2]	= -2.0f; //<---------------------------------L1z
    light1_position[3]	=  1.0f; //<---------------------------------L1w
    
    light1_specular		= new GLfloat[4]; //<------------------------Reserve memory
    light1_specular[0]	= 1.0f; //<----------------------------------L1Sr
    light1_specular[1]	= 1.0f; //<----------------------------------L1Sg
    light1_specular[2]	= 1.0f; //<----------------------------------L1Sb
    light1_specular[3]	= 1.0f; //<----------------------------------L1Sa
    
    light1_diffuse		= new GLfloat[4]; //<------------------------Reserve memory
    light1_diffuse[0]	= 0.4f; //<----------------------------------L1Dr
    light1_diffuse[1]	= 0.4f; //<----------------------------------L1Dg
    light1_diffuse[2]	= 0.4f; //<----------------------------------L1Db
    light1_diffuse[3]	= 1.0f; //<----------------------------------L1Da
    
    light1_ambient		= new GLfloat[4]; //<------------------------Reserve memory
    light1_ambient[0]	= 0.5f; //<----------------------------------L1Ar
    light1_ambient[1]	= 0.5f; //<----------------------------------L1Ag
    light1_ambient[2]	= 0.5f; //<----------------------------------L1Ab
    light1_ambient[3]	= 1.0f; //<----------------------------------L1Aa
    
    glLightfv( GL_LIGHT1, GL_POSITION,  light1_position );
    glLightfv( GL_LIGHT1, GL_AMBIENT,   light1_ambient);
    glLightfv( GL_LIGHT1, GL_DIFFUSE,   light1_diffuse);
    glLightfv( GL_LIGHT1, GL_SPECULAR,  light1_specular);
    
    mat0_shininess = new GLfloat[1];
    mat0_shininess[0] = 100.0f;
    
    glEnable(GL_LIGHT0);
    glEnable( GL_LIGHT1 );
    glEnable( GL_LIGHT2 );
    glEnable(GL_LIGHTING);
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_TEXTURE_2D);
    
    forklift = new Forklift();
    box = new Box();
    box->addCoordinates(2,-1.05,1);

    
    light0_position = new GLfloat[4];
    light0_position[0] = 3;
    light0_position[1] = 3;
    light0_position[2] = 0;
    light0_position[3] = 1; // POINT LIGHT
    glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
    
    mat0_specular = new GLfloat[4];
    mat0_specular[0] = 1.0f;
    mat0_specular[1] = 1.0f;
    mat0_specular[2] = 1.0f;
    mat0_specular[3] = 1.0f;
    
    mat0_diffuse = new GLfloat[4];
    mat0_diffuse[0] = 0.8f;
    mat0_diffuse[1] = 0.7f;
    mat0_diffuse[2] = 0.6f;
    mat0_diffuse[3] = 1.0f;
    
    mat0_shininess = new GLfloat[1];
    mat0_shininess[0] = 100.0f;
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

bool coliciona(float xi,float xj,float zi, float zj){
    printf("Log: [%f,%f] vs [%f,%f]\n",xi,zi,xj,zj);
    bool collisionX = xi + 1.9 >= xj &&
    xj + 0.5 >= xi;
    // Collision y-axis?
    bool collisionY = zi + 1.9 >= zj &&
    zj + 0.5 >= zi;
    // Collision only if on both axes
    return collisionX && collisionY;
    return false;
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat0_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat0_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat0_shininess);
    glLoadIdentity();
    gluLookAt(0, 0, -10,
              0, 0, 0,
              0, 1, 0);
    glRotatef( deltaY, 1.0, 0.0, 0.0 );
    glRotatef( deltaX, 0.0, 1.0, 0.0 );
    
    forklift->draw();
    box->draw();
    
    for(int i=0;i<1;i++){
        switch (i) {
            case 0:
                if(!forklift->with_box){
                    if(forklift->yf-0.05<box->y){
                        if(coliciona(forklift->x,box->x,forklift->z,box->z)){
                            forklift->with_box=true;
                            box->on_fork = true;
                        }
                    }
                }else{
                    box->angle = forklift->angle;
                    box->addCoordinates(forklift->x+1.09, forklift->fork_position, forklift->z+1.09);
                    
                }
                break;
                
            default:
                break;
        }
    }
    
    glutSwapBuffers();
    
}

void idle(void)
{
    glutPostRedisplay();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLdouble)w / (GLdouble)h, 0.01, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, -10,
              0, 0, 0,
              0, 1, 0);
}

void keyPress(unsigned char key, int x, int y) {
    
    switch(key){
        case 'w':
            forklift->move(1);
            break;
        case 's':
            forklift->move(-1);
            break;
        case 'a':
            forklift->rotate(1);
            break;
        case 'd':
            forklift->rotate(-1);
            break;
        case 'p':
            forklift->move_fork(1);
            break;
        case 'l':
            forklift->move_fork(-1);
            break;
    }
}

void move( int x, int y )
{
    static int lastX = 0, lastY = 0;
    deltaX -= (lastX - x);
    deltaY += (lastY - y);
    lastX = x;
    lastY = y;
}

void mouse( int button, int state, int x, int y )
{
    
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    //glutInitWindowSize(2000, 1000);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Forklift simulator");
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPress);
    init();
    glutMotionFunc( move );
    glutMouseFunc( mouse );
    
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;   /* ANSI C requires main to return int. */
}
