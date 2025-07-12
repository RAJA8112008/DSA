#include<stdio.h>
void main(){
    int ed,evensum=0,oddsum=0;
    printf("Enter the  ending value");
    scanf("%d",&ed);
    for(int i=1;i<=ed;i++){
        if(i%2==0){
            evensum=evensum+i;
        }else{
            oddsum=oddsum+i;
        }
    }
    printf("Sum of even num:%d\n",evensum);
    printf("sum of odd num:%d",oddsum);
}