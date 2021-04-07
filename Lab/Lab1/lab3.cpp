#include<graphics.h>
#include<iostream>


int main(){
    using namespace std;
    int gd=DETECT,gm,xc,yc,p,r,x,y;
    cout<<"Enter the radius of the circle to be generated: ";
    cin>>r;
    cout<<"\n Enter the x and y coordinated of the center : ";
    cin>>xc>>yc;
    initgraph(&gd,&gm,NULL);
    x=0;
    y=r;
    p=3-2*r;
    while(x<=y){
        delay(50);
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


  getch();
  closegraph();
return EXIT_SUCCESS;
}