#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

#include<GL/gl.h>
#include <GL/glut.h>
#include<mmsystem.h>

//Initializes 3D rendering
void initRendering() {
    glEnable(GL_DEPTH_TEST);
}
//Called when the window is resized
void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}
float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 10;
float _moveC1 = -11;
float _moveC2 = 11;
float _moveCL1 = -30;
float _moveCL2 = -20;
float _moveCL3 = -10;

float _movesun1 = 10;
float _movesun2 =  15;
float _moveman1 = -10;
float _moveman2 = -15;
float _skyR = 0.0;
float _skyG = 0.8;
float _skyB = 1.0;
float _sunG = 1.0;
float _moveCar = -6;
float _cntrlCar = 5; //car control asd
float scaleX = .4;
float scaleY = .4;
float scaleZ = .4;

bool skey = 0;
bool akey = 0;
bool dkey = 0;
bool isup = 0;
bool isDown = 0;
bool isOn = 0;
bool isday = 1;



void fatline()
{
    glPushMatrix();
    glTranslatef(0,-.5,.5);
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.5,.5);
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,1.5,.5);
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,2.5,.5);
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,3.5,.5);
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,4.5,.5);
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,5.5,.5);
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,6.5,.5);
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,7.5,.5);
    glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,8.5,.5);

    glutSolidCube(1.0);
    glPopMatrix();
}
void sun()
{
    glPushMatrix();
    glColor3f(1,_sunG,0);
    glutSolidSphere(1.5,100,100);
    glPopMatrix();
}

