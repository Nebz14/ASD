#include <stdio.h>

void segitiga(){
    int n;
    printf("Masukkan tinggi penuh: ");
    scanf("%d", &n);

    if (n % 2 == 0){
        printf("Input bilangan ganjil!");
    }

    else {
         int mid = (n + 1) / 2;

        for (int i = 1; i <= mid; i++){
            for (int j = 1; j <= i; j++)
            printf("* ");

            for (int j = 1; j <= 2 * (mid - i); j++)
            printf("  ");

            for (int j = 1; j <= i; j++)
            printf("* ");

            printf("\n");
        }

        for (int i = mid - 1; i >= 1; i--){
            for (int j = 1; j <= i; j++)
            printf("* ");

            for (int j = 1; j <= 2 * (mid - i); j++)
            printf("  ");

            for (int j = 1; j <= i; j++)
            printf("* ");

            printf("\n");
        }
    }
}

int main(){
    segitiga();
}