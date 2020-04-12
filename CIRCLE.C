#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

void circlemidpoint(int,int,int);
void Bresenhamcircle(int,int,int);
void circleplotpoints(int,int,int,int,char);
void circleobject();

int main(void)
{
   int gdriver = DETECT, gmode;
   int xcenter=0,ycenter=0,radius=0,c=0,A,cd,B,C;
   initgraph(&gdriver, &gmode, "C:/TURBOC3/BGI");
//   midx = getmaxx() / 2;
//   midy = getmaxy() / 2;
//   circle(midx, midy, radius);
  while(c!=4)
  {
	printf("\nChoose :\n1.Midpoint\t2.Bresenham circle\t3.Object\t4.Exit\n");
	scanf("%d",&c);
	switch(c)
	{
	       case 1:{
			 printf("Enter xcenter, ycenter and radius :\n");
			 scanf("%d%d%d",&xcenter,&ycenter,&radius);
			 circlemidpoint(xcenter,ycenter,radius);
             A:printf("Clear?\t 1(YES) or 0(NO)\n");
			 scanf("%d",&cd);
			 if(cd==1){
			 cleardevice();
			 break;
			 }else{
			 goto A;}
		      }
	       case 2:{
			 printf("Enter xcenter, ycenter and radius :\n");
			 scanf("%d%d%d",&xcenter,&ycenter,&radius);
			 Bresenhamcircle(xcenter,ycenter,radius);
             B:printf("Clear?\t 1(YES) or 0(NO)\n");
			 scanf("%d",&cd);
			 if(cd==1){
			 cleardevice();
			 break;
			 }else{
			 goto B;}
		      }
	       case 3:{
			circleobject();
            C:printf("Clear?\t 1(YES) or 0(NO)\n");
			scanf("%d",&cd);
			if(cd==1){
			cleardevice();
			break;
			}else{
			goto C;}
		      }
	       case 4: exit(1);
	       default:printf("Invalid");
	}
  }
   getch();
   closegraph();
   return 0;
}
void circlemidpoint(int xcenter,int ycenter,int radius)
{
  int x=0;
  int y=radius;
  int p=1-radius;
  circleplotpoints(xcenter,ycenter,x,y,YELLOW	);
  while(x<y){
  x++;
  if(p<=0)
  p += (2 * x) + 1;
  else{
  y--;
  p += 2 * (x-y) + 1;
  }
  circleplotpoints(xcenter,ycenter,x,y,YELLOW);
  }
}

void Bresenhamcircle(int xcenter,int ycenter,int radius)
{
  int x=0;
  int y=radius;
  int p=3 - (2 * radius);
  circleplotpoints(xcenter,ycenter,x,y,RED);
  while(x<y){
  x++;
  if(p<=0)
  p += (4 * x) + 6;
  else{
  y--;
  p += 4 * (x-y) + 10;
  }
  circleplotpoints(xcenter,ycenter,x,y,RED);
  }
}
void circleplotpoints(int xcenter,int ycenter,int x,int y,char col)
{
  putpixel(xcenter +x,ycenter +y,col);//4a
  putpixel(xcenter -x,ycenter +y,col);//3a
  putpixel(xcenter +x,ycenter -y,col);//1a
  putpixel(xcenter -x,ycenter -y,col);//2a

  putpixel(xcenter -y,ycenter -x,col);//2b
  putpixel(xcenter -y,ycenter +x,col);//3b
  putpixel(xcenter +y,ycenter -x,col);//1b
  putpixel(xcenter +y,ycenter +x,col);//4b
}
void circleobject()
{

  Bresenhamcircle(getmaxx()/2,getmaxy()/2,70);
  setfillstyle(SOLID_FILL,RED);
  floodfill(getmaxx()/2,getmaxy()/2,RED);

  circlemidpoint(200,300,10);
  setfillstyle(SOLID_FILL,YELLOW);
  floodfill(200,300,YELLOW);
  Bresenhamcircle(700,300,500);

  circlemidpoint(110,400,20);
  setfillstyle(SOLID_FILL,BROWN);
  floodfill(110,400,YELLOW);
  Bresenhamcircle(710,390,600);

  circlemidpoint(60,200,25);
  setfillstyle(SOLID_FILL,BLUE);
  floodfill(60,200,YELLOW);
  Bresenhamcircle(650,300,600);

  circlemidpoint(22,100,15);
  setfillstyle(SOLID_FILL,CYAN);
  floodfill(22,100,YELLOW);
  Bresenhamcircle(500,250,500);

}
