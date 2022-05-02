#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
using namespace std;

GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;
int cnt = 0; //��������
int z = 0;
void MyDisplay() {
	//glClear(GL_COLOR_BUFFER_BIT);//���۳��� �����
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();//���� ��� �ʱ�ȭ
	//glRotatef(z, 0.0, 0.0, 1.0);//ȸ���Լ�
	//glutWireTeapot(0.5);//glut�Լ��� glBegin,glEnd�ʿ����
	//glPointSize(4.0);
	glLineWidth(2.0);
	//glBegin(GL_LINES);//�׸��� ���� �׸��� ���� �������� �Ű�����
	/*glColor3f(1.0, 0, 0); glVertex3f(-0.5, -0.5, 0.0);//�簢�� ���������̼�(������)���� ���� ä��
	glColor3f(0, 1.0, 0); glVertex3f(0.5, -0.5, 0.0);
	glColor3f(0, 0, 1.0); glVertex3f(0.5, 0.5, 0.0);
	glColor3f(0, 1.0, 1.0); glVertex3f(-0.5, 0.5, 0.0);*/

	/*glColor3f(1.0, 0, 0); glVertex3f(0.0, 0.0, 0.0); ����
	glColor3f(0, 1.0, 0); glVertex3f(0.5, 0.0, 0.0);
	glColor3f(0, 0, 1.0); glVertex3f(0.0, 0.5, 0.0);*/

	//glColor3f(1.0, 0, 0); glVertex3f(0.0, 0.0, 0.0); //��
	//glVertex3f(0.5, 0.0, 0.0);
	//glColor3f(0, 1.0, 0); glVertex3f(0.0, 0.5, 0.0);
	//glVertex3f(0.5, 0.5, 0);

	//glColor3f(1,1, 0); glVertex3f(-0.5, 0, 0);//�ﰢ��
	//glVertex3f(-0.2, 0, 0); glVertex3f(-0.6, 0.5, 0);
	//glColor3f(0, 0, 1); glVertex3f(0, 0, 0);
	//glVertex3f(0.2, 0, 0); glVertex3f(0.1, 0.3, 0);

	//glutSolidSphere(0.5, 1000, 100);//��
	//glEnd();//�׸��� ����

	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	glVertex3f(TopLeftX / 300.0, (300 - TopLeftY) / 300.0, 0.0);

	glVertex3f(TopLeftX / 300.0, (300 - BottomRightY) / 300.0, 0.0);

	glVertex3f(BottomRightX / 300.0, (300 - BottomRightY) / 300.0, 0.0);

	glVertex3f(BottomRightX / 300.0, (300 - TopLeftY) / 300.0, 0.0);

	glEnd();


	printf("%d\n", cnt = cnt + 1);
	//glFlush(); //���� �����޸� ���
	glutSwapBuffers();
}
void MyMouseClick(GLint Button, GLint State, GLint x, GLint y) {
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		TopLeftX = x;
		TopLeftY = y;
	}
}
void Mykeyboard(unsigned char KeyPressed,int x,int y) {
	switch (KeyPressed) {
	case 'Q': case 'q':
		exit(0); break;
	case 'Z':case 'z':
		z += 10; break;
	case 'X': case 'x':
		z -= 10; break;
	}
	glutPostRedisplay();//�ٽ� �׸���� �ݹ��Լ�
}
void MyMotion(GLint x, GLint y) {
	BottomRightX = x;
	BottomRightY = y;

	glutPostRedisplay();
}
int main(int argc, char* argv[])//ǥ�� �Ű�����
{
	//glutInit(&argc, argv);
	//glutCreateWindow("OpenGL Example");
	//glutDisplayFunc(MyDisplay);
	//glutMainLoop();//idle ���� ����
	//return 0;
	glutInit(&argc, argv);

	glutInitWindowSize(600, 600); // ������ ũ��

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
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);//�������� ��ǥ ����
	glutDisplayFunc(MyDisplay); // (���÷��� �ݹ� ���)
	glutKeyboardFunc(Mykeyboard);//keyboard event handling
	glutMouseFunc(MyMouseClick);
	glutMotionFunc(MyMotion);

	glutMainLoop(); // �߿� �ڵ� ������ (�̺�Ʈ ����)
}