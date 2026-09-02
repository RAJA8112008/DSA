#include<stdio.h>
int main(){
    int i,j;
    int arr[3][3];
    int brr[3][3];
    int crr[3][3];
    
    for(i=0;i<3;i++){
        
        for(j=0;j<3;j++){
            scanf("\t%d",&arr[i][j]);
        }
    }
     for(j=0;j<3;j++){
        for(j=0;j<3;j++){
            scanf("\t%d",&brr[i][j]);
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            crr[i][j]=arr[i][j]+brr[i][j];
        }
    }
        for(i=0;i<3;i++){
        for(j=0;j<3;j++){
             printf("%d",&crr[i][j]);
        }
       print("\n");
    }
   
}