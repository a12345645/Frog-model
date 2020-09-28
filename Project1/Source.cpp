#include <GL/glut.h>
#include <math.h>
#include <iostream>
#define M_PI 3.14159265359


GLUquadricObj* quadricPtr = gluNewQuadric();
GLfloat m[16];

void XYZLine()
{
	glPushMatrix();
		glBegin(GL_LINES);
			glColor3f(0.0, 0.0, 0.0);
			glVertex3f(-400, 0, 0);
			glVertex3f(400, 0, 0);
			glVertex3f(0, 400, 0);
			glVertex3f(0, -400, 0);
			glVertex3f(0, 0, 400);
			glVertex3f(0, 0, -400);
		glEnd();
	glPopMatrix();
}

void HeadBone()                           // 頭骨架
{
	glPushMatrix();
		glTranslatef(0, 10, 0);

		glColor3f(0.84, 0.86, 0.28);
		glTranslatef(4.5, 0, 0);
		gluSphere(quadricPtr, 10, 40, 40);
		glTranslatef(-9, 0, 0);
		gluSphere(quadricPtr, 10, 40, 40);
		glPushMatrix();
			glRotatef(90, 0, 1, 0);
			gluCylinder(quadricPtr, 10.05, 10.05, 8.5, 40, 20);
		glPopMatrix();
		glTranslatef(-0.5, 0, 0);
	glPopMatrix();
}

void Eyes()             //眼睛
{
	glPushMatrix();

		glTranslatef(-5, 10, 0);
		glColor3f(1.0, 1.0, 1.0);

		glTranslatef(-2.0, 10.0, 5.0);   //左眼
		gluSphere(quadricPtr, 7.0, 20, 20);
		glTranslatef(14.0, 0.0, 0.0);   //右眼
		gluSphere(quadricPtr, 7.0, 20, 20);

		glColor3f(0.0, 0.0, 0.0);  //瞳孔

		glPushMatrix();  //左瞳孔
			glTranslatef(-13.0, 0.2, 7.5);
			glTranslatef(0.0, 0.0, -1);
			glRotatef(-21, 0, 1, 0);
			gluSphere(quadricPtr, 0.6, 20, 20);

			glPushMatrix();
				glTranslatef(-0.2, 0.2, 0.2);
				glRotatef(-30, 0, 0, 1);
				glRotatef(90, 0, 1, 0);
				glRotatef(35, 0, 1, 0);
				gluCylinder(quadricPtr, 0.6, 0.6, 3.5, 20, 20);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-0.2, -2.8, -0.1);
				glRotatef(30, 0, 0, 1);
				glRotatef(90, 0, 1, 0);
				glRotatef(35, 0, 1, 0);
				gluCylinder(quadricPtr, 0.6, 0.6, 3.5, 20, 20);
			glPopMatrix();

			glTranslatef(2.5, -1.3, -2.1);
			gluSphere(quadricPtr, 0.5, 20, 20);

			glTranslatef(-2.5, -1.5, 2);
			gluSphere(quadricPtr, 0.5, 20, 20);
		glPopMatrix();

		glPushMatrix();//右瞳孔
			glTranslatef(-2.5, 0, 6.2);
			glPushMatrix();
				glRotatef(-21, 0, 1, 0);
				m[0] = 4;
				m[5] = 4;
				m[10] = 1;
				m[15] = 1;
				glMultMatrixf(m);
				gluSphere(quadricPtr, 0.5, 20, 20);
			glPopMatrix();
		glPopMatrix();

	glPopMatrix();
}

