//Mouse
#include<GL/glut.h>
#include<iostream>
#include<math.h>
#define w 500
#define h 500
using namespace std;
int x1,y11,k=0,flag=0,choice,clear=0;
float mati[100][100];
float mato[100][100];

void myInit (void) {
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0f,0.0f,1.0f);
	glPointSize(3.0);
	glLineWidth(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2,w/2,-h/2,h/2);
}
//Plotting the pixel
void setpixel(float x,float y) {
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}
void MultiplyMatrix(float arr[3][3]){
	for(int i=0;i<k;i++){
		mato[i][0]=(float)(arr[0][0]*mati[i][0]+arr[0][1]*mati[i][1]+arr[0][2]*mati[i][2]);
		mato[i][1]=(float)(arr[1][0]*mati[i][0]+arr[1][1]*mati[i][1]+arr[1][2]*mati[i][2]);
		mato[i][2]=(float)(arr[2][0]*mati[i][0]+arr[2][1]*mati[i][1]+arr[2][2]*mati[i][2]);
	}
}
//Mouse Function
void mouse_click(int button,int state,int x,int y) {
	if(state==GLUT_DOWN) {
		if(button==GLUT_LEFT_BUTTON) {
			if(flag==1){
				cout<<k<<endl;
				k=0;
				flag=0;
			}
			mati[k][0]=(float)(x-250);
			mati[k][1]=(float)(250-y);
			mati[k][2]=(float)1;
			glBegin(GL_POINTS);
			glVertex2f(mati[k][0],mati[k][1]);
			glEnd();
			k++;
			glFlush();
		} else if(button==GLUT_RIGHT_BUTTON) {
			flag=1;
			cout<<flag;
			glBegin(GL_LINE_LOOP);
			for(int i=0; i<k; i++) {
				glVertex2f(mati[i][0],mati[i][1]);
			}
			glEnd();
			glFlush();
		}
	}
}
//Translation
void Translation() {
	float tx,ty;
	cout<<"Give values for shift vector"<<endl;
	cout<<"Enter tx: ";
	cin>>tx;
	cout<<"Enter ty: ";
	cin>>ty;
	float arrT[3][3];
	arrT[0][0]=1;
	arrT[0][1]=0;
	arrT[0][2]=tx;
	arrT[1][0]=0;
	arrT[1][1]=1;
	arrT[1][2]=ty;
	arrT[2][0]=0;
	arrT[2][1]=0;
	arrT[2][2]=1;
	MultiplyMatrix(arrT);
	glColor3f(0.0f,0.0f,1.0f);
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<k;i++){
		glVertex2f(mato[i][0],mato[i][1]);
	}
	glColor3f(1.0f,0.0f,1.0f);
	glEnd();
	glFlush();
}
//Scaling
void Scaling() {
	float Sx,Sy;
	if(choice==2){
		cout<<"Give values for Scale Factor"<<endl;
		cout<<"Enter S: ";
		cin>>Sx;
		Sy=Sx;
	}
	else if(choice==3){
		cout<<"Give values for Scale Factors"<<endl;
		cout<<"Enter Sx: ";
		cin>>Sx;
		cout<<"Enter Sy: ";
		cin>>Sy;
	}
	float arrS[3][3];
	arrS[0][0]=Sx;
	arrS[0][1]=0;
	arrS[0][2]=0;
	arrS[1][0]=0;
	arrS[1][1]=Sy;
	arrS[1][2]=0;
	arrS[2][0]=0;
	arrS[2][1]=0;
	arrS[2][2]=1;
	MultiplyMatrix(arrS);
	glColor3f(0.0f,1.0f,0.0f);
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<k;i++){
		glVertex2f(mato[i][0],mato[i][1]);
	}
	glColor3f(1.0f,0.0f,1.0f);
	glEnd();
	glFlush();
}
//Rotation
void Rotation() {
	float theta;
	cout<<"Give value of Theta (In Degree)"<<endl;
	cout<<"Enter Theta: ";
	cin>>theta;
	theta = theta*((3.14)/180);
	if(choice==1){
		theta=-theta;
	}	
	float arrR[3][3];
	arrR[0][0]=cos(theta);
	arrR[0][1]=-sin(theta);
	arrR[0][2]=0;
	arrR[1][0]=sin(theta);
	arrR[1][1]=cos(theta);
	arrR[1][2]=0;
	arrR[2][0]=0;
	arrR[2][1]=0;
	arrR[2][2]=1;
	MultiplyMatrix(arrR);
	glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<k;i++){
		glVertex2f(mato[i][0],mato[i][1]);
	}
	glColor3f(1.0f,0.0f,1.0f);
	glEnd();
	glFlush();
}
//Menu
void Menu(int n) {
	if(n==1) {
		Translation();
	} else if(n==2) {
		Rotation();
		choice=1;
	} else if(n==3) {
		Rotation();
	} else if(n==4) {
		Scaling();
		choice=2;
	} else if(n==5) {
		Scaling();
		choice=3;
	} else {
		exit(0);
	}
}
//Display Function
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);	
	for(int i=-w; i<=w; i++) {
		setpixel(0,i);
		setpixel(i,0);
	}
	glEnd();
	glFlush();
}
//Main Function
int main(int argc, char ** argv) {
	glutInit( & argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 150);
	glutCreateWindow(" Quadarant");
	myInit();
	glutDisplayFunc(display);
	glutMouseFunc(mouse_click);
	glutCreateMenu(Menu);
	glutAddMenuEntry("Translation",1);
	glutAddMenuEntry("Clockwise Rotation",2);
	glutAddMenuEntry("Anti Clockwise Rotation",3);
	glutAddMenuEntry("Uniform Scaling",4);
	glutAddMenuEntry("Differential Scaling",5);
	glutAddMenuEntry("Exit",6);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
	glutMainLoop();
	return 0;
}
