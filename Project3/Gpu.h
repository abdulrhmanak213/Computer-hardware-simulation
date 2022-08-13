#include <iostream>
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>

class Gpu
{

public:
int back, front, left, right, top,ground;
int gpuu,gpuuT,Vramm,ress,pcl,fann;


bool canmove(Camera  c)
{
	if (c.Position.x<-1116 || c.Position.x>1154 || c.Position.z>1660 || c.Position.z<-2398){
		return 0;}
	if ((c.Position.x>-834 && c.Position.x<800) && (c.Position.z>1207 &&c.Position.z<1646)){
			return 0;}
	if ((c.Position.x>-812 && c.Position.x<743) && (c.Position.z<720 &&c.Position.z>-423)){
			c.MoveForward(-5);
			return 0;}
	return 1;

}
 Gpu()
	{
	ground = LoadTexture("subwall.bmp");
	back = LoadTexture("subwall.bmp");
	front = LoadTexture("subwall.bmp");
	left = LoadTexture("subwall.bmp");
	right = LoadTexture("subwall.bmp");
	top = LoadTexture("subwall.bmp"); 

	gpuu=LoadTexture("gpuu.bmp");
	gpuuT=LoadTexture("nvidia.bmp");
	Vramm =LoadTexture("vram.bmp");
	ress =LoadTexture("gcircut.bmp");
	pcl =LoadTexture("circut.bmp");
	fann =LoadTexture("nvidia.bmp");
	}
void skybox()
{
	
	glBindTexture(GL_TEXTURE_2D, back);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -200, 300);
	glTexCoord2d(1, 0);
	glVertex3d(200, -200, 300);
	glTexCoord2d(1, 1);
	glVertex3d(200, 100, 300);
	glTexCoord2d(0, 1);
	glVertex3d(-200, 100, 300);
	glEnd();  

	
	glBindTexture(GL_TEXTURE_2D, front);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -200, -400);
	glTexCoord2d(1, 0);
	glVertex3d(200, -200, -400);
	glTexCoord2d(1, 1);
	glVertex3d(200, 100, -400);
	glTexCoord2d(0, 1);
	glVertex3d(-200, 100, -400);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, left);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -200, 300);
	glTexCoord2d(1, 0);
	glVertex3d(-200, -200, -400);
	glTexCoord2d(1, 1);
	glVertex3d(-200, 100, -400);
	glTexCoord2d(0, 1);
	glVertex3d(-200, 100, 300);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, right);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(200, -200, 300);
	glTexCoord2d(0, 0);
	glVertex3d(200, -200, -400);
	glTexCoord2d(0, 1);
	glVertex3d(200, 100, -400);
	glTexCoord2d(1, 1);
	glVertex3d(200, 100, 300);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, top);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, 100, -400);
	glTexCoord2d(1, 0);
	glVertex3d(200, 100, -400);
	glTexCoord2d(1, 1);
	glVertex3d(200, 100, 300);
	glTexCoord2d(0, 1);
	glVertex3d(-200, 100, 300);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, ground);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -200, -400);
	glTexCoord2d(1, 0);
	glVertex3d(200, -200, -400);
	glTexCoord2d(1, 1);
	glVertex3d(200, -200, 300);
	glTexCoord2d(0, 1);
	glVertex3d(-200, -200, 300);
	glEnd(); 

}
void gpu()
{
	glBindTexture(GL_TEXTURE_2D, gpuu);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-75, -200, -25);
	glTexCoord2d(1, 0);
	glVertex3d(75, -200, -25);
	glTexCoord2d(1, 1);
	glVertex3d(75, -125, -25);
	glTexCoord2d(0, 1);
	glVertex3d(-75, -125, -25);
	glEnd();  

	glBindTexture(GL_TEXTURE_2D, gpuu);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-75, -200, 100);
	glTexCoord2d(1, 0);
	glVertex3d(75, -200, 100);
	glTexCoord2d(1, 1);
	glVertex3d(75, -125, 100);
	glTexCoord2d(0, 1);
	glVertex3d(-75, -125, 100);
	glEnd();  

	glBindTexture(GL_TEXTURE_2D, gpuu);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-75, -200, -25);
	glTexCoord2d(1, 0);
	glVertex3d(-75, -200, 100);
	glTexCoord2d(1, 1);
	glVertex3d(-75, -125, 100);
	glTexCoord2d(0, 1);
	glVertex3d(-75, -125, -25);
	glEnd();  

	glBindTexture(GL_TEXTURE_2D, gpuu);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(75, -200, -25);
	glTexCoord2d(1, 0);
	glVertex3d(75, -200, 100);
	glTexCoord2d(1, 1);
	glVertex3d(75, -125, 100);
	glTexCoord2d(0, 1);
	glVertex3d(75, -125, -25);
	glEnd();  

	glBindTexture(GL_TEXTURE_2D, gpuu);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-75, -125, -25);
	glTexCoord2d(1, 0);
	glVertex3d(75, -125, -25);
	glTexCoord2d(1, 1);
	glVertex3d(75, -125, 100);
	glTexCoord2d(0, 1);
	glVertex3d(-75, -125, 100);
	glEnd(); 	 }
