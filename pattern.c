#include<stdio.h>
int febo(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }
    return febo(n-1)+febo(n-2);
}
int main(){
    int n,result;
    scanf("%d",&n);
    result=febo(n);
    printf("%d",result);

}