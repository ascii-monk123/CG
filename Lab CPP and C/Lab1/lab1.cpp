//square in lab file
#include <graphics.h>
#include <iostream>

int main(){
int gd=DETECT,gm;

int x1,y1,dx,dy,steps,length,breadth,xa,ya,xb,yb,xinc,yinc;
std::cout<<"Enter the start point co-ordinates : ";
std::cin>>x1>>y1;
std::cout<<"\n";
std::cout<<"Enter the length of rectangle : ";
std::cin>>length;
std::cout<<"Enter the breadth of rectangle : ";
std::cin>>breadth;
initgraph(&gd,&gm,NULL);
for(int i=0;i<4;i++){
    if(i==0){
     xa=x1;
     ya=y1;
     xb=x1+length;
     yb=y1;
     }
     else if(i==1){
         xa=x1+length;
         ya=y1;
         xb=x1+length;
         yb=y1+breadth;
     }
     else if(i==2){
         xa=x1+length;
         ya=y1+length;
         xb=x1;
         yb=y1+length;
     }
    else if(i==3){
        xa=x1;
        ya=y1+length;
        xb=x1;
        yb=y1;
    }

dx=xb-xa;
dy=yb-ya;

	if(abs(dx)>abs(dy))
	steps=abs(dx);
	else
	steps=abs(dy);
xinc=dx/steps;
yinc=dy/steps;
int xi=xa,yi=ya;
	for(int y=0;y<steps;y++)
	{
		putpixel(xi, yi, WHITE);
		xi=xi+xinc;
		yi=yi+yinc;
		delay(50);
	}
}
getch();
closegraph();

}