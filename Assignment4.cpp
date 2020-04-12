#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
#include<math.h>
#define pi 3.14

int accept_vertices(int x[],int y[])
{
  int n,flag=0,i,Xx,Yy;
  do
  {
    printf("\nEnter number of vertices : ");
    scanf("%d",&n);
    if(n<3)
    {
      printf("\nPolygon not possible with %d vertices",n);
      printf("\nPlease re-enter the coordinates");
      flag=0;
    }
    else
    {
      flag=1;
      for(i=0;i<n;i++)
      {
        printf("Enter x%d = ",i+1);
        scanf("%d",&Xx);
        x[i]=abs((Xx * 10) + 320);
        printf("Enter y%d = ",i+1);
        scanf("%d",&Yy);
        y[i]=abs(240 - (Yy * 10));
        printf("\n");
      }
    }
  } while(flag!=1);
  return n;
}

void draw_polygon(int x[],int y[],int n)
{
 int i;
 for(i=0;i<n-1;i++)
 line(x[i],y[i],x[i+1],y[i+1]);
 line(x[i],y[i],x[0],y[0]);
}

void draw_axis()
{
 line(320,0,320,480);
 line(0,240,640,240);
}
int* func1a(int x[],int y[],int n,float angle,int pivx,int pivy)
{
    int i=0;
    float t,v;
    for(i=0;i<n;i++)
 {
    t=x[i]-pivx;
    v=y[i]-pivy;
    x[i]=pivx+round(t*cos(angle)-v*sin(angle));
    y[i]=pivy+round(v*cos(angle)+t*sin(angle));

 }
 return x,y;
}

void func1()
{
 int th1,th2,i,pivx,pivy,x1[10],y1[10],n,x2[10],y2[10];
 float theta1,theta2,theta3;
 n=accept_vertices(x1,y1);
 draw_polygon(x1,y1,n);
 printf("\nEnter theta-1:");
 scanf("%d",&th1);
 printf("\nEnter theta-2:");
 scanf("%d",&th2);
 printf("\nEnter vertex co-ordinate:");
 scanf("%d%d",&pivx,&pivy);
 pivx = abs((pivx * 10) + 320);
 pivy = abs(240 - (pivy * 10));
 theta1=(th1 * pi)/180;
 theta2=(th2 * pi)/180;
 theta3=theta1+theta2;
// printf("%f\t%f\t\%f\n",theta1,theta2,theta3);

 for(i=0;i<n;i++){
    x2[i]=x1[i];
    y2[i]=y1[i];
 }

 func1a(x1,y1,n,theta1,pivx,pivy);
 setcolor(GREEN);
 draw_polygon(x1,y1,n);

 func1a(x1,y1,n,theta2,pivx,pivy);
 setcolor(RED);
 draw_polygon(x1,y1,n);

 func1a(x2,y2,n,theta3,pivx,pivy);
 setcolor(LIGHTMAGENTA);
 draw_polygon(x2,y2,n);

 setcolor(WHITE);
}

void func2()
{
 int th1,th2,i,pivx,pivy,x1[10],y1[10],n,x2[10],y2[10];
 float theta1,theta2;
 n=accept_vertices(x1,y1);
 draw_polygon(x1,y1,n);
 printf("\nEnter theta-1:");
 scanf("%d",&th1);
 printf("\nEnter theta-2:");
 scanf("%d",&th2);
 printf("\nEnter vertex co-ordinate:");
 scanf("%d%d",&pivx,&pivy);
 pivx = abs((pivx * 10) + 320);
 pivy = abs(240 - (pivy * 10));
 theta1=(th1 * pi)/180;
 theta2=(th2 * pi)/180;

 for(i=0;i<n;i++){
    x2[i]=x1[i];
    y2[i]=y1[i];
 }

 func1a(x1,y1,n,theta1,pivx,pivy);
 setcolor(GREEN);
 draw_polygon(x1,y1,n);

 func1a(x1,y1,n,theta2,pivx,pivy);
 setcolor(RED);
 draw_polygon(x1,y1,n);


 func1a(x2,y2,n,theta2,pivx,pivy);
 setcolor(LIGHTGREEN);
 draw_polygon(x2,y2,n);

 func1a(x2,y2,n,theta1,pivx,pivy);
 setcolor(LIGHTRED);
 draw_polygon(x2,y2,n);

 setcolor(WHITE);
}

int main()
{
  int gd=DETECT,gm,n,x[10],y[10];
  int choice,B,cd=0,A,C;

    initgraph(&gd,&gm,"C://tc//bgi");
    while(choice!=4){
    printf("1.Draw Polygon\t2.R(Q1)*R(Q2)=R(Q1+Q2)\t3.R(Q1)*R(Q2)=R(Q2)*R(Q1)\t4.Exit\nYour choice : ");
    scanf("%d",&choice);
    draw_axis();
    switch(choice)
    {
      case 1 :{
               n=accept_vertices(x,y);
	           draw_polygon(x,y,n);
             A:printf("Clear?\t 1(YES) or 0(NO)\n");
			   scanf("%d",&cd);
			   if(cd==1){
			   cleardevice();
			   break;
			   }else{
			   goto A;}
              }
      case 2 :{
               func1();
             B:printf("Clear?\t 1(YES) or 0(NO)\n");
			   scanf("%d",&cd);
			   if(cd==1){
			   cleardevice();
			   break;
			   }else{
			   goto B;}
              }

      case 3 :{
               func2();
             C:printf("Clear?\t 1(YES) or 0(NO)\n");
			   scanf("%d",&cd);
			   if(cd==1){
			   cleardevice();
			   break;
			   }else{
			   goto C;}
              }
      case 4 : exit(1);
      default : printf("\n Invalid Choice!");
    }
  }

  getch();
  closegraph();
  return 0;
}

