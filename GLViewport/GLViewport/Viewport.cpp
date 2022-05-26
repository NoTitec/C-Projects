#include <glut.h>

#include <GL/gl.h>

#include <GL/glu.h>



GLint winWidth = 700;

GLint winHeight = 700;



void MyDisplay()

{

	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glViewport(0, 400, 400, 400);
	glClearColor(0, 0, 0, 1);
	gluLookAt(0, 1, 0, 0, 0, 0, 1, 0, 0);
	glutWireTeapot(0.5);
	glPopMatrix();
	
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glViewport(0, 0, 400, 400);
	glClearColor(0, 0, 0, 1);
	gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);
	glutWireTeapot(0.5);
	glPopMatrix();

	glColor3f(1.0, 1.0, 0.0);
	glPushMatrix();
	glViewport(400, 0, 400, 400);
	glClearColor(0, 0, 0, 1);
	gluLookAt(1, 0, 0, 0, 0, 0, 0, 1, 0);
	glutWireTeapot(0.5);
	glPopMatrix();

	glColor3f(1.0, 0.0, 1.0);
	glPushMatrix();
	glViewport(400, 400, 400, 400);
	glClearColor(0, 0, 0, 1);
	gluLookAt(-1, 0, 0.3, 0, 0, 0, 0, 1, 0);
	glutWireTeapot(0.5);
	glPopMatrix();


	glFlush();

}



void MyReshape(int width, int height)

{

	winWidth = width;

	winHeight = height;

}



int main(int argc, char** argv)

{

	glutInit(&argc, argv);

	glutInitWindowSize(800, 800);

	glutCreateWindow("OpenGL Drawing Example");



	// Projection Setting

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 30.0);



	glutReshapeFunc(MyReshape);

	glutDisplayFunc(MyDisplay);



	glutMainLoop();

	return 0;

}