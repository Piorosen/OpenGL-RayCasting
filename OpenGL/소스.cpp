#include <stdio.h>
#include <glut.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.1415926535897

double getRadian(int num)
{
	return num * (PI / 180.0);
}
float a = 0, b = 0;

void DrawCircle() {
	float x = rand() % 200 / 100.0f;
	float y = rand() % 200 / 100.0f;
	float size = rand() % 100 / 100.0f;

	// x의 범위를 0.00 ~ 2.00 

	x -= 1.0f;
	y -= 1.0f;
	// -1 ~ 1

	glBegin(GL_TRIANGLE_FAN);
	
	glVertex2f(x * size + a, y * size + b);
	for (int i = 0; i < 361; i++)
	{
		double j = getRadian(i);
		glVertex2f((cos(j) + x) * size + a, (sin(j) + y) * size + b);
	}
	glEnd();
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT);//버퍼를 싹다 정리하고 새롭게 그린다

	DrawCircle();
	DrawCircle();
	DrawCircle();
	glFlush();
}

void Keyboard(unsigned char ch, int x1, int y1) {
	if (ch == 'q') {
		exit(0);
	}
	else if (ch == 'e') {
		glutPostRedisplay();
	}

}

int main() {
	glutCreateWindow("HelloOpenGL");//그림을 표현하는 콘솔
	glutDisplayFunc(Display);//그림 그리는 함수
	glutKeyboardFunc(Keyboard);
	glutMainLoop();
	return 0;
}