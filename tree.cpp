
#include <windows.h>
#include <GL/glut.h>

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawtree(int n)
{
    if (n)
    {
        glPushMatrix();
        glTranslatef(-0.5, 1.0, 0);
        glRotatef(45, 0.0, 0.0, 1.0);
        glScalef(0.607, 0.607, 0.607);
        drawtree(n - 1);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(0.5, 1.0, 0);
        glRotatef(-45, 0.0, 0.0, 1.0);
        glScalef(0.607, 0.607, 0.607);
        drawtree(n - 1);
        glPopMatrix();
        glutSolidCube(1);
    }
}

void display(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glColor3f(0, 0, 0);
    drawtree(12);//12 iterations
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Pythagoran_Tree");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}