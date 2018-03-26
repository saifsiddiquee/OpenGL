#include <iostream>
#include <math.h>
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
using namespace std;
/* Initialize OpenGL Graphics */
GLfloat angle = 0.0f;
GLfloat anglem = 0.0f;
GLfloat angleh = 0.0f;
GLint refresh = 1000;

void initGL()
{
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void Timer(int val)
{
    glutPostRedisplay();
    glutTimerFunc(refresh, Timer,0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);    // Clear the color buffer
    //glMatrixMode(GL_MODELVIEW);      // To operate on Model-View matrix
    //circle
    glLineWidth(10.0);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < 900 ; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(900);
        float x = 0.90 * cosf(theta);
        float y = 0.90 * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();


    glLineWidth(12.0);
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(0.0, 0.9);
    glVertex2f(0.0, 0.8 );
    glEnd();

    glLineWidth(12.0);
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(0.0, -0.9);
    glVertex2f(0.0, -0.8 );
    glEnd();

    glLineWidth(12.0);
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(-0.9, 0.0);
    glVertex2f(-0.8, 0.0 );
    glEnd();

    glLineWidth(12.0);
    glBegin(GL_LINES);
    glColor3f(0.5, 0.5, 0.5);
    glVertex2f(0.9, 0.0);
    glVertex2f(0.8, 0.0 );
    glEnd();

    glLoadIdentity();

    //second
    glPushMatrix();
    glRotatef(angle, 0.0f, 0.0f, 1.0f);// Reset the model-view matri
    glBegin(GL_POLYGON);               // Each set of 4 vertices form a quad
    glColor3f(1.0f, 1.0f, 1.0f);  // Red
    glVertex2f(0.0f, 0.0f);     // Define vertices in counter-clockwise (CCW) order
    glVertex2f( 0.6f, 0.025f);     //  so that the normal (front-face) is facing you
    glVertex2f( 0.7f,  0.0f);
    glVertex2f(0.6f,  -0.025f);
    glEnd();
    glPopMatrix();
    angle+=6.0f;

    if (angle>360.0)
    {
        anglem+= 6.0;
        angle = 0.0;
    }

    // minute
    glPushMatrix();
    glRotatef(anglem, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);               // Each set of 4 vertices form a quad
    glColor3f(1.0f, 0.0f, 0.0f);  // Red
    glVertex2f(0.0f, 0.0f);     // Define vertices in counter-clockwise (CCW) order
    glVertex2f( 0.5f, 0.025f);     //  so that the normal (front-face) is facing you
    glVertex2f( 0.6f,  0.0f);
    glVertex2f(0.5f,  -0.025f);
    glEnd();
    glPopMatrix();

    if (anglem>360.0)
    {
        angleh+= 30.0;
        anglem = 0.0;
    }

    //cout << angle<<" " << anglem<<" " << angleh<<endl;
    // hour
    glPushMatrix();
    glRotatef(angleh, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);               // Each set of 4 vertices form a quad
    glColor3f(0.0f, 1.0f, 0.0f);  // Red
    glVertex2f(0.0f, 0.0f);     // Define vertices in counter-clockwise (CCW) order
    glVertex2f( -0.025f, 0.3f);     //  so that the normal (front-face) is facing you
    glVertex2f( 0.0f,  0.4f);
    glVertex2f(0.025f,  0.3f);
    glEnd();
    glPopMatrix();
    //inner circle
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 3.5, 0.5);
    glLineWidth(5.0);
    for(int i = 0; i < 900 ; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(900);
        float x = 0.03 * cosf(theta);
        float y = 0.03 * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();   // Render now
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);          // Initialize GLUT
    glutInitWindowSize(320, 320);   // Set the window's initial width & height - non-square
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("clock");  // Create window with the given title
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    //glutReshapeFunc(reshape);       // Register callback handler for window re-size event
    initGL();
    //glutIdleFunc(GhuraGhuri);
    glutTimerFunc(0, Timer,0);                        // Our own OpenGL initialization
    glutMainLoop();
    // Enter the infinite event-processing loop
    return 0;
}


