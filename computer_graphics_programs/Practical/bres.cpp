#include<iostream>
#include<GL/glut.h>
#include<math.h>

#define h 500
#define w 500
using namespace std;

int x1, y11, x2, y2, dx, dy, x, y, interchange, e, S1, S2, temp;

void init(void)
{
	/*glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2,w/2,-h/2,h/2);*/
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
		return 1;
	else if(x<0)
		return -1;
	else
		return 0;
}
void setPixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void simple(int x1, int y11, int x2, int y2)
{
	x=x1;
	y=y11;
	dx=abs(x2-x1);
	dy=abs(y2-y11);
	S1=Sign(x2-x1);
	S2=Sign(y2-y11);
	
	if(dy>dx)
	{
		int temp=dx;
		dx=dy;
		dy=temp;
		interchange=1;
	}
	else
	{
		interchange=0;
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
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	for(int i=-w; i<=w; i++)
	{
		setPixel(i,0);
		setPixel(0,i);
	}
	simple(10,10,100,100);
	glEnd();
	glFlush();
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,500);
	glutCreateWindow("Practice Bresenham");
	init();
	glutDisplayFunc(display);
	//glutCreateMenu(menu);
	//glutAddMenuEntry("Simple Line", 1);
	//glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	//glutAddMenuEntry("Exit",6);
	
	glutMainLoop();
	return 0;
}