void man(){
        glPushMatrix(); //Save the transformations performed thus far
        glRotatef(_angle,0,1,0);
        glScalef(.2,.2,.2);
        glPushMatrix();
        glColor3f(0.0,0.0,0.0);
        glTranslatef(0,1,0);
        glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,1.0,0.0);
        glTranslatef(0,.1,0);
        glutSolidCube(1.2);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(0,-.2,0);
        glutSolidCube(1.2);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glTranslatef(.9,.5,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glTranslatef(.9,.3,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glTranslatef(.9,.1,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glTranslatef(-.9,.5,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glTranslatef(-.9,.3,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glTranslatef(-.9,.1,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,0.0,1.0);
        glTranslatef(.9,-0.2,0);
        glutSolidCube(.3);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,0.0,1.0);
        glTranslatef(.9,-0.4,0);
        glutSolidCube(.3);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,0.0,1.0);
        glTranslatef(-.9,-0.2,0);
        glutSolidCube(.3);
        glPopMatrix();
        glPushMatrix();
        glColor3f(1.0,0.0,1.0);
        glTranslatef(-.9,-0.4,0);
        glutSolidCube(.3);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(.3,-1.0,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(.3,-1.2,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(.3,-1.4,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(.3,-1.6,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(-.3,-1.0,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(-.3,-1.2,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(-.3,-1.4,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,0.0);
        glTranslatef(-.3,-1.6,0);
        glutSolidCube(.4);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,1.0);
        glTranslatef(.3,-1.9,0);
        glutSolidCube(.25);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,1.0);
        glTranslatef(.3,-2.0,0);
        glutSolidCube(.25);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,1.0);
        glTranslatef(-.3,-1.9,0);
        glutSolidCube(.25);
        glPopMatrix();
        glPushMatrix();
        glColor3f(0.0,1.0,1.0);
        glTranslatef(-.3,-2.0,0);
        glutSolidCube(.25);
        glPopMatrix();
        glPopMatrix();

}

//bridge er khamb
void khambas(){
    glPushMatrix(); //left most 1
    glScalef(0.2,0.37,0.5);
    glTranslatef(-30,-1.4,0);
    fatline();
    glPopMatrix();

    glPushMatrix(); //2
    glScalef(0.2,0.4,0.5);
    glTranslatef(-20,-0.8,0);
    fatline();
    glPopMatrix();

    glPushMatrix(); //3
    glScalef(0.2,0.41,0.5);
    glTranslatef(-10,-0.4,0);
    fatline();
    glPopMatrix();


    glPushMatrix(); //4
    glScalef(0.2,0.5,0.5);
    glTranslatef(0,-0.2,0);
    fatline();
    glPopMatrix();

    glPushMatrix(); //5
    glScalef(0.2,0.5,0.5);
    glTranslatef(10,-0.25,0);
    fatline();
    glPopMatrix();


    glPushMatrix(); //6
    glScalef(0.2,0.45,0.5);
    glTranslatef(20,-0.25,0);
    fatline();
    glPopMatrix();

    glPushMatrix(); //7
    glScalef(0.2,0.45,0.5);
    glTranslatef(30,-0.7,0);
    fatline();
    glPopMatrix();

    glPushMatrix();//8
    glScalef(0.2,0.38,0.5);
    glTranslatef(40,-1.4,0);
    fatline();
    glPopMatrix();

}

void arch(){
glPushMatrix();
glRotatef(180,0,0,1);
glPushMatrix();
    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/100;
        float r=2;
        float x = r * cos(A);
        float y = r * sin(A);
        glPushMatrix();
        glTranslatef(x,y,0);
        if(i>150)
        {
            glutSolidSphere(.2,100,100);
        }

        glPopMatrix();
    }


    glPopMatrix();
    glPopMatrix();

}

void archPart()
{
    glPushMatrix();
    if(isDown==1)
        glColor3f(0.168, 0.913, 0.850);
    else
        glColor3f(0.9, 0.9, 0.9);
    glPushMatrix();
    glScalef(0.5,0.5,1);
    glPushMatrix();
    glScalef(9,4,1.2);
    glTranslatef(0.2,-0.25,0);
    arch();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-0.2);
    glScalef(1.4,1.7,1);
    khambas();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

}

void car(){
    glPushMatrix(); //car
    glTranslatef(0,.5,0);
    glPushMatrix();
    glColor3f(0.890, 0.125, 0.050);
    glScalef(0.6,0.4,0.5);
    //glRotatef(50,0,0,1);
    glutSolidCube(2);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.968, 0.937, 0.133); //upper part
    glScalef(0.6,0.4,0.4);
    glRotatef(50,0,0,1);
    glTranslatef(-1,0.3,0);
    glutSolidCube(2);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.968, 0.937, 0.133);
    glScalef(0.6,0.4,0.4);
    glRotatef(50,0,0,1);
    glTranslatef(0.2,-1,0);
    glutSolidCube(2);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glScalef(2,1,1);
    glPushMatrix();
    glColor3f(0.890, 0.125, 0.050); //middle part
    glScalef(1,.25,.5);
    glutSolidCube(2);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.584, 0.513, 0.513);
    glTranslatef(-.5,-0.2,.4);
    glutSolidSphere(.25,10,10);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.584, 0.513, 0.513);
    glTranslatef(.5,-0.2,.4);
    glutSolidSphere(.25,10,10);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.584, 0.513, 0.513);
    glTranslatef(-.5,-0.2,-.4);
    glutSolidSphere(.25,10,10);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.584, 0.513, 0.513);
    glTranslatef(.5,-0.2,-.4);
    glutSolidSphere(.25,10,10);
    glPopMatrix();
    glPopMatrix();
}
//bridge
void bridge()
{

    glPushMatrix();
    archPart(); //1st
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,-4);
    archPart(); //2nd
    glPopMatrix();
    glColor3f(0.274, 0.305, 0.301);
    glPushMatrix();
    glTranslatef(0,0,-2);
    glPushMatrix(); //road
    glScalef(12,0.1,1);
    glutSolidCube(4);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_moveC1,0.65,-1);

    car();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(_moveC2,0.65,-2.85);

    car();
    glPopMatrix();



}
void sky()
{
        glPushMatrix();//sky
        glBegin(GL_POLYGON);
        glColor3f(_skyR,_skyG,_skyB);
        //glColor3f(0,0.8,1.0);
        glVertex3i(-50,0,0);
        glVertex3i(50,0,0);
        glVertex3i(50,40,0);
        glVertex3i(-50,40,0);

        glEnd();
        glPopMatrix();
        if(isDown == 0){
        glPushMatrix();
        glTranslatef(0,0,2);
        //cloud1
        glPushMatrix();
        glTranslatef(_moveCL1,0.0,0.0);
        glPushMatrix();
        glColor3f(1.0,1.0,1.0);
        glTranslatef(-24.4,9.5,0);
        glutSolidSphere(1.25,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-24.3,7.3,0);
        glColor3f(1.0,1.0,1.0);
        glutSolidSphere(1.25,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-22.0,9.5,0);
        glColor3f(2.0,2.0,2.0);
        glutSolidSphere(1.35,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-26,8.5,0);
        glColor3f(1.5,1.5,1.5);
        glutSolidSphere(1.30,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-22.9,7.8,0);
        glColor3f(1.0,1.0,1.0);
        glutSolidSphere(1.25,100,100);
        glPopMatrix();
        glPopMatrix();
         //cloud2
        glPushMatrix();
        glTranslatef(_moveCL2,0.0,0.0);
        glPushMatrix();
        glTranslatef(-5.0,9.8,0);
        glColor3f(1.0,1.0,1.0);
        glutSolidSphere(1.0,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-6.5,9.2,0);
        glColor3f(2.0,2.0,2.0);
        glutSolidSphere(1.15,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-6.8,8.2,0);
        glColor3f(1.5,1.5,1.5);
        glutSolidSphere(1.30,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-5.0,8.3,0);
        glColor3f(1.0,1.0,1.0);
        glutSolidSphere(1.30,100,100);
        glPopMatrix();
        glPopMatrix();
        //cloud3
        glPushMatrix();
        glTranslatef(_moveCL3,0.0,0.0);
        glPushMatrix();
        glColor3f(1.5,8.5,1.5);
        glTranslatef(-5.4,8.5,0);
        glutSolidSphere(1.25,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-4.3,8.3,0);
        glColor3f(1.0,1.0,1.0);
        glutSolidSphere(1.25,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-6.8,9,0);
        glColor3f(2.0,2.0,2.0);
        glutSolidSphere(1.15,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-5.5,9,0);
        glColor3f(1.5,1.5,1.5);
        glutSolidSphere(1.30,100,100);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-5.9,8.0,0);
        glColor3f(1.0,1.0,1.0);
        glutSolidSphere(1.25,100,100);
        glPopMatrix();
        glPopMatrix();
        glPopMatrix();
    }
}

