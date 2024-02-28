#include <iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;
int option ;
struct Point
{
	int x;
	int y;
};

struct Color   
{
	float r;
	float g;
	float b;
};


void myinit()
{
	glClearColor(0.0, 0.0, 0.0, 1.0); 
	glColor3f(1.0, 1.0, 1.0);    
	glPointSize(1.0);
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

Color getPixelColor(int x, int y) 
{
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}

void setPixelColor(int x, int y, Color color)   
{
	glColor3f(color.r, color.g, color.b);  
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void bFill(int x, int y, Color fColor, Color bColor)
{
	Color color;
	color = getPixelColor(x, y);
	if ((color.r != fColor.r || color.g != fColor.g || color.b != fColor.b) && (color.r != bColor.r || color.g != bColor.g || color.b != bColor.b)) {
		setPixelColor(x, y, fColor);
		bFill(x + 1, y, fColor, bColor);
		bFill(x, y + 1, fColor, bColor);
		bFill(x - 1, y, fColor, bColor);
		bFill(x, y - 1, fColor, bColor);

	}
	return;
	glFlush();
}




void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glVertex2f(100,100);
	glVertex2f(400,100);
	glVertex2f(400,100);
	glVertex2f(400,400);
	glVertex2f(100,400);
	glVertex2f(400,400);
	glVertex2f(100,100);
	glVertex2f(100,400);
	
	/*glVertex2f(10,100);
	glVertex2f(100,100);
	glVertex2f(100,100);
	glVertex2f(100,10);
	glVertex2f(100,10);
	glVertex2f(10,10);
	glVertex2f(10,10);
	glVertex2f(10,100);
	glEnd();
	glFlush();*/
}



void myMouse(int button, int state, int x, int y)
{
	
	y = 480-y;
	if(button==GLUT_LEFT_BUTTON)
	{
	        if(state==GLUT_DOWN)
	        {
			Color bColor = { 1.0f,1.0f,1.0f };
			Color fColor = { 1.0f,0.0f,0.0f };
			bFill(x, y, fColor, bColor);
        	}
    	}
}



int main (int argc, char** argv)
{
	glutInit (&argc, argv); 
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowSize (640, 480);
	glutInitWindowPosition(0, 0); 
	glutCreateWindow ("boundary fill");
	glutDisplayFunc(display); 
	glutMouseFunc(myMouse);
	myinit();
	glutMainLoop();
	return 0;
}
