#include <stdio.h>
#include <glut.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
float _x = 0.0;
float _y = 0.0;
void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(_x, _y);

	float t = rand() % 100 / 100.0f;
	float rad = 0.5;
	for (int i = 0; i < 361; i++)
	{
		float angle = i * 3.14159265358979 / 180; // 3f는 차원을 뜻함 2f는 2차원
		float x = rad * cos(angle);
		float y = rad * sin(angle);
		glVertex2f(x + _x, y + _y);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 360; i++)
	{
		float a, b, c;
		a = i * 3.141592 / 180;
		b = t * sin(a);
		c = t * cos(a);
		glVertex2f(b+t,c+ t);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	t = rand() % 100 / 100.0f;
	for (int i = 0; i < 360; i++)
	{
		float a, b, c;
		a = i * 3.141592 / 180;
		b = t * sin(a);
		c = t * cos(a);
		glVertex2f(b - t, c - t);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	t = rand() % 100 / 100.0f;
	for (int i = 0; i < 360; i++)
	{
		float a, b, c;
		a = i * 3.141592 / 180;
		b = t * sin(a);
		c = t * cos(a);
		glVertex2f( b+t, c-t);
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	t = rand() % 100 / 100.0f;
	for (int i = 0; i < 360; i++)
	{
		float a, b, c;
		a = i * 3.141592 / 180;
		b = t * sin(a);
		c = t * cos(a);
		glVertex2f(b- t, c+t);
	}
	glEnd();
	glFlush();
}


void keyboardInput(unsigned char ch, int x, int w) {
	printf("%f %f\n", _x, _y);
	if (ch == 'w') {
		_y += 0.01f;
	}
	if (ch == 's') {
		_y -= 0.01f;
	}
	if (ch == 'd') {
		_x += 0.01f;
	}
	if (ch == 'a') {
		_x -= 0.01f;
	}
	if (ch == 'x')
	{
		exit(0);
	}
	glutPostRedisplay();
}
int main() {
	srand(time(NULL));
	glutCreateWindow("HelloOpenGL");
	glutDisplayFunc(Display);
	glutKeyboardFunc(keyboardInput);
	glutMainLoop();
	return 0;
}