//water
void water()
{
    glPushMatrix(); // water
    glColor3f(_skyR,_skyG,_skyB);
    glBegin(GL_POLYGON);
    glVertex3f(-30,-.55,30);
    glVertex3f(30,-.55,30);
    glVertex3f(30,-.55,-30);
    glVertex3f(-30,-.55,-30);
    glEnd();

    glPopMatrix();

}


//water shade
void shade(){
    glPushMatrix();
    glScalef(1,0.1,1);
    glRotatef(90,1,0,0);
    archPart();
    glPopMatrix();
 if(isDown==0)
        glColor3f(0.0, 0.8, 1.0);
    else
        glColor3f(0.1, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(0,0.1,0);
    glPushMatrix();//cube shade1
    glScalef(110,0.1,1);
    glutSolidCube(0.15);
    glPopMatrix();
    glPushMatrix();//cube shade2
    glScalef(110,0.1,1);
    glTranslatef(0,0,0.30);
    glutSolidCube(0.15);
    glPopMatrix();
    glPushMatrix();//cube shade3
    glScalef(110,0.1,1);
    glTranslatef(0,0,0.75);
    glutSolidCube(0.15);
    glPopMatrix();
    glPushMatrix();//cube shade4
    glScalef(110,0.1,1);
    glTranslatef(0,0,1);
    glutSolidCube(0.15);
    glPopMatrix();
    glPushMatrix();//cube shade5
    glScalef(110,0.1,1);
    glTranslatef(0,0,1.30);
    glutSolidCube(0.15);
    glPopMatrix();
     glPushMatrix();//cube shade6
    glScalef(110,0.1,1);
    glTranslatef(0,0,1.70);
    if(isOn || isup == 1)
    glutSolidCube(0.15);
    glPopMatrix();
    glPopMatrix();
}

//mati
void mati()
{
    glPushMatrix();
    glColor3f(0.078,0.447,0.015);
    glPushMatrix();
    glScalef(5,2,2);
    glutSolidCube(3);
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    //glColor3f(1,1,1);
    glPushMatrix();
    glTranslatef(-6,-0.7,2);
    glutSolidSphere(2,100,100);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-4,-0.7,2);
    glutSolidSphere(2,100,100);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2,-0.7,2);
    glutSolidSphere(2,100,100);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,-0.7,2);
    glutSolidSphere(2,100,100);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2,-0.7,2);
    glutSolidSphere(2,100,100);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(4,-0.7,2);
    glutSolidSphere(2,100,100);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(6,-0.7,2);
    glutSolidSphere(2,100,100);
    glPopMatrix();
    glPopMatrix();
}

