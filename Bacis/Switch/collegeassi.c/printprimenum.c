#include<stdio.h>
int isprime(int n){      // as did before (num is prime or not)
    int count =0;
   for(int i=2;i<n;i++){     
    if(n%i==0){
        count++;
    }
    if(count==2){
        return 0;
    }
   }
}
int main(){
    int first,Last;
    //start num
    printf("Enter the First num:");
    scanf("%d",&first);
    //last num
    printf("Enter the Last num:");
    scanf("%d",&Last);
               // first num must be greater then one
    for(int i=first;i<=Last;i++){
       if(isprime(i)){
        printf("\nPrime num is :%d",i);
       }
    }
   }
