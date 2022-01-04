#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

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

void barnsleyFern(void)
{
    typedef GLfloat point2[2];
    point2 point = {0.0, 50.0}, newPoint;

    double prob[3] = {85, 92, 99};

    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < points; i++)
    {
        GLfloat xi = point[0];
        GLfloat randomnum = rand() % 100 + 1;
        if (randomnum < prob[0])
        {
            point[0] = point[0] * 0.85 + 0.04 * point[1];
            point[1] = xi * (-0.04) + 0.85 * point[1] + 1.6;
        }
        else if (randomnum < prob[1])
        {
            point[0] = 0.2 * point[0] - 0.26 * point[1];
            point[1] = 0.23 * xi + 0.22 * point[1] + 1.6;
        }
        else if (randomnum < prob[2])
        {
            point[0] = -0.15 * point[0] + 0.28 * point[1];
            point[1] = 0.26 * xi + 0.24 * point[1] + 0.44;
        }
        else
        {
            point[0] = 0.0;
            point[1] = 0.16 * point[1];
        }

        newPoint[0] = point[0] * 50 + 250;
        newPoint[1] = point[1] * 50;
        if (i > 100)
        {
            glBegin(GL_POINTS);
            glVertex2fv(newPoint);
            glEnd();
        }
    }

    glFlush();
    glutSwapBuffers();
}

void myDisplay()
{
    barnsleyFern();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("barnsley fern");
    glutDisplayFunc(myDisplay);
    myinit();
    glutMainLoop();
    return 0;
}