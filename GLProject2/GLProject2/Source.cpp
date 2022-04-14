#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include "BunnyModel.h"
using namespace std;

GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;
int cnt = 0; //��������
int z = -1; //ȸ�� ���� ����
int dir;//timer�Լ� �����
GLint g_objectID = 1;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);//���۳��� �����
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//���� ��� �ʱ�ȭ

	//glCallList(g_objectID);//GenerateCallList���� ������ ������Ʈ id�ѱ������ ������ �׸��� ����
	// 
	// 
	glBegin(GL_LINES);

	glColor3f(1, 0, 0); // X R

	glVertex3f(-1, 0, 0); glVertex3f(1, 0, 0);

	glColor3f(0, 1, 0); // Y G

	glVertex3f(0, -1, 0); glVertex3f(0, 1, 0);

	glColor3f(0, 0, 1); // Z B

	glVertex3f(0, 0, -1); glVertex3f(0, 0, 1);

	glEnd();

	{
		//glPushMatrix();
		//glTranslatef(0.7, 0.7, 1.0);//��ġ�̵�
		//glRotatef(45, 0.0, 0.0, 1.0);//ȸ��
		//glScalef(2.0, 2.0, 1.0);//ũ��Ȯ��//�� �Լ����� ��Ŀ����̹Ƿ� ȣ���� ����Ʒ��ź��� ����ȴ� �۷��� ��ȯ��Ģ �����ȵǹǷ� �����ؼ� �ۼ��ؾ��Ѵ�
		//
		//glBegin(GL_POLYGON);
		//glVertex3f(-0.1, -0.1, 0.0); glVertex3f(0.1, -0.1, 0.0); glVertex3f(0.1, 0.1, 0.0); glVertex3f(-0.1, 0.1, 0.0);
		//printf("%d\n", cnt = cnt + 1);
		//glEnd();
		//glPopMatrix();
		//
		//glPushMatrix();
		//glTranslatef(-0.4, 0, 0);
		//glRotatef(45, 0.0, 0.0, 1.0);
		//glBegin(GL_POLYGON);
		//
		//glVertex3f(-0.1, -0.1, 0.0); glVertex3f(0.1, -0.1, 0.0); glVertex3f(0.1, 0.1, 0.0); glVertex3f(-0.1, 0.1, 0.0);

		//printf("%d\n", cnt = cnt + 1);
		//glEnd();

		//glPopMatrix();
	}

	/*glutWireTeapot(0.2);
	glPushMatrix();
	glTranslated(2.0, 2.0,0.0);
	glutWireTeapot(0.2);
	glPushMatrix();
	glTranslatef(3.0,-1.0,0.0);
	glRotatef(45, 0.0, 0.0, 1.0);
	glScalef(2.0, 2.0, 2.0);
	glutWireTeapot(0.2);
	glPopMatrix();
	glPopMatrix();
	glTranslatef(0.0, -2.0, 0.0);
	glutWireTeapot(0.2);*/
	glPushMatrix();

	glTranslatef(-0.6, 0, 0);
	glutSolidCube(0.4);

	glPushMatrix();
	glColor3f(1.0,1.0,0);
	glTranslatef(0.0, 0.2, 0.0);
	glRotatef(-90, 1.0, 0, 0);
	glutSolidCone(0.2,0.3,36,10);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.2, 0.0,0.0);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidCube(0.4);
	glPopMatrix();
	glTranslatef(0.2, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidCube(0.4);
	glTranslatef(0.4, 0.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glutSolidCube(0.4);
	glTranslatef(0.0,0.2, 0.0);
	glRotatef(-90, 1.0, 0, 0);
	glColor3f(1.0, 1.0, 0.0);
	glutSolidCone(0.2, 0.3, 36, 10);
	glLoadIdentity();
	glFlush(); //���� �����޸� ���
	glutSwapBuffers();
}

GLint GenerateCallList() {//�Ź� ���� ���α׸��� ���귮�� ����-> �������� ������ ���
	GLint id = glGenLists(1);//������Ʈ id��ȣ ����
	glNewList(id, GL_COMPILE);// �� id���� ����Ʈ�� �����Ϲ��� �������� ����
	for (int i = 0; i < 16302; i++) {
		int vi;
		glBegin(GL_POINTS);
		vi = face_indicies[i][0]; glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);//x,y,z
		vi = face_indicies[i][1]; glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		vi = face_indicies[i][2]; glVertex3fv(vertices[vi]);
		glEnd();
	}

	/*glBegin(GL_LINES);
	for (int i = 0; i < 16302; i++) {
		int vi;

		vi = face_indicies[i][0]; glvertex3f(vertices[vi][0], vertices[vi][1],vertices[vi][2]);//x,y,z
		vi = face_indicies[i][1]; glvertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);

		vi = face_indicies[i][1]; glvertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		vi = face_indicies[i][2]; glvertex3fv(vertices[vi]);

		vi = face_indicies[i][2]; glvertex3fv(vertices[vi]);
		vi = face_indicies[i][0]; glvertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);

	}
	glEnd();*/
	//glLineWidth(2.0);
	glEndList();// ��� �ۼ��ߴٸ� endlist�� ���� ����
	return id;
}

