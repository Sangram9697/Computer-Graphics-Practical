#include<iostream>
#include<GL/glut.h>
#include<math.h>
#define h 700
#define w 800
#define pi 3.14
using namespace std;
float red[3] = {1.0, 0.0, 0.0}, green[3] = {0.0, 1.0, 0.0}, white[3] = {1.0, 1.0, 1.0}, black[3] = {0.0, 0.0, 0.0}, blue[3] = {0.0, 0.0, 1.0};
float matrix[20][3];	//ip	//matrix[][0]=x		matrix[][1]=y		matrix[][3]=1
float tmatrix[2][3];//tra
float pmatrix[20][3];//op
bool flag=1; // draw flag;
static int k;

void dis(float a[][3], int m)
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
void mul_matrix(float a[][3], float b[][3], float c[][3], int d)
{
	//cout << "value 4 k: "<<k<<"  \n";
	for(int i=0; i<=d; i++)
	{
		for(int j=0; j<=2; j++)
		{
			for(int m=0; m<=2; m++)
			{
				c[i][j] += (a[i][m]*b[m][j]); //(float)
			}
		}
	}
}

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);	//black background
	//glColor3f(0.0, 0.0, 0.0);		//white brush
	glPointSize(4.0);
	glLineWidth(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w/2, w/2, -h/2, h/2);
	
}

