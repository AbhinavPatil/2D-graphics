#include<iostream>
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <time.h>

void fracLine(int x1, int y1, int x2, int y2, int ite, int sign){
    int midx, midy;
    srand(time(NULL));
    midx = (int)((x1 + x2)/2) + (sign);
    midy = (int)((y1 + y2)/2) - (sign * rand() % 70);
    sign = sign * -1;
    if(ite>0){
        fracLine(x1, y1, midx, midy, ite - 1, sign);
        sign = sign * -1;
        fracLine(midx, midy, x2, y2, ite - 1, sign);
    }
    else{
        line(x1, y1, midx, midy);
        line(midx, midy, x2, y2);
    }
}

int main(){
    int gd = DETECT, gm;
    int ite, sign = -1,j=1;
    int choice, x1, x2, y1, y2,i;
    initgraph(&gd,&gm,"C://tc//bgi");
    printf("Enter x1: ");
    scanf("%d",&x1);
    printf("Enter y1: ");
    scanf("%d",&y1);
    printf("Enter x2: ");
    scanf("%d",&x2);
    printf("Enter y2: ");
    scanf("%d",&y2);
    printf("Enter the number of iterations: ");
    scanf("%d",&ite);

    for(i=0;i<ite;i++){
        setcolor(j);
        cleardevice();
        fracLine(x1, y1, x2, y2, i, sign);
        sign = sign * 1;
        getch();
        j++;
    }
    getch();
    closegraph();
    return 0;
}