void Mouth()            //嘴巴
{
	glPushMatrix();
		glTranslatef(-5, 10, -1.5);
		glPushMatrix();//左邊
			glTranslatef(-1.3, -4.5, 0);
			glPushMatrix();
				glTranslatef(-0.2, 0.2, 10.45);
				glRotatef(10, 0, 1, 0);
				glRotatef(-30, 0, 0, 1);
				glRotatef(13, 0, 0, 1);
				glRotatef(90, 0, 1, 0);
				gluCylinder(quadricPtr, 0.8, 0.8, 7, 20, 20);
			glPopMatrix();
			glTranslatef(0, 0.2, 10.45);
			gluSphere(quadricPtr, 0.7, 20, 20);
		glPopMatrix();

		glPushMatrix();//右邊
			glTranslatef(5.3, -6.7, 0);
			glPushMatrix();
				glTranslatef(-0.2, 0.3, 9.0);
				glRotatef(-10, 0, 1, 0);
				glRotatef(30, 0, 0, 1);
				glRotatef(-11, 0, 0, 1);
				glRotatef(90, 0, 1, 0);
				gluCylinder(quadricPtr, 0.8, 0.8, 7, 20, 20);
			glPopMatrix();
			glTranslatef(6.4, 2.55, 10.4);
			gluSphere(quadricPtr, 0.7, 20, 20);
		glPopMatrix();
		glTranslatef(5, -6.3, 9.0);
		gluSphere(quadricPtr, 0.8, 20, 20);

	glPopMatrix();
}

