///National flag of Armenia using GL Primitives.
/*
        Name: Rayhan, Md Saif Siddique
        Id: 15-28295-1
        Sec: B2
*/
#include <GL/gl.h>
#include <Gl/glut.h>

void display()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

// initializing Red Color
    glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-1.0, 1.0);
        glVertex2f(-1.0, 0.33);
        glVertex2f(1.0, 0.33);
        glVertex2f(1.0, 1.0);
    glEnd();
// initializing Blue Color
    glBegin(GL_QUADS);
        glColor3f(0.0,0.0,1.0);
        glVertex2f(-1.0, 0.33);
        glVertex2f(-1.0, -0.33);
        glVertex2f(1.0, -0.33);
        glVertex2f(1.0, 0.33);
	glEnd();

// initializing Yellow Color
	glBegin(GL_QUADS);
        glColor3f(1.0,1.0,0.0);
        glVertex2f(1.0, -1.0);
        glVertex2f(1.0, -0.33);
        glVertex2f(-1.0, -0.33);
        glVertex2f(-1.0, -1.0);
	glEnd();

	glFlush(); // Rendering

}
int main(int argc, char**argv)
{
   glutInit(&argc, argv);
   glutCreateWindow("Armenia's Flag");
   glutInitWindowSize(320,320);
   glutInitWindowPosition(50,50);
   glutDisplayFunc(display);
   glutMainLoop();
}
