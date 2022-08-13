#include <iostream>
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include <texture.h>
#include "Model_3DS.h"
#include "GLTexture.h"
#include "camera.h"
#include "Cpu.h"
#include "Gpu.h"
#include "fan.h"
#include "Ram.h"
#include "SSD.h"
#include "room.h"

using namespace std;
HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Cntext
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = FALSE;	// Fullscreen Flag Set To Fullscreen Mode By Default

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

														// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 200000.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}
double x=0;
double movX, movY, movZ;
double lX, lY;
bool A=false,B=false,C=false,D=false,A1=false,B1=false,C1=false,D1=false,E1=false,F1=false;
Camera c;

pair<float,float> pos[25];

int back, front, l, r, top,flor,cpuimg,gpuimg,fanimg,hardimg;

Cpu p;
Gpu n;
fan f;
Ram rr;
SSD ss;
room rooom;
GLTexture a,b,d,e;
int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	sndPlaySound("Super Mario.wav",SND_ASYNC);
	p=Cpu ();
	n=Gpu ();
	f=fan();
	rr=Ram();
	ss=SSD();
	rooom=room();
	glEnable(GL_TEXTURE_2D);
	back	= LoadTexture("wall.bmp");
	front	= LoadTexture("wall.bmp");
	l		= LoadTexture("wall.bmp");
	r		= LoadTexture("wall.bmp");
	top		= LoadTexture("stars.bmp");
	flor	= LoadTexture("floor.bmp");
	cpuimg	= LoadTexture("cpu-processor.bmp");
	gpuimg	= LoadTexture("gppu.bmp");
	hardimg	= LoadTexture("hhhh.bmp");
	fanimg	= LoadTexture("faan.bmp");

	return TRUE;										// Initialization Went OK
}
void GGpu(int x,int y, int z){
			glPushMatrix();

	glTranslated(x,y,z);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,gpuimg);

	glBegin(GL_POLYGON);
	glTexCoord2d(1, 0);
	glVertex3d(-465,-133,-260);	//A
	glTexCoord2d(1, 1);
	glVertex3d(-465,-133,275);	//C
	glTexCoord2d(0, 1);
	glVertex3d(468,-133,275);	//D
	glTexCoord2d(0, 0);
	glVertex3d(468,-133,-260);	//B
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor3ub(0,0,0);

	glBegin(GL_POLYGON);
	glVertex3d(-465,-135,-260);	
	glVertex3d(-465,-135,275);	
	glVertex3d(-465,-195,275);
	glVertex3d(-465,-195,-260);	
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(-465,-135,275);	
	glVertex3d(468,-135,275);
	glVertex3d(468,-195,275);	
	glVertex3d(-465,-195,275);	
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(468,-135,275);	
	glVertex3d(468,-135,-260);	
	glVertex3d(468,-195,-260);
	glVertex3d(468,-195,275);	
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(468,-135,-260);	
	glVertex3d(-465,-135,-260);	
	glVertex3d(-465,-195,-260);	
	glVertex3d(468,-195,-260);	
	glEnd();

	glColor3f(1,1,1);
	glPopMatrix();
	
}
void FFan(int x,int y, int z){
			glPushMatrix();

	glTranslated(x,y,z);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,fanimg);

	glBegin(GL_POLYGON);
	glTexCoord2d(1, 0);
	glVertex3d(-465,-133,-260);	//A
	glTexCoord2d(1, 1);
	glVertex3d(-465,-133,275);	//C
	glTexCoord2d(0, 1);
	glVertex3d(468,-133,275);	//D
	glTexCoord2d(0, 0);
	glVertex3d(468,-133,-260);	//B
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor3ub(0,0,0);

	glBegin(GL_POLYGON);
	glVertex3d(-465,-135,-260);	
	glVertex3d(-465,-135,275);	
	glVertex3d(-465,-195,275);
	glVertex3d(-465,-195,-260);	
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(-465,-135,275);	
	glVertex3d(468,-135,275);
	glVertex3d(468,-195,275);	
	glVertex3d(-465,-195,275);	
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(468,-135,275);	
	glVertex3d(468,-135,-260);	
	glVertex3d(468,-195,-260);
	glVertex3d(468,-195,275);	
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(468,-135,-260);	
	glVertex3d(-465,-135,-260);	
	glVertex3d(-465,-195,-260);	
	glVertex3d(468,-195,-260);	
	glEnd();

	glColor3f(1,1,1);
	glPopMatrix();


}
void HHdd(int x,int y, int z){
			glPushMatrix();

	glTranslated(x,y,z);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,hardimg);

	glBegin(GL_POLYGON);
	glTexCoord2d(1, 0);
	glVertex3d(-465,-133,-260);	//A
	glTexCoord2d(1, 1);
	glVertex3d(-465,-133,275);	//C
	glTexCoord2d(0, 1);
	glVertex3d(468,-133,275);	//D
	glTexCoord2d(0, 0);
	glVertex3d(468,-133,-260);	//B
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor3ub(0,0,0);

	glBegin(GL_POLYGON);
	glVertex3d(-465,-135,-260);	
	glVertex3d(-465,-135,275);	
	glVertex3d(-465,-195,275);
	glVertex3d(-465,-195,-260);	
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(-465,-135,275);	
	glVertex3d(468,-135,275);
	glVertex3d(468,-195,275);	
	glVertex3d(-465,-195,275);	
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(468,-135,275);	
	glVertex3d(468,-135,-260);	
	glVertex3d(468,-195,-260);
	glVertex3d(468,-195,275);	
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(468,-135,-260);	
	glVertex3d(-465,-135,-260);	
	glVertex3d(-465,-195,-260);	
	glVertex3d(468,-195,-260);	
	glEnd();

	glColor3f(1,1,1);
	glPopMatrix();

}
void check(){
	for(int i=0;i<5;i++){
		if((pos[i].first-100 <= c.Position.x && c.Position.x<= pos[i].first+100  ) && (pos[i].second-100 <= c.Position.z && c.Position.z<= pos[i].second+100)){
	
			if(keys['O'] && i==0&& pos[i].first!=0 ){
				p.m.rot.x=180;
				glLineWidth(20);
				glColor3f(1,0,0);
				glBegin(GL_LINES);
				glVertex3f(c.Position.x,c.Position.y,c.Position.z);
				glVertex3f(p.m.pos.x,p.m.pos.y,p.m.pos.z);
				glEnd();
				pos[i].first=0;
				p.D2=false;
			
			}
			if(keys['O'] && i==1 && pos[i].first!=0){
				p.n.rot.x=180;
			glLineWidth(30);
				glColor3f(1,0,0);
				glBegin(GL_LINES);
				glVertex3f(c.Position.x,c.Position.y,c.Position.z);
				glVertex3f(p.n.pos.x,p.n.pos.y,p.n.pos.z);
				glEnd();
				pos[i].first=0;
				p.C2=false;}

			if(keys['O'] && i==2&& pos[i].first!=0){
				p.k.rot.x=180;
				glColor3f(1,0,0);
				glLineWidth(20);
				glBegin(GL_LINES);
				glVertex3f(c.Position.x,c.Position.y,c.Position.z);
				glVertex3f(p.k.pos.x,p.k.pos.y,p.k.pos.z);
				glEnd();
				pos[i].first=0;
				p.E2=false;}

			if(keys['O'] && i==3 && pos[i].first!=0){
				p.j.rot.x=180;
				glColor3f(1,0,0);
				glLineWidth(20);
				glBegin(GL_LINES);
				glVertex3f(c.Position.x,c.Position.y,c.Position.z);
				glVertex3f(p.j.pos.x,p.j.pos.y,p.j.pos.z);
				glEnd();
				pos[i].first=0;
				p.F2=false;}

			if(keys['O'] && i==4 && pos[i].first!=0){
				p.p.rot.x=180;
				glColor3f(1,0,0);
				glLineWidth(20);
				glBegin(GL_LINES);
				glVertex3f(c.Position.x,c.Position.y,c.Position.z);
				glVertex3f(p.p.pos.x,p.p.pos.y,p.p.pos.z);
				glEnd();
				pos[i].first=0;
				p.G2=false;
			}}}
			}

