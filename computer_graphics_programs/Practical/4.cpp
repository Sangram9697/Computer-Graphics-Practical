#include <iostream> 
#include <GL/glut.h> 
#include <math.h>

using namespace std;


#define h 700
#define w 700


/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int k=0,ch;
float matrix[3][3],mati[10][3],mato[10][3],tx,ty,a,b,sx,sy;


void myInit(void){
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(1.0,1.0,1.0,0.0);//white
glColor3f(0.0f,0.0f,0.0f);//black glPointSize(3.0);
glLineWidth(4.0);
glMatrixMode(GL_PROJECTION); glLoadIdentity();
gluOrtho2D(-w/2,w/2,-h/2,h/2);


}


void setpixel(int x, int y){
glColor3f(0.0,1.0,0.0); glBegin(GL_POINTS); glVertex2i(x,y);
glEnd(); glFlush();
}


void mydisplay(void){
//glClear(GL_COLOR_BUFFER_BIT); glColor3f(0.0,1.0,0.0);
glBegin(GL_POINTS); for(int i=-w;i<=w;i++)
{

setpixel(i,0); setpixel(0,i);
}

//		glEnd(); glFlush();

}



void multiplication(float a[][3],float b[][3]){


for(int i=0;i<3;i++){
for(int j=0;j<3;j++){ 
mato[i][j]=0;
}


}





for(int i=0;i<k;i++)
{

mato[i][0]=(float)(a[0][0]*b[i][0]+a[0][1]*b[i][1]+a[0][2]*b[i][2]);

mato[i][1]=(float)(a[1][0]*b[i][0]+a[1][1]*b[i][1]+a[1][2]*b[i][2]);

mato[i][2]=(float)(a[2][0]*b[i][0]+a[2][1]*b[i][1]+a[2][2]*b[i][2]);
}


}











void plot(float draw[][3]){

for(int i=0;i<k;i++){
glBegin(GL_LINE_LOOP); 
glColor3f(0.0,0.0,1.0);
glVertex2f(draw[i][0],draw[i][1]);

}
glEnd(); 
glFlush();
}


void myclick
(int button,int state, int x, int y){
 if(state==GLUT_DOWN){
if(button==GLUT_LEFT_BUTTON){






mati[k][0]=float(x-350);
mati[k][1]=float(350-y);
mati[k][2]=(float)1;
glColor3f(1.0,0.0,0.0);
 glBegin(GL_POINTS);
glVertex2f(mati[k][0],mati[k][1]);
 k++;
glEnd();


glFlush();


}


else if(button=GLUT_RIGHT_BUTTON){



glBegin(GL_LINE_LOOP); 
glColor3f(1.0,0.0,0.0); 
for(int i=0;i<k;i++){
glVertex2f(mati[i][0],mati[i][1]);


}
glEnd(); 
glFlush();
}
}
}

void menu(int ch){
glBegin(GL_POINTS); 
mydisplay();

}


void translate(int tx,int ty){ 
for(int i=0;i<3;i++){
for(int j=0;j<3;j++){ 
matrix[i][j]=0;
}


matrix[0][0]=1;
matrix[0][1]=0; 
matrix[0][2]+=tx; 
matrix[1][0]=0;
matrix[1][1]=1; 
matrix[1][2]+=ty;
matrix[2][0]=0;
matrix[2][1]=0;
matrix[2][2]=1;
}
}

void translation_menu(int i){ 
int tx=0,ty=0;
switch(i){
case 1:
cout<<"Enter the x point:\t"; 
cin>>tx;
translate(tx,ty);
multiplication(matrix,mati); 
plot(mato);
break; 
case 2:
cout<<"Enter the y point:\t"; 
cin>>ty;
translate(tx,ty);
multiplication(matrix,mati); 
plot(mato);
break; 
case 3:
cout<<"Enter the x point:\t"; 
cin>>tx;
cout<<"Enter the y point:\t"; 
cin>>ty;
translate(tx,ty);
multiplication(matrix,mati); 
plot(mato);
break;
}
}