void setPixel(int x, int y)
{
	glColor3fv(black);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
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

void translation(float tx, float ty)
{
	for(int i=0; i<=2; i++)
	{
		for(int j=0; j<=2; j++)
		{
			tmatrix[i][j]=0;
		}
	}
	tmatrix[0][0] =1;
	tmatrix[0][1] =0;
	tmatrix[0][2] =0;
	tmatrix[1][0] =0;
	tmatrix[1][1] =1;
	tmatrix[1][2] =0;
	tmatrix[2][0] =tx;
	tmatrix[2][1] =ty;
	tmatrix[2][2] =1;
	cout << "translation matrix: "<<endl;
	dis(tmatrix, 3);
}

void scaling(float sx, float sy)
{
	for(int i=0; i<=2; i++)
	{
		for(int j=0; j<=2; j++)
		{
			tmatrix[i][j]=0;
		}
	}
	tmatrix[0][0] =sx;
	tmatrix[0][1] =0;
	tmatrix[0][2] =0;
	tmatrix[1][0] =0;
	tmatrix[1][1] =sy;
	tmatrix[1][2] =0;
	tmatrix[2][0] =0;
	tmatrix[2][1] =0;
	tmatrix[2][2] =1;
	cout << "scaling matrix: "<<endl;
	dis(tmatrix, 3);	
}

void rotation_anticlockwise(float angle)
{
	angle=angle*(M_PI/180);
	for(int i=0; i<=2; i++)
	{
		for(int j=0; j<=2; j++)
		{
			tmatrix[i][j]=0;
		}
	}
	cout << "\nangle: "<< angle <<"  cos: "<<cos(angle) << "  sin: " << sin(angle)<< endl; 
	tmatrix[0][0] =cos(angle);
	tmatrix[0][1] =sin(angle); 
	tmatrix[0][2] =0;
	tmatrix[1][0] =-(sin(angle));
	tmatrix[1][1] =cos(angle);	
	tmatrix[1][2] =0;
	tmatrix[2][0] =0;
	tmatrix[2][1] =0;
	tmatrix[2][2] =1;
	cout << "rotation anticlockwise matrix: "<<endl;
	dis(tmatrix, 3);
}
 
void rotation_clockwise(float angle)
{
	angle=angle*M_PI/180;
	for(int i=0; i<=2; i++)
	{
		for(int j=0; j<=2; j++)
		{
			tmatrix[i][j]=0;
		}
	}
	cout << "\n cos: "<<cos(angle) << "  sin: " << sin(angle)<< endl;
	tmatrix[0][0] =cos(angle);
	tmatrix[0][1] =-(sin(angle)); 
	tmatrix[0][2] =0;
	tmatrix[1][0] =sin(angle);
	tmatrix[1][1] =cos(angle);
	tmatrix[1][2] =0;
	tmatrix[2][0] =0;
	tmatrix[2][1] =0;
	tmatrix[2][2] =1;
	cout << "rotation clockwise matrix: "<<endl;
	dis(tmatrix, 3);
}

void share(int shx, int shy)
{
	for(int i=0; i<=2; i++)
	{
		for(int j=0; j<=2; j++)
		{
			tmatrix[i][j]=0;
		}
	}
	tmatrix[0][0] =1;
	tmatrix[0][1] =shy;
	tmatrix[0][2] =0;
	tmatrix[1][0] =shx;
	tmatrix[1][1] =1;
	tmatrix[1][2] =0;
	tmatrix[2][0] =0;
	tmatrix[2][1] =0;
	tmatrix[2][2] =1;
	cout << "Share matrix: "<<endl;
	dis(tmatrix, 3);	
}

void reflection(int x, int y)
{
	for(int i=0; i<=2; i++)
	{
		for(int j=0; j<=2; j++)
		{
			tmatrix[i][j]=0;
		}
	}
	tmatrix[0][0] =x;
	tmatrix[0][1] =0;
	tmatrix[0][2] =0;
	tmatrix[1][0] =0;
	tmatrix[1][1] =y;
	tmatrix[1][2] =0;
	tmatrix[2][0] =0;
	tmatrix[2][1] =0;
	tmatrix[2][2] =1;
	cout << "reflection matrix: "<<endl;
	dis(tmatrix, 3);	
}

void reflection_xy()
{
	for(int i=0; i<=2; i++)
	{
		for(int j=0; j<=2; j++)
		{
			tmatrix[i][j]=0;
		}
	}
	tmatrix[0][0] =0;
	tmatrix[0][1] =1;
	tmatrix[0][2] =0;
	tmatrix[1][0] =1;
	tmatrix[1][1] =0;
	tmatrix[1][2] =0;
	tmatrix[2][0] =0;
	tmatrix[2][1] =0;
	tmatrix[2][2] =1;
	cout << "reflextion_xy matrix: "<<endl;
	dis(tmatrix, 3);	
}

void myDisplay(void)
{
	//glClear(GL_COLOR_BUFFER_BIT);
	
	
	
	glEnd();
    	glFlush();
  
}

void myMouse(int button, int state, int x, int y)
{
	if(state==GLUT_DOWN)
	{
		if(button==GLUT_LEFT_BUTTON)
		{
			if(flag)
			{
				flag = 0; // collect points
				k = 0;
			}
			matrix[k][0]=x-w/2;
			matrix[k][1]=h/2-y;
			matrix[k][2]=1;
			setPixel(x-w/2, h/2-y);
			//cout << "x " << (x-w/2) << " y " << (h/2-y) << endl;
			k=k+1;
			//cout << "k " << k << "	flag: " << flag << endl;
		}
		else if(button==GLUT_RIGHT_BUTTON)
		{
			flag = 1;
			
			cout << "input matrix: "<<endl;
          		dis(matrix, k);
          		glColor3fv(black);
			glBegin(GL_LINE_LOOP);
			for(int i=0; i<k; i++)
			{
				glVertex2f(matrix[i][0], matrix[i][1]);
			}
			glEnd();
			glFlush();
			//cout << "draw object\n";	//draw polygon
			//cout << "k " << k << "	flag: " << flag << endl;
			
		}
	}
	
}

void clearDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	//draw axis 
	glColor3fv(blue);
	glBegin(GL_POINTS);
	for(int i=-w/2; i<w/2; i++)
	{
		glVertex2i(i, 0);
		glVertex2i(0, i);
	}
	glEnd();
	glFlush();
}

void myMenu(int s)
{
	
	if (s==1);
	{
		clearDisplay();
		for(int i=0; i<=k; i++)
		{
			for(int j=0; j<3; j++)
			{
				tmatrix[i][j]=0;
				pmatrix[i][j]=0;
			}
		}
	}
}

void translation_menu(int t)
{

	int tx=0, ty=0;
	switch(t)
	{
		case 1:
			cout << "Enter value of tx: ";
			cin >>	tx;
			translation(tx, ty);
			mul_matrix(matrix, tmatrix, pmatrix, k);
			cout << "Result matrix: "<<endl;
                        dis(pmatrix, k);
			plot(pmatrix, k);
			cout << "\nTraslation in X is complete\n";
			break;
		case 2:
			cout << "Enter value of ty: ";
			cin >>ty;
			translation(tx, ty);
			mul_matrix(matrix, tmatrix, pmatrix, k);
			cout << "Result matrix: "<<endl;
                        dis(pmatrix, k);
                        plot(pmatrix, k);
			cout << "\nTraslation in Y is complete\n";
			break;
		case 3:
			cout << "Enter value of tx and ty: ";
			cin >>	tx >> ty;
			translation(tx, ty);
			mul_matrix(matrix, tmatrix, pmatrix, k);
			cout << "Result matrix: "<<endl;
                        dis(pmatrix, k);
			plot(pmatrix, k);
			cout << "\nTraslation in X, Y is complete\n";
			break;	
	}
}

