#include<stdio.h>
int main(){
    int num,count=0;
    printf("Enter the num:");
    scanf("%d",&num);
  for(int i=1;i<=num;i++){
    if(num%i==0){
        count++;
    }
  }
  if(count==2){
    printf("Num is prime:%d",num);

  }else{
    
    printf("Num is not Prime:%d",num);
  }
}