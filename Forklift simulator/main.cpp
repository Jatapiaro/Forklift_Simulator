
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


GLfloat		rotationY = 0.0f;
GLfloat		rotationX = 0.0f;

GLfloat*	mat0_specular;
GLfloat*	mat0_diffuse;
GLfloat*	mat0_shininess;
GLfloat*	light0_position;

Forklift *forklift;

void init(void)
{
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    glClearColor(0.2, 0.2, 0.2, 1.0);
    
    
    forklift = new Forklift();
    
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

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat0_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat0_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat0_shininess);
    
    forklift->draw();
    
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
    gluLookAt(0, 0, -5,
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
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("OBJ Loader!");
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPress);
    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;   /* ANSI C requires main to return int. */
}
