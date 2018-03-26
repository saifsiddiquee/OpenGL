/// MD SAIF SIDDIQUE RAYHAN
/// ID: 15-28295-1

#include <iostream>
#include <math.h>
#include <windows.h>
#include <GL/glut.h>
using namespace std;

GLfloat angle = 0.0f;
GLfloat anglem = 0.0f;
GLfloat angleh = 0.0f;
GLint refresh = 30;

void initGL()
{
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Timer(int val)
{
    glutPostRedisplay();
    glutTimerFunc(refresh, Timer,0);
}

//speed Control
void speed(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        if (refresh<2)
        {
            refresh = 2;
        }
        else
            refresh--;
        cout << "Speed Increasing"<< endl;
        break;
    case GLUT_KEY_DOWN:

        if (refresh > 30)
        {
            refresh = 30;
        }

        else
            refresh++;
        cout <<"Speed Decreasing"<<endl;

    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);    // Clear the color buffer

    //circle
    glLineWidth(10.0);
    glColor3f(0.6, 0.5, 0.4);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f);
    for(int i = 0; i < 900 ; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(900);
        float x = 0.17 * cosf(theta);
        float y = 0.17 * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();

    //Wing 1
    glPushMatrix();
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.2f, 0.1f);
    glVertex2f( 0.8f, 0.05f);
    glVertex2f( 0.8f,  -0.05f);
    glVertex2f(0.2f,  -0.1f);
    glEnd();
    glPopMatrix();

    //Wing 2
    glPushMatrix();
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.2f, 0.1f);
    glVertex2f( -0.8f, 0.05f);
    glVertex2f( -0.8f,  -0.05f);
    glVertex2f(-0.2f,  -0.1f);
    glEnd();
    glPopMatrix();

    //Wing 3
    glPushMatrix();
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.2f);
    glVertex2f(0.1f, 0.2f);
    glVertex2f( 0.05f, 0.8f);
    glVertex2f( -0.05f,  0.8f);
    glVertex2f(-0.1f,  0.2f);
    glEnd();
    glPopMatrix();

    //Wing 4
    glPushMatrix();
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glColor3f(1.55f, 0.8f, 0.16f);
    glVertex2f(0.1f, -0.2f);
    glVertex2f( 0.05f, -0.8f);
    glVertex2f( -0.05f,  -0.8f);
    glVertex2f(-0.1f,  -0.2f);
    glEnd();
    glPopMatrix();
    angle+=8.0f;

    glutSpecialFunc(speed);

    glFlush();  // Render now
}

int main(int argc, char** argv)
{
//    cout << "Enter speed of fan"<<endl;
//    cin >> refresh;
    glutInit(&argc, argv);          // Initialize GLUT
    glutInitWindowSize(320, 320);   // Set the window's initial width & height - non-square
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("FAN");  // Create window with the given title
    glutDisplayFunc(display);
    initGL();

    glutTimerFunc(0, Timer,0);
    glutMainLoop();
    return 0;
}
