#include<stdio.h>
//pass by reference
int main(){
    int temp,a,b;
    printf("Enter the value :");
    scanf("%d",&a);
    scanf("%d",&b);
    swap(&a,&b);
    printf("swep num:%d%d",a,b);
}
void swap(int *x,int *y){
   int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}