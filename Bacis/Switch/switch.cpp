#include <stdio.h>

int main() {
    int num;
    printf("value of num: ");
    scanf("%d", &num);

    switch (num > 0){
        case 1:
        
        printf("num is positive");
        break;
        case 0:
        switch(num<0){
            
            case 1:
            printf("num is negative");
            break;
            case 0:
            printf("num is zero");
            break;
        }
        break;

    }
       
}