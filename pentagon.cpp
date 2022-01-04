#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>

GLsizei wh = 700, ww = 700;
int points = 8000, x1, y1, mi = 1, xL = 0, yL = 0;

void myinit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 700.0, 0.0, 700.0);
    glMatrixMode(GL_MODELVIEW);
}

void pentagon(void)
{
    typedef GLfloat point2[2];
    point2 vertice[5] = {{500, 400}, {800, 400}, {895, 700}, {650, 880}, {405, 700}};
    int j, k;
    int rand();
    point2 p = {0.0, 50.0};
    glClear(GL_COLOR_BUFFER_BIT);
    for (k = 0; k < points; k++)
    {
        j = rand() % 5;
        p[0] = (p[0] + vertice[j][0]) * (3.0 / 8.0);
        p[1] = (p[1] + vertice[j][1]) * (3.0 / 8.0);
        glBegin(GL_POINTS);
        glVertex2fv(p);
        glEnd();
    }
    glFlush();
    glutSwapBuffers();
}

void myDisplay()
{
    pentagon();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Pentagon");
    glutDisplayFunc(myDisplay);
    myinit();
    glutMainLoop();
    return 0;
}