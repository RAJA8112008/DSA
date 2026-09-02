#include<stdio.h>
int main(){
    int i,num,factorial=1;
    printf("Enter the num:");
    scanf("%d",&num);
if(num<0){
    printf("\nNOT possible %d",num);
}
else{
for(i=1;i<=num;i++){
    factorial*=i;   
  }
  printf("\nFactorial is %d:",factorial);
}
return 0;
}
// #include <stdio.h>

// int main() {
//     int i, num, factorial = 1;
//     printf("Enter the num: ");
//     scanf("%d", &num);

//     if (num < 0) {
//         printf("\nNOT possible for negative number: %d", num);
//     } else {
//         for (i = 1; i <= num; i++) {
//             factorial *= i;
//         }
//         printf("\nFactorial of %d is: %d", num, factorial);
//     }

//     return 0;
// }
