#include <iostream>
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>

using namespace std;

class Cpu
{
public :
	int  b, f, l, r, t,fr,transes;
	float X,Y,Z,J,K;
	bool C2,D2,E2,F2,G2;
	Model_3DS m,n,k,j,p;

public:
	Cpu(){
	l		= LoadTexture("subwall.bmp",255);
	r		= LoadTexture("subwall.bmp",255);
	t		= LoadTexture("grond.bmp",255);
	fr		= LoadTexture("grond.bmp",255);
	transes	= LoadTexture("trans.bmp",255);
	m=Model_3DS() ;
	m.Load("Ant N170608.3ds");
	n=Model_3DS() ;
	n.Load("Ant N170608.3ds");
	k=Model_3DS() ;
	k.Load("Ant N170608.3ds");
	j=Model_3DS() ;
	j.Load("Ant N170608.3ds");
	p=Model_3DS() ;
	p.Load("Ant N170608.3ds");
	X=0;
	Y=0;
	Z=0;
	J=0;
	K=0;
	C2=true;
	D2=true;
	E2=true;
	F2=true;
	G2=true;

	}
	void box(){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, r);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-1500, -200, -1500);
	glTexCoord2d(1, 0);
	glVertex3d(1500, -200, -1500);
	glTexCoord2d(1, 1);
	glVertex3d(1500, 200, -1500);
	glTexCoord2d(0, 1);
	glVertex3d(-1500, 200, -1500);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, r);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-1500, -200, 1500);
	glTexCoord2d(1, 0);
	glVertex3d(1500, -200, 1500);
	glTexCoord2d(1, 1);
	glVertex3d(1500, 200, 1500);
	glTexCoord2d(0, 1);
	glVertex3d(-1500, 200, 1500);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, r);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-1500, -200, 1500);
	glTexCoord2d(1, 0);
	glVertex3d(-1500, -200, -1500);
	glTexCoord2d(1, 1);
	glVertex3d(-1500, 200, -1500);
	glTexCoord2d(0, 1);
	glVertex3d(-1500, 200, 1500);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, r);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(1500, -200, 1500);
	glTexCoord2d(0, 0);
	glVertex3d(1500, -200, -1500);
	glTexCoord2d(0, 1);
	glVertex3d(1500, 200, -1500);
	glTexCoord2d(1, 1);
	glVertex3d(1500, 200,1500);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, t);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-1500, 200, -1500);
	glTexCoord2d(0, 1);
	
	glVertex3d(1500, 200, -1500);
	glTexCoord2d(1, 1);
	glVertex3d(1500, 200, 1500);
	glTexCoord2d(1, 0);
	glVertex3d(-1500, 200, 1500);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,fr);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-1500, -200, -1500);
	glTexCoord2d(1, 0);
	glVertex3d(-1500,-200, 1500);
	glTexCoord2d(1, 1);
	glVertex3d(1500, -200, 1500);
	glTexCoord2d(0, 1);
	glVertex3d(1500, -200, -1500);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	}
	bool canMove(Camera c){
		if(c.Position.x>1475 || c.Position.x<-1475 || c.Position.z<-1475 || c.Position.z>1475){
			c.MoveForward(-50);
		return false;}
		if(c.Position.x>-195 && c.Position.x<340 && c.Position.z>-570 && c.Position.z<580){
			c.MoveForward(-50);
		return false;}
	return true;
	}
	void trans(){

		glPushMatrix();
		glTranslated(0,0,0);
		glColor3f(0.8,0.8,0.8);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, transes);
		glBegin(GL_POLYGON);
		glTexCoord2d(0, 0);
		glVertex3f(-215,-200,560);
		glTexCoord2d(1, 0);
		glVertex3f(-215,200,560);
		glTexCoord2d(1, 1);
		glVertex3f(-130,200,560);
		glTexCoord2d(0, 1);
		glVertex3f(-130,-200,560);
		glEnd();

		glPushMatrix();
		glBegin(GL_POLYGON);
		glTexCoord2d(0, 0);
		glVertex3f(-215,-200,390);
		glTexCoord2d(1, 0);
		glVertex3f(-215,200,390);
		glTexCoord2d(1, 1);
		glVertex3f(-130,200,390);
		glTexCoord2d(0, 1);
		glVertex3f(-130,-200,390);
		glEnd();


		glPushMatrix();
		glBegin(GL_POLYGON);
		glTexCoord2d(0, 0);
		glVertex3f(-215,-200,560);
		glTexCoord2d(1, 0);
		glVertex3f(-215,200,560);
		glTexCoord2d(1, 1);
		glVertex3f(-215,200,390);
		glTexCoord2d(0, 1);
		glVertex3f(-215,-200,390);
		glEnd();

		
		glPushMatrix();
		glBegin(GL_POLYGON);
		glTexCoord2d(0, 0);
		glVertex3f(-130,-200,560);
		glTexCoord2d(1, 0);
		glVertex3f(-130,200,560);
		glTexCoord2d(1, 1);
		glVertex3f(-130,200,390);
		glTexCoord2d(0, 1);
		glVertex3f(-130,-200,390);
		glEnd();
		glColor3f(1,1,1);
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);
		

	}
	void draw(int x,int y,int z){
		glTranslated(x,y,z);
		box();

		trans();//1
		glPushMatrix();
		glTranslated(175,0,0);
		trans();

		glTranslated(175,0,0);
		trans();

		glTranslated(170,0,0);
		trans();

		glTranslated(170,0,0);
		trans();
		glPopMatrix();

		//2
		glPushMatrix();
		glTranslated(0,0,-225);
		trans();

		glTranslated(0,0,-225);
		trans();

		glTranslated(0,0,-225);
		trans();

		glTranslated(0,0,-225);
		trans();
		glPopMatrix();

		//3
		glPushMatrix();
		glTranslated(175,0,-225);
		trans();
		glTranslated(0,0,-225);
		trans();
		glTranslated(0,0,-225);
		trans();
		glTranslated(0,0,-225);
		trans();
		glPopMatrix();

		//4
		glPushMatrix();
		glTranslated(350,0,-225);
		trans();
		glTranslated(0,0,-225);
		trans();
		glTranslated(0,0,-225);
		trans();
		glTranslated(0,0,-225);
		trans();
		glPopMatrix();

		//5
		glPushMatrix();
		glTranslated(520,0,-225);
		trans();
		glTranslated(0,0,-225);
		trans();
		glTranslated(0,0,-225);
		trans();
		glTranslated(0,0,-225);
		trans();
		glPopMatrix();
	

		glPopMatrix();
		glPushMatrix();
		glColor3ub(101,67,33);
		
	//	glTranslated(-500,-190,-90);
		m.pos.x=-1000+X;
		m.pos.y=-190;
		m.pos.z=-90;
		m.rot.y=-90;
		//glRotated(-90,0,0,0);
		
		m.Draw();
		glPopMatrix();
		
		//
		glPushMatrix();
		n.pos.x=-467;
		n.pos.y=-185;
		n.pos.z=-800+Y;
	//	n.rot.y=-90;
		n.Draw();
		glPopMatrix();

		glPushMatrix();
		k.pos.x=-1000+Z;
		k.pos.y=-190;
		k.pos.z=-311;
		k.rot.y=-90;
		k.Draw();
		glPopMatrix();

		glPushMatrix();
		j.pos.x=-1000+J;
		j.pos.y=-190;
		j.pos.z=130;
		j.rot.y=-90;
		j.Draw();
		glPopMatrix();

		
		glPushMatrix();
		p.pos.x=-1000+K;
		p.pos.y=-190;
		p.pos.z=365;
		p.rot.y=-90;
		p.Draw();
		glPopMatrix();


		if(m.pos.x<500 && D2)
			X+=0.1;
		if(m.pos.x>=500)
			while(X>0)
				X-=0.001;
		
		if(n.pos.x<500 && C2)
			Y+=0.1;
		if(n.pos.x>=500)
			while(Y>0)
				Y-=0.001;

		if(k.pos.x<500 && E2)
			Z+=0.1;
		if(k.pos.x>=500)
			while(Z>0)
				Z-=0.001;

		if(j.pos.x<500 && F2)
			J+=0.1;
		if(j.pos.x>=500)
			while(J>0)
				J-=0.001;

		if(p.pos.x<500&& G2 )
			K+=0.1;
		if(p.pos.x>=500)
			while(K>0)
				K-=0.001;


		
		glColor3f(1,1,1);}};
