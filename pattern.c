#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,sum=0;
    printf("Enter the value :");
    scanf("%d",&n);
    int *ptr=(int*)malloc(n*sizeof(int));
    if(ptr==NULL){
        printf("Memmory not assign");
        return 1;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&ptr[i]);
        sum+=ptr[i];
    }
     printf("Printing sum:%d",sum);
    free(ptr);
}