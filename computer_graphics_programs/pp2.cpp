#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;
# define h 500
# define w 500


float mati[3][3] , mato[3][3];
int k=0;
int ch,tx,ty,sx,sy,shx,shy;
float matrix[3][3];


void myInit (void) {
  glClearColor(1.0,1.0,1.0,0.0);
  glColor3f(0.0f,0.0f,0.0f);
  glPointSize(3.0);
  glLineWidth(5.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-w/2 , w/2 , -h/2 , h/2);
}
void setpixel(int x , int y){
     glBegin(GL_POINTS);
      glColor3f(0.0,1.0,0.0);
     glVertex2i(x,y);
     glEnd();
} 
void mydisplay(void){
     //glClear(GL_COLOR_BUFFER_BIT);
     for(int i=-w ; i<=w ; i++){
         setpixel(i , 0);
         setpixel(0,i);
     }
     glEnd();
     //glFlush();
}
void  matrix_multiplication(float a[][3] , float b[][3] ){
    
  for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ;j++){
             mato[i][j]=0;
        }
    }
    /*for(int i=0 ; i<c ; i++){
       for(int j=0 ; j<3 ; j++){
            for(int m=0 ; m<3 ; m++){
                mato[i][j]=mato[i][j]+a[i][m]*b[m][j];
            }
       }
    }*/
    for(int i=0;i<3;i++)
			{
				mato[i][0]=(float)(a[0][0]*b[i][0]+a[0][1]*b[i][1]+a[0][2]*b[i][2]);
				mato[i][1]=(float)(a[1][0]*b[i][0]+a[1][1]*b[i][1]+a[1][2]*b[i][2]);
				mato[i][2]=(float)(a[2][0]*b[i][0]+a[2][1]*b[i][1]+a[2][2]*b[i][2]);
			}
}
void translate(int tx, int ty){
   for(int i=0 ; i<3;i++){
      for(int j=0 ; j<3 ; j++){
         matrix[i][j]=0;
      }
   } 
   
   matrix[0][0]=1;
   matrix[0][1]=0;
   matrix[0][2]=matrix[0][2]+tx;
   matrix[1][0]=0;
   matrix[1][1]=1;
   matrix[1][2]=matrix[1][2]+ty;
   matrix[2][0]=0;
   matrix[2][1]=0;
   matrix[2][2]=1;
}

void scaling(int sx , int sy){
   for(int i=0 ; i<3;i++){
      for(int j=0 ; j<3 ; j++){
         matrix[i][j]=0;
      }
   }
   matrix[0][0]=sx;
   matrix[0][1]=0;
   matrix[0][2]=0;
   matrix[1][0]=0;
   matrix[1][1]=sy;
   matrix[1][2]=0;
   matrix[2][0]=0;
   matrix[2][1]=0;
   matrix[2][2]=1;
   
}

void rotation_anticlockwise(float angle){
   for(int i=0 ; i<3;i++){
      for(int j=0 ; j<3 ; j++){
         matrix[i][j]=0;
      }
   }
   matrix[0][0]=cos(angle);
   matrix[0][1]=-(sin(angle));
   matrix[0][2]=0;
   matrix[1][0]=sin(angle);
   matrix[1][1]=cos(angle);
   matrix[1][2]=0;
   matrix[2][0]=0;
   matrix[2][1]=0;
   matrix[2][2]=1;
   
}
void rotation_clockwise(float angle){
   for(int i=0 ; i<3;i++){
      for(int j=0 ; j<3 ; j++){
         matrix[i][j]=0;
      }
   }
   matrix[0][0]=cos(angle);
   matrix[0][1]=sin(angle);
   matrix[0][2]=0;
   matrix[1][0]=-(sin(angle));
   matrix[1][1]=cos(angle);
   matrix[1][2]=0;
   matrix[2][0]=0;
   matrix[2][1]=0;
   matrix[2][2]=1;
}

void reflection_X_axis(){
   for(int i=0 ; i<3;i++){
      for(int j=0 ; j<3 ; j++){
         matrix[i][j]=0;
      }
   }
   matrix[0][0]=1;
   matrix[0][1]=0;
   matrix[0][2]=0;
   matrix[1][0]=0;
   matrix[1][1]=-1;
   matrix[1][2]=0;
   matrix[2][0]=0;
   matrix[2][1]=0;
   matrix[2][2]=1;
}
void reflection_Y_axis(){
   for(int i=0 ; i<3;i++){
      for(int j=0 ; j<3 ; j++){
         matrix[i][j]=0;
      }
   }
   matrix[0][0]=-1;
   matrix[0][1]=0;
   matrix[0][2]=0;
   matrix[1][0]=0;
   matrix[1][1]=1;
   matrix[1][2]=0;
   matrix[2][0]=0;
   matrix[2][1]=0;
   matrix[2][2]=1;
}

