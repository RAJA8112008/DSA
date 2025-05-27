#include<stdio.h>
void main(){
    int num,i;
    int count=0;
    printf("Enter the num:");
    scanf("%d",&num);
    for(int i=1;i<=num;i++){
    if(num%i==0){
       count++;
    }
}
if(count==2){
    printf("Num is prime",num);
}else{
    printf("num is not prime",num);
}

}