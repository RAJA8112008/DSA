#include<stdio.h>

int fact(int num){
    if(num==0||num==1){
        return 1;
    }
    return num*fact(num-1);
}

int  main(){
    int n;
printf("Enter the num:");
scanf("%d",&n);
if(n<0){

    printf("NO number found");
}else{
 int result=fact(n);
printf("%d",result);
}
return 0;
}