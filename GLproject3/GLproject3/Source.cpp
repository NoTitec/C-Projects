#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include "BunnyModel.h"
using namespace std;

GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;
int cnt = 0; //전역변수
int z = 0;
GLint g_objectID = 1;
int dir=0;
void Mykeyboard(unsigned char KeyPressed, int x, int y) {// KeyPressed 는 키보드 눌린순간의 키정보,x,y는 눌렸을때의 마우스 좌표
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
	case '=':dir = 1;  break;//타이머 제어변수 1 시계
	case '-':dir = 0;  break;//타이머 제어변수 0 반시계
	case 's':dir = -1; break;// 멈춤
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
	glutPostRedisplay();//MyDisplay() 재호출

	glutTimerFunc(100, MyTimer, 1);//재귀

}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);//버퍼내용 지우기
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//내부 행렬 초기화
	glBegin(GL_LINES);

	glColor3f(1, 0, 0); // X R

	glVertex3f(-1, 0, 0); glVertex3f(1, 0, 0);

	glColor3f(0, 1, 0); // Y G

	glVertex3f(0, -1, 0); glVertex3f(0, 1, 0);

	glColor3f(0, 0, 1); // Z B

	glVertex3f(0, 0, -1); glVertex3f(0, 0, 1);

	glEnd();
	glRotatef(z, 0.0, 1.0, 0.0);//회전함수

	glCallList(g_objectID);

	printf("%d\n", cnt = cnt + 1);
	glFlush(); //현재 비디오메모리 출력
	glutSwapBuffers();
}
GLint GenerateCallList() {//매번 모델을 새로그리면 연산량이 증가-> 만들어놓고 가져다 사용
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


int main(int argc, char* argv[])//표준 매개변수
{
	glutInit(&argc, argv);
	glutInitWindowSize(300, 300); // 윈도우 크기
	glutInitWindowPosition(100, 100); // (100,100) 위치에 윈도우
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);//grb면 rgb모드 single이면 프레임 버퍼가 1개이다
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

	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	g_objectID = GenerateCallList();//생성한 오브젝트 컴파일 id 숫자
	glutDisplayFunc(MyDisplay); // (디스플레이 콜백 등록)
	glutKeyboardFunc(Mykeyboard);
	glutTimerFunc(100, MyTimer, 1);// 맨뒤 숫자는 타이머 id (여러타이머있으면 구분필요)
	
	glutMainLoop(); // 중요 코드 생략됨 (이벤트 루프)
}