void scaling(int sx,int sy){
for(int i=0;i<3;i++){ 
for(int j=0;j<3;j++){ 
matrix[i][j]=0;
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
}

void scaling_menu(int i){
switch(i) {


case 1:
do{


cout<<"Enter same scaling factor:\n"; cout<<"Enter sx ";
cin>>sx;
cout<<"Enter sy "; 
cin>>sy;
}while(sx!=sy);
scaling(sx,sy);
multiplication(matrix,mati);

plot(mato);


case 2:

break;


do{


cout<<"Enter different scaling factor:\n"; cout<<"Enter sx ";
cin>>sx;
cout<<"Enter sy "; cin>>sy;

}while(sx==sy);
scaling(sx,sy);
multiplication(matrix,mati);

plot(mato);


break;


}
}


void rotation_anticlockwise(float angle){ for(int i=0 ; i<3;i++){
for(int j=0 ; j<3 ; j++){ matrix[i][j]=0;
}
}

matrix[0][0]=cos(angle);
matrix[0][1]=-(sin(angle)); matrix[0][2]=0;
matrix[1][0]=sin(angle); matrix[1][1]=cos(angle); matrix[1][2]=0;
matrix[2][0]=0;
matrix[2][1]=0;
matrix[2][2]=1;


}
void rotation_clockwise(float angle){ for(int i=0 ; i<3;i++){
for(int j=0 ; j<3 ; j++){ matrix[i][j]=0;
}
}

matrix[0][0]=cos(angle); matrix[0][1]=sin(angle); matrix[0][2]=0;
matrix[1][0]=-(sin(angle)); matrix[1][1]=cos(angle); matrix[1][2]=0;
matrix[2][0]=0;
matrix[2][1]=0;
matrix[2][2]=1;
}

void rotaion_menu(int i) { float angle;
cout<<"Enter Rotaion angle "; cin>>angle;
angle=(angle*(3.142/180));

switch(i) {
case 1:rotation_clockwise(angle); multiplication(matrix,mati); plot(mato);
break;
case 2:rotation_anticlockwise(angle); multiplication(matrix,mati); plot(mato);
break;

}
}


void reflection_X_axis(){ for(int i=0 ; i<3;i++){
for(int j=0 ; j<3 ; j++){ matrix[i][j]=0;
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

void reflection_Y_axis(){ for(int i=0 ; i<3;i++){
for(int j=0 ; j<3 ; j++){ matrix[i][j]=0;
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


void reflection_X_equal_Y_axis(){ for(int i=0 ; i<3;i++){
for(int j=0 ; j<3 ; j++){ matrix[i][j]=0;
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

void reflection_about_origin(){ for(int i=0 ; i<3;i++){
for(int j=0 ; j<3 ; j++){ matrix[i][j]=0;
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


void reflection_X_equal_minus_Y_axis(){ for(int i=0 ; i<3;i++){
for(int j=0 ; j<3 ; j++){ matrix[i][j]=0;
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


void Reflection_menu(int i){ switch(i){
case 1:reflection_X_axis();
multiplication(matrix,mati); plot(mato);
break;
case 2:reflection_Y_axis();
multiplication(matrix,mati); plot(mato);
break;
case 3:reflection_X_equal_Y_axis(); multiplication(matrix,mati);
plot(mato); break;
case 4:reflection_about_origin(); multiplication(matrix,mati);
plot(mato); break;
case 5:reflection_X_equal_minus_Y_axis(); multiplication(matrix,mati);
plot(mato); break;
}
}




void shearing_X_axis(){
cout<<"Enter shx "; cin>>a;
for(int i=0 ; i<3;i++){ for(int j=0 ; j<3 ; j++){
matrix[i][j]=0;


}
}

matrix[0][0]=1;
matrix[0][1]=a;
matrix[0][2]=0;
matrix[1][0]=0;
matrix[1][1]=1;
matrix[1][2]=0;
matrix[2][0]=0;
matrix[2][1]=0;
matrix[2][2]=1;
}


void shearing_Y_axis(){ cout<<"Enter shy "; cin>>b;
for(int i=0 ; i<3;i++){ for(int j=0 ; j<3 ; j++){
matrix[i][j]=0;

}
}

matrix[0][0]=1;
matrix[0][1]=0;
matrix[0][2]=0;
matrix[1][0]=b;
matrix[1][1]=1;
matrix[1][2]=0;
matrix[2][0]=0;
matrix[2][1]=0;
matrix[2][2]=1;
}


void shearing_menu(int i){ switch(i){
case 1:
shearing_X_axis();
multiplication(matrix,mati); plot(mato);
break; case 2:
shearing_Y_axis();
multiplication(matrix,mati); plot(mato);
break;
}
}

void Rotation_about_arbitary()
{	float angle;
cout<<"Enter the Rotaion angle : "; cin>>angle;
angle=(angle*(3.142/180)); cout<<"Enter the value of tx :"; cin>>tx;
cout<<"Enter the value of ty :"; cin>>ty;
for(int i=0 ; i<3;i++){
for(int j=0 ; j<3 ; j++){ matrix[i][j]=0;
}
}
matrix[0][0]=cos(angle);
matrix[0][1]=(-sin(angle));
matrix[0][2]=(-tx*cos(angle)+ty*sin(angle)+tx); matrix[1][0]=sin(angle);
matrix[1][1]=cos(angle);
matrix[1][2]=(-tx*sin(angle)-ty*cos(angle)+ty); matrix[2][0]=0;
matrix[2][1]=0;
matrix[2][2]=1;
}

void rotation_ref_menu(int i){ switch(i){
case 1:


Rotation_about_arbitary(); multiplication(matrix,mati);
plot(mato); break;
}
}


void Scalling_about_reference()
{
float xp,yp;
cout<<"Enter the value of xp :";
cin>>xp;
cout<<"Enter the value of yp :";
cin>>yp;
cout<<"Enter the value of Sx :";
cin>>sx;
cout<<"Enter the value of Sy :"; cin>>sy;

//xp=3;
//yp=3; matrix[0][0]=sx;
matrix[0][1]=0;
matrix[0][2]=0;
matrix[1][0]=0;
matrix[1][1]=sy;
matrix[1][2]=0;
matrix[2][0]=xp-(xp*sx);
matrix[2][1]=yp-(yp*sy); matrix[2][2]=1;

}
void Scalling_reference_menu(int i) { switch(i) {
case 1: Scalling_about_reference(); multiplication(matrix,mati);
plot(mato);
break;

}
}


int main(int argc, char** argv) {


glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB); glutInitWindowSize(700,700);
glutInitWindowPosition(50,100);
glutCreateWindow("Transformation"); myInit();
glutDisplayFunc(mydisplay); glutMouseFunc(myclick);

int translation_id=glutCreateMenu(translation_menu); glutAddMenuEntry("Along x-axis",1);
glutAddMenuEntry("Along Y-axis",2); glutAddMenuEntry("Along XY-axis",3);
int scaling_id=glutCreateMenu(scaling_menu); glutAddMenuEntry("Uniform",1);
glutAddMenuEntry("Differential",2);


int rotation_id=glutCreateMenu(rotaion_menu);
glutAddMenuEntry("Rotation Clockwise",1);
glutAddMenuEntry("Rotation Anticlockwise",2);


int reflection_id=glutCreateMenu(Reflection_menu);
glutAddMenuEntry("about x-axis ",1);
glutAddMenuEntry("about y-axis ",2);
glutAddMenuEntry("about xy-axis ",3);
glutAddMenuEntry("about origin ",4);
glutAddMenuEntry("about x=-y axis ",5); int shear_id=glutCreateMenu(shearing_menu);
glutAddMenuEntry("about x-axis ",1);
glutAddMenuEntry("about y-axis ",2); int rotation_ref_id=glutCreateMenu(rotation_ref_menu);
glutAddMenuEntry("-Rotation with respect to reference point ",1);

int scaling_ref_id=glutCreateMenu(Scalling_reference_menu);
glutAddMenuEntry("-Scaling with respect to reference point ",1);



glutCreateMenu(menu);
glutAddSubMenu("Translation",translation_id); glutAddSubMenu("Scaling",scaling_id);
glutAddSubMenu("Rotation",rotation_id);
glutAddSubMenu("Reflection",reflection_id); glutAddSubMenu("Shear",shear_id);
glutAddSubMenu("Rotation with respect to reference point ",rotation_ref_id); glutAddSubMenu("Scaling with respect to reference point ",scaling_ref_id);
glutAttachMenu(GLUT_MIDDLE_BUTTON); glutMainLoop();
return 0;
}
