#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <cmath>
using namespace std;

GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;
int cnt = 0; //전역변수
int z = -1; //회전 제어 변수
int dir;//timer함수 제어변수
GLint g_objectID = 1;

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

	gluLookAt(2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);//이 위치에 lookat함수 2,2,2 위치에서 원점을 바라봄
	//glCallList(g_objectID);//GenerateCallList에서 생성한 오브젝트 id넘김받으면 실제로 그리기 실행
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
	glPushMatrix();
		glTranslatef(-0.5, -2.0, 0.0);
	glPushMatrix();

		glColor3f(0.0, 1.0, 1.0);
		glRotatef(llngle, 1.0, 0.0, 0.0);
		glScalef(0.5, 4.0, 0.5);
		glutSolidCube(1.0);
	glPopMatrix();
		glRotatef(llngle, 1.0, 0.0, 0.0);
		glTranslatef(0.0, -2.5, 0.0);
		glColor3f(0, 0, 0);
	glutSolidCube(0.5);
	glPopMatrix();
	//rightleg
	glPushMatrix();
	glTranslatef(0.5, -2.0, 0.0);
	glPushMatrix();
	glRotatef(lrngle, 1.0, 0.0, 0.0);
	glColor3f(0.0, 1.0, 1.0);
	glScalef(0.5, 4.0, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
	glRotatef(lrngle, 1.0, 0.0, 0.0);
	glTranslatef(0.0, -2.5, 0.0);
	glColor3f(0, 0, 0);
	glutSolidCube(0.5);
	glPopMatrix();
	glLoadIdentity();
	glFlush(); //현재 비디오메모리 출력
	glutSwapBuffers();
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

	alangle=sin(time) * 40;
	arngle = -alangle;

	llngle = sin(time) * 30;
	lrngle = -llngle;
	glutPostRedisplay();//MyDisplay() 재호출

	glutTimerFunc(30, MyTimer, 1);//재귀

}

void Mykeyboard(unsigned char KeyPressed, int x, int y) {
	switch (KeyPressed) {
	case 'Q': case 'q':
		exit(0); break;
	case 'Z':case 'z':
		z += 10;
		glutPostRedisplay();//다시 그리라는 콜백함수
		break;
	case 'X': case 'x':
		z -= 10;
		glutPostRedisplay();//다시 그리라는 콜백함수
		break;
	case '=':dir = 1;  break;
	case '-':dir = 0;  break;
	case 's':dir = -1; break;
	}

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

	glMatrixMode(GL_PROJECTION);//투상행렬로 전환
	glLoadIdentity();
	glOrtho(-6.0, 6.0, -6.0, 6.0, -7.0, 7.0);//공간부피설정 각각 x,y,z 범위 지정
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);//깊이처리 활성화
	//glutKeyboardFunc(Mykeyboard);
	//g_objectID = GenerateCallList();
	glutDisplayFunc(MyDisplay); // (디스플레이 콜백 등록)
	glutTimerFunc(30, MyTimer, 1);
	glutMainLoop(); // 중요 코드 생략됨 (이벤트 루프)

}