void Blushes()                  ////腮紅
{
	glPushMatrix();
		glColor3f(1.1, 0.7, 1.0);
		glTranslatef(-5, 10, -0.5);
		glPushMatrix();//左腮紅
			glTranslatef(-5, 0, 8.9);
			glPushMatrix();
				glRotatef(-30, 0, 1, 0);

				m[0] = 6;
				m[5] = 5;
				m[10] = 1;
				m[15] = 1;
				glMultMatrixf(m);
				gluSphere(quadricPtr, 0.5, 20, 20);
				glPopMatrix();
			glPopMatrix();
		glPushMatrix();//右腮紅
			glTranslatef(15, 0, 8.9);
			glPushMatrix();
				glRotatef(30, 0, 1, 0);

				m[0] = 6;
				m[5] = 5;
				m[10] = 1;
				m[15] = 1;
				glMultMatrixf(m);
				gluSphere(quadricPtr, 0.5, 20, 20);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

void BodyBone()
{
	glPushMatrix();
		glColor3f(1.0, 1.0, 1.0);
		glTranslatef(0, 2.5, 0);

		glPushMatrix();//主體
			glRotatef(90, 1, 0, 0);
			m[0] = 2.1;
			m[5] = 1.3;
			m[10] = 1;
			m[15] = 1;
			glMultMatrixf(m);
			gluCylinder(quadricPtr, 5, 6.5, 11, 20, 20);
		glPopMatrix();

		glPushMatrix();//下蓋
			glTranslatef(0, -10, 0);
			glRotatef(90, 1, 0, 0);
			m[0] = 26;
			m[5] = 16;
			m[10] = 0.5;
			m[15] = 1;
			glMultMatrixf(m);
			gluSphere(quadricPtr, 0.5, 20, 20);
		glPopMatrix();
	glPopMatrix();
}

void Stripe()           //身體條紋
{
	glPushMatrix();
	glTranslatef(0, 2.5, 0);
		glColor3f(1.06, 0.4, 0.54);
		glPushMatrix();//中
			glTranslatef(0, -5.5, 6.87);
			m[0] = 5;
			m[5] = 11;
			m[10] = 1.2;
			m[15] = 1;
			glPushMatrix();
				glRotatef(-10.1, 1, 0, 0);
				glMultMatrixf(m);
				glutSolidCube(1);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();//左
			glTranslatef(-7.5, -5.5, 5.3);
			m[0] = 5;
			m[5] = 11;
			m[10] = 1;
			m[15] = 1;
			glPushMatrix();
				glRotatef(-30.0, 0, 1, 0);
				glRotatef(-11.8, 1, 0, 0);
				glMultMatrixf(m);
				glutSolidCube(1);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();//右
			glTranslatef(7.5, -5.5, 5.3);
			m[0] = 5;
			m[5] = 11;
			m[10] = 1;
			m[15] = 1;
			glPushMatrix();
				glRotatef(30.0, 0, 1, 0);
				glRotatef(-11.8, 1, 0, 0);
				glMultMatrixf(m);
				glutSolidCube(1);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();//左側
			glTranslatef(-11.6, -5.5, 0);
			m[0] = 5;
			m[5] = 11;
			m[10] = 1;
			m[15] = 1;
			glPushMatrix();
				glRotatef(-16.0, 0, 0, 1);
				glRotatef(90, 0, 1, 0);
				glMultMatrixf(m);
				glutSolidCube(1);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();//右側
			glTranslatef(11.6, -5.5, 0);
			m[0] = 5;
			m[5] = 11;
			m[10] = 1;
			m[15] = 1;
			glPushMatrix();
				glRotatef(16.0, 0, 0, 1);
				glRotatef(90, 0, 1, 0);
				glMultMatrixf(m);
				glutSolidCube(1);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();//後中
			glTranslatef(0, -5.5, -6.87);
			m[0] = 5;
			m[5] = 11;
			m[10] = 1.2;
			m[15] = 1;
			glPushMatrix();
				glRotatef(10.1, 1, 0, 0);
				glMultMatrixf(m);
				glutSolidCube(1);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();//後右
			glTranslatef(-7.5, -5.5, -5.3);
			m[0] = 5;
			m[5] = 11;
			m[10] = 1;
			m[15] = 1;
			glPushMatrix();
				glRotatef(30.0, 0, 1, 0);
				glRotatef(11.8, 1, 0, 0);
				glMultMatrixf(m);
				glutSolidCube(1);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();//右
			glTranslatef(7.5, -5.5, -5.3);
			m[0] = 5;
			m[5] = 11;
			m[10] = 1;
			m[15] = 1;
			glPushMatrix();
				glRotatef(-30.0, 0, 1, 0);
				glRotatef(11.8, 1, 0, 0);
				glMultMatrixf(m);
				glutSolidCube(1);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();//蝴蝶結
			glColor3f(0, 0, 0);
			glPushMatrix();
				glTranslatef(3, -4, 6);
				glRotatef(30, 0, 1, 0);
				glRotatef(-15, 1, 0, 0);
				glRotatef(22, 0, 0, 1);
				glRotatef(45, 1, 1, 1);
				m[0] = 4;
				m[5] = 4;
				m[10] = 4;
				m[15] = 1;
				glMultMatrixf(m);
				glutSolidTetrahedron();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-3, -4, 6);
				glRotatef(-30, 0, 1, 0);
				glRotatef(200, 0, 0, 1);
				glRotatef(45, 1, 1, 1);
				m[0] = 4;
				m[5] = 4;
				m[10] = 4;
				m[15] = 1;
				glMultMatrixf(m);
				glutSolidTetrahedron();
			glPopMatrix();
		glPopMatrix();

	glPopMatrix();
}
void RightHand() //右手
{
	glPushMatrix();
		glTranslatef(12, 0, 0);
		glColor3f(0.84, 0.86, 0.28);
		glPushMatrix();//手臂
			glRotatef(30.0, 0, 0, 1);
			m[0] = 1.3;
			m[5] = 0.9;
			m[10] = 1;
			m[15] = 1;
			glMultMatrixf(m);
			gluSphere(quadricPtr, 4, 20, 20);
		glPopMatrix();

		glPushMatrix();//中指
			glTranslatef(4, 2.8, 0);
			glRotatef(30.0, 0, 0, 1);
			m[0] = 1.3;
			m[5] = 1;
			m[10] = 1;
			m[15] = 1;
			glMultMatrixf(m);
			gluSphere(quadricPtr, 1.2, 20, 20);
		glPopMatrix();

		glPushMatrix();//食指
			glTranslatef(2.3, 4, 0);
			glRotatef(35.0, 0, 0, 1);
			m[0] = 1.3;
			m[5] = 1;
			m[10] = 1;
			m[15] = 1;
			glMultMatrixf(m);
			gluSphere(quadricPtr, 1.2, 20, 20);
		glPopMatrix();

		glPushMatrix();//無名指
			glTranslatef(4.5, 0.9, 0);
			glRotatef(25.0, 0, 0, 1);
			m[0] = 1.3;
			m[5] = 1;
			m[10] = 1;
			m[15] = 1;
			glMultMatrixf(m);
			gluSphere(quadricPtr, 1.2, 20, 20);
		glPopMatrix();

	glPopMatrix();
}

