//          *****************COMPUTER****************************
#include<GL/glut.h>
void myInit(void)
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0f,0.0f,0.0f);
	glLineWidth(4.0);
	//glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,640.0,0.0,480.0);
}
void displayComp(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);  //keyboard
		glVertex2i(250,220);
		glVertex2i(260,260);
		glVertex2i(440,260);
		glVertex2i(450,220);
			
	glEnd();
	glBegin(GL_LINE_LOOP);  //keyboard outline
		glVertex2i(260,230);
		glVertex2i(270,250);
		glVertex2i(430,250);
		glVertex2i(440,230);
		
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2i(290,290);	//monitor base
		glVertex2i(290,300);
		glVertex2i(410,300);
		glVertex2i(410,290);
		
	glEnd();
	
	glBegin(GL_LINE_LOOP);
		glVertex2i(260,320);	//monitor outline
		glVertex2i(260,400);
		glVertex2i(440,400);
		glVertex2i(440,320);
		
	glEnd();	
		
	glBegin(GL_LINE_LOOP);
		glVertex2i(270,330);	//monitor screen
		glVertex2i(270,390);
		glVertex2i(430,390);
		glVertex2i(430,330);
		
	glEnd();	
	glBegin(GL_LINE_STRIP);
		glVertex2i(330,300);	//strips
		glVertex2i(330,320);
		glVertex2i(380,320);
		glVertex2i(380,300);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
		glVertex2i(500,270);	//cpu
		glVertex2i(500,400);
		glVertex2i(570,400);
		glVertex2i(570,270);
		
	glEnd();	
	glBegin(GL_LINE_LOOP);
		glVertex2i(510,300);	//cpu
		glVertex2i(510,320);
		glVertex2i(560,320);
		glVertex2i(560,300);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
		glVertex2i(500,290);	//strips
		glVertex2i(440,320);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
		glVertex2i(500,290);	//strips
		glVertex2i(440,260);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
		glVertex2i(470,210);	//mouse
		glVertex2i(460,240);
		glVertex2i(480,240);
		glVertex2i(490,210);
	glEnd();
	
	glBegin(GL_LINES);
		glVertex2i(470,235);	//strips
		glVertex2i(475,220);
	glEnd();
	
	glBegin(GL_LINE_STRIP);
		glVertex2i(475,240);	//strips
		glVertex2i(500,290);
		
	glEnd();
	glFlush();	
}
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100,150);
	glutCreateWindow("My House");
	glutDisplayFunc(displayComp);
	myInit();
	glutMainLoop();
	return 0;
}


