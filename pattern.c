#include<stdio.h>
void main(){
    int n,arr[n];
    printf("Enter the value :");
    scanf("%d",&n);
    int *ptr=(int*)malloc(n*sizeof(int));
    if(ptr==NULL){
        printf("Memmory not assign");
        return 1;
    }
    for(int i=0;i<n;i++){
        scanf("%d",arr[i]);
    }
    printf("Printing:");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    free(ptr);

}