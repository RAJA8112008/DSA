#include<stdio.h>
void main(){
    int marks;
    printf("Enter the marks:");
    scanf("%d",&marks);
if(marks<100&&marks>=90){
    printf("Grade A");
}else if(marks<90&& marks>=80){
    printf("Grade B");
}
else if(marks<80 && marks>=70){
    printf("Grade C");
}
else if(marks<60 && marks>=50){
    printf("Grade D");
}
else if(marks>=0 &&marks<49){
    printf("Fail");
}else{
    printf("Invalid");
}
}
