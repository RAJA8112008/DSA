# include<stdio.h>
int  main(){
   int phy,chem,math;
   int sum;
   int avr;
   scanf("%d",&phy);
   scanf("%d",&chem);
   scanf("%d",&math);
   sum = phy+chem+math;
  printf("sum of subjects=%d",sum);
  avr=sum/3;
  printf("average of subjects=%d",avr);

}