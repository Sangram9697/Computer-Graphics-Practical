
/*
Implement Bresenham circle drawing algorithm to draw any object. i) Simple circle ii) Concentric
circle iii) Olympic ring iv) Spiral .The object should be displayed in all the quadrants with respect to
center and radius
*/
#include<iostream>
#include<GL/glut.h>
using namespace std;
#define he 1300
#define wi 1300

int h, k, r, d, x, y, no;

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glPointSize(3.0);
	glLineWidth(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-wi/2,wi/2,-he/2,he/2);
}

void Plot(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void Circle(int r)
{
	d = 3 - 2*r;
	
	x = 0;
	y = r;
	
	Plot(x,y);
	
	while(x<=y)
	{
		if(d<=0)
		{
			d = d + 4*x + 6;
			x++;
		}
		else
		{
			d = d + 4*(x-y) + 10;
			x++;
			y--;
		}
		
		Plot(x+h,y+k);
		Plot(-x+h,-y+k);
		Plot(y+h,x+k);
		Plot(-y+h,-x+k);
		Plot(-y+h,x+k);
		Plot(y+h,-x+k);
		Plot(-x+h,y+k);
		Plot(x+h,-y+k);		
	}			
}

void Olympic_Ring(int r, int h, int k)
{
	d = 3 - 2*r;
	
	x = 0;
	y = r;
	
	Plot(x,y);
	
	while(x<=y)
	{
		if(d<=0)
		{
			d = d + 4*x + 6;
			x++;
		}
		else
		{
			d = d + 4*(x-y) + 10;
			x++;
			y--;
		}
		
		Plot(x+h,y+k);
		Plot(-x+h,-y+k);
		Plot(y+h,x+k);
		Plot(-y+h,-x+k);
		Plot(-y+h,x+k);
		Plot(y+h,-x+k);
		Plot(-x+h,y+k);
		Plot(x+h,-y+k);
	}			
}

void Spiral_Curve_1(int r, int h)
{
	d = 3 - 2*r;
	
	x = 0;
	y = r;
	
	Plot(x,y);
	
	while(x<=y)
	{
		if(d<=0)
		{
			d = d + 4*x + 6;
			x++;
		}
		else
		{
			d = d + 4*(x-y) + 10;
			x++;
			y--;
		}
		
		Plot(x+h,y+k);
	//	Plot(-x+h,-y+k);
		Plot(y+h,x+k);
	//	Plot(-y+h,-x+k);
		Plot(-y+h,x+k);
	//	Plot(y+h,-x+k);
		Plot(-x+h,y+k);
	//	Plot(x+h,-y+k);		
	}			
}

void Spiral_Curve_2(int r, int h)
{
	d = 3 - 2*r;
	
	x = 0;
	y = r;
	
	Plot(x,y);
	
	while(x<=y)
	{
		if(d<=0)
		{
			d = d + 4*x + 6;
			x++;
		}
		else
		{
			d = d + 4*(x-y) + 10;
			x++;
			y--;
		}
		
	//	Plot(x+h,y+k);
		Plot(-x+h,-y+k);
	//	Plot(y+h,x+k);
		Plot(-y+h,-x+k);
	//	Plot(-y+h,x+k);
		Plot(y+h,-x+k);
	//	Plot(-x+h,y+k);
		Plot(x+h,-y+k);		
	}			
}

void Menu(int n)
{	
	switch(n)
	{
		case 1:
			Circle(r);
			break;
				
		case 2:
			for(int i = 1; i<=no; i++)
			{
				Circle(r);
				r += 20;
			}	
			break;
			
		case 3:		
			// Upper Rings 
			glColor3f(0.0,0.0,1.0);
			Olympic_Ring(r, 2*r, 6*r);
			glColor3f(0.0, 0.0, 0.0);
			Olympic_Ring(r, 3.6*r, 6*r);
			glColor3f(1.0,0.0,0.0);
			Olympic_Ring(r, 5.2*r, 6*r);
			
			// Lower Rings
			
			glColor3f(1.0,1.0,0.0);
			Olympic_Ring(r, 2.8*r, 4.8*r);
			glColor3f(0.0,1.0,0.0);
			Olympic_Ring(r, 4.4*r, 4.8*r);
			glColor3f(0.0,0.0,0.0);
			break;	
			
		case 4:	
			for(int i = 0; i<2; i++)
			{
				Spiral_Curve_1(r, h);
				r *= 2;
				h -= r/2;
				Spiral_Curve_2(r, h);
				r *= 2;
				h += r/2;
			}		
			break;	
		/*	
		case 5:
			for(int i = 0; i<10; i++)
			{
				Spiral_Curve_2(r, h);
				r *= 2;
				h -= r/2;
				Spiral_Curve_1(r, h);
				r *= 2;
				h += r/2;
			}		
			break;	
		*/
		case 5:
			exit(0);
	}	
	
}	

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
//	glBegin(GL_POINTS);
	
	for(int i=-wi; i<=wi; i++)
	{
		Plot(i, 0);
		Plot(0, i);
	}	
		
	glEnd();
	glFlush();
}	
		
int main(int argc, char **argv)
{				
		cout<<"\n\n\t\t ===================================== \n";
		cout<<"\t\t ||  Bresenham Circle Drawing Algo  || \n";
		cout<<"\t\t ===================================== \n\n";
		
			cout<<"\n >>> Enter the Radius of the Circle : \n >> Radius = ";
			cin>>r;
			
			cout<<"\n\n >>> Enter the No of Circle's you want : \n >> No = ";
			cin>>no;  
				
			glutInit(&argc,argv);
			glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
			glutInitWindowSize(800,800);
			glutInitWindowPosition(200,100);
			glutCreateWindow("Circle Algorithm");
			glutDisplayFunc(myDisplay);
			myInit();
			glutCreateMenu(Menu); //Menu Creation
				glutAddMenuEntry(" 1. Simple Circle ", 1);
				glutAddMenuEntry(" 2. Concentric Circle ", 2);
				glutAddMenuEntry(" 3. Olympic Ring ", 3);
				glutAddMenuEntry(" 4. ClockWise Spiral Curve ", 4);
			//	glutAddMenuEntry(" 5. AntiClockWise Spiral Curve ", 5);
				glutAddMenuEntry(" 5. Exit ", 5);
			glutAttachMenu(GLUT_RIGHT_BUTTON);
			glutMainLoop();
	
	return 0;	
}
