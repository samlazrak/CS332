#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaring num ( array size and max value ) i ( iterator 1 ) j ( iterator 2 ) k ( iterator 3 )
    int num, i, j, k;
    // Getting array size and maximum random value
    printf("Enter a number:");
    scanf("%d", &num);

    // Declaring array and filling with random ints 1 - num
    int a[num];
    for (i = 0; i <= num; i++) a[i] = rand() % num + 1;

    // Sorting using insertion sort
    for (i = 0; i < num; i++) {
        k = a[i];
        for (j = i-1; j >= 0 && a[j] > k; j--) {
            a[j + 1] = a[j];
        }
        a[j + 1] = k;
    }

    // Printing the final array
    for (i = 0; i < num; i++) {
        if (i != 0) printf(", ");
        printf("%d", a[i]);
    }
    printf("\n"); 
}