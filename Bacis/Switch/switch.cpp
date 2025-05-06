#include <stdio.h>

int main() {
    int num;
    printf("value of num: ");
    scanf("%d", &num);

    switch (num > 0) {
        case 1:
            printf("\nnum is positive: %d", num);
            break;
        case 0:
            switch (num < 0) {
                case 1:
                    printf("\nnum is negative: %d", num);
                    break;
                case 0:
                    printf("\nnum is zero: %d", num);
                    break;
            }
            break;
    }

    return 0;
}

