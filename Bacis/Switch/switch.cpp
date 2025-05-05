# include<stdio.h>
int  main(){
 int a,b,c;
 scanf("%d",&a);
 scanf("%d",&b);
 scanf("%d",&c);
if(a<b && a<c){
    printf("small number:%",a);
}else if(b<c){
   printf("print b:%d",b);
}else{  
    printf("print c:%d",c);
}
}