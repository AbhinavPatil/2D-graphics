#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
//#include<DDA.h>

struct queue
{
  int x,y;
  struct queue *next;
};
typedef struct queue node;
node *front=NULL,*rear=NULL;

node* createNode(int x_cordinate,int y_cordinate)
{
  node *temp;
  temp=(node*)malloc(sizeof(node));
  temp->x = x_cordinate;
  temp->y = y_cordinate;
  temp->next = NULL;
  return temp;
}

void addq(node *x)
{
  if(rear==NULL)
  {
    front=x;
    rear=x;
  }
  else
  {
    rear->next=x;
    rear=rear->next;
  }
}

node* delq()
{
  return front;
}

int accept_vertices(int x[],int y[])
{
  int n,flag=0,i;

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
        scanf("%d",&x[i]);
        printf("Enter y%d = ",i+1);
        scanf("%d",&y[i]);
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

int InOut(int xseed,int yseed,int x[],int y[],int ct){
    int add=1,sum=0,flag,i,j,flagg;
    for(i=0;i<ct;i++){
        if(xseed==x[i]){
            return 1;
        }
    }
    for(i=0;i<=xseed;i++){
        if(getpixel(i,yseed)==15){
            for(j=0;j<ct;j++){
                add=1;
                if(i==x[j]){
                    add=1;
                    if(j==0){
                        if((y[ct]>y[j]&&y[j+1]>y[j])||(y[ct]<y[j]&&y[j+1]<y[j])){
                           add=0;
                        }
                    }
                    else if(j==ct){
                        if((y[0]>y[j]&&y[j-1]>y[j])||(y[0]<y[j]&&y[j-1]<y[j])){
                           add=0;
                        }
                    }
                    else{
                        if((y[j+1]>y[j]&&y[j-1]>y[j])||(y[j+1]<y[j]&&y[j-1]<y[j])){
                           add=0;
                        }
                    }
                    sum=sum+add;
                    flagg=1;
                    break;
                }
            }
            if(flagg!=1){
                sum=sum+1;
                flagg=0;
            }
        }
                //sum=sum+1;

        }
    if(sum==0){
        flag=0;
    }
    else if(sum%2==0){
        flag=1;
    }
    else{
        flag=0;

    }
    return flag;
}

void boundary_fill(int xseed,int yseed,int boundcolour,int fillcolour)
{
   node *temp,*p;
   int x,y;
   front=NULL;
   rear=NULL;
   temp=createNode(xseed,yseed);
   addq(temp);
   while(front!=NULL)
   {
     p=delq();
     x = p->x;
     y = p->y;
     putpixel(x,y,fillcolour);
     if(getpixel(x,y+1)!=fillcolour && getpixel(x,y+1)!=boundcolour)
     {
       putpixel(x,y+1,fillcolour);
       temp=createNode(x,y+1);
       addq(temp);
     }
     if(getpixel(x,y-1)!=fillcolour && getpixel(x,y-1)!=boundcolour)
     {
       putpixel(x,y-1,fillcolour);
       temp=createNode(x,y-1);
       addq(temp);
     }
     if(getpixel(x+1,y)!=fillcolour && getpixel(x+1,y)!=boundcolour)
     {
       putpixel(x+1,y,fillcolour);
       temp=createNode(x+1,y);
       addq(temp);
     }
     if(getpixel(x-1,y)!=fillcolour && getpixel(x-1,y)!=boundcolour)
     {
       putpixel(x-1,y,fillcolour);
       temp=createNode(x-1,y);
       addq(temp);
     }
     front=front->next;
     p->next=NULL;

   }
}



int main()
{
  int gd=DETECT,gm,n,x[10],y[10];
  int xseed,yseed,backcolour,fillcolour,i,boundcolour,choice,B,cd=0,A;

    initgraph(&gd,&gm,"C://tc//bgi");
    while(choice!=3){
    printf("1.Draw Polygon\t2.Fill Polygon\t3.Exit\nYour choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1 :{
               n=accept_vertices(x,y);
	           draw_polygon(x,y,n);
			   break;
              }
      case 2 :{
              A: printf("\nenter seed point : ");
               printf("\nx = ");
               scanf("%d",&xseed);
               printf("y = ");
               scanf("%d",&yseed);
           //    InOut(xseed,yseed,x[],y[],n);
               if(InOut(xseed,yseed,x,y,n)==1){
                printf("Error, wrong points");
                goto A;
               }
               printf("\nChoose colour to fill Polygon");
               printf("\n1.Blue\n2.Green\n3.Cyan\n4.Red\n5.Magenta");
               printf("\nColour = ");
               scanf("%d",&fillcolour);
               boundcolour=15;
               draw_polygon(x,y,n);
               boundary_fill(xseed,yseed,boundcolour,fillcolour);
               B:printf("Clear?\t 1(YES) or 0(NO)\n");
			   scanf("%d",&cd);
			   if(cd==1){
			   cleardevice();
			   break;
			   }else{
			   goto B;}
              }

      case 3 : exit(1);
      default : printf("\n Invalid Choice!");
    }
  }

  getch();
  closegraph();
  return 0;
}