//matir charpash
void matircharpash(){

    glPushMatrix();
    glTranslatef(-25,0,0);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25,0,05);
    mati();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-25,0,10);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25,0,15);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25,0,20);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25,0,25);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25,0,27);
    mati();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-25,0,-27);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25,0,-26);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25,0,-20);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25,0,-15);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25,0,-10);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25,0,-05);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,0,27);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-5,0,27);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,27);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,0,27);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(15,0,27);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(20,0,27);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-15,0,-27);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,0,-27);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-05,0,-27);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(05,0,-27);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(10,0,-27);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(20,0,-27);
    mati();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-20,0,27);
    mati();
    glPopMatrix();

    glPushMatrix();
    //glRotatef(-90,1,0,0);
    glPushMatrix();
    glTranslatef(30,0,-27);
    glRotatef(-90,0,1,0);
    mati();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    //glRotatef(-90,1,0,0);
    glPushMatrix();
    glTranslatef(30,0,-18);
    glRotatef(-90,0,1,0);
    mati();
    glPopMatrix();
    glPopMatrix();

     glPushMatrix();
    //glRotatef(-90,1,0,0);
    glPushMatrix();
    glTranslatef(30,0,-12);
    glRotatef(-90,0,1,0);
    mati();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    //glRotatef(-90,1,0,0);
    glPushMatrix();
    glTranslatef(30,0,-5);
    glRotatef(-90,0,1,0);
    mati();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    //glRotatef(-90,1,0,0);
    glPushMatrix();
    glTranslatef(30,0,5);
    glRotatef(-90,0,1,0);
    mati();
    glPopMatrix();
    glPopMatrix();

     glPushMatrix();
    //glRotatef(-90,1,0,0);
    glPushMatrix();
    glTranslatef(30,0,10);
    glRotatef(-90,0,1,0);
    mati();
    glPopMatrix();
    glPopMatrix();

     glPushMatrix();
    //glRotatef(-90,1,0,0);
    glPushMatrix();
    glTranslatef(30,0,15);
    glRotatef(-90,0,1,0);
    mati();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    //glRotatef(-90,1,0,0);
    glPushMatrix();
    glTranslatef(30,0,20);
    glRotatef(-90,0,1,0);
    mati();
    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    //glRotatef(-90,1,0,0);
    glPushMatrix();
    glTranslatef(30,0,23);
    glRotatef(-90,0,1,0);
    mati();
    glPopMatrix();
    glPopMatrix();


}



