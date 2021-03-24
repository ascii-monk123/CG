//simple code in lab file
#include<graphics.h>
#include<iostream>
int main()
{
 int gd=DETECT, gm;
 int x1,y1,x2,y2,p,dx,dy;

 std::cout<<"Enter all the 4 coordinates : ";
 std::cin>>x1>>y1>>x2>>y2;
 dx=x2-x1;
 dy=y2-y1;
 p=2*dy-dx;
initgraph(&gd,&gm,NULL);
 putpixel(x1,y1,WHITE);

 for(int i=0;i<dx;i++)
 {
	if(p<0)
	{
	x1++;
	p=p+2*dy;
	}
	else
	{
	x1++;
	y1++;
	p=p+2*dy-2*dx;
	}
	putpixel(x1,y1,WHITE);
	delay(50);
 }
 getch();
 closegraph();
 return 0;
 }