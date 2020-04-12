#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int main(){
    int gd=DETECT, gm;
    int i,x1,y1,x2,y2,m,A=0;
	int xmax,ymax,xmin,ymin;
    int start[4],endd[4],code[4];
    initgraph(&gd,&gm,"C://tc//bgi");
    printf("Enter coordinates of window (xmin,ymin,xmax,ymax) ");
    scanf("%d %d %d %d",&xmin,&ymin,&xmax,&ymax);
    setcolor(WHITE);
    rectangle(xmin,ymin,xmax,ymax);
    printf("\nPlease enter the co-ordinates for starting point of line: ");
    scanf("%d %d",&x1,&y1);
    printf("\nPlease enter the co-ordinates for ending point of line: ");
    scanf("%d %d",&x2,&y2);
    for(i=0;i<4;i++){
        start[i]=0;
        endd[i]=0;
        }
    m=abs((y2-y1)/(x2-x1));
    if(x1 <xmin) start[0]=1;
    if(x1 >xmax) start[1]=1;
    if(y1 >ymax) start[2]=1;
    if(y1 <ymin) start[3]=1;
    if(x2 <xmin) endd[0]=1;
    if(x2 >xmax) endd[1]=1;
    if(y2 >ymax) endd[2]=1;
    if(y2 <ymin) endd[3]=1;
    for(i=0;i<4;i++)
    code[i]=start[i]&&endd[i];
    if((code[0]==0)&&(code[1]==0)&&(code[2]==0)&&(code[3]==0)){
        if((start[0]==0)&&(start[1]==0)&&(start[2]==0)&&(start[3]==0)&&(endd[0]==0)&&(endd[1]==0)&&(endd[2]==0)&&(endd[3]==0)){
            printf("\n\t\tThe line is totally visible and no clipping needed");
            line(x1,y1,x2,y2);
        }else{
            printf("\nLine is partially visible");
            line(x1,y1,x2,y2);

        if((start[2]==0)&&(start[3]==1)){
            x1=x1+abs((ymin-y1)/m);
            y1=ymin;
        }

        if((endd[2]==0)&&(endd[3]==1)){
            x2=x2+abs((ymin-y2)/m);
            y2=ymin;
        }

        if((start[2]==1)&&(start[3]==0)){
            x1=x1+abs((ymax-y1)/m);
            y1=ymax;
        }

        if((endd[2]==1)&&(endd[3]==0)){
            x2=x2+abs((ymax-y2)/m);
            y2=ymax;
        }

        if((start[1]==0)&&(start[0]==1)){
            y1=y1+abs(m*(xmin-x1));
            x1=xmin;
        }

        if((endd[1]==0)&&(endd[0]==1)){
            y2=y2+abs(m*(xmin-x2));
            x2=xmin;
        }

        if((start[1]==1)&&(start[0]==0)){
            y1=y1+abs(m*(xmax-x1));
            x1=xmax;
        }

        if((endd[1]==1)&&(endd[0]==0)){
            y2=y2+abs(m*(xmax-x2));
            x2=xmax;
        }

        printf("\n\t\tAfter clippling:");
        setcolor(RED);
        line(x1,y1,x2,y2);
        getchar();
        goto A;
            }
     }
    else{
     printf("\nLine is invisible");
     }
    A:getch();
    closegraph();
    return 0;
}
