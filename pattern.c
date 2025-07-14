#include<stdio.h>

void swap(int *a,int *b){
    int temp;
    if(*a>*b){
        temp=*a;
       *a=*b;
       *b=temp;
      
    }
     printf("%d",*a);
       printf("%d",*b);
}
int main(){
  int n1,n2;
  printf("Enter the values:");
  scanf("%d %d",&n1,&n2);
 swap(&n1,&n2);
 
}