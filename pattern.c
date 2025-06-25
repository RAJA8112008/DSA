#include<stdio.h>
int recur(num){
    if(num==0){
    return 1;
    }else{
        return num*recur(num-1);
    }
}
int main(){
    int num,result;
    scanf("%d",&num);
   result=recur(num);
   printf("%d",result);
}