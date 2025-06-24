#include<stdio.h>

int sum(int num){
    if(num==0){
        return 0;
    } 
   return num+sum(num-1);

}
int  main(){
    int n;
    scanf("%d",&n);
   int result=sum(n);
   printf("%d",result);
}