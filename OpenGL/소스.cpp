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

	// x�� ������ 0.00 ~ 2.00 

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
	glClear(GL_COLOR_BUFFER_BIT);//���۸� �ϴ� �����ϰ� ���Ӱ� �׸���

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
	glutCreateWindow("HelloOpenGL");//�׸��� ǥ���ϴ� �ܼ�
	glutDisplayFunc(Display);//�׸� �׸��� �Լ�
	glutKeyboardFunc(Keyboard);
	glutMainLoop();
	return 0;
}