void scaling_menu(int t)
{
	float sx, sy;
	switch(t)
	{
		case 1:
			cout << "Enter value of sx: ";
			cin >>	sx;
			sy=1;
			scaling(sx, sy);
			mul_matrix(matrix, tmatrix, pmatrix, k);
			cout << "Result matrix: "<<endl;
                        dis(pmatrix, k);
			plot(pmatrix, k);
			cout << "\nScaling in X, Y is complete\n";
			break;
		case 2:
			cout << "Enter value of sy: ";
			cin >>sy;
			sx=1;
			scaling(sx, sy);
			mul_matrix(matrix, tmatrix, pmatrix, k);
			cout << "Result matrix: "<<endl;
                        dis(pmatrix, k);
			plot(pmatrix, k);
			cout << "\nScaling in Y is complete\n";
			break;
		case 3:
			cout << "Enter value of sx and sy: ";
			cin >>	sx >> sy;
			scaling(sx, sy);
			mul_matrix(matrix, tmatrix, pmatrix, k);
			cout << "Result matrix: "<<endl;
                        dis(pmatrix, k);
			plot(pmatrix, k);
			cout << "\nScaling in X, Y is complete\n";
			break;
	}	
}

void rotation_menu(int t)
{
	int angle;
	switch(t)
	{
		
		case 1:
			cout << "Enter value of angle: ";
			cin >>angle;
			rotation_clockwise(angle);
			mul_matrix(matrix, tmatrix, pmatrix, k);
			cout << "value k: "<<k<<"  ";
			cout << "seg start  ";
			cout << "Result matrix: "<<endl;
                        dis(pmatrix, k);
			plot(pmatrix, k);
			cout << "\nRotation clockwise is complete\n";
			break;
		case 2:
			cout << "Enter value of angle: ";
			cin >>angle;
			
			rotation_anticlockwise(angle);
			
			mul_matrix(matrix, tmatrix, pmatrix, k);
			cout << "Result matrix: "<<endl;
                        dis(pmatrix, k);
			
			plot(pmatrix, k);
			cout << "\nRotation anti-clockwise is complete\n";
			break;	
	}
}

void share_menu(int t)
{
	float shx=0, shy=0;
	switch(t)
	{
		case 1:
			cout << "Enter value of shx: ";
			cin >>	shx;
			share(shx, shy);
			mul_matrix(matrix, tmatrix, pmatrix, k);
			cout << "Result matrix: "<<endl;
                        dis(pmatrix, k);
			plot(pmatrix, k);
			cout << "\nshare in X is complete\n";
			break;
		case 2:
			cout << "Enter value of shy: ";
			cin >>shy;
			share(shx, shy);
			mul_matrix(matrix, tmatrix, pmatrix, k);
			cout << "Result matrix: "<<endl;
                        dis(pmatrix, k);
			plot(pmatrix, k);
			cout << "\nshare in Y is complete\n";
			break;

	}	
}

void reflection_menu(int t)
{
	switch(t)
	{
		case 1:
			reflection(1, -1);
			mul_matrix(matrix, tmatrix, pmatrix, k);
			cout << "Result matrix: "<<endl;
                        dis(pmatrix, k);
			plot(pmatrix, k);
			cout << "\nRelection w.r.t X-axis is complete\n";
			break;
		case 2:
			reflection(-1, 1);
			mul_matrix(matrix, tmatrix, pmatrix, k);
			cout << "Result matrix: "<<endl;
                        dis(pmatrix, k);
			plot(pmatrix, k);
			cout << "\nRelection w.r.t Y-axis is complete\n";
			break;
		case 3:
			reflection(-1, -1);
			mul_matrix(matrix, tmatrix, pmatrix, k);
			cout << "Result matrix: "<<endl;
                        dis(pmatrix, k);
			plot(pmatrix, k);
			cout << "\nRelection w.r.t Origin is complete\n";
			break;
		case 4:
			reflection_xy();
			mul_matrix(matrix, tmatrix, pmatrix, k);
			cout << "Result matrix: "<<endl;
                        dis(pmatrix, k);
			plot(pmatrix, k);
			cout << "\nRelection w.r.t X=Y line is complete\n";
			break;
		
	}	
}

