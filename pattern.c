#include<stdio.h>
void max(int,int);
int main(){
   int a,b;
    printf("Enter the values:");
    scanf("%d",&a);
    scanf("%d",&b);
    max(a,b);
}
  void max(int a,int b){
     if(a>b){
        printf("A is greater");
     }else{
         printf("B is greater");
     }

    
}