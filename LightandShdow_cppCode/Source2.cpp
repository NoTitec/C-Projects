#include <glut.h>					
#include <GL/gl.h>						
#include <GL/glu.h>	

void MyLightInit()
{
	GLfloat light1_ambient[] = { 0.0, 0.0, 0.0, 1.0 };		//1번광원특성
	GLfloat light1_diffuse[] = { 0.5, 0.2, 0.3, 1.0 };		//            - 확산광  
	GLfloat light1_specular[] = { 0.0, 0.0, 0.0, 1.0 };		//            - 경면광 
	GLfloat material_ambient[] = { 0.3, 0.3, 0.3, 1.0 };		//물체특성 - 주변광
	GLfloat material_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };    //         - 확산광
	GLfloat material_specular[] = { 0.0, 0.0, 1.0, 1.0 };   //         - 경면광
	GLfloat material_shininess[] = { 25.0 };

	glShadeModel(GL_FLAT);	//구로셰이딩 (GL_SMOOTH)
	glEnable(GL_DEPTH_TEST);	//깊이버퍼활성화
	glEnable(GL_LIGHTING);		//조명활성화

	glEnable(GL_LIGHT1);		//1번광원활성화
	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);		//1번광원특성할당
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);	//물체특성할당
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);
}


void MyDisplay()
{
	GLfloat LightPosition1[] = { 1.0, 1.0, 1.0, 1.0 };	//1번광원위치
	//스팟광원설정
	GLfloat LightDirection1[] = { -0.5, -1.0, -1.0 };	//1번광원방향
	GLfloat SpotAngle1[] = { 20.0 };			//1번광원각도

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.5, 0.5, 0.5, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0);	//시점변환

	glTranslatef(0.3, 0.3, 0.0);						//모델변환

	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);	//스포트라이트
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection1);	//방향
	glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, SpotAngle1);	//각도
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1.0);			//코사인승수

	glutSolidTorus(0.3, 0.6, 40, 40);			//원환체정의

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(700, 700);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("OpenGL Drawing Example");

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -2.0, 2.0);

	// Lighting
	MyLightInit();

	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
