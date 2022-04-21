#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include "BunnyModel.h"
using namespace std;

GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;
int cnt = 0; //��������
int z = 0;
GLint g_objectID = 1;
int dir=0;
void Mykeyboard(unsigned char KeyPressed, int x, int y) {// KeyPressed �� Ű���� ���������� Ű����,x,y�� ���������� ���콺 ��ǥ
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
	case '=':dir = 1;  break;//Ÿ�̸� ����� 1 �ð�
	case '-':dir = 0;  break;//Ÿ�̸� ����� 0 �ݽð�
	case 's':dir = -1; break;// ����
	}

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
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);//���۳��� �����
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//���� ��� �ʱ�ȭ
	glBegin(GL_LINES);

	glColor3f(1, 0, 0); // X R

	glVertex3f(-1, 0, 0); glVertex3f(1, 0, 0);

	glColor3f(0, 1, 0); // Y G

	glVertex3f(0, -1, 0); glVertex3f(0, 1, 0);

	glColor3f(0, 0, 1); // Z B

	glVertex3f(0, 0, -1); glVertex3f(0, 0, 1);

	glEnd();
	glRotatef(z, 0.0, 1.0, 0.0);//ȸ���Լ�

	glCallList(g_objectID);

	printf("%d\n", cnt = cnt + 1);
	glFlush(); //���� �����޸� ���
	glutSwapBuffers();
}
GLint GenerateCallList() {//�Ź� ���� ���α׸��� ���귮�� ����-> �������� ������ ���
	GLint id = glGenLists(1);
	glNewList(id, GL_COMPILE);
	for (int i = 0; i < 16302; i++) {
		int vi;
		glBegin(GL_POINTS);
		vi = face_indicies[i][0]; glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);//x,y,z
		vi = face_indicies[i][1]; glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		vi = face_indicies[i][2]; glVertex3fv(vertices[vi]);
		glEnd();
	}
	glEndList();
	return id;
}


int main(int argc, char* argv[])//ǥ�� �Ű�����
{
	glutInit(&argc, argv);
	glutInitWindowSize(300, 300); // ������ ũ��
	glutInitWindowPosition(100, 100); // (100,100) ��ġ�� ������
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

	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	g_objectID = GenerateCallList();//������ ������Ʈ ������ id ����
	glutDisplayFunc(MyDisplay); // (���÷��� �ݹ� ���)
	glutKeyboardFunc(Mykeyboard);
	glutTimerFunc(100, MyTimer, 1);// �ǵ� ���ڴ� Ÿ�̸� id (����Ÿ�̸������� �����ʿ�)
	
	glutMainLoop(); // �߿� �ڵ� ������ (�̺�Ʈ ����)
}