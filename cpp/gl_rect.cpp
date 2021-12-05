//ref: http://wisdom.sakura.ne.jp/system/opengl/gl3.html

#include <iostream>

#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif


void disp( void ) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0 , 0 , 1);
	glRectf(-0.8 , 0.8 , 0.8 , -0.8);
    glFlush();//without this, show nothing.
}

int main(int argc , char ** argv) {
	glutInit(&argc , argv);
	glutInitWindowPosition(100 , 50);
	glutInitWindowSize(400 , 300);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutCreateWindow("Kitty on your lap_gl3");
	glutDisplayFunc(disp);
	glutMainLoop();
	return 0;
}