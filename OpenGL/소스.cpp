#include <stdio.h>
#include <stdlib.h>
#include <glut.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265

float srand(time(NULL));
float a = (rand() % 50 - 25.0) / (float)100.0;
float b = (rand() % 50 - 25.0) / (float)100.0;
float c = (rand() % 50) / (float)100.0;

double getRadian(int num)
{
	return num * (PI / 180.0);
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLE_FAN);

	glVertex2f(a, b);

	for (int i = 0; i < 361; i++)
	{
		float j = getRadian(i);
		float x = c * cos(j), y = c * sin(j);
		glVertex2f(x + a, y + b);
	}

	glEnd();

	glFlush();
}

void Display3() {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLE_FAN);

	glVertex2f(a, b);

	for (int i = 0; i < 361; i++)
	{
		float j = getRadian(i);
		float x = c * cos(j), y = c * sin(j);
		glVertex2f(x + a, y + b);
	}

	glVertex2f(a, -b);

	for (int i = 0; i < 361; i++)
	{
		float j = getRadian(i);
		float x = c * cos(j), y = c * sin(j);
		glVertex2f(x + a, y - b);
	}

	glVertex2f(-a, b);

	for (int i = 0; i < 361; i++)
	{
		float j = getRadian(i);
		float x = c * cos(j), y = c * sin(j);
		glVertex2f(x - a, y + b);
	}

	glEnd();

	glFlush();
}

void Keyboard(unsigned char ch, int x, int y)
{
	if (ch == 'Q' || ch == 'q')
	{
		exit(1);
	}
	else if (ch == 'E' || ch == 'e') {
		glutDisplayFunc(Display3);
	}
	else if (ch == 'W' || ch == 'w') {
		b += 0.01f;
	}
	else if (ch == 'S' || ch == 's') {
		b -= 0.01f;
	}
	else if (ch == 'A' || ch == 'a') {
		a -= 0.01f;
	}
	else if (ch == 'D' || ch == 'd') {
		a += 0.01f;
	}
	glutPostRedisplay();
}

int main() {
	glutCreateWindow("HelloOpenGL");
	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);
	glutMainLoop();
	return 0;
}