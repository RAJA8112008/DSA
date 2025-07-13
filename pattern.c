#include<stdio.h>
#define PI 3.14
void calculatr(float*r,float*cirf,float*area){
 *area=PI*(*r)*(*r);
 *cirf=2*PI*(*r);
}
int main(){
    float radius,cirf,area;
  printf("Enter the radius:");
  scanf("%f",&radius);
calculatr(&radius,&cirf,&area);
printf("Area:%.2f\n",area);
printf("Cirf:%.2f\n",cirf);
}