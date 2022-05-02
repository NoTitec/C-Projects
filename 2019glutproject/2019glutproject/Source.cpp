#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
using namespace std;

GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;
int cnt = 0; //전역변수
int z = 0;
void MyDisplay() {
	//glClear(GL_COLOR_BUFFER_BIT);//버퍼내용 지우기
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();//내부 행렬 초기화
	//glRotatef(z, 0.0, 0.0, 1.0);//회전함수
	//glutWireTeapot(0.5);//glut함수는 glBegin,glEnd필요없음
	//glPointSize(4.0);
	glLineWidth(2.0);
	//glBegin(GL_LINES);//그리기 시작 그리고 싶은 도형종류 매개변수
	/*glColor3f(1.0, 0, 0); glVertex3f(-0.5, -0.5, 0.0);//사각형 인터폴레이션(보간법)으로 색을 채움
	glColor3f(0, 1.0, 0); glVertex3f(0.5, -0.5, 0.0);
	glColor3f(0, 0, 1.0); glVertex3f(0.5, 0.5, 0.0);
	glColor3f(0, 1.0, 1.0); glVertex3f(-0.5, 0.5, 0.0);*/

	/*glColor3f(1.0, 0, 0); glVertex3f(0.0, 0.0, 0.0); 정점
	glColor3f(0, 1.0, 0); glVertex3f(0.5, 0.0, 0.0);
	glColor3f(0, 0, 1.0); glVertex3f(0.0, 0.5, 0.0);*/

	//glColor3f(1.0, 0, 0); glVertex3f(0.0, 0.0, 0.0); //선
	//glVertex3f(0.5, 0.0, 0.0);
	//glColor3f(0, 1.0, 0); glVertex3f(0.0, 0.5, 0.0);
	//glVertex3f(0.5, 0.5, 0);

	//glColor3f(1,1, 0); glVertex3f(-0.5, 0, 0);//삼각형
	//glVertex3f(-0.2, 0, 0); glVertex3f(-0.6, 0.5, 0);
	//glColor3f(0, 0, 1); glVertex3f(0, 0, 0);
	//glVertex3f(0.2, 0, 0); glVertex3f(0.1, 0.3, 0);

	//glutSolidSphere(0.5, 1000, 100);//원
	//glEnd();//그리기 종료

	glColor3f(1.0, 0.0, 0.0);

	glBegin(GL_POLYGON);

	glVertex3f(TopLeftX / 300.0, (300 - TopLeftY) / 300.0, 0.0);

	glVertex3f(TopLeftX / 300.0, (300 - BottomRightY) / 300.0, 0.0);

	glVertex3f(BottomRightX / 300.0, (300 - BottomRightY) / 300.0, 0.0);

	glVertex3f(BottomRightX / 300.0, (300 - TopLeftY) / 300.0, 0.0);

	glEnd();


	printf("%d\n", cnt = cnt + 1);
	//glFlush(); //현재 비디오메모리 출력
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
	glutPostRedisplay();//다시 그리라는 콜백함수
}
void MyMotion(GLint x, GLint y) {
	BottomRightX = x;
	BottomRightY = y;

	glutPostRedisplay();
}
int main(int argc, char* argv[])//표준 매개변수
{
	//glutInit(&argc, argv);
	//glutCreateWindow("OpenGL Example");
	//glutDisplayFunc(MyDisplay);
	//glutMainLoop();//idle 상태 조정
	//return 0;
	glutInit(&argc, argv);

	glutInitWindowSize(600, 600); // 윈도우 크기

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
	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);//정사투영 좌표 설정
	glutDisplayFunc(MyDisplay); // (디스플레이 콜백 등록)
	glutKeyboardFunc(Mykeyboard);//keyboard event handling
	glutMouseFunc(MyMouseClick);
	glutMotionFunc(MyMotion);

	glutMainLoop(); // 중요 코드 생략됨 (이벤트 루프)
}