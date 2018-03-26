#include <GL/gl.h>
#include <GL/glut.h>

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(2.5);

    glColor3f(0.0, 0.0, 0.0);//White

    //First QUAD
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(-0.5f, 0.4f);
    glVertex2f(-0.5f, -0.1f);
    glVertex2f(0.0f, -0.1);
    glEnd();

    //Second Quad
    glBegin(GL_POLYGON);
    glVertex2f(-0.25f, 0.4f);
    glVertex2f(-0.25f, 0.6f);
    glVertex2f(-0.6f, 0.6f);
    glVertex2f(-0.6f, 0.4f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.6f, 0.6f);
    glVertex2f(-0.9f, 0.6f);
    glVertex2f(-0.6f, 0.4f);
    glEnd();
    //second

    //third Quad
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, -0.1);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.0f, -0.2);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, -0.2);
    glVertex2f(-0.2f, -0.2f);
    glVertex2f(0.0f, -0.5f);
    glEnd();

    //left triangle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(-0.45f, -0.1f);
    glVertex2f(-0.2f, -0.2f);
    glEnd();

    //third end

    //head
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.4f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(-0.1f, 0.5);
    glVertex2f(-0.12f, 0.4);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.06f, 0.5);
    glVertex2f(-0.08f, 0.6);
    glVertex2f(-0.12f, 0.4);

    glEnd();

    //paste



    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Batman");
    glutInitWindowSize(320, 320);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
