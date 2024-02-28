#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
using namespace std;
int x1;
int y11;
int x2,y2,s1,s2,dx,dy,x,y,interchange,e ,xi,length;
float boundaryColor[3]={1,0,0}, interiorColor[3]={1,1,1}, fillColor[3]={0,1,1};
float readpixel[3];

void myInit (void) {
  glClearColor(1.0,1.0,1.0,1.0);
  glLineWidth(5.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,640.0,0.0,480.0);
}
int Sign(int x){
if(x>0)
return 1;
else if(x<0)
return -1;
else
return 0;
}
void setpixel(float x , float y){
     glColor3fv(fillColor);
     glBegin(GL_POINTS);
     glVertex2f(x,y);
     glEnd();
     glFlush();
}

void getpixel(int x , int y , float *Color){
   glReadPixels(x,y,1,1,GL_RGB , GL_FLOAT , Color);
 
}
void DDA(float x1,float y11,float x2,float y2){
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

glBegin(GL_POINTS);
	
	glVertex2i(x,y);

int i=1;
while(i<=length)
{
x=x+dx;
y=y+dy;
   glVertex2i(x,y);
   i=i+1;
}

   glEnd();
   glFlush();
    
}
   


void boundaryFill(int x,int y,float fillColor[],float boundaryColor[])
{
	getpixel(x, y,readpixel);
	if ((readpixel[0] != boundaryColor[0] || readpixel[1] != boundaryColor[1] || readpixel[2] != boundaryColor[2]) && (readpixel[0] != fillColor[0] || readpixel[1] !=fillColor[1] || readpixel[2] != fillColor[2]))
	 {setpixel( x ,  y);
		boundaryFill(x + 1, y,fillColor,boundaryColor);
		boundaryFill(x - 1, y,fillColor,boundaryColor);
		boundaryFill(x, y + 1,fillColor,boundaryColor);
		boundaryFill(x, y - 1,fillColor,boundaryColor);

	}

	
}
void floodFill(int x, int y,float fillColor[],float interiorColor[])
{
	getpixel(x, y,readpixel);
	if (readpixel[0] == interiorColor[0] && readpixel[1] == interiorColor[1] && readpixel[2] == interiorColor[2])
	{setpixel( x ,  y);
		floodFill(x + 1, y , fillColor , interiorColor);
		floodFill(x, y + 1,fillColor,interiorColor);
		floodFill(x - 1, y,fillColor,interiorColor);
		floodFill(x, y - 1,fillColor,interiorColor);

	
	
	}
}
void display(){

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

void mouse(int btn , int state , int x , int y){
   	if((btn==GLUT_LEFT_BUTTON) && (state==GLUT_DOWN)){
      		xi=x;
      		y11=480-y;
      	}
}

void Menu(int ch){
  switch(ch){
     case 1:boundaryFill(xi,  y11, fillColor , boundaryColor);
            break;
     case 2: floodFill(xi,y11,fillColor,interiorColor);
            break;
     case 3:exit(0);
  }
}
int main(int argc,char ** argv){
     
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Polygon Filling algorithm");
    myInit();
    glutDisplayFunc(display);
    glutCreateMenu(Menu);
    glutAddMenuEntry("1.Boundary Fill" , 1);
    glutAddMenuEntry("2.Flood Fill" , 2);
    glutAddMenuEntry("3.Exit" , 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMouseFunc(mouse);
    
    
    glutMainLoop();
    return 0;
    }


