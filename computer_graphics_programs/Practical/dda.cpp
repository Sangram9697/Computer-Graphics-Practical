#include<iostream>
#include<GL/glut.h>
#include<math.h>
#define w 500
#define h 500

using namespace std;

float x1, y11, x2, y2, len, dx, dy, x, y, interchange;
int ch;

void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2,w/2,-h/2,h/2);
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



void dda(float x1, float y11, float x2, float y2)
{
	if(abs(x2-x1)>abs(y2-y11))
	{
		len=abs(x2-x1);
	}
	else
	{
		len=abs(y2-y11);
	}	
	dx=(x2-x1)/len;
	dy=(y2-y11)/len;
	
	x=x1+0.5*Sign(dx);
	y=y11+0.5*Sign(dy);
	setPixel(x,y);
	int i=1;
	while(i<=len)
	{
		x=x+dx;
		y=y+dy;
		i=i+1;
		setPixel(x,y);
	}

}

void dotted_dda(float x1, float y11, float x2, float y2)
{
	if(abs(x2-x1)>abs(y2-y11))
	{
		len=abs(x2-x1);
	}
	else
	{
		len=abs(y2-y11);
	}	
	dx=(x2-x1)/len;
	dy=(y2-y11)/len;
	
	x=x1+0.5*Sign(dx);
	y=y11+0.5*Sign(dy);
	setPixel(x,y);
	int i=1;
	while(i<=len)
	{
		x=x+dx;
		y=y+dy;
		i=i+1;
		if(i%25==0)
		setPixel(x,y);
	}
}

void dashed_dda(float x1, float y11, float x2, float y2)
{
	if(abs(x2-x1)>abs(y2-y11))
	{
		len=abs(x2-x1);
	}
	else
	{
		len=abs(y2-y11);
	}	
	dx=(x2-x1)/len;
	dy=(y2-y11)/len;
	
	x=x1+0.5*Sign(dx);
	y=y11+0.5*Sign(dy);
	setPixel(x,y);
	int i=1;
	while(i<=len)
	{
		x=x+dx;
		y=y+dy;
		i=i+1;
		if(i%2==0 && i%5!=0)
		setPixel(x,y);
	}
}

void center_dotted_dda(float x1, float y11, float x2, float y2)
{
	if(abs(x2-x1)>abs(y2-y11))
	{
		len=abs(x2-x1);
	}
	else
	{
		len=abs(y2-y11);
	}	
	dx=(x2-x1)/len;
	dy=(y2-y11)/len;
	
	x=x1+0.5*Sign(dx);
	y=y11+0.5*Sign(dy);
	setPixel(x,y);
	int i=1;
	while(i<=len)
	{
		x=x+dx;
		y=y+dy;
		i=i+1;
		if(i%20<=10 || i%20==15)
		setPixel(x,y);
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glColor3f(1.0,0.0,0.0);
	
	for(int i=-w; i<=w; i++)
	{
		setPixel(i, 0);
		setPixel(0, i);
	}
	glEnd();
	glFlush();
	
}

void menu(int ch)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_POINTS);
	display();
	if(ch==1) 
	dda(10,10,100,100);
	
	if(ch==2)
	dotted_dda(-10,10,-100,100);
	
	if(ch==3)
	dashed_dda(10,-10,100,-100);
	
	if(ch==4)
	center_dotted_dda(-10,-10,-100,-100);
	
	if(ch==5)
	exit(0);
		
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	
	glutInitWindowSize(600,400);
	glutInitWindowPosition(100,500);
	glutCreateWindow("DDA");
	init();
	glutDisplayFunc(display);
	glutCreateMenu(menu);
	glutAddMenuEntry("Simple Line", 1);
	glutAddMenuEntry("Dotted Line", 2);
	glutAddMenuEntry("Dashed Line", 3);
	glutAddMenuEntry("Center Dotted Line", 4);
	glutAddMenuEntry("Exit", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	
	glutMainLoop();
	return 0;
}











