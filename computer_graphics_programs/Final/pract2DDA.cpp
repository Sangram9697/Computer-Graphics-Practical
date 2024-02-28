//Practical 1 -DDA line drawing algorithm with all cases:
#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;
# define h 500
# define w 500
float x1,y11,x2,y2,length,dx,dy,x,y;
int ch;

void myInit (void) {
  glClearColor(1.0,1.0,1.0,0.0);
  glColor3f(0.0f,0.0f,0.0f);
  glPointSize(3.0);
  glLineWidth(0.5);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-w/2 , w/2 , -h/2 , h/2);
}

int Sign(int x){
	if(x>0)
	return +1;
	else if(x<0)
	return -1;
	else
	return 0;
}

void setpixel(int x , int y){
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void mydisplay(void){
	glClear(GL_COLOR_BUFFER_BIT);
	for(int i=-w ; i<=w ; i++){
		setpixel(i , 0);
		setpixel(0,i);
	}
	glEnd();
	glFlush();
}

void DDA1(float x1,float y11,float x2,float y2){
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

	setpixel(x,y);

	int i=1;
	while(i<=length)
	{
		x=x+dx;
		y=y+dy;
		i=i+1;

		setpixel(x, y);
	}

}

void DDA2(float x1,float y11,float x2,float y2){
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

	setpixel(x,y);

	int i=1;
	while(i<=length)
	{
		x=x+dx;
		y=y+dy;
		i=i+1;
	
		if(i%25==0 )
		setpixel(x, y);
	}

}

void DDA3(float x1,float y11,float x2,float y2){
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

	setpixel(x,y);

	int i=1;
	while(i<=length)
	{
		x=x+dx;
		y=y+dy;
		i=i+1;

		if(i%1==0 && i%5!=0 )
		setpixel(x, y);
   
	}
}

void DDA4(float x1,float y11,float x2,float y2){
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

	setpixel(x,y);

	int i=1;
	while(i<=length)
	{
		x=x+dx;
		y=y+dy;
		i=i+1;

		if(i%20<=10 || i%20==15)
		setpixel(x, y);
	}

}

void boat(){
	DDA1(50,50,200,50);  //Line 1
	DDA1(0,125,250,125);  //Line 2
	DDA1(0,125,50,50);  //Line 3
	DDA1(250,125,200,50);  //Line 4
	DDA1(75,125,75,200);  //Line 5
	DDA1(140,125,75,200);  //Line 6
//	DDA1(5,50,10,20);
     
}

void display1(){

}

void menu(int ch) {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	mydisplay();

	if(ch==1)
		DDA1(x1, y11, x2, y2);

	if(ch==2)
		DDA2(x1, y11, x2, y2);

	if(ch==3)
		DDA3(x1, y11, x2, y2);

	if(ch==4)
		DDA4(x1, y11, x2, y2);

	if(ch==5)
		boat();
     
	if(ch==6)
		exit(0);

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
	myInit ();
	glutDisplayFunc(display1);
	glutCreateMenu(menu);
	glutAddMenuEntry("Normal Line", 1);
	glutAddMenuEntry("Dotted Line", 2);
	glutAddMenuEntry("Dash Line", 3);
	glutAddMenuEntry("Centre dash Line", 4);
	glutAddMenuEntry("Boat",5);
	glutAddMenuEntry("Exit", 6);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}


