
#include <iostream>
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include "Model_3DS.h"
#include "GLTexture.h"
//#include <texture.h>

using namespace std;

class room
{
public:

	int back, front, l, r, top,g, wall,roof,earth, tableee;
room(){
	glEnable(GL_TEXTURE_2D);
	g = LoadTexture("subwall.bmp");
	back = LoadTexture("subwall.bmp");
	front = LoadTexture("subwall.bmp");
	l = LoadTexture("subwall.bmp");
	r = LoadTexture("subwall.bmp");
	top = LoadTexture("subwall.bmp"); 

	wall=LoadTexture("wall2.bmp");
	roof=LoadTexture("roof3.bmp");
	earth=LoadTexture("carpets.bmp");
	tableee=LoadTexture("roof5.bmp");
	glDisable(GL_TEXTURE_2D);
}

void skybox()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0,0,0);
	glTexCoord2d(1, 0);
	glVertex3d(300,0,0);
	glTexCoord2d(1, 1);
	glVertex3d(300,300,0);
	glTexCoord2d(0, 1);
	glVertex3d(0,300,0);
	glEnd();  

glBindTexture(GL_TEXTURE_2D, wall);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0,0,300);
	glTexCoord2d(1, 0);
	glVertex3d(300,0,300);
	glTexCoord2d(1, 1);
	glVertex3d(300,300,300);
	glTexCoord2d(0, 1);
	glVertex3d(0,300,300);
	glEnd();  


	glBindTexture(GL_TEXTURE_2D, wall);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0,0,0);
	glTexCoord2d(1, 0);
	glVertex3d(0,0,300);
	glTexCoord2d(1, 1);
	glVertex3d(0,300,300);
	glTexCoord2d(0, 1);
	glVertex3d(0,300,0);
	glEnd();

		glBindTexture(GL_TEXTURE_2D, wall);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(300,0,0);
	glTexCoord2d(1, 0);
	glVertex3d(300,0,300);
	glTexCoord2d(1, 1);
	glVertex3d(300,300,300);
	glTexCoord2d(0, 1);
	glVertex3d(300,300,0);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, roof);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0,300,0);
	glTexCoord2d(1, 0);
	glVertex3d(0,300,300);
	glTexCoord2d(1, 1);
	glVertex3d(300,300, 300);
	glTexCoord2d(0, 1);
	glVertex3d(300,300,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, earth);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(0,0,0);
	glTexCoord2d(1, 0);
	glVertex3d(0,0,300);
	glTexCoord2d(1, 1);
	glVertex3d(300,0, 300);
	glTexCoord2d(0, 1);
	glVertex3d(300,0,0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void table()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tableee);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(75,100,225);
	glTexCoord2d(1, 0);
	glVertex3d(225,100,225);
	glTexCoord2d(1, 1);
	glVertex3d(225,110,225);
	glTexCoord2d(0, 1);
	glVertex3d(75,110,225);
	glEnd();  

	glBindTexture(GL_TEXTURE_2D, tableee);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(75,100,275);
	glTexCoord2d(1, 0);
	glVertex3d(225,100,275);
	glTexCoord2d(1, 1);
	glVertex3d(225,110,275);
	glTexCoord2d(0, 1);
	glVertex3d(75,110,275);
	glEnd();  



	glBindTexture(GL_TEXTURE_2D, tableee);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(75,100,225);
	glTexCoord2d(1, 0);
	glVertex3d(75,100,275);
	glTexCoord2d(1, 1);
	glVertex3d(75,110,275);
	glTexCoord2d(0, 1);
	glVertex3d(75,110,225);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, tableee);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(225,100,225);
	glTexCoord2d(1, 0);
	glVertex3d(225,100,275);
	glTexCoord2d(1, 1);
	glVertex3d(225,110,275);
	glTexCoord2d(0, 1);
	glVertex3d(225,110,225);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, tableee);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(75,110,225);
	glTexCoord2d(1, 0);
	glVertex3d(225,110,225);
	glTexCoord2d(1, 1);
	glVertex3d(225,110, 275);
	glTexCoord2d(0, 1);
	glVertex3d(75,110,275);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, tableee);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(75,100,225);
	glTexCoord2d(1, 0);
	glVertex3d(225,100,225);
	glTexCoord2d(1, 1);
	glVertex3d(225,100, 275);
	glTexCoord2d(0, 1);
	glVertex3d(75,100,275);
	glEnd();
	glDisable(GL_TEXTURE_2D);

}
void colom()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tableee);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(75,100,225);
	glTexCoord2d(1, 0);
	glVertex3d(80,100,225);
	glTexCoord2d(1, 1);
	glVertex3d(80,100,230);
	glTexCoord2d(0, 1);
	glVertex3d(75,100,230);
	glEnd();  
		
	glBindTexture(GL_TEXTURE_2D, tableee);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(75,0,225);
	glTexCoord2d(1, 0);
	glVertex3d(80,0,225);
	glTexCoord2d(1, 1);
	glVertex3d(80,0,230);
	glTexCoord2d(0, 1);
	glVertex3d(75,0,230);
	glEnd();  

	glBindTexture(GL_TEXTURE_2D, tableee);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(75,100,225);
	glTexCoord2d(1, 0);
	glVertex3d(80,100,225);
	glTexCoord2d(1, 1);
	glVertex3d(80,0,225);
	glTexCoord2d(0, 1);
	glVertex3d(75,0,225);
	glEnd();  

		glBindTexture(GL_TEXTURE_2D, tableee);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(75,100,230);
	glTexCoord2d(1, 0);
	glVertex3d(80,100,230);
	glTexCoord2d(1, 1);
	glVertex3d(80,0,230);
	glTexCoord2d(0, 1);
	glVertex3d(75,0,230);
	glEnd();  

		glBindTexture(GL_TEXTURE_2D, tableee);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(75,100,225);
	glTexCoord2d(1, 0);
	glVertex3d(75,100,230);
	glTexCoord2d(1, 1);
	glVertex3d(75,0,230);
	glTexCoord2d(0, 1);
	glVertex3d(75,0,225);
	glEnd(); 

		glBindTexture(GL_TEXTURE_2D, tableee);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(80,100,225);
	glTexCoord2d(1, 0);
	glVertex3d(80,100,230);
	glTexCoord2d(1, 1);
	glVertex3d(80,0,230);
	glTexCoord2d(0, 1);
	glVertex3d(80,0,225);
	glEnd(); 
	glDisable(GL_TEXTURE_2D);
}

void draw(int x,int y,int z)
	{
	
	glTranslated(x,y,z);
	skybox();
	table();
	colom();
	//B R
	glPushMatrix;
	glTranslated(0,0,45);
	colom();
	glPopMatrix;
	//F L
	glPushMatrix;
	glTranslated(145,0,0);
	colom();
	glPopMatrix;
	//B L
	glPushMatrix;
	glTranslated(0,0,-45);
	colom();
	glPopMatrix;

	
	}

};

