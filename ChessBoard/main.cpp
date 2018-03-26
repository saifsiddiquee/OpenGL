///Chess board using GL Primitives.
/*
        Name: Rayhan, Md Saif Siddique
        Id: 15-28295-1
        Sec: B2
*/
#include <GL/gl.h>
#include <Gl/glut.h>

void display()
{
    glClearColor(0.0, 0.0, 0.0, 0.0); // set background color to black
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(255.0, 255.0, 255.0); // initialize white color
    float x = -1; // coordinate 'x'
    float y = 1; // coordinate 'y'
    float intv = 0.25; // interval between Quads

    for (int t = 1; t < 3; t++) // for iteration twice
    {
        for(int a = 1; a < 5; a++)
        {
            for(int b = 1; b < 5; b++)
            {
                glBegin(GL_QUADS);
                glVertex2f(x, y);
                glVertex2f(x, y-intv);
                glVertex2f(x+intv, y-intv);
                glVertex2f(x+intv, y);
                glEnd();
                x+=0.5;
            }
            x = -1.0;
            if (t == 2)
            {
                x = -0.75;
            }
            y -= 0.50;
        }
        x = -0.75;
        y = 0.75;
    }
    glFlush();
}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("8x8 Chess Board");
    glutInitWindowSize(320,320);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);

    glutMainLoop();
}
