#include<iostream>
#include<GL/glut.h>
#include<math.h>
#define h 700
#define w 800
#define pi 3.14
using namespace std;

float red[3]={1.0,0.0,0.0}, green[3]={0.0,1.0,0.0}, white[3]={1.0, 1.0, 1.0}, black[3]={0.0, 0.0, 0.0}, blue[3]={0.0,0.0,1.0};

float mati[20][3];
float mat[2][3];
float mato[20][3];

static int k;
bool flag=1;

void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glPointSize(5.0);
	glLineWidth(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2,w/2,-h/2, h/2);
}

void mul(float a[][3], float b[][3], float c[][3], int d)
{
	
	for(int i=0; i<=d; i++)
	{
		for(int j=0; j<=2; j++)
		{
			for(int m=0; m<=2; m++)
			{
				c[i][j]+=(a[i][m]*b[m][j]);
			}
		}
	}
}

void plot(float a[][3], int m)
{
	glColor3fv(green);
	glBegin(GL_LINE_LOOP);
	for(int i=0; i<m; i++)
	{
		glVertex2f(a[i][0], a[i][1]);
	}
	glEnd();
	glFlush();
}

void setPixel(int x, int y)
{
	glColor3fv(black);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}

void translate(float tx, float ty)
{
	for(int i=0; i<=2; i++)
	{
		for(int j=0; j<=2; j++)
		{
			mat[i][j]=0;
		}
	}
	
	mat[0][0]=1;
	mat[0][1]=0;
	mat[0][2]=0;
	mat[1][0]=0;
	mat[1][1]=1;
	mat[1][2]=0;
	mat[2][0]=tx;
	mat[2][1]=ty;
	mat[2][2]=1;	
}

void clearDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3fv(blue);
	glBegin(GL_POINTS);
	for(int i=-w/2; i<w/2; i++)
	{
		setPixel(i,0);
		setPixel(0,i);
	}
	glEnd();
	glFlush();
}

void myMenu(int s)
{
	if(s==1)
	{
		clearDisplay();
		for(int i=0; i<=k; i++)
		{
			for(int j=0; j<=3; j++)
			{
				mat[i][j]=0;
				mato[i][j]=0;
			}
		}
	}
}

void translation_menu(int t)
{
	int tx=0, ty=0;
	switch(t)
	{
		case 1: cout<<"tx";
		cin>>tx;
		translate(tx,ty);
		mul(mati, mat, mato, k);
		plot(mato, k);
		break;
		
		case 2: cout<<"ty";
		cin>>ty;
		translate(tx,ty);
		mul(mati, mat, mato, k);
		plot(mato, k);
		break;
		
		case 3: cout<<"tx";
		cin>>tx;
		cout<<"ty";
		cin>>ty;
		translate(tx,ty);
		mul(mati, mat, mato, k);
		plot(mato, k);
		break;
	}
}
void myDisplay()
{
	glEnd();
	glFlush();
}

void myMouse(int btn, int state, int x, int y)
{
	if(state==GLUT_DOWN)
	{
		if(btn==GLUT_LEFT_BUTTON)
		{
			if(flag)
			{
				flag=0;
				k=0;
			}
			
			mati[k][0]=x-w/2;
			mati[k][1]=h/2-y;
			mati[k][2]=1;
			setPixel(x-w/2, h/2-y);
			k=k+1;
		}
		
		else if(btn==GLUT_RIGHT_BUTTON)
		{
			flag=1;
			
			glBegin(GL_LINE_LOOP);
			for(int i=0; i<k; i++)
			{
				glVertex2f(mati[i][0], mati[i][1]);
			}
			glEnd();
			glFlush();
		}
	}
	
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(w,h);
	glutInitWindowPosition(100,500);
	glutCreateWindow("Trans Pract");
	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	init();
	
	int translation_id= glutCreateMenu(translation_menu);
		glutAddMenuEntry("x-axis", 1);
		glutAddMenuEntry("y-axis", 2);
		glutAddMenuEntry("xy-axis", 3);
	
	glutCreateMenu(myMenu);
	glutAddMenuEntry("Clear Dispaly", 1);
	glutAddSubMenu("Translation", translation_id);
		
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
	glutMainLoop();
	return 0;
}














