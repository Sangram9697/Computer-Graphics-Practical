#include<iostream>
//#include <Gl/glut.h>
#include<math.h>
#include<GL/glut.h>
using namespace std;

#define h 500
#define w 500

float x1,y11,x2,y2,length,dx,dy,x,y;
int ch;


void myInit(void){
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(3.0);
	glLineWidth(0.5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2, w/2, -h/2, h/2);
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

void SimpleDDA(float x1, float y11, float x2, float y2)
{
	if(abs(x2-x1)>=abs(y2-y11))
	{
		length=abs(x2-x1);
	}
	else
	{
		length=abs(y2-y11);
	}
	dx=(x2-x1)/length;
	dy=(y2-y11)/length;
	
	x=x1+0.5*Sign(dx);
	y=y11+0.5*Sign(dy);
	
	setPixel(x,y);
	int i=1;
	while(i<=length)
	{
		x=x+dx;
		y=y+dy;
		i=i+1;
		setPixel(x,y);
	}
}

void DottedDDA(float x1, float y11, float x2, float y2)
{
	if(abs(x2-x1)>=abs(y2-y11))
		length=abs(x2-x1);
	else
		length=abs(y2-y11);
		
	dx=(x2-x1)/length;
	dy=(y2-y11)/length;
	
	x=x1+0.5*Sign(dx);
	y=y11+0.5*Sign(dy);
	
	setPixel(x,y);
	int i=1;
	while(i<=length)
	{
		x=x+dx;
		y=y+dy;
		i=i+1;
		
		if(i%25==0)
		setPixel(x,y);
	}
}

void DashedDDA(float x1, float y11, float x2, float y2)
{
	if(abs(x2-x1)>=abs(y2-y11))
		length=abs(x2-x1);
	else
		length=abs(y2-y11);
		
	dx=(x2-x1)/length;
	dy=(y2-y11)/length;
	
	x=x1+0.5*Sign(dx);
	y=y11+0.5*Sign(dy);
	
	setPixel(x,y);
	int i=1;
	while(i<=length)
	{
		x=x+dx;
		y=y+dy;
		i=i+1;
		
		if(i%2==0 && i%5!=0)
		setPixel(x,y);
	}
}

void CenterDottedDDA(float x1, float y11, float x2, float y2)
{
	if(abs(x2-x1)>=abs(y2-y11))
		length=abs(x2-x1);
	else
		length=abs(y2-y11);
		
	dx=(x2-x1)/length;
	dy=(y2-y11)/length;
	
	x=x1+0.5*Sign(dx);
	y=y11+0.5*Sign(dy);
	
	setPixel(x,y);
	int i=1;
	while(i<=length)
	{
		x=x+dx;
		y=y+dy;
		i=i+1;
		
		//if(i%20<=10 || i%20==15)
		if(i%20<=10 || i%20==15)
		setPixel(x,y);
	}
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	for(int i=-w; i<=w; i++)
	{
		setPixel(i,0);
		setPixel(0,i);
	}
	//DDA(10,10,100,100);
	glEnd();
	glFlush();
}

void menu(int ch)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	myDisplay();
	
	if(ch==1)
		SimpleDDA(10,10,100,100);
		
	if(ch==2)
		DottedDDA(-10,-10,-100,-100);
		
	if(ch==3)
		DashedDDA(-10,10,-100,100);
	
	if(ch==4)
		CenterDottedDDA(10,-10,100,-100);
		
	if(ch==5)
		SimpleDDA(10,10,20,20);
		SimpleDDA(20,20,30,10);
		SimpleDDA(30,10,40,20);
		SimpleDDA(42,20,50,10);
		SimpleDDA(50,10,60,20);
		SimpleDDA(60,20,70,10);
		SimpleDDA(70,10,80,20);
		SimpleDDA(80,20,90,10);
		
		
	if(ch==6)
		exit(0);
	
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);	
	glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("Practice Program");
	myInit();
	glutDisplayFunc(myDisplay);
	glutCreateMenu(menu);
	glutAddMenuEntry("Simple DDA", 1);
	glutAddMenuEntry("Dotted DDA", 2);
	glutAddMenuEntry("Dashed DDA", 3);
	glutAddMenuEntry("Center Dotted DDA", 4);
	glutAddMenuEntry("Zigzag Line", 5);
	glutAddMenuEntry("Exit", 6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}





















