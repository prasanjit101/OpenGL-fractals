#include <GL/glut.h>
#include <iostream>
#include <math.h>

#define PI 3.14159265358979323846
using namespace std;

GLfloat xi = 500, yi = 800, i = 5;
void koch_curve(GLdouble dig, GLfloat len, GLint iteration)
{
  GLfloat xf, yf;
  GLdouble rad = PI / 180.0 * dig;
  xf = xi + len * cos(rad);
  yf = yi + len * sin(rad);

  if (iteration)
  {
    iteration--;
    koch_curve(dig, len, iteration);
    dig += 60;
    koch_curve(dig, len, iteration);
    dig -= 120;
    koch_curve(dig, len, iteration);
    dig += 60;
    koch_curve(dig, len, iteration);
  }
  else
  {
    glVertex2f(xi, yi);
    glVertex2f(xf, yf);
    xi = xf;
    yi = yf;
  }
}

void display()
{
  glColor3f(0, 0, 0);
  glBegin(GL_LINES);
  koch_curve(0, 2, i);
  koch_curve(-120, 2, i);
  koch_curve(120, 2, i);
  glEnd();
  glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  glutInitWindowSize(600, 600);
  glutCreateWindow("Koch curve");
  gluOrtho2D(0, 1080, 0, 1080);
  glClearColor(1, 1, 1, 0);
  glClearDepth(1);
  glClear(GL_COLOR_BUFFER_BIT);
  glutDisplayFunc(display);
  display();
  glutMainLoop();
  return 0;
}