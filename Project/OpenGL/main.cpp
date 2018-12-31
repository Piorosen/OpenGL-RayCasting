#include "main.h"




void Display() {
	glClear(GLUT_RGB);


	glutSwapBuffers();
}

void Keyboard(unsigned char ch, int x1, int y1) {

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