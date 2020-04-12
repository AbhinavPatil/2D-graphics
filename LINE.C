#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>

int DDA(int,int,int,int);
int Bresenham(int,int,int,int);
int object();

int main()
{
int gm, gd, c, x1, y1, x2, y2;
gd=DETECT;
//clrscr();
initgraph(&gd, &gm,"C:/TURBOC3/BGI");
while(c!=4)
{
	printf("\nChoose:\n1.DDA\t2.Bresenham\t3.Object\t4.Exit\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1: {
			printf("Enter the starting co-od: ");
			scanf("%d%d",&x1, &y1);
			printf("Enter the end co-od: ");
			scanf("%d%d",&x2, &y2);
		       //	line(x1, y1, x2, y2);
			DDA(x1, y1, x2, y2);
			break;
			}
		case 2: {
			printf("Enter the starting co-od: ");
			scanf("%d%d",&x1, &y1);
			printf("Enter the end co-od: ");
			scanf("%d%d",&x2, &y2);
		    //	line(x1, y1, x2, y2);
			Bresenham(x1, y1, x2, y2);
			break;
			}
		case 3: {
			object();
			break;
			}
		case 4: exit(1);
		default:printf("Invalid choice");
	}
}
getch();
closegraph();
return 0;
}
int DDA(int x1, int y1, int x2, int y2)
{
	int i, xc, yc;
	float dist, xn, yn, dx, dy, xf, yf, x1d=x1, y1d=y1;
	dx=x2-x1d;
	dy=y2-y1d;
	if(abs(dx)>abs(dy))
		dist=abs(dx);
	else
		dist=abs(dy);
	xn=dx/dist;
	yn=dy/dist;
	putpixel(x1d, y1d, RED);
	for(i=0;i<dist;i++)
	{
		x1d=x1d+xn;
		y1d=y1d+yn;
		if(abs(dx)<abs(dy))
		{
			yc=(int)y1d;
			xc=(int)x1d;
			xf=x1d-xc;
			if(xf>=0.5)
			{
				xc++;
				putpixel(xc, yc, RED);
			}
			else
				putpixel(xc, yc, RED);
		}
		else
		{
			xc=(int)x1d;
			yc=(int)y1d;
			yf=y1d-yc;
			if(yf>=0.5)
			{
				yc++;
				putpixel(xc, yc, RED);
			}
			else
				putpixel(xc, yc, RED);
		}
	}
	return 0;
}
int Bresenham(int x1, int y1, int x2, int y2)
{
	int dy, dyc, dx, dxc, i, G, distx, disty, xn, yn;
	dxc=x2-x1;
	dx=abs(x2-x1);
	dyc=y2-y1;
	dy=abs(y2-y1);
	putpixel(x1, y1, LIGHTBLUE);
	if(abs(dx)>abs(dy))
	{
		G=(2*dy)-dx;
		distx=abs(dx);
		for(i=0; i<distx; i++)
		{
			if(dxc>0)
				x1++;
			else
				x1--;
			if(G>=0)
			{
				if(y2>y1)
					y1++;
				else
					y1--;
				putpixel(x1, y1, LIGHTBLUE);
				G=G + (2*dy) - (2*dx);
			}
			else
			{
				putpixel(x1, y1, LIGHTBLUE);
				G= G + (2 * dy);
			}
		}
	}
	else
	{
		G=(2*dx)-dy;
		disty=abs(dy);
		for(i=0; i<disty; i++)
		{
			if(dyc>0)
				y1++;
			else
				y1--;
			if(G>=0)
			{
				if(x2>x1)
					x1++;
				else
					x1--;
				putpixel(x1, y1, LIGHTBLUE);
				G=G + (2*dx) - (2*dy);
			}
			else
			{
				putpixel(x1, y1, LIGHTBLUE);
				G= G + (2 * dx);
			}
		}
	}
	return 0;
}
int object()
{
DDA(400,150,450,200);
DDA(450,200,400,250);
DDA(400,250,350,200);
DDA(350,200,400,150);
DDA(350,200,450,200);
DDA(400,150,400,250);

Bresenham(400,250,410,255);
Bresenham(410,255,400,260);
Bresenham(400,260,410,265);
Bresenham(410,265,400,270);
Bresenham(400,270,410,275);
Bresenham(410,275,400,280);
Bresenham(400,280,410,285);

Bresenham(350,200,340,205);
Bresenham(340,205,350,210);

Bresenham(450,200,440,205);
Bresenham(440,205,450,210);

Bresenham(400,200,100,400);
return 0;
}
