#include<stdio.h>
int fibonaci(n){
   if(n==0){
    return 0;
   }
   if(n==1){
    return 1;
   }
    return (n-1)+(n-2);

}

void main(){
 int n;
   printf("Enter the num:");
   scanf("%d",&n);
 for(int i=1;i<=n;i++){
    int result=fibonaci(i);
    printf("%d",result);
 }
}
