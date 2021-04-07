#include<graphics.h>
#include<iostream>
#include <cmath>
void DrawCircle(int xc,int yc,int r);
void DrawLine(int x1,int y1,int x2,int y2);
int main(){
    using namespace std;
    int gd=DETECT,gm,xc,yc,r,width;
    cout<<"Enter the radius of the circle to be generated: ";
    cin>>r;
    cout<<"\n Enter the x and y coordinated of the center : ";
    cin>>xc>>yc;
    cout<<"\nEnter the axle length of the car : ";
    cin>>width;
    int xc2=xc+width;
    initgraph(&gd,&gm,NULL);
    //first tyre
    DrawCircle(xc,yc,r);
    DrawLine(xc,yc+r,xc,yc-r);
    DrawLine(xc-r,yc,xc+r,yc);
    DrawLine(xc+abs(cos(0.785398)*r),yc+abs(sin(0.785398)*r),xc-abs(cos(0.785398)*r),yc-abs(sin(0.785398)*r));
    DrawLine(xc-abs(cos(0.785398)*r),yc+abs(sin(0.785398)*r),xc+abs(cos(0.785398)*r),yc-abs(sin(0.785398)*r));

     //second tyre
     DrawCircle(xc2,yc,r);
     DrawLine(xc2,yc+r,xc2,yc-r);
     DrawLine(xc2-r,yc,xc2+r,yc);
     DrawLine(xc2+abs(cos(0.785398)*r),yc+abs(sin(0.785398)*r),xc2-abs(cos(0.785398)*r),yc-abs(sin(0.785398)*r));
     DrawLine(xc2-abs(cos(0.785398)*r),yc+abs(sin(0.785398)*r),xc2+abs(cos(0.785398)*r),yc-abs(sin(0.785398)*r));
     //lines for joining top of tyres
     DrawLine(xc,yc+r,xc2,yc+r);
     DrawLine(xc,yc-r,xc2,yc-r);

     //drawing the upper part
     DrawLine(xc+20,yc-r,xc+20,yc-r-50);
     DrawLine(xc2-20,yc-r,xc2-20,yc-r-50);
     DrawLine(xc+20,yc-r-50,xc2-20,yc-r-50);

     //drawing the cannon
     DrawLine(xc2-20,yc-r-30,xc2-20+180,yc-r-30);
     DrawLine(xc2-20,yc-r-20,xc2-20+180,yc-r-20);
     DrawLine(xc2-20+180,yc-r-30,xc2-20+180,yc-r-20);
     
    
 
    



  getch();
  closegraph();


  

    return EXIT_SUCCESS;
}

void DrawCircle(int xc,int yc,int r){
    using namespace std;
    int p,x,y;
 
   
    x=0;
    y=r;
    p=3-2*r;
    while(x<=y){
        delay(10);
        putpixel(xc+x,yc+y,RED);
		putpixel(xc+x,yc-y,RED);
		putpixel(xc-x,yc+y,RED);
		putpixel(xc-x,yc-y,RED);
		putpixel(xc+y,yc+x,RED);
		putpixel(xc+y,yc-x,RED);
		putpixel(xc-y,yc+x,RED);
		putpixel(xc-y,yc-x,RED);
        if(p<=0){
            p=p+4*x+6;
            x=x+1;

        }
        else{
            p=p+4*x-4*y+10;
            y-=1;
            x+=1;
        }

    }
}

void DrawLine(int x1,int y1,int x2,int y2){
int dx,dy,steps,xinc,yinc;
dx=x2-x1;
dy=y2-y1;

	if(abs(dx)>abs(dy))
	steps=abs(dx);
	else
	steps=abs(dy);
xinc=dx/steps;
yinc=dy/steps;

	for(int i=0;i<steps;i++)
	{
		putpixel(x1, y1, RED);
		x1=x1+xinc;
		y1=y1+yinc;
		delay(10);
	}
}