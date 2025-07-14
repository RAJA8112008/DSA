#include<stdio.h>


void swap(int *a,int *b){
 int temp;
 if(*a>*b){
    temp=*a;
    *a=*b;
    *b=temp;
 }
}
int main(){
  //call by reference
  int x,y;
  printf("Enter the nums:");
  scanf("%d",&x);
   scanf("%d",&y);
   swap(&x,&y);
   printf("%d %d",x,y);
}