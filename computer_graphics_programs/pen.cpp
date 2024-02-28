#include<GL/glut.h>
#include<math.h>

const float g=9.8;
const float L=0.5;
const float dt=0.01;

float theta=3.14159/4;
float omega=0.0;


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(0.0,0.0);
	glVertex2f(L*sin(theta), -L*cos(theta));
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2f(-0.5,0.0);
	glVertex2f(0.5,0.0);
	glEnd();
	
	
	glTranslatef(L*sin(theta), -L*cos(theta), 0.0);
	glColor3f(1.0,0.0,0.0);
	glutSolidSphere(0.05,20,20);
	
	glutSwapBuffers();
}

void update(int value)
{
	omega-=(g/L)*sin(theta)*dt;
	theta+=omega*dt;
	glutPostRedisplay();
	glutTimerFunc(10,update,0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800,600);
	glutCreateWindow("Pendulum");
	glClearColor(0.0,0.0,0.0,1.0);
	gluOrtho2D(-1.0,1.0,-1.0,1.0);
	glutDisplayFunc(display);
	glutTimerFunc(10,update,0);
	glutMainLoop();
	return 0;
}