bool canMove1( ){
	if(c.Position.x>2385 || c.Position.x<-2385 || c.Position.z<-1985 || c.Position.z>1985){
		c.MoveForward(-50);
		return false;}
	if(c.Position.x>-465 && c.Position.x<468 && c.Position.z<275 && c.Position.z>-265){
		c.MoveForward(-50);
		return false;}
	return true;
}
void camera()
{
	if(keys['W'] && canMove1( )){ 
		c.MoveForward(3);  
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y<<"  ";
		cout<<"z:"<<c.Position.z<<endl;
		cout<<"view x"<<c.View.x<<cout<<"  view Y:  "<<c.View.y<<"  View Z:   "<<c.View.z<<endl;
		}
	if(keys['S'] ) {
		c.MoveForward(-3);
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y<<"  ";
		cout<<"z:"<<c.Position.z<<endl;
	cout<<"view x"<<c.View.x<<cout<<"  view Y:  "<<c.View.y<<"  View Z:   "<<c.View.z<<endl;}
	if(keys['A'] && canMove1()){
		c.MoveRight(-3);
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y<<"  ";
		cout<<"z:"<<c.Position.z<<endl;
	cout<<"view x"<<c.View.x<<cout<<"  view Y:  "<<c.View.y<<"  View Z:   "<<c.View.z<<endl;}	
	if(keys['D']&& canMove1()){
		c.MoveRight(3);
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y<<"  ";
		cout<<"z:"<<c.Position.z<<endl;
	cout<<"view x"<<c.View.x<<cout<<"  view Y:  "<<c.View.y<<"  View Z:   "<<c.View.z<<endl;
	}
		
	if(keys['X']) {
		c.MoveUpward(1);	
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}
	if(keys['Z']){
		c.MoveUpward(-1);
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}
	if(keys[VK_LEFT]) c.RotateY(0.2);		if(keys[VK_RIGHT]) c.RotateY(-0.2);
	if(keys[VK_UP]) c.RotateX(-0.2);		if(keys[VK_DOWN]) c.RotateX(0.2);
	c.Render();
}
void camera2()
{
	if(keys['W'] && p.canMove(c)){ 
		c.MoveForward(0.7);  
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y-600<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}
	if(keys['S']) {
		c.MoveForward(-0.7);
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y-600<<"  ";
		cout<<"z:"<<c.Position.z<<endl;
		}
	if(keys['A'] && p.canMove(c)){
		c.MoveRight(-0.7);
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y-600<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}	
	if(keys['D']&& p.canMove(c)){
		c.MoveRight(0.7);
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y-600<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}
		
	if(keys['X'] ) {
		c.MoveUpward(0.7);	
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y-600<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}
	if(keys['Z']&& p.canMove(c)){
		c.MoveUpward(-0.7);
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}
	if(keys[VK_LEFT]) c.RotateY(0.2);		if(keys[VK_RIGHT]) c.RotateY(-0.2);
	if(keys[VK_UP]) c.RotateX(-0.2);		if(keys[VK_DOWN]) c.RotateX(0.2);
	if(!p.canMove(c)){
		c.MoveForward(-50);}	
		c.Render();




}
void camera3()
{
	if(keys['W'] && n.canmove(c)){ 
		c.MoveForward(0.7);  
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y-600<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}
	if(keys['S']) {
		c.MoveForward(-0.7);
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y-2000<<"  ";
		cout<<"z:"<<c.Position.z<<endl;
		}
	if(keys['A']&&  n.canmove(c)){
		c.MoveRight(-0.7);
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y-2000<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}	
	if(keys['D'] &&n.canmove(c)){
		c.MoveRight(0.7);
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y-2000<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}
		
	if(keys['X']&& n.canmove(c)) {
		c.MoveUpward(0.7);	
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y-2000<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}
	if(keys['Z']&& n.canmove(c)){
		c.MoveUpward(-0.7);
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}
	if(keys[VK_LEFT]) c.RotateY(0.2);		if(keys[VK_RIGHT]) c.RotateY(-0.2);
	if(keys[VK_UP]) c.RotateX(-0.2);		if(keys[VK_DOWN]) c.RotateX(0.2);
	if(! n.canmove(c))
		c.MoveForward(-50);
	c.Render();




}
void camera4()
{
	if(keys['W'] ){ 
		c.MoveForward(0.7);  
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y-4000<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}
	if(keys['S']) {
		c.MoveForward(-0.7);
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y-4000<<"  ";
		cout<<"z:"<<c.Position.z<<endl;
		}
	if(keys['A']){
		c.MoveRight(-0.7);
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y-4000<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}	
	if(keys['D'] ){
		c.MoveRight(0.7);
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y-4000<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}
		
	if(keys['X']) {
		c.MoveUpward(0.7);	
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y-4000<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}
	if(keys['Z']){
		c.MoveUpward(-0.7);
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}
	if(keys[VK_LEFT]) c.RotateY(0.2);		if(keys[VK_RIGHT]) c.RotateY(-0.2);
	if(keys[VK_UP]) c.RotateX(-0.2);		if(keys[VK_DOWN]) c.RotateX(0.2);
	c.Render();




}
void camera5()
{
	if(keys['W'] ){ 
		c.MoveForward(0.7);  
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}
	if(keys['S']) {
		c.MoveForward(-0.7);
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y<<"  ";
		cout<<"z:"<<c.Position.z<<endl;
		}
	if(keys['A']){
		c.MoveRight(-0.7);
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}	
	if(keys['D'] ){
		c.MoveRight(0.7);
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}
		
	if(keys['X']) {
		c.MoveUpward(0.7);	
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}
	if(keys['Z']){
		c.MoveUpward(-0.7);
		cout<<"x:"<<c.Position.x<<"  ";
		cout<<"y:"<<c.Position.y<<"  ";
		cout<<"z:"<<c.Position.z<<endl;}
	if(keys[VK_LEFT]) c.RotateY(0.2);		if(keys[VK_RIGHT]) c.RotateY(-0.2);
	if(keys[VK_UP]) c.RotateX(-0.2);		if(keys[VK_DOWN]) c.RotateX(0.2);
	c.Render();




}
void choose(){
		if(keys['1']){
		A=true;}
	else if(keys['2']){
		B=true;}
	else if(keys['3']){
		A1=true;}
	else if(keys['4']){
		C1=true;}
	else if(keys[VK_SPACE]){
		E1=true;}

}
void choose2(){
	if(A){
		c=Camera(1900,0,0,90);
		A=false;
		C=true;
		D=false;
		B1=false;
		D1=false;
		F1=false;}
	if(B){
		c=Camera(0,600,1000,0);
		B=false;
		D=true;
		C=false;
		B1=false;
		D1=false;
		F1=false;}
	if(A1){
		c=Camera(-1000,1600,1500,-20);
		A1=false;
		C=false;
		D=false;
		B1=true;
		D1=false;
		F1=false;}
	if(C1){
		c=Camera(-229,4650,1000,0);
		C1=false;
		C=false;
		D=false;
		B1=false;
		D1=true;
		F1=false;}
	if(E1){
		c=Camera(1934,-1815,456,170);
		E1=false;
		C=false;
		D=false;
		B1=false;
		D1=false;
		F1=true;
	}}
