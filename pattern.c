#include<stdio.h>
int sum(int,int); //function decleration
void main(){
      int a,b,result;  //sum of n numbers using function
      printf("Enter the value of n:");
      scanf("%d",&a);
      scanf("%d",&b);
      
      result= sum(a,b);
   printf("sum:%d",result);
}                  
int sum(int x,int y){
    int total=x+y;
    return total;
}