void floor(){
    //1stbasha
    glPushMatrix();
    glTranslatef(-2,0,0);
    glColor3f(0.9,0.9,0.9);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1,0,0);
    if(isDown==0)
        glColor3f(0.019,0.118,0.980);
    else
        glColor3f(1,1,0);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,0);
    glColor3f(0.9,0.9,0.9);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1,0,0);
    if(isDown==0)
        glColor3f(0.019,0.118,0.980);
    else
        glColor3f(1,1,0);
    glutSolidCube(1);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(2,0,0);
    glColor3f(0.9,0.9,0.9);
    glutSolidCube(1);
    glPopMatrix();


    //roof

    glPushMatrix();
    glTranslatef(0,0.9,0);
    glScalef(5,.8,1);
    glColor3f(0.9,0.9,0.9);
    glutSolidCube(1);
    glPopMatrix();
}

void chartalabasha(){
    glPushMatrix();
    glTranslatef(0,5.2,0);
    floor();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,3.6,0);
    floor();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,1.8,0);
    floor();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,0);
    floor();
    glPopMatrix();
}

void tintalabasha(){
    glPushMatrix();
    glTranslatef(0,5.2,0);
    floor();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,3.6,0);
    floor();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,1.8,0);
    floor();
    glPopMatrix();
}

