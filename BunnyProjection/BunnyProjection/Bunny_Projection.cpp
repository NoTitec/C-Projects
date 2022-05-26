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

GLint zDistance = 3; //  -2;   // increase & decrease + / -
GLint fovValue = 45; // 45;	// increase & decrease [ / ]

GLint GenerateCallList()
{
	unsigned int i;

	GLint lid = glGenLists(1);

	glNewList(lid, GL_COMPILE);

	for (i = 0; i < (sizeof(face_indicies) / sizeof(face_indicies[0])); i++)
	{
		int vi;

		glBegin(GL_LINES);
		vi = face_indicies[i][0];
		glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		vi = face_indicies[i][1];
		glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);

		vi = face_indicies[i][1];
		glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		vi = face_indicies[i][2];
		glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);

		vi = face_indicies[i][2];
		glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		vi = face_indicies[i][0];
		glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		glEnd();
	}

	glEndList();

	return lid;
}

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);

	// 변환 행렬을 프로젝션 행렬로 지정 
	 glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// 투상 방법 지정
	//glOrtho(-1.0, 1.0, -1.0, 1.0, -30.0, 30.0);	// 정사 투상
	gluPerspective(fovValue, 1.0, 0.1, 30.0);	// 원근 투상
	//glFrustum(-1.0, 1.0, -1.0, 1.0, -30.0, 30.0);
	// 변환 행렬을 모델링 행렬로 지정
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//glColor3f(1.0f, 0.0f, 0.0f);

	 gluLookAt(0.0, 0.0,zDistance, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glRotatef(xValue, 1.0, 0.0, 0.0);
	glRotatef(yValue, 0.0, 1.0, 0.0);
	glRotatef(zValue, 0.0, 0.0, 1.0);

	// Axis (좌표축그리는코드)
	glLineWidth(2);
	glBegin(GL_LINES);
	glColor3f(1.0f, 0.0f, 0.0f);		glVertex3f(0.0f, 0.0f, 0.0f);		glVertex3f(1.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);		glVertex3f(0.0f, 0.0f, 0.0f);		glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);		glVertex3f(0.0f, 0.0f, 0.0f);		glVertex3f(0.0f, 0.0f, 1.0f);
	glEnd();

	// display Call Lists
	glColor3f(1.0f, 1.0f, 0.0f);
	glCallList(g_stanfordBunnyID);
	// glutSolidTeapot(0.4);

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
	case 'a'://43: // +
		zDistance += 1;	printf("zDistance: %d\n", zDistance);
		break;
	case 's'://95: // -
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
	glutInitWindowSize(700, 700);
	glutCreateWindow("OpenGL Example");

	glClearColor(0.0, 0.0, 0.0, 0.0);

	g_stanfordBunnyID = GenerateCallList();

	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutMouseFunc(MyMouseClick);
	glutMotionFunc(MyMouseMove);
	glutMainLoop();

	return 0;
}