void skybox()
{

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, front);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2400, -200, -2000);
	glTexCoord2d(1, 0);
	glVertex3d(2400, -200, -2000);
	glTexCoord2d(1, 1);
	glVertex3d(2400, 200, -2000);
	glTexCoord2d(0, 1);
	glVertex3d(-2400, 200, -2000);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, back);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2400, -200, 2000);
	glTexCoord2d(1, 0);
	glVertex3d(2400, -200, 2000);
	glTexCoord2d(1, 1);
	glVertex3d(2400, 200, 2000);
	glTexCoord2d(0, 1);
	glVertex3d(-2400, 200, 2000);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, l);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2400, -200, 2000);
	glTexCoord2d(1, 0);
	glVertex3d(-2400, -200, -2000);
	glTexCoord2d(1, 1);
	glVertex3d(-2400, 200, -2000);
	glTexCoord2d(0, 1);
	glVertex3d(-2400, 200, 2000);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, r);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(2400, -200, 2000);
	glTexCoord2d(0, 0);
	glVertex3d(2400, -200, -2000);
	glTexCoord2d(0, 1);
	glVertex3d(2400, 200, -2000);
	glTexCoord2d(1, 1);
	glVertex3d(2400, 200, 2000);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, top);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2400, 200, -2000);
	glTexCoord2d(1, 0);
	glVertex3d(2400, 200, -2000);
	glTexCoord2d(1, 1);
	glVertex3d(2400, 200, 2000);
	glTexCoord2d(0, 1);
	glVertex3d(-2400, 200, 2000);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,flor);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2400, -200, -2000);
	glTexCoord2d(1, 0);
	glVertex3d(-2400,-200, 2000);
	glTexCoord2d(1, 1);
	glVertex3d(2400, -200, 2000);
	glTexCoord2d(0, 1);
	glVertex3d(2400, -200, -2000);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void cpu(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,cpuimg);

	glBegin(GL_POLYGON);
	glTexCoord2d(1, 0);
	glVertex3d(-465,-133,-260);	//A
	glTexCoord2d(1, 1);
	glVertex3d(-465,-133,275);	//C
	glTexCoord2d(0, 1);
	glVertex3d(468,-133,275);	//D
	glTexCoord2d(0, 0);
	glVertex3d(468,-133,-260);	//B
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	glColor3ub(0,0,0);

	glBegin(GL_POLYGON);
	glVertex3d(-465,-135,-260);	
	glVertex3d(-465,-135,275);	
	glVertex3d(-465,-195,275);
	glVertex3d(-465,-195,-260);	
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(-465,-135,275);	
	glVertex3d(468,-135,275);
	glVertex3d(468,-195,275);	
	glVertex3d(-465,-195,275);	
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(468,-135,275);	
	glVertex3d(468,-135,-260);	
	glVertex3d(468,-195,-260);
	glVertex3d(468,-195,275);	
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3d(468,-135,-260);	
	glVertex3d(-465,-135,-260);	
	glVertex3d(-465,-195,-260);	
	glVertex3d(468,-195,-260);	
	glEnd();

	glColor3f(1,1,1);


}
float z=0;
int DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glTranslated(0, 0, 0);

	choose();
	choose2();


	if(C){
		camera();}
	if(D){
		camera2();}
	if(B1){
		camera3();}
	if(D1){
		camera4();}
	if(F1){
		camera5();}


	glPushMatrix();
	glTranslated(0,-4000,0);
	glScaled(10,10,10);
	rooom.draw(0,0,0);
	glPopMatrix();
	
	/*glPushMatrix();
	glTranslated(0,5500,0);
	glScaled(60,60,60);
	rr.draw(0,0,0);
	glPopMatrix();
	*/
	glPushMatrix();
	skybox();

	cpu();
	GGpu(1915,0,-1715);
	HHdd(-1915,0,1715);
	FFan(-1915,0,-1715);
	p.draw(0,600,0);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0,2000,0);
	glScaled(6,6,6);
	n.draw(0,0,0);
	glPopMatrix();




	glPushMatrix();
	glTranslated(0,400,0);
	glScaled(100,100,100);
	f.buildPower(0,0,0);
	glPopMatrix();


	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glTranslated(-500,-5000,0);
	glScaled(2,2,5);
	ss.drawSSD(0,0,0);
	glDisable(GL_TEXTURE_2D);

	
	/*glPushMatrix();
	glTranslated(0,-7000,0);
	glScaled(60,60,60);
	hh.buildhard(0,0,0);
	glPopMatrix();*/


	pos[0]=make_pair (p.m.pos.x, p.m.pos.z);
	pos[1]=make_pair (p.n.pos.x, p.n.pos.z);
	pos[2]=make_pair (p.k.pos.x, p.k.pos.z);
	pos[3]=make_pair (p.j.pos.x, p.j.pos.z);
	pos[4]=make_pair (p.p.pos.x, p.p.pos.z);
	check();

	glPopMatrix();
	glColor3f(1,1,1);

	return TRUE;
}