void reflection_X_equal_Y_axis(){
   for(int i=0 ; i<3;i++){
      for(int j=0 ; j<3 ; j++){
         matrix[i][j]=0;
      }
   }
   matrix[0][0]=0;
   matrix[0][1]=1;
   matrix[0][2]=0;
   matrix[1][0]=1;
   matrix[1][1]=0;
   matrix[1][2]=0;
   matrix[2][0]=0;
   matrix[2][1]=0;
   matrix[2][2]=1;
}

void reflection_about_origin(){
   for(int i=0 ; i<3;i++){
      for(int j=0 ; j<3 ; j++){
         matrix[i][j]=0;
      }
   }
   matrix[0][0]=-1;
   matrix[0][1]=0;
   matrix[0][2]=0;
   matrix[1][0]=0;
   matrix[1][1]=-1;
   matrix[1][2]=0;
   matrix[2][0]=0;
   matrix[2][1]=0;
   matrix[2][2]=1;
}

void reflection_X_equal_minus_Y_axis(){
  for(int i=0 ; i<3;i++){
      for(int j=0 ; j<3 ; j++){
         matrix[i][j]=0;
      }
   }
   matrix[0][0]=0;
   matrix[0][1]=-1;
   matrix[0][2]=0;
   matrix[1][0]=-1;
   matrix[1][1]=0;
   matrix[1][2]=0;
   matrix[2][0]=0;
   matrix[2][1]=0;
   matrix[2][2]=1;
}

void shearing_X_axis(){
   cout<<"Enter shx ";
   cin>>shx;
   for(int i=0 ; i<3;i++){
      for(int j=0 ; j<3 ; j++){
         matrix[i][j]=0;
      }
   }
   matrix[0][0]=1;
   matrix[0][1]=shx;
   matrix[0][2]=0;
   matrix[1][0]=0;
   matrix[1][1]=1;
   matrix[1][2]=0;
   matrix[2][0]=0;
   matrix[2][1]=0;
   matrix[2][2]=1;
}

void shearing_Y_axis(){
   cout<<"Enter shy ";
   cin>>shy;
   for(int i=0 ; i<3;i++){
      for(int j=0 ; j<3 ; j++){
         matrix[i][j]=0;
      }
   }
   matrix[0][0]=1;
   matrix[0][1]=0;
   matrix[0][2]=0;
   matrix[1][0]=shy;
   matrix[1][1]=1;
   matrix[1][2]=0;
   matrix[2][0]=0;
   matrix[2][1]=0;
   matrix[2][2]=1;
}

void plot(float draw[][3]){
    for(int i=0 ; i<3 ; i++){
                     
                     glBegin(GL_LINE_LOOP);
                      glColor3f(0.0,0.0,1.0);
                     glVertex2f(draw[i][0],draw[i][1]);
             }
              glEnd();
              glFlush();
    
}
void myMouse(int button , int state , int x, int y){
    if(state==GLUT_DOWN){
       if(button==GLUT_LEFT_BUTTON){
          mati[k][0]=(float)(x-250);
          mati[k][1]=(float)(250-y);
          glColor3f(1.0,0.0,0.0);
          glBegin(GL_POINTS);
          glVertex2f(mati[k][0] , mati[k][1]);
          glEnd();
          k++;
          glFlush();
       }
       if(button==GLUT_RIGHT_BUTTON){
          glBegin(GL_LINE_LOOP);
          for(int i=0 ; i<k; i++)
             glVertex2f(mati[i][0],mati[i][1]);
             glEnd();
             glFlush();
       }
    }
}
void menu(int ch) {
glBegin(GL_POINTS);
mydisplay();
}

