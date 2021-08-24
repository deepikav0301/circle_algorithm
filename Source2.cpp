#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;
int p, q, r;
void myInit(void)
{
	glClearColor(0.5, 1.0, 0.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void plotVertex(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x + p, y + q);
	glEnd();
}
void drawLine(int a1, int b1, int a2, int b2)
{
    glColor3f(1.0, 0.0, 0.0);
    int dx, dy, x_l, y_l, c, x, y;
    dx = abs(a1 - a2);
    dy = abs(b1 - b2);
    if (dy <= dx)
    {
        c = 2 * dy - dx;
        if (a1 > a2)
        {
            x = a2;
            y = b2;
            x_l = a1;
        }
        else
        {
            x = a1;
            y = b1;
            x_l = a2;
        }
        while (x <= x_l)
        {
            glBegin(GL_POINTS);
            glVertex2d(x, y);
            glEnd();
            x += 1;
            if (c < 0)
            {
                c += 2 * dy;
            }
            else
            {
                c += 2 * (dy - dx);
                y += 1;
            }
        }
    }
    else
    {
        c = 2 * dx - dy;
        if (b1 > b2)
        {
            x = a2;
            y = b2;
            y_l = b1;
        }
        else
        {
            x = a1;
            y = b1;
            y_l = b2;
        }
        while (y <= y_l)
        {
            glBegin(GL_POINTS);
            glVertex2d(x, y);
            glEnd();
            y += 1;
            if (c < 0)
            {
                c += 2 * dx;
            }
            else
            {
                c += 2 * (dx - dy);
                x += 1;
            }
        }
    }
    glFlush();
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	glPointSize(4.0);
	int x = 0;
	int y = r;
	float decs = 5 / 4 - r;
	plotVertex(x, y);
	while (y > x)
	{
		if (decs < 0)	{
			x++;
			decs += 2 * x + 1;
		}
		else {
			y--;
			x++;
			decs += 2 * (x - y) + 1;
		}
		plotVertex(x, y);
		plotVertex(x, -y);
		plotVertex(-x, y);
		plotVertex(-x, -y);
		plotVertex(y, x);
		plotVertex(-y, x);
		plotVertex(y, -x);
		plotVertex(-y, -x);
	}
    drawLine(p, q, p, q+r-15);
    drawLine(p, q, p+r-45, q-30);
	glFlush();
}

void main(int argc, char** argv)
{
	cout << " Clock using Line and Circle Drawing Alogrithm in C++ using OpenGL\n\n";
	cout << "Enter x co-ordinate for center of circle : "; cin >> p;
	cout << "Enter y co-ordinate for center of circle : "; cin >> q;
	cout << "Enter the radius : "; cin >> r;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(300, 100);
	glutCreateWindow("Clock using Line and Circle Drawing Alogrithm");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
