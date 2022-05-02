#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <cmath>
using namespace std;

GLint g_objectID = 1;
GLint xValue = 0;
GLint yValue = 0;
GLint zValue = 0;
GLint clickDown = 0;
GLint fitX = 0;
GLint fitY = 0;

GLfloat hangle = 0.0f;
GLfloat alangle = 0.0f;
GLfloat arngle = 0.0f;
GLfloat llngle = 0.0f;
GLfloat lrngle = 0.0f;
double time = 0;


void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//버퍼내용 지우기, 깊이버퍼지움
	glMatrixMode(GL_MODELVIEW);//모델뷰행렬지정
	glLoadIdentity();//내부 행렬 초기화

	gluLookAt(0.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//이 위치에 lookat함수 2,2,2 위치에서 원점을 바라봄
	//glCallList(g_objectID);//GenerateCallList에서 생성한 오브젝트 id넘김받으면 실제로 그리기 실행
	
	
	glRotatef(xValue, 1.0, 0.0, 0.0);
	glRotatef(yValue, 0.0, 1.0, 0.0);
	glRotatef(zValue, 0.0, 0.0, 1.0);


	glBegin(GL_LINES);

	glColor3f(1, 0, 0); // X R

	glVertex3f(-1, 0, 0); glVertex3f(1, 0, 0);

	glColor3f(0, 1, 0); // Y G

	glVertex3f(0, -1, 0); glVertex3f(0, 1, 0);

	glColor3f(0, 0, 1); // Z B

	glVertex3f(0, 0, -1); glVertex3f(0, 0, 1);

	glEnd();

	// Using Push-Pop Matrix

	glColor3f(1.0, 0.0, 0.0);
	//head
	glPushMatrix();
	glRotatef(hangle, 0.0, 1.0, 0.0);
		glRotatef(-90, 0, 1.0, 0.0);
		glTranslatef(0.0, 2.8, 0.0);
		glutSolidTeapot(0.8);
	glPopMatrix();

	//body
	glColor3f(0.0,0.0,1.0);
	glPushMatrix();
		glTranslated(0.0, 1.0, 0.0);
		//scale
		glScalef(2.0, 2.0, 1.0);
		glutSolidCube(1.0);
	glPopMatrix();
	//left
	//transandrotate
	glPushMatrix();
	glTranslatef(0.0, 2.0, 0.0);
	glRotatef(alangle, 1, 0, 0);
	//modeling
	glPushMatrix();
	glColor3f(1, 1, 0);
	glTranslatef(-1.5, -1, 0);
	glScalef(0.5, 2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-1.5, -2.25, 0);
	glutSolidSphere(0.25, 20, 20);
	glPopMatrix();
	glPopMatrix();

	//right

	//transandrotate
	glPushMatrix();
	glTranslatef(0.0, 2.0, 0.0);
	glRotatef(arngle, 1, 0, 0);
	//modeling
	glPushMatrix();
	glColor3f(0, 1, 0);
	glTranslatef(1.5, -1, 0);
	glScalef(0.5, 2, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(1.5, -2.25, 0);
	glutSolidSphere(0.25, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//leftleg
	
	//transandrotate
	glPushMatrix();
	glTranslated(-0.5, 0, 0);
	glRotatef(llngle, 1.0, 0, 0);
	//modeling
	glPushMatrix();
	glColor3f(0, 1.0, 1.0);
	glTranslatef(0, -2.0, 0);
	glScalef(0.5, 4.0, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0, -4.5, 0);
	glutSolidCube(0.5);
	glPopMatrix();
	glPopMatrix();

	//rightleg
	//transandrotate
	glPushMatrix();
	glTranslated(0.5, 0, 0);
	glRotatef(lrngle, 1.0, 0, 0);
	//modeling
	glPushMatrix();
	glColor3f(0, 1.0, 1.0);
	glTranslatef(0, -2.0, 0);
	glScalef(0.5, 4.0, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0, -4.5, 0);
	glutSolidCube(0.5);
	glPopMatrix();
	glPopMatrix();
	glLoadIdentity();
	glFlush(); //현재 비디오메모리 출력
	glutSwapBuffers();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
	switch (KeyPressed) {
	case 'x':
		xValue += 1;
		if (xValue > 360)xValue -= 360;
		break;
	case 'y':
		yValue += 1;
		if (yValue > 360)yValue -= 360;
		break;
	case 'z':
		zValue += 1;
		if (zValue > 360)zValue -= 360;
		break;
	case 'q':
		exit(0); break;
	case 32:
		xValue = 0;
		yValue = 0;
		zValue = 0;
		break;

	}
	glutPostRedisplay();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		fitX = X;
		fitY = Y;
		clickDown = 1;
	}
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_UP) {
		
		clickDown = 0;
	}
}
void MyMouseMove(GLint X, GLint Y) {
	if (clickDown == 1) {
		yValue += (fitX - X);
		xValue += (fitY - Y);
		fitX = X;
		fitY = Y;
	}
	glutPostRedisplay();
}
GLint GenerateCallList() {//매번 모델을 새로그리면 연산량이 증가-> 만들어놓고 가져다 사용
	GLint id = glGenLists(1);//오브젝트 id번호 리턴
	glNewList(id, GL_COMPILE);// 이 id가진 리스트를 컴파일버전 만들어놓는 버전
	for (int i = 0; i < 16302; i++) {
		int vi;
		//glBegin(GL_POINTS);
		//vi = face_indicies[i][0]; glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);//x,y,z
		//vi = face_indicies[i][1]; glVertex3f(vertices[vi][0], vertices[vi][1], vertices[vi][2]);
		//vi = face_indicies[i][2]; glVertex3fv(vertices[vi]);
		//glEnd();
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
	glEndList();// 모두 작성했다면 endlist로 종료 선언
	return id;
}

void MyTimer(int value) {

	time = time + 0.1;
	hangle += 5;
	if (hangle >= 360) hangle -= 360;

	alangle=cos(time) * 40;
	arngle = -alangle;

	lrngle = cos(time) * 30;
	llngle = -lrngle;
	glutPostRedisplay();//MyDisplay() 재호출

	glutTimerFunc(30, MyTimer, 1);//재귀

}


int main(int argc, char* argv[])//표준 매개변수
{
	glutInit(&argc, argv);

	glutInitWindowSize(800, 800); // 윈도우 크기

	glutInitWindowPosition(200, 200); // (100,100) 위치에 윈도우

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);//grb면 rgb모드 single이면 프레임 버퍼가 1개이다 깊이처리



	glutCreateWindow("OpenGL Example");

	glutSetWindowTitle("Updated OpenGL Example");



	int screenWidth, screenHeight;

	int windowWidth, windowHeight;

	int windowX, windowY;



	// Properties

	screenWidth = glutGet(GLUT_SCREEN_WIDTH); // 화면 너비

	screenHeight = glutGet(GLUT_SCREEN_HEIGHT); // 화면 크기

	windowWidth = glutGet(GLUT_INIT_WINDOW_WIDTH); // 윈도우 너비

	windowHeight = glutGet(GLUT_WINDOW_HEIGHT); // 윈도우 크기



	windowX = glutGet(GLUT_INIT_WINDOW_X); // 윈도우 X 좌표

	windowY = glutGet(GLUT_INIT_WINDOW_Y); // 윈도우 Y 좌표



	printf("Screen Info: %d %d\n", screenWidth, screenHeight);

	printf("Window Info: %d %d\n", windowWidth, windowHeight);

	printf("Window pos.: %d %d\n", windowX, windowY);
	
	// 시점 설정시 GL_DEPTH 사용하는 경우 필요

	glMatrixMode(GL_PROJECTION);//투상행렬로 전환
	glLoadIdentity();
	glOrtho(-6.0, 6.0, -6.0, 6.0, -7.0, 7.0);//공간부피설정 각각 x,y,z 범위 지정
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);//깊이처리 활성화
	//g_objectID = GenerateCallList();
	glutDisplayFunc(MyDisplay); // (디스플레이 콜백 등록)
	glutKeyboardFunc(MyKeyboard);
	glutMouseFunc(MyMouseClick);
	glutMotionFunc(MyMouseMove);
	glutTimerFunc(30, MyTimer, 1);
	glutMainLoop(); // 중요 코드 생략됨 (이벤트 루프)

}