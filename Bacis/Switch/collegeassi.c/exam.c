#include<stdio.h>
void main (){
    int arr[3],brr[3],crr[3],i;
    for(i=0;i<3;i++){
        scanf("%d",&arr[i]);
    } 
    for(i=0;i<3;i++){
        scanf("%d",&brr[i]);
    }
    printf("total sum:\n");
    for(i=0;i<3;i++){
        crr[i]=arr[i]+brr[i];
        printf("%d",crr[i]);
    }
}