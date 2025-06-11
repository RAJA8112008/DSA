#include <stdio.h>

int main() {
    int rows = 5;

    // Upper part of the tree
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            printf("  ");
        }
        printf("*");
        if (i > 0) {
            for (int j = 0; j < 2 * i - 1; j++) {
                printf("  ");
            }
            printf(" *");
        }
        printf("\n");
    }
    // Bottom row (full stars)
    for (int i = 0; i < 2 * rows - 1; i++) {
        printf("* ");
    }
    printf("\n");

    return 0;
}
