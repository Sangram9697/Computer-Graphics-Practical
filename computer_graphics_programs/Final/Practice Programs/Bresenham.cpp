#include<iostream>
#include<GL/glut.h>
#include<math.h>
#define h 500
#define w 500

using namespace std;
int x1, y11, x2, y2, dx, dy,S1,S2, interchange, e, temp, x,y;

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2,w/2,-h/2,h/2);
	glPointSize(3.0);
}

int Sign(int x)
{
	if(x>0)
		return +1;
	else if(x<0)
		return -1;
	else
		return 0;
}

void setPixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void bline(int x1, int y11, int x2, int y2)
{
	x=x1;
	y=y11;
	
	dx=abs(x2-x1);
	dy=abs(y2-y11);
	S1=Sign(x2-x1);
	S2=Sign(y2-y11);
	
	if(dy>dx)
	{
		temp=dx;
		dx=dy;
		dy=temp;
		interchange=1;		
	}
	else
	{
		interchange =0;
	}
	e=2*dy-dx;
	for(int i=1; i<=dx; i++)
	{
		setPixel(x,y);
		while(e>=0)
		{
			if(interchange==1)
			{
				x=x+S1;
			}
			else
			{
				y=y+S2;
			}
			e=e-2*dx;
		}
		if(interchange==1)
		{
			y=y+S2;
		}
		else
		{
			x=x+S1;
		}
		e=e+2*dy;
	}
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	for(int i =-w; i<=w;i++)
	{
		setPixel(i,0);
		setPixel(0,i);
	}
	bline(100,100,50,200);
	glEnd();
	glFlush();	
}

int main(int argc, char **argv)
{	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("Practice Bresenham");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}














