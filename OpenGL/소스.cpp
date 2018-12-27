#include <cstdio>
#include <glut.h>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define PI 3.1415926535897

class Circle {
private:
	float x, y;
	float size;
	float R, G, B;

	float getRadian(int num)
	{
		return num * (PI / 180.0);
	}

public:
	void Init() {
		x = rand() % 200 / 100.0f - 1.0f;
		y = rand() % 200 / 100.0f - 1.0f;
		R = rand() % 100 / 100.0f;
		G = rand() % 100 / 100.0f;
		B = rand() % 100 / 100.0f;

		size = rand() % 100 / 100.0f;
	}

	void Draw() {

		glBegin(GL_TRIANGLE_FAN);
		glColor3f(R, G, B);
		glVertex2f(x * size, y * size);
		for (int i = 0; i < 361; i++)
		{
			double j = getRadian(i);
			glVertex2f((cos(j) + x) * size, (sin(j) + y) * size);
		}
		glEnd();
	}
};


void Display() {
	glClear(GL_COLOR_BUFFER_BIT);//버퍼를 싹다 정리하고 새롭게 그린다
	Circle c[10];
	for (int i = 0; i < 10; i++) {
		c[i].Init();
		c[i].Draw();
	}
	glFlush();
}

void DrawCircle() {

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
	srand((unsigned)time(0));
	glutCreateWindow("HelloOpenGL");//그림을 표현하는 콘솔
	glutDisplayFunc(Display);//그림 그리는 함수
	glutKeyboardFunc(Keyboard);
	glutMainLoop();
	return 0;
}