void LeftHand()
{
	glPushMatrix();  //左手
		glTranslatef(-10, 0, 0);
		glColor3f(0.84, 0.86, 0.28);//glColor3f(0.95, 0.95, 0);
		glPushMatrix();//手臂
			glRotatef(40.0, 0, 0, 1);
			m[0] = 1.3;
			m[5] = 0.9;
			m[10] = 1;
			m[15] = 1;
			glMultMatrixf(m);
			gluSphere(quadricPtr, 4, 20, 20);
		glPopMatrix();

		glPushMatrix();//中指
			glTranslatef(-3.5, -3.5, 0);
			glRotatef(40.0, 0, 0, 1);
			m[0] = 1.3;
			m[5] = 1;
			m[10] = 1;
			m[15] = 1;
			glMultMatrixf(m);
			gluSphere(quadricPtr, 1.2, 20, 20);
		glPopMatrix();

		glPushMatrix();//食指
			glTranslatef(-3, -2.8, 2.5);
			glRotatef(-20.0, 0, 0, 1);
			glRotatef(40.0, 0, 0, 1);
			m[0] = 1.3;
			m[5] = 1;
			m[10] = 1;
			m[15] = 1;
			glMultMatrixf(m);
			gluSphere(quadricPtr, 1.2, 20, 20);
		glPopMatrix();

		glPushMatrix();//無名指
			glTranslatef(-3, -2.8, -2.5);
			glRotatef(-20.0, 0, 0, 1);
			glRotatef(40.0, 0, 0, 1);
			m[0] = 1.3;
			m[5] = 1;
			m[10] = 1;
			m[15] = 1;
			glMultMatrixf(m);
			gluSphere(quadricPtr, 1.2, 20, 20);
			glPopMatrix();
		glPopMatrix();
}

void RighFoot()       //右腳
{
	glPushMatrix();
		glRotatef(-10, 1, 0, 0);
		glColor3f(0.84, 0.86, 0.28);
		glPushMatrix();//小指
			glTranslatef(9, -8, 0);
			glRotatef(40, 0, 0, 1);
			m[0] = 1.1;
			m[5] = 1.5;
			m[10] = 1;
			m[15] = 1;
			glMultMatrixf(m);
			gluSphere(quadricPtr, 3, 20, 20);
		glPopMatrix();
		glPushMatrix();//中指
			glTranslatef(6, -7.5, 2);
			m[0] = 1;
			m[5] = 1.5;
			m[10] = 1;
			m[15] = 1;
			glMultMatrixf(m);
			gluSphere(quadricPtr, 3, 20, 20);
		glPopMatrix();
		glPushMatrix();//拇指
			glTranslatef(2, -8.5, 2);
			glRotatef(-10, 0, 0, 1);
			m[0] = 1.2;
			m[5] = 1.3;
			m[10] = 1;
			m[15] = 1;
			glMultMatrixf(m);
			gluSphere(quadricPtr, 3, 20, 20);
		glPopMatrix();


		glPopMatrix();

		glPushMatrix();//腿
			glPushMatrix();
				glTranslatef(5, -5, -0.5);
				glRotatef(10, 0, 1, 0);
				glRotatef(90, 1, 0, 0);
				m[0] = 0.95;
				m[5] = 0.6;
				m[10] = 1;
				m[15] = 1;
				glMultMatrixf(m);
				gluCylinder(quadricPtr, 7, 7, 6.4, 20, 20);
			glPopMatrix();
			glPushMatrix();//底
				glTranslatef(5, -11.2, -0.5);
				m[0] = 12;
				m[5] = 0.5;
				m[10] = 8;
				m[15] = 1;
				glMultMatrixf(m);
			gluSphere(quadricPtr, 0.5, 20, 20);
		glPopMatrix();
	glPopMatrix();
}