void MyTimer(int value) {

	if (dir == 0) {
		z += 10;
	}
	else {
		z -= 10;
	}
	if (dir == -1) {
		if (z == 10) {
			z -= 10;
		}
		else {
			z += 10;
		}
	}
	glutPostRedisplay();//MyDisplay() ��ȣ��

	glutTimerFunc(100, MyTimer, 1);//���

}

void Mykeyboard(unsigned char KeyPressed, int x, int y) {
	switch (KeyPressed) {
	case 'Q': case 'q':
		exit(0); break;
	case 'Z':case 'z':
		z += 10;
		glutPostRedisplay();//�ٽ� �׸���� �ݹ��Լ�
		break;
	case 'X': case 'x':
		z -= 10;
		glutPostRedisplay();//�ٽ� �׸���� �ݹ��Լ�
		break;
	case '=':dir = 1;  break;
	case '-':dir = 0;  break;
	case 's':dir = -1; break;
	}

}



int main(int argc, char* argv[])//ǥ�� �Ű�����
{
	glutInit(&argc, argv);

	glutInitWindowSize(800, 800); // ������ ũ��

	glutInitWindowPosition(200, 200); // (100,100) ��ġ�� ������

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);//grb�� rgb��� single�̸� ������ ���۰� 1���̴�



	glutCreateWindow("OpenGL Example");

	glutSetWindowTitle("Updated OpenGL Example");



	int screenWidth, screenHeight;

	int windowWidth, windowHeight;

	int windowX, windowY;



	// Properties

	screenWidth = glutGet(GLUT_SCREEN_WIDTH); // ȭ�� �ʺ�

	screenHeight = glutGet(GLUT_SCREEN_HEIGHT); // ȭ�� ũ��

	windowWidth = glutGet(GLUT_INIT_WINDOW_WIDTH); // ������ �ʺ�

	windowHeight = glutGet(GLUT_WINDOW_HEIGHT); // ������ ũ��



	windowX = glutGet(GLUT_INIT_WINDOW_X); // ������ X ��ǥ

	windowY = glutGet(GLUT_INIT_WINDOW_Y); // ������ Y ��ǥ



	printf("Screen Info: %d %d\n", screenWidth, screenHeight);

	printf("Window Info: %d %d\n", windowWidth, windowHeight);

	printf("Window pos.: %d %d\n", windowX, windowY);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	//glutKeyboardFunc(Mykeyboard);
	//g_objectID = GenerateCallList();
	glutDisplayFunc(MyDisplay); // (���÷��� �ݹ� ���)
	//glutTimerFunc(100, MyTimer, 1);
	glutMainLoop(); // �߿� �ڵ� ������ (�̺�Ʈ ����)

}