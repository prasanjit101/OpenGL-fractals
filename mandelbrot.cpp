#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;
float frame = 600;
int limit = 100;

float sc = frame / 2;

int lim(float cR, float cI)
{

	float zR = 0, zI = 0, fzR = 0, fzI = 0,i=0;
	while (i < limit)
	{
		fzI = 2 * zR * zI + cI;
		fzR = zR * zR - zI * zI + cR;
		zI = fzI;
		zR = fzR;
		if (fzR > 2)
			return i;
		i++;
	}
	return limit;
}

void mandelbrot()
{
	int l;
	glBegin(GL_POINTS);
	for (float j = -frame; j < frame; j += 0.5)
	{
		for (float i = -frame; i < frame; i += 0.5)
		{
			l = lim(j / sc, i / sc);
			if (l != limit)
			{
				glColor3f(1, 1, 1);
				glVertex2f(i,j);
			}
			else
			{
				glColor3f(0, 0, 0);
				glVertex2f(i,j);
			}
		}
	}
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("MandelBrot Set");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-frame, frame, -frame, frame, -1, 1);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glutInitWindowSize(1920, 1080);
	glutInitWindowPosition(0, 0);
	glutDisplayFunc(mandelbrot);
	glutMainLoop();
	return 0;
}