#include<stdio.h>
void main(){
    int marks;
    printf("Enter the value of marks:");
    scanf("%d",&marks);
    switch(marks/10){
        case 10:
        case 9:
        printf("G-A");
        break;
        case 8:
        printf("G-B");
        break;
        case 7:
        printf("G-C");
        break;
        case 6:
        printf("G-D");
        break;
        default:
        printf("Fail");
    }
}