void topGpu()
{//top quad
	glBindTexture(GL_TEXTURE_2D, gpuuT);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-60, -125, -15);
	glTexCoord2d(1, 0);
	glVertex3d(60, -125, -15);
	glTexCoord2d(1, 1);
	glVertex3d(60, -100, -15);
	glTexCoord2d(0, 1);
	glVertex3d(-60, -100, -15);
	glEnd();  

	glBindTexture(GL_TEXTURE_2D, gpuuT);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-60, -125, 90);
	glTexCoord2d(1, 0);
	glVertex3d(60, -125, 90);
	glTexCoord2d(1, 1);
	glVertex3d(60, -100, 90);
	glTexCoord2d(0, 1);
	glVertex3d(-60, -100, 90);
	glEnd();  

	glBindTexture(GL_TEXTURE_2D, gpuuT);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-60, -125, -15);
	glTexCoord2d(1, 0);
	glVertex3d(-60, -125, 90);
	glTexCoord2d(1, 1);
	glVertex3d(-60, -100, 90);
	glTexCoord2d(0, 1);
	glVertex3d(-60, -100, -15);
	glEnd();  

	glBindTexture(GL_TEXTURE_2D, gpuuT);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(60, -125, -15);
	glTexCoord2d(1, 0);
	glVertex3d(60, -125, 90);
	glTexCoord2d(1, 1);
	glVertex3d(60, -100, 90);
	glTexCoord2d(0, 1);
	glVertex3d(60, -100, -15);
	glEnd();  

	glBindTexture(GL_TEXTURE_2D, gpuuT);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-60, -100, -15);
	glTexCoord2d(1, 0);
	glVertex3d(60, -100, -15);
	glTexCoord2d(1, 1);
	glVertex3d(60, -100, 90);
	glTexCoord2d(0, 1);
	glVertex3d(-60, -100, 90);
	glEnd(); 	
} 
void Vram()
{
	glBindTexture(GL_TEXTURE_2D, Vramm );
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(100, -200, -25);
	glTexCoord2d(1, 0);
	glVertex3d(150, -200, -25);
	glTexCoord2d(1, 1);
	glVertex3d(150, -150, -25);
	glTexCoord2d(0, 1);
	glVertex3d(100, -150, -25);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, Vramm);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(100, -200, 15);
	glTexCoord2d(1, 0);
	glVertex3d(150, -200, 15);
	glTexCoord2d(1, 1);
	glVertex3d(150, -150, 15);
	glTexCoord2d(0, 1);
	glVertex3d(100, -150, 15);
	glEnd(); 

	glBindTexture(GL_TEXTURE_2D, Vramm);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(100, -200, -25);
	glTexCoord2d(1, 0);
	glVertex3d(100, -200, 15);
	glTexCoord2d(1, 1);
	glVertex3d(100, -150, 15);
	glTexCoord2d(0, 1);
	glVertex3d(100, -150, -25);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, Vramm);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(150, -200, -25);
	glTexCoord2d(1, 0);
	glVertex3d(150, -200, 15);
	glTexCoord2d(1, 1);
	glVertex3d(150, -150, 15);
	glTexCoord2d(0, 1);
	glVertex3d(150, -150, -25);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, Vramm);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(100, -150, -25);
	glTexCoord2d(1, 0);
	glVertex3d(150, -150, -25);
	glTexCoord2d(1, 1);
	glVertex3d(150, -150, 15);
	glTexCoord2d(0, 1);
	glVertex3d(100, -150, 15);
	glEnd();
	
	
}
void res()
	{glBindTexture(GL_TEXTURE_2D, ress);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-140, -200, 275);
	glTexCoord2d(1, 0);
	glVertex3d(-110, -200, 275);
	glTexCoord2d(1, 1);
	glVertex3d(-110, -175, 275);
	glTexCoord2d(0, 1);
	glVertex3d(-140, -175, 275);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, ress);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-140, -200, 200);
	glTexCoord2d(1, 0);
	glVertex3d(-110, -200, 200);
	glTexCoord2d(1, 1);
	glVertex3d(-110, -175, 200);
	glTexCoord2d(0, 1);
	glVertex3d(-140, -175, 200);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, ress);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-140, -200, 275);
	glTexCoord2d(1, 0);
	glVertex3d(-140, -200, 200);
	glTexCoord2d(1, 1);
	glVertex3d(-140, -175, 200);
	glTexCoord2d(0, 1);
	glVertex3d(-140, -175, 275);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, ress);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-110, -200, 275);
	glTexCoord2d(1, 0);
	glVertex3d(-110, -200, 200);
	glTexCoord2d(1, 1);
	glVertex3d(-110, -175, 200);
	glTexCoord2d(0, 1);
	glVertex3d(-110, -175, 275);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, ress);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-140, -175, 275);
	glTexCoord2d(1, 0);
	glVertex3d(-140, -175, 200);
	glTexCoord2d(1, 1);
	glVertex3d(-110, -175, 200);
	glTexCoord2d(0, 1);
	glVertex3d(-110, -175, 275);
	glEnd();
}
void pcle()
{   glBindTexture(GL_TEXTURE_2D, pcl);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -200, -400);
	glTexCoord2d(1, 0);
	glVertex3d(-150, -200, -400);
	glTexCoord2d(1, 1);
	glVertex3d(-150, -190, -400);
	glTexCoord2d(0, 1);
	glVertex3d(-200, -190, -400);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, pcl);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -200, -150);
	glTexCoord2d(1, 0);
	glVertex3d(-150, -200, -150);
	glTexCoord2d(1, 1);
	glVertex3d(-150, -190, -150);
	glTexCoord2d(0, 1);
	glVertex3d(-200, -190, -150);
	glEnd();

    glBindTexture(GL_TEXTURE_2D, pcl);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-150, -200, -400);
	glTexCoord2d(1, 0);
	glVertex3d(-150, -200, -150);
	glTexCoord2d(1, 1);
	glVertex3d(-150, -190, -150);
	glTexCoord2d(0, 1);
	glVertex3d(-150, -190, -400);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, pcl);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -200, -400);
	glTexCoord2d(1, 0);
	glVertex3d(-200, -200, -150);
	glTexCoord2d(1, 1);
	glVertex3d(-200, -190, -150);
	glTexCoord2d(0, 1);
	glVertex3d(-200, -190, -400);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, pcl);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-200, -190, -400);
	glTexCoord2d(1, 0);
	glVertex3d(-200, -190, -150);
	glTexCoord2d(1, 1);
	glVertex3d(-150, -190, -150);
	glTexCoord2d(0, 1);
	glVertex3d(-150, -190, -400);
	glEnd();

	
}
	void draw(int x,int y,int z)
	{
	glTranslated(x,y,z);
	skybox();
	//glScaled(0.75,0.75,0.75);
	gpu();
	topGpu();
	Vram();



	glPushMatrix();
	glTranslated(0,0,50);
	Vram();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,100);
	Vram();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,-50);
	Vram();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-60,0,-50);
	Vram();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-120,0,-50);
	Vram();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-180,0,-50);
	Vram();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-240,0,-50);
	Vram();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-240,0,0);
	Vram();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-240,0,50);
	Vram();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-240,0,100);
	Vram();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-160,0,130);
	Vram();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-80,0,130);
	Vram();
	glPopMatrix();

	res();

	glPushMatrix();
	glTranslated(50,0,0);
	res();
	glPopMatrix();

	glPushMatrix();
	glTranslated(100,0,0);
	res();
	glPopMatrix();

	glPushMatrix();
	glTranslated(150,0,0);
	res();
	glPopMatrix();

	glPushMatrix();
	glTranslated(200,0,0);
	res();
	glPopMatrix();

	glPushMatrix();
	glTranslated(250,0,0);
	res();
	glPopMatrix();

	pcle();

	glPushMatrix();
	glTranslated(115,0,0);
	pcle();
	glPopMatrix();

		glPushMatrix();
	glTranslated(230,0,0);
	pcle();
	glPopMatrix();

		glPushMatrix();
		glTranslated(350,0,0);
		pcle();
		glPopMatrix();

		glPushMatrix();}};

