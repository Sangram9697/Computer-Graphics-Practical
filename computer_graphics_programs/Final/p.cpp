#include<GL/glut.h>
#include<iostream>

using namespace std;

float x1,y11,x2,y2,dx,dy,x,y,length,xi;
float bcolor[3]={1,0,0}, icolor[3]={1,1,1}, fcolor[3]={0,1,1};
float readPixel[3];

void myInit (void) {
  glClearColor(1.0,1.0,1.0,1.0);
  glLineWidth(5.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,640.0,0.0,480.0);
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
	glColor3fv(fcolor);
     glBegin(GL_POINTS);
     glColor3f(1.0,0.0,0.0);
     glVertex2f(x,y);
     glEnd();
     glFlush();
}
void DDA(float x1, float y11, float x2, float y2)
{
	if(abs(x2-x1)>abs(y2-y11))
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
		setPixel(x,y);
	}
}

void getPixel(int x, int y, float *Color)
{
	glReadPixels(x,y,1,1,GL_RGB, GL_FLOAT, Color);
}

void bfill(int x, int y, float fcolor[], float bcolor[])
{
	getPixel(x,y,readPixel);
	if(readPixel[0]!=bcolor[0] || readPixel[1]!=bcolor[1] || readPixel[2]!=bcolor[2] && readPixel[0]!=fcolor[0] || readPixel[1]!=fcolor[1] || readPixel[2]!=fcolor[2])
	{
		setPixel(x,y);
		bfill(x+1, y, fcolor, bcolor);
		bfill(x-1, y, fcolor, bcolor);
		bfill(x, y+1, fcolor, bcolor);
		bfill(x, y-1, fcolor, bcolor);
	}
}
void floodFill(int x, int y,float fcolor[],float icolor[])
{
	getPixel(x, y,readPixel);
	if (readPixel[0] == icolor[0] && readPixel[1] == icolor[1] && readPixel[2] == icolor[2])
	{setPixel( x ,  y);
		floodFill(x + 1, y , fcolor , icolor);
		floodFill(x, y + 1,fcolor,icolor);
		floodFill(x - 1, y,fcolor,icolor);
		floodFill(x, y - 1,fcolor,icolor);

	
	
	}
}
void myDisplay()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glColor3f(1.0,0.0,0.0);
	DDA(150,100,450,100);
	DDA(450,100,450,300);
	DDA(450,300,150,300);
	DDA(150,300,150,100);
	glEnd();
	glFlush();

}


void mouse(int btn, int state, int x, int y)
{
	if((btn==GLUT_LEFT_BUTTON) && (state==GLUT_DOWN))
	{
		xi=x;
		y11=480-y;
	}
}

void menu(int ch)
{
	switch(ch)
	{
		case 1: bfill(xi, y11, fcolor, bcolor);
			break;
     		case 2: floodFill(xi,y11,fcolor,icolor);
           		break;
		
		case 3:exit(0);
	}
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,500);
	glutCreateWindow("Polygon Filling");
	myInit();
	glutDisplayFunc(myDisplay);
	glutCreateMenu(menu);
	glutAddMenuEntry("Boundary fill", 1);
	glutAddMenuEntry("Flood fill", 2);
	glutAddMenuEntry("Exit", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);	
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;


}