void gach(){

        glPushMatrix();
        glScalef(5,5,5);
        glPushMatrix();
        glColor3f(.8,.3,0);
        glScalef(0.1,0.05,0.1);
        glTranslatef(0.4,0,-1);
        fatline();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(0.05,.35,-.05);
        glColor3f(0,.8,0);
        glRotatef(90,-1,0,0);
        glutSolidCone(.18,.5,20,20);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(0.05,.50,-.05);
        glColor3f(0,1,0);
        glRotatef(90,-1,0,0);
        glutSolidCone(.2,.5,20,20);
        glPopMatrix();
        glPopMatrix();

}

 void lampPost(){
        glPushMatrix();
        glColor3f(.5,.5,.5);
        glBegin(GL_POLYGON);
        glVertex3f(0,0,0);
        glVertex3f(.1,0,0);
        glVertex3f(.1,1.5,0);
        glVertex3f(0,1.5,0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(.1,0,0);
        glVertex3f(.1,0,-.1);
        glVertex3f(.1,1.5,-.1);
        glVertex3f(.1,1.5,0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(0,0,-.1);
        glVertex3f(.1,0,-.1);
        glVertex3f(.1,1.5,-.1);
        glVertex3f(0,1.5,0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(0,0,0);
        glVertex3f(0,0,-.1);
        glVertex3f(0,1.5,-.1);
        glVertex3f(0,1.5,0);
        glEnd();

        glPopMatrix();
        glPushMatrix();
        glColor3f(.5,.5,.5);
        glBegin(GL_POLYGON);
        glVertex3f(0,1.5,0);
        glVertex3f(1,1.5,0);
        glVertex3f(1,1.6,0);
        glVertex3f(0,1.6,0);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(0,1.5,-0.1);
        glVertex3f(1,1.5,-0.1);
        glVertex3f(1,1.6,-0.1);
        glVertex3f(0,1.6,-0.1);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex3f(0,1.6,0);
        glVertex3f(1,1.6,0);
        glVertex3f(1,1.6,-0.1);
        glVertex3f(0,1.6,-0.1);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glColor4f(1,1,0,.4);
        glRotatef(-90,1,0,0);
        glTranslatef(.95,0.05,0.05);
        if(isOn || isup == 1)
            glutSolidCone(.8,1.5,10,10);
    glPopMatrix();
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
    glLoadIdentity(); //Reset the drawing perspective
    glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
    glTranslatef(0.0, 0.0, -7.0);//Move forward 5 units

    glPushMatrix();
    glRotatef(_ang_tri,1,0,0);
    glRotatef(_angle,0,1,0);
    //glTranslatef(0,0,2.0);
    glScalef(scaleX, scaleY,scaleZ);


    glPushMatrix();
    glTranslatef(35,0,20);
    glRotatef(-90,0,1,0);
    sky();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(-35,0,20);
    glRotatef(90,0,1,0);
    sky();
    glPopMatrix();
    glPushMatrix();//sun
    if(isup == 1){
        glTranslatef(10,_movesun2,-30);
        sun();
    }
    glPopMatrix();

    glPushMatrix();//4th sky
    glTranslatef(15,0,31);
    glRotatef(-180,0,1,0);
    sky();
    glPopMatrix();




    glPushMatrix();
    glTranslatef(1.6,3.1,0);
    bridge();
    //archPart();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,-30);
    sky();
    glPopMatrix();


    glPushMatrix();//2nd shade
    glTranslatef(1,0,3);
    shade();
    glPopMatrix();

    glPushMatrix();//1st shade
    glTranslatef(2.8,0,-6.5);
    glRotatef(180,0,1,0);
    shade();
    glPopMatrix();

    glPushMatrix();
    water();
    glPopMatrix();


    glPushMatrix();
    matircharpash();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-30,3,0);
    gach();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-20,3,10);
    gach();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-30,3,-7);
    gach();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30,3,-7);
    gach();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30,3,-14);
    gach();
    glPopMatrix();

    glPushMatrix();//1st boro basha
    glTranslatef(-30,3,-26);
    chartalabasha();
    glPopMatrix();

    glPushMatrix();//1st choto basha
    glTranslatef(-27,1,-23);
    tintalabasha();
    glPopMatrix();

    glPushMatrix();//2nd boro basha
    glTranslatef(30,3,26);
    chartalabasha();
    glPopMatrix();

    glPushMatrix();//2nd choto basha
    glTranslatef(27,1,23);
    tintalabasha();
    glPopMatrix();

    glPushMatrix();//3rd boro basha
    glTranslatef(30,3,-26);
    chartalabasha();
    glPopMatrix();

    glPushMatrix();//3rd choto basha
    glTranslatef(27,1,-23);
    tintalabasha();
    glPopMatrix();

    glPushMatrix();//4th boro basha
    glTranslatef(-20,3,-26);
    chartalabasha();
    glPopMatrix();

    glPushMatrix();//5th boro basha
    glTranslatef(-13,3,-26);
    chartalabasha();
    glPopMatrix();

    glPushMatrix();//6th boro basha
    glTranslatef(-5,3,-26);
    chartalabasha();
    glPopMatrix();

    glPushMatrix();//7th boro basha
    glTranslatef(5,3,-26);
    chartalabasha();
    glPopMatrix();

    glPushMatrix();//8th boro basha
    glTranslatef(10,3,-26);
    chartalabasha();
    glPopMatrix();



    glPushMatrix(); // 1st
    glRotatef(90,0,1,0);
    glTranslatef(0.1,3.2,-8);
    glScalef(1,2,1);

    lampPost();
    glPopMatrix();


    glPushMatrix(); // 2nd
    glRotatef(90,0,1,0);
    glTranslatef(0.1,3.2,-12);
    glScalef(1,2,1);

    lampPost();
    glPopMatrix();

    glPushMatrix();//3rd
    glRotatef(90,0,1,0);
    glTranslatef(0.1,3.2,13);
    glScalef(1,2,1);

    lampPost();
    glPopMatrix();

    glPushMatrix();//4th
    glRotatef(90,0,1,0);
    glTranslatef(0.1,3.2,17);
    glScalef(1,2,1);

    lampPost();
    glPopMatrix();

    glPushMatrix(); // 1st
    glRotatef(-90,0,1,0);
    glTranslatef(-3.9,3.2,-13);
    glScalef(1,2,1);

    lampPost();
    glPopMatrix();


    glPushMatrix(); // 2nd
    glRotatef(-90,0,1,0);
    glTranslatef(-3.9,3.2,-17);
    glScalef(1,2,1);

    lampPost();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90,0,1,0);
    glTranslatef(-3.9,3.2,8);
    glScalef(1,2,1);

    lampPost();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90,0,1,0);
    glTranslatef(-3.9,3.2,12);
    glScalef(1,2,1);

    lampPost();
    glPopMatrix();


    glPushMatrix();
    glRotatef(-90,0,1,0);
    glTranslatef(_moveman1,4,23);
    man();
    glPopMatrix();
    glPushMatrix();
    glRotatef(60,0,1,0);
    glTranslatef(_moveman2,4,-23);
    man();
    glPopMatrix();



    glPopMatrix();// main pop
    glutSwapBuffers();// exchange for glFlash()
}

