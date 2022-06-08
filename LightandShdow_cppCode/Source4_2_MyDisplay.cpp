void MyDisplay()

{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	glBindTexture(GL_TEXTURE_2D, MyTextureObject[0]);



	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.0, 0.0);

	 glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f); //앞면

	 glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);//1.0 2.0 변경시 이어붙이거나 반복

	 glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);

	 glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);

	//glVertex3f(-1.0f, -1.0f, 1.0f); //앞면 -- for repeat or clamp

	//glVertex3f(1.0f, -1.0f, 1.0f);

	//glVertex3f(1.0f, 1.0f, 1.0f);

	//glVertex3f(-1.0f, 1.0f, 1.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.0, 1.0, 0.0);

	glVertex3f(-1.0f, -1.0f, -1.0f); //뒷면

	glVertex3f(-1.0f, 1.0f, -1.0f);

	glVertex3f(1.0f, 1.0f, -1.0f);

	glVertex3f(1.0f, -1.0f, -1.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.0, 0.0, 1.0);

	glVertex3f(-1.0f, 1.0f, -1.0f); //윗면

	glVertex3f(-1.0f, 1.0f, 1.0f);

	glVertex3f(1.0f, 1.0f, 1.0f);

	glVertex3f(1.0f, 1.0f, -1.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(1.0, 0.0, 1.0);

	glVertex3f(-1.0f, -1.0f, -1.0f); //아랫면

	glVertex3f(1.0f, -1.0f, -1.0f);

	glVertex3f(1.0f, -1.0f, 1.0f);

	glVertex3f(-1.0f, -1.0f, 1.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(0.0, 1.0, 1.0);

	glVertex3f(1.0f, -1.0f, -1.0f); //우측면

	glVertex3f(1.0f, 1.0f, -1.0f);

	glVertex3f(1.0f, 1.0f, 1.0f);

	glVertex3f(1.0f, -1.0f, 1.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(1.0, 1.0, 0.0);

	glVertex3f(-1.0f, -1.0f, -1.0f); //좌측면

	glVertex3f(-1.0f, -1.0f, 1.0f);

	glVertex3f(-1.0f, 1.0f, 1.0f);

	glVertex3f(-1.0f, 1.0f, -1.0f);

	glEnd();



	glutSwapBuffers();

}