#include <GL/glut.h>
#include <math.h>

// Constants
const float g = 9.8;       // Acceleration due to gravity
const float L = 0.5;       // Length of the pendulum
const float dt = 0.01;     // Time step

// Variables
//float theta = 3.14159 / 4; // Initial angle of the pendulum
float theta = 3.5 / 4;
float omega = 0.0;         // Angular velocity of the pendulum

void myInit(void)
{
	glLineWidth(10.0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
// Draw the pendulum rod
glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(L * sin(theta), -L * cos(theta));
    glEnd();
    
    //draw horizontal line
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.5, 0.0);
    glVertex2f(0.5,0.0);
    glEnd();

    // Draw the pendulum bob
    glTranslatef(L * sin(theta), -L * cos(theta), 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidSphere(0.1, 20, 20);

    glutSwapBuffers();
}

void update(int value)
{
    omega -= (g / L) * sin(theta) * dt;
    theta += omega * dt;

    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}

int main(int argc, char** argv)
{
	
    glutInit(&argc, argv);
    myInit();
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Pendulum Simulation");

    glClearColor(0.0, 0.0, 0.0, 1.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    glutDisplayFunc(display);
    glutTimerFunc(10, update, 0);

    glutMainLoop();

    return 0;
}
