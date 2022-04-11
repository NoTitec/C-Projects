#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include "BunnyModel.h"
using namespace std;

GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;
int cnt = 0; //��������
int z = 0; //ȸ�� ���� ����
int dir ;//timer�Լ� �����
GLint g_objectID = 1;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);//���۳��� �����
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//���� ��� �ʱ�ȭ
	glRotatef(z, 0.0, 1.0, 0.0);//ȸ��
	glScalef(2.0, 1.0, 1.0);//ũ��Ȯ��//�� �Լ����� ��Ŀ����̹Ƿ� ȣ���� ����Ʒ��ź��� ����ȴ� �۷��� ��ȯ��Ģ �����ȵǹǷ� �����ؼ� �ۼ��ؾ��Ѵ�
	glTranslatef(0.2, 0, 0);//��ġ�̵�
	glCallList(g_objectID);
	printf("%d\n", cnt = cnt + 1);
	glFlush(); //���� �����޸� ���
	glutSwapBuffers();
}
GLint GenerateCallList() {
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
	glEndList();
	return id;
}
void MyTimer(int value) {
	
	if (dir == 0) {
		z += 10;
	}else {
		z -= 10;
	}
	if (dir == -1) {
		return;
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

	glutKeyboardFunc(Mykeyboard);
	g_objectID = GenerateCallList();
	glutDisplayFunc(MyDisplay); // (���÷��� �ݹ� ���)
	glutTimerFunc(100, MyTimer, 1);
	glutMainLoop(); // �߿� �ڵ� ������ (�̺�Ʈ ����)
	
}