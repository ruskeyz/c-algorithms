#include <stdio.h>
#include "insertion-sort.h"

// display function
void display(int s[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", s[i]);
  }
  printf("\n");
}
// main function or driver function
 int main() {
  int s[] = {9, 5, 1, 4, 3};
  int n = sizeof(s) / sizeof(s[0]);
  printf("Elements before sorting:\n");
  display(s, n);
  insertion_sort(s, n);
  printf("Elements after sorting:\n");
  display(s, n);
}

