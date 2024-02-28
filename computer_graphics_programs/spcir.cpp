#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

// Center of the cicle = (320, 240)
int xc = 150, yc = 130, r=5;

int xc1 = 150, yc1 = 180, r1=5;


void Init()
{
  /* Set clear color to white */
  glClearColor(1.0,1.0,1.0,0);
  /* Set fill color to black */
  glColor3f(0.0,0.0,0.0);
  /* glViewport(0 , 0 , 640 , 480); */
  /* glMatrixMode(GL_PROJECTION); */
  /* glLoadIdentity(); */
  gluOrtho2D(0 , 640 , 0 , 480);
  glPointSize(7.0);
  //glCircleWidth(0.5);
}

// Plot eight points using circle's symmetrical property


// Function to draw a circle using bresenham's
// circle drawing algorithm
void bresenham_circle1(int xc, int yc, int r)
{
  int x=0,y=r;
  float pk=(5.0/4.0)-r;

  //plot_point(x,y);
  int k;
  while(x < y)
  {
    x = x + 1;
    if(pk < 0)
      pk = pk + 2*x+1;
    else
    {
      y = y - 1;
      pk = pk + 2*(x - y) + 1;
    }
   
  glBegin(GL_POINTS);
  /*
  glVertex2i(xc+x, yc+y);   1
  glVertex2i(xc+x, yc-y);   4
  glVertex2i(xc+y, yc+x);   2
  glVertex2i(xc+y, yc-x);   3
  glVertex2i(xc-x, yc-y);   5
  glVertex2i(xc-y, yc-x);   6
  glVertex2i(xc-x, yc+y);   8
  glVertex2i(xc-y, yc+x);   7   */ 
  
  
  /*glVertex2i(xc+y, yc-x);  
  glVertex2i(xc+x, yc-y);  
  glVertex2i(xc-x, yc-y);  
  glVertex2i(xc-y, yc-x); 
  */
  


  glVertex2i(xc+y+35, yc-x);  
  glVertex2i(xc+x+35, yc-y);  
  glVertex2i(xc-x+35, yc-y);  
  glVertex2i(xc-y+35, yc-x); 
  
  
  /*glVertex2i(xc-y+5, yc+x);   
  glVertex2i(xc-x+5, yc+y);  
  glVertex2i(xc+x+5, yc+y);  
  glVertex2i(xc+y+5, yc+x);  

  */
  glEnd();
  }
  
  glFlush();
}


void bresenham_circle2(int xc, int yc, int r)
{
  int x=0,y=r;
  float pk=(5.0/4.0)-r;

  //plot_point(x,y);
  int k;
  while(x < y)
  {
    x = x + 1;
    if(pk < 0)
      pk = pk + 2*x+1;
    else
    {
      y = y - 1;
      pk = pk + 2*(x - y) + 1;
    }
   
  glBegin(GL_POINTS);
  
  /*glVertex2i(xc-y+35, yc+x);   
  glVertex2i(xc-x+35, yc+y);  
  glVertex2i(xc+x+35, yc+y);  
  glVertex2i(xc+y+35, yc+x); */
  
  
  glVertex2i(xc-y, yc+x);   
  glVertex2i(xc-x, yc+y);  
  glVertex2i(xc+x, yc+y);  
  glVertex2i(xc+y, yc+x);  

  
  glEnd();
  }
  
  glFlush();
}






void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,1.0);
	bresenham_circle1(xc, yc, r);
	bresenham_circle2(xc, yc, r+35);
	bresenham_circle1(xc, yc, r+70);
	bresenham_circle2(xc, yc, r+105);
	bresenham_circle1(xc, yc, r+140);
	bresenham_circle2(xc, yc, r+175);
	
	//glColor3f(0.0,0.0,0.0);
	//bresenham_circle(xc+2.5*r, yc, r);
	//glColor3f(1.0,0.0,0.0);
	//bresenham_circle(xc+5.0*r, yc, r);
	//glColor3f(1.0,1.0,0.0);
	//bresenham_circle(xc+r+10, yc-1.0*r, r);
	//glColor3f(0.0,1.0,0.0);
	//bresenham_circle(xc+r+70+1.5*r, yc-1.0*r, r);
	glFlush();
}



int main(int argc, char **argv)
{
  /* Initialise GLUT library */
  glutInit(&argc,argv);
  /* Set the initial display mode */
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  /* Set the initial window position and size */
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  /* Create the window with title "DDA_Line" */
  glutCreateWindow("Spiral circle");
  /* Initialize drawing colors */
  Init();
  /* Call the displaying function */
  glutDisplayFunc(display);
  /* Keep displaying untill the program is closed */
  glutMainLoop();
}
