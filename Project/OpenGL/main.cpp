#include "main.h"


Player player;

void Display() {
	glClear(GLUT_RGB);

	player.Draw(800, 600);



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
	glutPostRedisplay();
}

int main() {
	player.MapLoad("D:\\map.txt");
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("HelloOpenGL");
	glutDisplayFunc(Display);\
	glutKeyboardFunc(Keyboard);
	glutMainLoop();
	return 0;
}