#include<iostream>
#include<math.h>
#include<GL/glut.h>
#include<GL/gl.h>
using namespace std;
#define h 500
#define w 500

float dx,dy,x,y,x1,x2,len,y11,y2;
void myinit(void){
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0f,0.0f,0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPointSize(4.0);
	glLineWidth(0.5);
	gluOrtho2D(-w/2,w/2,-h/2,h/2);
}
void setpixel(int x,int y){
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	for(int i=-w;i<=w;i++){
	setpixel(i,0);
	setpixel(0,i);
	
	}
	glEnd();
	glFlush();
}
int sign(int x){
	if(x>0)
	return +1;
	else if(x<0)
	return -1;
	else
	return 0;
}
void dda(float x1,float y11,float x2,float y2){
	if(abs(x2-x1)>abs(y2-y11)){
	len=abs(x2-x1);
	}
	else{
	len=abs(y2-y11);
	}
	dx=(x2-x1)/len;
	dy=(y2-y11)/len;
	x=x1+0.5*sign(dx);
	y=y11+0.5*sign(dy);
	
	setpixel(x,y);
	int i=1;
	while(i<=len){
		x=x+dx;
		y=y+dy;
		i=i+1;
		setpixel(x,y);
	}
	


//return x,y;
}
void menu(int ch){
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS);
	display();
	if(ch=1)
	dda(x1,y11,x2,y2);	
    glEnd();
    glFlush();
}
int main(int argc, char ** argv) {
cout<<endl<<"|| Prgramm Of DDA Algorithm ||"<<endl<<endl;

  cout<<"Enter Point x1 : ";
  cin>>x1;
  cout<<"Enter Point y1 : ";
  cin>>y11;
  cout<<"Enter Point x2 : ";
  cin>>x2;
  cout<<"Enter Point y2 : ";
  cin>>y2;
 
  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 150);
  glutCreateWindow("DDA Line");
  myinit ();
  glutCreateMenu(menu);
  glutAddMenuEntry("Normal Line", 1);

  glutAttachMenu(GLUT_RIGHT_BUTTON);
 
 
 
 
  glutMainLoop();
  return 0;
}