void cloudMov()
{
    if(skey == 0)

    {
         if(akey == 0)
         {
                _moveC1 += 0.3;//speed
            if(_moveC1>= 11)//initialise point
                _moveC1 = -11;//end point
         }
         if(dkey == 0)
         {
             _moveC2 -= 0.3;
        if(_moveC2<= -11)
            _moveC2 = 11;
         }


    }
                _moveCL1 += 0.3;
            if(_moveCL1>= 30)
                _moveCL1 = -30;

                _moveCL2 += 0.2;
            if(_moveCL2>= 50)
                _moveCL2 = -20;

                _moveCL3 += 0.4;
            if(_moveCL3>= 50)
                _moveCL3 = -10;



}
void update(int value) {
    cloudMov();
    //Tell GLUT that the display has changed

    if(isup == 0){
    _movesun1 += .25;
    if(_movesun1>=30){
        _movesun1= -2;
        isup = 1;
     }
     _skyG = 0.8;
     _skyB = 1;
     _sunG = 1;
    }

    if(isup == 1){
        _movesun2 -= .25;
        if(_movesun2<= -15){
            _movesun2 = 14;
            isup = 0;
            isDown = 0;
        }
        if(_movesun2<= -3.0)
            isDown = 1;
        _skyG -= 0.008;
        _skyB -= 0.010;
        _sunG -= 0.01;

    }
       /* _moveCar += .25;
        if(_moveCar>=5.5){
            _moveCar = -18.5;
        }*/

      _moveman1 += .1;
    if(_moveman1>=5){
        _moveman1 = -7.5;
    }
    _moveman2 += .05;
    if(_moveman2>=5){
        _moveman2 = -7.5;
    }
    //Tell GLUT to call update again in 30 milliseconds
    glutPostRedisplay();
    glutTimerFunc(30, update, 0);
}


void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'o':
        if(isOn == 0)
            isOn = 1;
        else
            isOn = 0;
        glutPostRedisplay();
        break;
    case 's':
        if(skey == 0)
            skey = 1;
        else
            skey = 0;
        break;
    case 'a':
        if (akey == 0)
            akey = 1;
        else
            akey = 0;
        break;
    case 'd':
        if (dkey == 0)
            dkey = 1;
        else
            dkey = 0;

        break;
    default:
        break;
    case 't':
        if(isday==1)
            isday=0;
        else
            isday=1;
        glutPostRedisplay();
        break;
    case '+':
        scaleX += .05;
        scaleY += .05;
        scaleZ += .05;
        break;
    case '-':
        scaleX -= .05;
        scaleY -= .05;
        scaleZ -= .05;
        break;
    }
}

void specialKey(int key, int x, int y){
    switch (key) {
    case GLUT_KEY_LEFT:
        _angle += 2;
        if(_angle>=360)
            _angle = 0.0;
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        _angle -= 2;
        if(_angle>=360)
            _angle = 0.0;
        glutPostRedisplay();
        break;
    case GLUT_KEY_UP:
        _ang_tri += 2;
        if(_ang_tri>=180)
            _ang_tri=0;
        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN:
        _ang_tri -= 2;
        if(_ang_tri<= 0)
            _ang_tri = 180;
        break;
    default:
        break;
    }
}

void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
    gluOrtho2D(0.0,1360,0.0,800);
}

int main(int argc, char** argv) {
    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1360, 600);

    //Create the window
    glutCreateWindow("Nirjhor");


    initRendering();
    init();

    //Set handler functions
    glutDisplayFunc(drawScene);
    glutReshapeFunc(handleResize);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKey);
    glutTimerFunc(30, update, 0); //Add a timer
    sndPlaySound("G:\\19-1\\graphicsfinalproject\\graphicsfinal\\12.wav",SND_ASYNC | SND_LOOP);
    glutMainLoop();
    return 0;
}


