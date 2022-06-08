// ���� ���õ� ����

#include <glut.h>						
#include <GL/gl.h>							
#include <GL/glu.h>		
#include <stdio.h>

#include "BunnyModel.h"

GLuint g_stanfordBunnyID = -1;

GLint xValue = 0;
GLint yValue = 0;
GLint zValue = 0;

GLint clickDown = 0;
GLint fixX = 0;
GLint fixY = 0;

GLint zDistance = 6; //  -2;   // increase & decrease + / -
GLint fovValue = 45;  // 45;	// increase & decrease [ / ]

// Light position
GLfloat light0Pos[] = { 0.0, 0.0, 3.0, 0.0 };//������ġ
GLfloat light0ambient[] = { 1.0, 0.0, 0.0, 1.0 };  //0�� ���� �ֺ��� Ư�� (�ֺ� ȯ�濡 ���� ����� ��)
GLfloat light0diffuse[] = { 1.0, 1.0, 0.0, 1.0 };  //0�� ���� Ȯ�걤 Ư�� (���� ��)
GLfloat light0specular[] = { 0.0, 1.0, 0.0, 1.0 }; //0�� ���� �ݻ籤 Ư��

GLint GenerateCallList()
{
	GLint lid = glGenLists(1);

	glNewList(lid, GL_COMPILE);

	// Coding : Bunny Model �׸��� (���� �� ���� Ȱ��)
	for (unsigned int i = 0; i < (sizeof(face_indicies) / sizeof(face_indicies[0])); i++)
	{
		int vi;
		int ni;
		glBegin(GL_POLYGON);
		vi = face_indicies[i][0];
		ni = face_indicies[i][3];
		glNormal3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		//glTexCoord2f();
		glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		vi = face_indicies[i][1];
		ni = face_indicies[i][4];
		glNormal3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		//glTexCoord2f();
		glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		vi = face_indicies[i][2];
		ni = face_indicies[i][5];
		glNormal3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		//glTexCoord2f();
		glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		glEnd();
	}

	glEndList();

	return lid;
}

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// ��ȯ ����� �������� ��ķ� ���� 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// ���� ��� ����
	// glOrtho(-1.0, 1.0, -1.0, 1.0, -30.0, 30.0);	// Orthogonal Proj.
	gluPerspective(fovValue, 1.0, 0.1, 30.0);	// Perspective Proj.

	// ��ȯ ����� �𵨸� ��ķ� ����
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0, 0.0, zDistance, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glRotatef(xValue, 1.0, 0.0, 0.0);
	glRotatef(yValue, 0.0, 1.0, 0.0);
	glRotatef(zValue, 0.0, 0.0, 1.0);

	// Axis
	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);		glVertex3f(0.0f, 0.0f, 0.0f);		glVertex3f(1.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);		glVertex3f(0.0f, 0.0f, 0.0f);		glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);		glVertex3f(0.0f, 0.0f, 0.0f);		glVertex3f(0.0f, 0.0f, 1.0f);
	glEnd();

	// ���� ��ġ
	glLightfv(GL_LIGHT0, GL_POSITION, light0Pos);		//0�� ���� ��ġ�Ҵ�

	glPushMatrix();
	glColor3fv(light0diffuse);
	glTranslatef(light0Pos[0], light0Pos[1], light0Pos[2]);
	glutSolidSphere(0.05, 36, 36);
	glPopMatrix();

	// display Call Lists
	glColor3f(1.0, 0.0, 0.0);
	 glEnable(GL_LIGHTING); //��������
	glCallList(g_stanfordBunnyID);
	 glDisable(GL_LIGHTING);

	glFlush();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
	switch (KeyPressed) {
	case 'X':
	case 'x':
		xValue += 1;
		if (xValue > 360) xValue -= 360;
		break;
	case 'Y':
	case 'y':
		yValue += 1;
		if (yValue > 360) yValue -= 360;
		break;
	case 'Z':
	case 'z':
		zValue += 1;
		if (zValue > 360) zValue -= 360;
		break;
	case 'Q':
	case 'q':
		exit(0); break;
	case 32: // SPACE key
		xValue = 0;
		yValue = 0;
		zValue = 0;
		break;
	case 27: // ESC key
		exit(0);
		break;
	case 91: // [
		fovValue += 1; printf("fovValue: %d\n", fovValue);
		break;
	case 93: // ]
		fovValue -= 1; printf("fovValue: %d\n", fovValue);
		break;
	case 43: // +
		zDistance += 1;	printf("zDistance: %d\n", zDistance);
		break;
	case 95: // -
		zDistance -= 1;	printf("zDistance: %d\n", zDistance);
		break;
	}

	glutPostRedisplay();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		fixX = X;
		fixY = Y;
		clickDown = 1;
	}
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_UP) {
		clickDown = 0;
	}
}

void MyMouseMove(GLint X, GLint Y) {
	if (clickDown == 1)
	{
		yValue = yValue + (fixX - X);
		xValue = xValue + (fixY - Y);

		fixX = X;
		fixY = Y;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(700, 700);
	glutCreateWindow("OpenGL Example");

	glClearColor(0.0, 0.0, 0.0, 0.0);

	g_stanfordBunnyID = GenerateCallList();

	// Lighting ����
	 glEnable(GL_LIGHT0);								// 0�� ���� ��� ����

	 glLightfv(GL_LIGHT0, GL_AMBIENT, light0ambient);	// 0�� ���� Ư���Ҵ�
	 glLightfv(GL_LIGHT0, GL_DIFFUSE, light0diffuse);
	 glLightfv(GL_LIGHT0, GL_SPECULAR, light0specular);

	glShadeModel(GL_SMOOTH);	// glShadeModel(GL_FLAT); ���̵���弳��

	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutMouseFunc(MyMouseClick);
	glutMotionFunc(MyMouseMove);
	glutMainLoop();

	return 0;
}