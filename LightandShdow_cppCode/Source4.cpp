#include <stdio.h>

#include <glut.h>	
#include <GL/gl.h>
#include <GL/glu.h>

#include "bmp.h"

GLfloat xrot = 0.9f;
GLfloat yrot = 0.8f;
GLfloat zrot = 1.0f;

unsigned int MyTextureObject[1];

AUX_RGBImageRec* pTextureImage[1]; //텍스쳐 저장 공간을 가리키는 포인터    

char fileName[16] = "./apple.bmp";

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBindTexture(GL_TEXTURE_2D, MyTextureObject[0]);

	// 앞면
	glBegin(GL_POLYGON);

	glEnd();
	// 뒷면
	glBegin(GL_POLYGON);

	glEnd();
	// 윗면
	glBegin(GL_POLYGON);

	glEnd();
	// 아랫면
	glBegin(GL_POLYGON);

	glEnd();
	// 우측면
	glBegin(GL_POLYGON);

	glEnd();
	// 좌측면
	glBegin(GL_POLYGON);

	glEnd();

	glutWireTeapot(1.0);

	glutSwapBuffers();
}

void MyTimer(int Value)
{
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glRotatef(zrot, 0.0f, 0.0f, 1.0f);

	glutPostRedisplay();

	glutTimerFunc(50, MyTimer, 1);
}

int LoadGLTextures(char* szFilePath)			//파일을 로드하고 텍스쳐로 변환	
{
	int Status = FALSE;

	glClearColor(0.0, 0.0, 0.0, 0.5);

	memset(pTextureImage, 0, sizeof(void*) * 1);

	//비트맵을 로드하고 오류확인
	if (pTextureImage[0] = auxDIBImageLoad(szFilePath))
	{
		Status = TRUE;							//상태 플랙을 True로

		glGenTextures(1, &MyTextureObject[0]);	//텍스쳐 생성 (1개 texture)
		glBindTexture(GL_TEXTURE_2D, MyTextureObject[0]);

		glTexImage2D(GL_TEXTURE_2D, 0, 3,
			pTextureImage[0]->sizeX, pTextureImage[0]->sizeY,
			1, GL_RGB, GL_UNSIGNED_BYTE, pTextureImage[0]->data);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // Minimization Filter (GL_NEAREST / GL_LINEAR)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // Maximization Filter (GL_NEAREST / GL_LINEAR)

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// S Direction  
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);	// T Direction

		glEnable(GL_TEXTURE_2D);
	}

	if (pTextureImage[0]) {					//텍스쳐가 존재하면		
		if (pTextureImage[0]->data) {		//텍스쳐 영상이 존재하면		
			free(pTextureImage[0]->data);	//텍스쳐 영상공간 반납
		}
		free(pTextureImage[0]);				//텍스쳐 반납			
	}

	return Status;
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	glutCreateWindow("OpenGL Example");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);

	glutDisplayFunc(MyDisplay);
	glutTimerFunc(500, MyTimer, 1);

	glEnable(GL_DEPTH_TEST);

	if (LoadGLTextures(fileName))
	{
		glutMainLoop();
	}
}
