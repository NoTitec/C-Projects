#include <glut.h>					
#include <GL/gl.h>						
#include <GL/glu.h>	

void MyLightInit()
{
	GLfloat light1_ambient[] = { 0.0, 0.0, 0.0, 1.0 };		//1������Ư��
	GLfloat light1_diffuse[] = { 0.5, 0.2, 0.3, 1.0 };		//            - Ȯ�걤  
	GLfloat light1_specular[] = { 0.0, 0.0, 0.0, 1.0 };		//            - ��鱤 
	GLfloat material_ambient[] = { 0.3, 0.3, 0.3, 1.0 };		//��üƯ�� - �ֺ���
	GLfloat material_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };    //         - Ȯ�걤
	GLfloat material_specular[] = { 0.0, 0.0, 1.0, 1.0 };   //         - ��鱤
	GLfloat material_shininess[] = { 25.0 };

	glShadeModel(GL_FLAT);	//���μ��̵� (GL_SMOOTH)
	glEnable(GL_DEPTH_TEST);	//���̹���Ȱ��ȭ
	glEnable(GL_LIGHTING);		//����Ȱ��ȭ

	glEnable(GL_LIGHT1);		//1������Ȱ��ȭ
	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient);		//1������Ư���Ҵ�
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);	//��üƯ���Ҵ�
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
	glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);
}


void MyDisplay()
{
	GLfloat LightPosition1[] = { 1.0, 1.0, 1.0, 1.0 };	//1��������ġ
	//���̱�������
	GLfloat LightDirection1[] = { -0.5, -1.0, -1.0 };	//1����������
	GLfloat SpotAngle1[] = { 20.0 };			//1����������

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.5, 0.5, 0.5, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0);	//������ȯ

	glTranslatef(0.3, 0.3, 0.0);						//�𵨺�ȯ

	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);	//����Ʈ����Ʈ
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, LightDirection1);	//����
	glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, SpotAngle1);	//����
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1.0);			//�ڻ��ν¼�

	glutSolidTorus(0.3, 0.6, 40, 40);			//��ȯü����

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