void LeftFoot()
{
	glPushMatrix();
		glPushMatrix();
			glRotatef(-10, 1, 0, 0);
			glPushMatrix();//小指
				glTranslatef(-9, -8, 0);
				glRotatef(-40, 0, 0, 1);
				m[0] = 0.8;
				m[5] = 1.5;
				m[10] = 1;
				m[15] = 1;
				glMultMatrixf(m);
				gluSphere(quadricPtr, 3, 20, 20);
			glPopMatrix();
			glPushMatrix();//中指
				glTranslatef(-6, -8, 2);
				glRotatef(-20, 0, 0, 1);
				m[0] = 1.15;
				m[5] = 1.5;
				m[10] = 1;
				m[15] = 1;
				glMultMatrixf(m);
				gluSphere(quadricPtr, 3, 20, 20);
			glPopMatrix();
			glPushMatrix();//拇指
				glTranslatef(-2.5, -8.3, 2);
				glRotatef(-10, 0, 0, 1);
				m[0] = 0.8;
				m[5] = 1.4;
				m[10] = 1;
				m[15] = 1;
				glMultMatrixf(m);
				gluSphere(quadricPtr, 3, 20, 20);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//腿
			glTranslatef(-4.8, -5, -0);
			glRotatef(-15, 0, 1, 0);
			glRotatef(90, 1, 0, 0);
			m[0] = 0.95;
			m[5] = 0.6;
			m[10] = 1;
			m[15] = 1;
			glMultMatrixf(m);
			gluCylinder(quadricPtr, 7, 7, 6.4, 20, 20);
		glPopMatrix();
		glPushMatrix();//底
			glTranslatef(-5, -11.2, -0.5);
			m[0] = 12;
			m[5] = 0.5;
			m[10] = 8;
			m[15] = 1;
			glMultMatrixf(m);
			gluSphere(quadricPtr, 0.5, 20, 20);

		glPopMatrix();
	
	glPopMatrix();
}

void Box(float x, float y, float z) //
{
	glPushMatrix();
	glScalef(x, y, z);
	glEnable(GL_TEXTURE_2D); //
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);// 
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);// 
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);// 
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);// 
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);//
	glPopMatrix();
}



bool line = false;
float angle = 0;
bool rotate = false;

void mydisplay() {


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.9, 0.9, 0.9, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	if (line == true)
		XYZLine();

	glShadeModel(GL_SMOOTH);
	gluQuadricNormals(quadricPtr, GLU_SMOOTH);

	for (int i = 0; i < 16; i++)
		m[i] = 0;
	m[0] = m[5] = m[10] = m[15] = 1;
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();

		glRotatef(angle, 0, 1, 0);

		glPushMatrix();   // 頭

			HeadBone();
			Eyes();
			Mouth();
			Blushes();

		glPopMatrix();

		glPushMatrix(); //身體

			BodyBone();
			Stripe();

		glPopMatrix();

		RightHand();

		LeftHand();

		RighFoot();

		LeftFoot();

	glPopMatrix();



	glFlush();
}

void init()
{
	GLfloat lightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
	//GLfloat lightPosition[] = { 5, 5, 5.0, 0.0 };
	GLfloat lightPosition[] = { 0.5, 0.5, 4.0, 0.0 };//光位置

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_SMOOTH);

	glDepthFunc(GL_LEQUAL);

	glMaterialfv(GL_FRONT, GL_SPECULAR, lightSpecular);
	glMaterialf(GL_FRONT, GL_SHININESS, 100.0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

	glEnable(GL_BLEND);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
}


void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
		glOrtho(-40.0, 40.0, -40.0*(GLfloat)h / (GLfloat)w, 40.0*(GLfloat)h / (GLfloat)w, -40.0, 40.0);
	else
		glOrtho(-40.0*(GLfloat)w / (GLfloat)h, 40.0*(GLfloat)w / (GLfloat)h, -40.0, 40.0, -40.0, 40.0);
		




	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

bool free_v = false;
float ax = 0, ay = 0, az = 0;
int far = 40;


