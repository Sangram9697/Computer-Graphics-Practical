#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;
#define hi 500
#define w 500
int r,d,h,k,x,y,n;

void myInit (void) {
	glClearColor(1.0,1.0,1.0,1.0);
  	glColor3f(0.0,0.0,0.0);
  	glPointSize(5.0);
  	glMatrixMode(GL_PROJECTION);
  	glLoadIdentity();
  	gluOrtho2D(-w/2,w/2,-hi/2,hi/2);
}

void setpixel(int x , int y){
     	glBegin(GL_POINTS);
     	glVertex2i(x,y);
     	glEnd();
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	
	for(int i=-w; i<=w; i++)
	{
		setpixel(i, 0);
		setpixel(0, i);
	}	

	glEnd();
	glFlush();
}	


void Circle(int r){
      d=3-2*r;
      x=0;
      y=r;
      setpixel(x,y);
      while(x<=y){
        if(d<=0){
            d=d+4*x+6;
            x=x+1;
        }
        else{
            d=d+4*(x-y)+10;
            x=x+1;
            y=y-1;
        }
      
      setpixel(x+h,y+k); //2
      setpixel(y+h,x+k); //1
      setpixel(-y+h,x+k); //4
      setpixel(-x+h,y+k); //3
      setpixel(-x+h,-y+k); //6
      
      setpixel(-y+h,-x+k); //5
      
      setpixel(y+h,-x+k);  //8
     
      setpixel(x+h,-y+k);  //7
    
      }
}

void olympic_ring(int r,int h , int k){
      d=3-2*r;
      x=0;
      y=r;
      setpixel(x,y);
      while(x<=y){
        if(d<=0){
            d=d+4*x+6;
            x=x+1;
        }
        else{
            d=d+4*(x-y)+10;
            x=x+1;
            y=y-1;
        }
      
      setpixel(x+h,y+k);
      setpixel(-x+h,-y+k);
      setpixel(y+h,x+k);
      setpixel(-y+h,-x+k);
      setpixel(-y+h,x+k);
      setpixel(y+h,-x+k);
      setpixel(-x+h,y+k);
      setpixel(x+h,-y+k);
    
      }
}
void bresenham_circle1(int r,int h , int k)
{
      d=3-2*r;
      x=0;
      y=r;
      setpixel(x,y);
      while(x<=y){
        if(d<=0){
            d=d+4*x+6;
            x=x+1;
        }
        else{
            d=d+4*(x-y)+10;
            x=x+1;
            y=y-1;
        }
   
  
        setpixel(x+h+r,y+k); //2
      	setpixel(y+h+r,x+k); //1
      	setpixel(-y+h+r,x+k); //4
      	setpixel(-x+h+r,y+k); //3

}
  glFlush();
}
void bresenham_circle2(int r,int h , int k)
{
	d=3-2*r;
      x=0;
      y=r;
      setpixel(x,y);
      while(x<=y){
        if(d<=0){
            d=d+4*x+6;
            x=x+1;
        }
        else{
            d=d+4*(x-y)+10;
            x=x+1;
            y=y-1;
        }
      setpixel(-x+h,-y+k); //6
      
      setpixel(-y+h,-x+k); //5
      
      setpixel(y+h,-x+k);  //8
     
      setpixel(x+h,-y+k);  //7  
  
  }
  
  glFlush();
}



void Menu(int ch){
  switch(ch){
     case 1:Circle(r);
            break;
     case 2://upper ring
            glColor3f(0.0,0.0,1.0);
            olympic_ring(r,2*r,6*r);
            glColor3f(0.0, 0.0, 0.0);
            olympic_ring(r,3.6*r,6*r);
            glColor3f(1.0,0.0,0.0);
            olympic_ring(r,5.2*r,6*r);
            
            //lower rings
            glColor3f(1.0,1.0,0.0);
            olympic_ring(r,2.8*r,4.8*r);
            glColor3f(0.0,1.0,0.0);
            olympic_ring(r,4.4*r,4.8*r);
            glColor3f(0.0,0.0,0.0); 
            break;
     case 3:for(int i=1 ; i<=n ; i++){
                Circle(r);
                r=r+20;
     }
            break;
     case 4:bresenham_circle1(r, h-r*2, k);
	bresenham_circle2(r+r*1, h, k );
	bresenham_circle1(r+r*2, h-r*4, k );
	bresenham_circle2(r+r*3, h, k );
	bresenham_circle1(r+r*4, h-r*6, k );
	bresenham_circle2(r+r*5, h, k );
	glFlush();	
            break;
    
     case 5:exit(0);
  }
}
int main(int argc,char ** argv){
    cout<<"Enter the radius of circle:"<<endl;
    cin>>r;
    cout<<"Enter the No. of Concentric circles you want to draw:"<<endl;
    cin>>n;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1080,720);
    glutInitWindowPosition(50,100);
    glutCreateWindow("Bresenham circle drawing algorithm");
    myInit();
    glutDisplayFunc(myDisplay);
    glutCreateMenu(Menu);
    glutAddMenuEntry("1.Circle" , 1);
    glutAddMenuEntry("2.olympic ring" , 2);
    glutAddMenuEntry("3.Concentric Circles" , 3);
    glutAddMenuEntry("4.Spiral rings" , 4);
    glutAddMenuEntry("5.Exit" , 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}
