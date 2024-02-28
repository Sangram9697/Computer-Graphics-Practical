#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;
int x1;
int y11;
int x2,y2,s1,s2,dx,dy,x,y,interchange,e;
#define h 500
#define w 500

void myInit (void) {
  glClearColor(1.0,1.0,1.0,1.0);
  glColor3f(0.0,0.0,0.0);
  glPointSize(5.0);
  glLineWidth(5.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-w/2, w/2, -h/2 ,h/2);
}
int Sign(int x){
if(x>0)
return 1;
else if(x<0)
return -1;
else
return 0;
}

void setpixel(float x , float y){
     glBegin(GL_POINTS);
     glVertex2i(x,y);
     glEnd();
}
void mydisplay(void){
   glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_POINTS);
   for(int i=-w ; i<=w ; i++){
    setpixel(i,0);
    setpixel(0,i);
}
   glEnd();
   glFlush();
 }
void Bresenham_simple_line(int x1,int y11,int x2,int y2){
   x=x1;
   y=y11;
   dx=abs(x2-x1);
   dy=abs(y2-y11);
   s1=Sign(x2-x1);
   s2=Sign(y2-y11);
   if(dy>dx){
         int temp=dx;
         dx=dy;
         dy=temp;
         interchange=1;
   }
   else{
         interchange=0;
   }
   e=2*dy-dx;
   for(int i=1 ; i<=dx ; i++){
    setpixel(x,y);
    while(e>=0){
                           if(interchange==1){
                            x=x+s1;
      }
      else{
      y=y+s2;
      }
       e=e-2*dx;
  }
if(interchange==1){
y=y+s2;
}
else{
x=x+s1;
}
e=e+2*dy;
   }
}
void Bresenham_Dotted_line(int x1,int y11,int x2,int y2){
   x=x1;
   y=y11;
   dx=abs(x2-x1);
   dy=abs(y2-y11);
   s1=Sign(x2-x1);
   s2=Sign(y2-y11);
   if(dy>dx){
         int temp=dx;
         dx=dy;
         dy=temp;
         interchange=1;
   }
   else{
         interchange=0;
   }
   e=2*dy-dx;
   for(int i=1 ; i<=dx ; i++){
    if(i%20==0){
    setpixel(x,y);
    }
    while(e>=0){
                           if(interchange==1){
                            x=x+s1;
      }
      else{
      y=y+s2;
      }
       e=e-2*dx;
  }
if(interchange==1){
y=y+s2;
}
else{
x=x+s1;
}
e=e+2*dy;
   }
}
void Bresenham_Dashed_line(int x1,int y11,int x2,int y2){
   x=x1;
   y=y11;
   dx=abs(x2-x1);
   dy=abs(y2-y11);
   s1=Sign(x2-x1);
   s2=Sign(y2-y11);
   if(dy>dx){
         int temp=dx;
         dx=dy;
         dy=temp;
         interchange=1;
   }
   else{
         interchange=0;
   }
   e=2*dy-dx;
   for(int i=1 ; i<=dx ; i++){
    if(i%4==0 && i%20!=0){
    setpixel(x,y);
    }
    while(e>=0){
                           if(interchange==1){
                            x=x+s1;
      }
      else{
      y=y+s2;
      }
       e=e-2*dx;
  }
if(interchange==1){
y=y+s2;
}
else{
x=x+s1;
}
e=e+2*dy;
   }
}
void Bresenham_centre_dotted_line(int x1,int y11,int x2,int y2){
   x=x1;
   y=y11;
   dx=abs(x2-x1);
   dy=abs(y2-y11);
   s1=Sign(x2-x1);
   s2=Sign(y2-y11);
   if(dy>dx){
         int temp=dx;
         dx=dy;
         dy=temp;
         interchange=1;
   }
   else{
         interchange=0;
   }
   e=2*dy-dx;
   for(int i=1 ; i<=dx ; i++){
      if(i%20<=10 || i%20==15){
           setpixel(x,y);
      }
    while(e>=0){
                           if(interchange==1){
                            x=x+s1;
      }
      else{
      y=y+s2;
      }
       e=e-2*dx;
  }
if(interchange==1){
y=y+s2;
}
else{
x=x+s1;
}
e=e+2*dy;
   }
}
void Shape(void){
     Bresenham_simple_line(40,30,100,30);
     Bresenham_simple_line(100,30,100,100);
     Bresenham_simple_line(100,100,40,100);
     Bresenham_simple_line(40,100,40,30);
     
     
     Bresenham_simple_line(70,30,100,65);
     Bresenham_simple_line(100,65,70,100);
     Bresenham_simple_line(70,100,40,65);
     Bresenham_simple_line(40,65,70,30);
     
     
     Bresenham_simple_line(55,47.5,85,47.5);
     Bresenham_simple_line(85,47.5,85,82.5);
     Bresenham_simple_line(85,82.5,55,82.5);
     Bresenham_simple_line(55,82.5,55,47.5);
    
     
     
}
void Menu(int ch){
  switch(ch){
     case 1:Bresenham_simple_line(x1,y11,x2,y2);
            break;
     case 2:Bresenham_Dotted_line(x1,y11,x2,y2);
            break;
     case 3:Bresenham_Dashed_line(x1,y11,x2,y2);
            break;
     case 4:Bresenham_centre_dotted_line(x1,y11,x2,y2);
            break;
     case 5:Shape();
            break;
     case 6:exit(0);
  }
}

int main(int argc,char ** argv){
     cout<<endl<<"|| Prgramm Of Bresenham Algorithm ||"<<endl<<endl;

  cout<<"Enter Point x1 : ";
  cin>>x1;
  cout<<"Enter Point y1 : ";
  cin>>y11;
  cout<<"Enter Point x2 : ";
  cin>>x2;
  cout<<"Enter Point y2 : ";
  cin>>y2;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1080,720);
    glutInitWindowPosition(50,100);
    glutCreateWindow("Bresenham line drawing algorithm");
    myInit();
    glutDisplayFunc(mydisplay);
    glutCreateMenu(Menu);
    glutAddMenuEntry("1.Simple Line" , 1);
    glutAddMenuEntry("2.Dotted Line" , 2);
    glutAddMenuEntry("3.Dashed Line" , 3);
    glutAddMenuEntry("4.Centre_Dotted Line" , 4);
    glutAddMenuEntry("5.Shape",5);
    glutAddMenuEntry("6.Exit" , 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glutMainLoop();
    return 0;
    }