void ron()
{
	glLoadIdentity();
	gluLookAt(0, 0, 0, -far * sin(ax * 2 * M_PI / 180), -far * sin(ay * 2 * M_PI / 180)
		, -far * cos(az * 2 * M_PI / 180), 0, 1, 0);
}

void view(int x)
{
	if (x == 0)
	{
		glLoadIdentity();
		ax = 0;
		ay = 0;
		az = 0;
	}
	else if (free_v == false)
	{
		switch (x)
		{
		case 1:
			gluLookAt(0, 0, 0, 40, -40, -40, 0, 1, 0);
			break;
		case 2:
			gluLookAt(0, 0, 0, 0, -40, 0, 0, 1, -1);
			break;
		case 3:
			gluLookAt(0, 0, 0, -40, -40, -40, 0, 1, 0);
			break;
		case 4:
			gluLookAt(0, 0, 0, 40, 0, 0, 0, 1, 0);
			break;
		case 6:
			gluLookAt(0, 0, 0, -40, 0, 0, 0, 1, 0);
			break;
		case 7:
			gluLookAt(0, 0, 0, 40, 40, -40, 0, 1, 0);
			break;
		case 8:
			gluLookAt(0, 0, 0, 0, 40, 0, 0, 1, 1);
			break;
		case 9:
			gluLookAt(0, 0, 0, -40, 40, -40, 0, 1, 0);
			break;
		default:
			break;
		}
	}
	else if (free_v == true)
	{
		switch (x)
		{
		case 1:
			ax --;
			ay ++;
			az --;
			break;
		case 2:
			ay ++;
			az--;
			break;
		case 3:
			ax ++;
			ay ++;
			az--;
			break;
		case 4:
			ax --;
			az--;
			break;
		case 6:
			ax ++;
			az--;
			break;
		case 7:
			ax --;
			ay --;
			az ++;
			break;
		case 8:
			ay --;
			az ++;
			break;
		case 9:
			ax ++;
			ay --;
			az ++;
			break;
		default:
			break;
		}
		if (ax == 360 || ax == -360)
			ax = 0;
		if (ay == 360 || ay == -360)
			ay = 0;
		if (az == 360 || az == -360)
			az = 0;
		ron();
		
	}
}



void keyboard(unsigned char key, int x, int y)
{
	if (key == 's' || key == 'S')
		view(0);
	else if (key == 'q' || key == 'Q')
		view(1);
	else if (key == 'w' || key == 'W')
		view(2);
	else if (key == 'e' || key == 'E')
		view(3);
	else if (key == 'a' || key == 'A')
		view(4);
	else if (key == 'd' || key == 'D')
		view(6);
	else if (key == 'z' || key == 'Z')
		view(7);
	else if (key == 'x' || key == 'X')
		view(8);
	else if (key == 'c' || key == 'C')
		view(9);
	else if (key == 'l' || key == 'L')
	{
		if (line == true)
			line = false;
		else
			line = true;
		mydisplay();
	}

	else if (key == 'r' || key == 'R')
	{
		if (rotate == true)
			rotate = false;
		else
			rotate = true;
	}

	else if ((key == 'f' || key == 'F') && rotate == false)
		angle = 0;
	else if (key == 'v' || key == 'V')
	{
		glLoadIdentity();
		if (free_v == true)
		{
			free_v = false;
			glutPostRedisplay();
		}
			
		else
		{
			free_v = true;
			glutPostRedisplay();
		}
			
		ax = 0;
		ay = 0;
	}
	else if ((key == 't' || key == 'T') && free_v == true)
	{
		far++;
		std::cout << "e";
	}
		

	glutPostRedisplay();
}

void Timer(int x)
{
	if (rotate == true)
	{
		angle += 10;
		if (angle >= 360)
			angle = 0;
	}

	glutTimerFunc(50, Timer, 0);
	mydisplay();
}



int  main(int argc, char** argv) {
	glutInitWindowSize(500, 500);
	glutCreateWindow("1063002 ");
	glutDisplayFunc(mydisplay);

	
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(50, Timer, 0);
	init();

	glutMainLoop();
}
