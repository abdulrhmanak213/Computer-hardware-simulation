#include "Cpu.h"

#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library

#include <cmath>
#include <glaux.h>		// Header File For The Glaux Library
#include "texture.h"




void init(){
	b		= LoadTexture("wall1.bmp",255);
	f		= LoadTexture("wall1.bmp",255);
	l		= LoadTexture("wall1.bmp",255);
	r		= LoadTexture("wall1.bmp",255);
	t		= LoadTexture("stars.bmp",255);
	fr		= LoadTexture("floor.bmp",255);
	}
	void box(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, f);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-400, -200, -2000);
	glTexCoord2d(1, 0);
	glVertex3d(400, -200, -2000);
	glTexCoord2d(1, 1);
	glVertex3d(400, 200, -2000);
	glTexCoord2d(0, 1);
	glVertex3d(-400, 200, -2000);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, b);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-400, -200, 500);
	glTexCoord2d(1, 0);
	glVertex3d(400, -200, 500);
	glTexCoord2d(1, 1);
	glVertex3d(400, 200, 500);
	glTexCoord2d(0, 1);
	glVertex3d(-400, 200, 500);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, l);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-400, -200, 500);
	glTexCoord2d(1, 0);
	glVertex3d(-400, -200, -500);
	glTexCoord2d(1, 1);
	glVertex3d(-400, 200, -500);
	glTexCoord2d(0, 1);
	glVertex3d(-400, 200, 500);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, r);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(400, -200, 500);
	glTexCoord2d(0, 0);
	glVertex3d(400, -200, -500);
	glTexCoord2d(0, 1);
	glVertex3d(400, 200, -500);
	glTexCoord2d(1, 1);
	glVertex3d(400, 200,500);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, t);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-400, 200, -500);
	glTexCoord2d(1, 0);
	glVertex3d(400, 200, -500);
	glTexCoord2d(1, 1);
	glVertex3d(400, 200, 500);
	glTexCoord2d(0, 1);
	glVertex3d(-400, 200, 500);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,fr);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-400, -200, -500);
	glTexCoord2d(1, 0);
	glVertex3d(-400,-200, 500);
	glTexCoord2d(1, 1);
	glVertex3d(400, -200, 500);
	glTexCoord2d(0, 1);
	glVertex3d(400, -200, -500);
	glEnd();
	glDisable(GL_TEXTURE_2D);}


	void draw(int x,int y,int z){
		glTranslated(x,y,z);
		box();}

