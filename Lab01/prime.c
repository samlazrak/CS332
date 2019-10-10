#include <stdio.h>

int main() {
  int given_number;

  printf("Enter number\n");
  scanf("%d", &given_number);

  if (!given_number) {
    printf("No input.\n");
  } else if ( given_number % 2 == 0 ) {
    printf("The number is not prime.\n");
  } else if ( given_number % 2 != 0) {
    printf("The number is prime.\n");
  }

  return 0;
}