void composite_menu(int t)
{
	int tx=0, ty=0, angle;
	float sx=1, sy=1;
	float p1matrix[20][3]={0}, p2matrix[20][3]={0}; // this matrix are used because we are getting problem as P = P * T ie we get 3rd colum as full of 2, 3, 4 we decides to use more matrix
	switch(t)
	{
		case 1:
			cout << "Rotation @ arbitrary point\n";
			cout << "coordinate of point (x, y) and angle of ratation: ";
			cin >>	tx >> ty >> angle;
			translation(-tx, -ty);
			mul_matrix(matrix, tmatrix, p1matrix, k);
			cout << "Result matrix 1: "<<endl;
                        dis(p1matrix, k);
			rotation_anticlockwise(angle);
			mul_matrix(p1matrix, tmatrix, p2matrix, k);
			cout << "Result matrix 2: "<<endl;
                        dis(p2matrix, k);
			translation(tx, ty);
			mul_matrix(p2matrix, tmatrix, pmatrix, k);
			cout << "Result matrix 3: "<<endl;
                        dis(pmatrix, k);
			plot(pmatrix, k);
			cout << "\n Roation @ arbitrary point is completed\n";
			break;
		case 2:
			cout << "Scaling @ arbitrary point\n";
			cout << "coordinate of point (x, y) and values of (Sx, Sy) ";
			cin >>	tx >> ty >> sx >> sy;
			translation(-tx, -ty);
			mul_matrix(matrix, tmatrix, p1matrix, k);
			cout << "Result matrix 1: "<<endl;
                        dis(p1matrix, k);
			scaling(sx, sy);
			mul_matrix(p1matrix, tmatrix, p2matrix, k);
			cout << "Result matrix 2: "<<endl;
                        dis(p2matrix, k);
			translation(tx, ty);
			mul_matrix(p2matrix, tmatrix, pmatrix, k);
			cout << "Result matrix 3: "<<endl;
                        dis(pmatrix, k);
			plot(pmatrix, k);
			cout << "\nScaling @ arbitrary point is completed\n";
			break;
	}	
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(w, h);
	glutInitWindowPosition(200, 300);
	glutCreateWindow("Translation");
	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	myInit();
	
	int translation_id = glutCreateMenu(translation_menu);
		glutAddMenuEntry("x-axis", 1);
		glutAddMenuEntry("y-axis", 2);
		glutAddMenuEntry("xy-axis", 3);
	int scaling_id = glutCreateMenu(scaling_menu);
		glutAddMenuEntry("x-axis", 1);
		glutAddMenuEntry("y-axis", 2);
		glutAddMenuEntry("xy-axis", 3);
	int rotation_id = glutCreateMenu(rotation_menu);
		glutAddMenuEntry("Clockwise", 1);
		glutAddMenuEntry("Anticlockwise", 2);
	int share_id = glutCreateMenu(share_menu);
		glutAddMenuEntry("X share", 1);
		glutAddMenuEntry("Y share", 2);
	int reflection_id = glutCreateMenu(reflection_menu);
		glutAddMenuEntry("In x-axis", 1);
		glutAddMenuEntry("In y-axis", 2);
		glutAddMenuEntry("@ origin", 3);
		glutAddMenuEntry("IN x=y LIne", 4);
	int composite_id = glutCreateMenu(composite_menu);
		glutAddMenuEntry("Rotation @ point", 1);
		glutAddMenuEntry("Scaling @ point", 2);
	
	glutCreateMenu(myMenu);
		glutAddMenuEntry("Clear Dispaly", 1);
		glutAddSubMenu("Translation", translation_id);
		glutAddSubMenu("Scaling", scaling_id);
		glutAddSubMenu("Rotation", rotation_id);
		glutAddSubMenu("Share", share_id);
		glutAddSubMenu("Reflection", reflection_id);
		glutAddSubMenu("Composite", composite_id);
		
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
	glutMainLoop();
	return 0;
}


