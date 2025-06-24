#include<stdio.h>
int main(){
    int a,b;
    printf("Enter the nums:");
    scanf("%d",&a);
    scanf("%d",&b);
    swap(a,b);
}
void swap(int x,int y){
    int temp;
     temp=x;
     x=y;
     y=temp;
     printf("Num is:%d %d",x,y);
     
}