/*m=Model_3DS() ;
	m.Load("Ant N170608.3ds");
	n=Model_3DS() ;
	n.Load("Ant N170608.3ds");
	k=Model_3DS() ;
	k.Load("Ant N170608.3ds");
	j=Model_3DS() ;
	j.Load("Ant N170608.3ds");
	p=Model_3DS() ;
	p.Load("Ant N170608.3ds");*/
	//X=0;
		/*void ant(){
		glColor3ub(101,67,33);
		glPushMatrix();
		m.pos.x=-500+X;
		m.pos.y=-190;
		m.pos.z=-90;
		m.rot.y=-90;
		m.Draw();
		glPopMatrix();
		
		glPushMatrix();
		n.pos.x=-500+X;
		n.pos.y=-190;
		n.pos.z=-90;
		n.rot.y=-90;
		n.Draw();
		glPopMatrix();

		glPushMatrix();
		k.pos.x=-500+X;
		k.pos.y=-190;
		k.pos.z=-90;
		k.rot.y=-90;
		k.Draw();
		glPopMatrix();

		glPushMatrix();
		j.pos.x=-500+X;
		j.pos.y=-190;
		j.pos.z=-90;
		j.rot.y=-90;
		j.Draw();
		glPopMatrix();

		glPushMatrix();
		p.pos.x=-500+X;
		p.pos.y=-190;
		p.pos.z=-90;
		p.rot.y=-90;
		p.Draw();
		glPopMatrix();
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		if(m.pos.x<500)
			X+=0.1;
		if(m.pos.x>=500)
			while(X>0)
				X-=0.001;





	}*/
GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
*	title			- Title To Appear At The Top Of The Window				*
*	width			- Width Of The GL Window Or Fullscreen Mode				*
*	height			- Height Of The GL Window Or Fullscreen Mode			*
*	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
*	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "GL template", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

																	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(HWND	hWnd,			// Handle For This Window
	UINT	uMsg,			// Message For This Window
	WPARAM	wParam,			// Additional Message Information
	LPARAM	lParam)			// Additional Message Information
{
	switch (uMsg)									// Check For Windows Messages
	{
	case WM_ACTIVATE:							// Watch For Window Activate Message
	{
		if (!HIWORD(wParam))					// Check Minimization State
		{
			active = TRUE;						// Program Is Active
		}
		else
		{
			active = FALSE;						// Program Is No Longer Active
		}

		return 0;								// Return To The Message Loop
	}

	case WM_SYSCOMMAND:							// Intercept System Commands
	{
		switch (wParam)							// Check System Calls
		{
		case SC_SCREENSAVE:					// Screensaver Trying To Start?
		case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
			return 0;							// Prevent From Happening
		}
		break;									// Exit
	}

	case WM_CLOSE:								// Did We Receive A Close Message?
	{
		PostQuitMessage(0);						// Send A Quit Message
		return 0;								// Jump Back
	}

	case WM_KEYDOWN:							// Is A Key Being Held Down?
	{
		keys[wParam] = TRUE;					// If So, Mark It As TRUE
		return 0;								// Jump Back
	}

	case WM_KEYUP:								// Has A Key Been Released?
	{
		keys[wParam] = FALSE;					// If So, Mark It As FALSE
		return 0;								// Jump Back
	}

	case WM_SIZE:								// Resize The OpenGL Window
	{
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
		return 0;								// Jump Back
	}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done = FALSE;								// Bool Variable To Exit Loop

														// Ask The User Which Screen Mode They Prefer
														//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("OpenGL template", 640, 480, 16, fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}

	while (!done)									// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message == WM_QUIT)				// Have We Received A Quit Message?
			{
				done = TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active)								// Program Active?
			{
				if (keys[VK_ESCAPE])				// Was ESC Pressed?
				{
					done = TRUE;						// ESC Signalled A Quit
				}
				else								// Not Time To Quit, Update Screen
				{
					DrawGLScene();					// Draw The Scene
					SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
				}
			}

			if (keys[VK_F1])						// Is F1 Being Pressed?
			{
				keys[VK_F1] = FALSE;					// If So Make Key FALSE
				KillGLWindow();						// Kill Our Current Window
				fullscreen = !fullscreen;				// Toggle Fullscreen / Windowed Mode
														// Recreate Our OpenGL Window
				if (!CreateGLWindow("OpenGL template", 640, 480, 16, fullscreen))
				{
					return 0;						// Quit If Window Was Not Created
				}
			}
		}
	}

	// Shutdown
	KillGLWindow();									// Kill The Window
	return (msg.wParam);							// Exit The Program
}
int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine , int nCmdShow)
{

	return WinMain(hInstance,hPrevInstance,IpCmdLine,nCmdShow);;
}