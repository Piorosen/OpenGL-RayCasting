#include "main.h"


Player player;

void Display() {
	glClear(GLUT_RGB);


	glutSwapBuffers();
}

void Keyboard(unsigned char ch, int x1, int y1) {

	if (ch == 'w') {
		player.Move(true);
	}
	if (ch == 's') {
		player.Move(false);
	}
	if (ch == 'a') {
		player.Rotate(-10);
	}
	if (ch == 'd') {
		player.Rotate(10);
	}
}

void Timer(int value) {

}

int main() {
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("HelloOpenGL");
	glutDisplayFunc(Display);
	glutTimerFunc(0, Timer, 0);
	glutKeyboardFunc(Keyboard);
	glutMainLoop();
	return 0;
}