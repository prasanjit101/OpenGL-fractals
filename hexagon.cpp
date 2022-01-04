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
void hexagon(void)
{
    typedef GLfloat point2[3];
    point2 vertices[6] = {{650, 900}, {900, 770}, {900, 520}, {650, 400}, {400, 520}, {400, 770}};
    int j, k;
    int rand();
    point2 p = {0.0, 50.0};
    glClear(GL_COLOR_BUFFER_BIT);
    for (k = 0; k < points; k++)
    {
        j = rand() % 6;
        p[0] = (p[0] + vertices[j][0]) * (1.0 / 3.0);
        p[1] = (p[1] + vertices[j][1]) * (1.0 / 3.0);
        glBegin(GL_POINTS);
        glVertex2fv(p);
        glEnd();
    }
    glFlush(); /* clear buffers */
    glutSwapBuffers();
}

void myDisplay()
{
    hexagon();
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