void translation_menu(int i){
	int tx = 0,ty = 0;
	switch(i) {
	
		case 1:
			cout<<"Enter tx ";
			cin>>tx;
			translate(tx,ty);
                        matrix_multiplication(matrix,mati);
                        plot(mato);
			break;
			
		case 2:
			cout<<"Enter ty ";
			cin>>ty;
			translate(tx,ty);
                        matrix_multiplication(matrix,mati);
                        plot(mato);
			break;
		
		case 3:
			cout<<"Enter tx ";
			cin>>tx;
			cout<<"Enter ty ";
			cin>>ty;
			translate(tx,ty);
                        matrix_multiplication(matrix,mati);
                        plot(mato);
			break;
	}
}

void scaling_menu(int i){
	int sx = 1,sy = 1;
	switch(i) {
	
		case 1:
			cout<<"Enter sx ";
			cin>>sx;
			scaling(sx,sy);
			matrix_multiplication(matrix,mati);
                        plot(mato);
			break;
			
		case 2:
			cout<<"Enter sy ";
			cin>>sy;
			scaling(sx,sy);
			matrix_multiplication(matrix,mati);
                        plot(mato);
			break;
		
		case 3:
			cout<<"Enter sx ";
			cin>>sx;
			cout<<"Enter sy ";
			cin>>sy;
			scaling(sx,sy);
			matrix_multiplication(matrix,mati);
                        plot(mato);
			break;
	}
}

void rotaion_menu(int i) {
	float angle;
	cout<<"Enter Rotaion angle ";
	cin>>angle;
	angle=(angle*(3.142/180));
	
	switch(i) {
		case 1:rotation_clockwise(angle);
		       matrix_multiplication(matrix,mati);
		       plot(mato);
		       break;
		case 2:rotation_anticlockwise(angle);
		       matrix_multiplication(matrix,mati);
		       plot(mato);
			break;
	}
} 

void Reflection_menu(int i){
   switch(i){
      case 1:reflection_X_axis();
             matrix_multiplication(matrix,mati);
	     plot(mato);
             break;
      case 2:reflection_Y_axis();
             matrix_multiplication(matrix,mati);
	     plot(mato);
	     break;
      case 3:reflection_X_equal_Y_axis();
             matrix_multiplication(matrix,mati);
	     plot(mato);
	     break;
      case 4:reflection_about_origin();
             matrix_multiplication(matrix,mati);
	     plot(mato);
             break;
      case 5:reflection_X_equal_minus_Y_axis();
             matrix_multiplication(matrix,mati);
	     plot(mato);
             break;
   }
}

void shearing_menu(int i){
    switch(i){
           case 1:
                  shearing_X_axis();
                  matrix_multiplication(matrix,mati);
	     plot(mato);
             break;
           case 2:
                  shearing_X_axis();
                  matrix_multiplication(matrix,mati);
	     plot(mato);
             break;
    }
}
int main(int argc, char ** argv) {

  glutInit( & argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 150);
  glutCreateWindow("Transformation");
  myInit (); 
  
  glutDisplayFunc(mydisplay);
  glutMouseFunc(myMouse);
  
  int translation_id = glutCreateMenu(translation_menu);
			glutAddMenuEntry("along x-axis ",1);
			glutAddMenuEntry("along y-axis ",2);
			glutAddMenuEntry("along xy-axis ",3);
			
  int scaling_id = glutCreateMenu(scaling_menu);
			glutAddMenuEntry("along x-axis ",1);
			glutAddMenuEntry("along y-axis ",2);
			glutAddMenuEntry("along xy-axis ",3);
			
  int rotation_id = glutCreateMenu(rotaion_menu);
			glutAddMenuEntry("clockwise",1);
			glutAddMenuEntry("Anticlockwise",2);
			
  int reflection_id=glutCreateMenu(Reflection_menu);
			glutAddMenuEntry("about x-axis ",1);
			glutAddMenuEntry("about y-axis ",2);
			glutAddMenuEntry("about xy-axis ",3);
			glutAddMenuEntry("about origin ",4);
			glutAddMenuEntry("about x=-y axis ",5);
			
  int shearing_id=glutCreateMenu(shearing_menu);
			glutAddMenuEntry("about x-axis ",1);
			glutAddMenuEntry("about y-axis ",2);
			
  glutCreateMenu(menu);
		glutAddSubMenu("Translation",translation_id);
		glutAddSubMenu("Scaling",scaling_id);
		glutAddSubMenu("Rotation",rotation_id);
		glutAddSubMenu("Reflection",reflection_id);
		glutAddSubMenu("Shearing",shearing_id);
		
  
  
  glutAttachMenu(GLUT_MIDDLE_BUTTON);
  glutMainLoop();
  return 0;
}
