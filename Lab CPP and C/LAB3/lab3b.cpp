#include<stdio.h>
#include<graphics.h>

int main()
{
int xc,yc, x,y,r,gd=DETECT,gm,p;
printf("Enter Radius:-");
scanf("%d", &r);
x=0;
y=r;
p=1-r;
initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
printf("Enter the center coordinates;-");
scanf("%d%d", &xc,&yc);
	do
	{       putpixel(xc+x,yc+y,3);
		putpixel(xc+x,yc-y,3);
		putpixel(xc-x,yc+y,3);
		putpixel(xc-x,yc-y,3);
		putpixel(xc+y,yc+x,3);
		putpixel(xc+y,yc-x,3);
		putpixel(xc-y,yc+x,3);
		putpixel(xc-y,yc-x,3);
		delay(50);
		if(p<0)
		{
		x=x+1;
		p=p+2*x+3;
		}
		else
		{
		x=x+1;
		y=y-1;
		p=p+2*(x-y)+5;
		}
	}while(x<y);
	getch();
	closegraph();

    return 0;
}
