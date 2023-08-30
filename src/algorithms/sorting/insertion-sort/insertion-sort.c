#include <stdio.h>
#include "insertion-sort.h"

// swap function
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void insertion_sort(int s[], int n) {
  int i, j; // counters

  for(i = 1; i < n; i++) {
    j=i;
    while ((j > 0) && (s[j] < s[j - 1])) {
      swap(&s[j], &s[j - 1]);
      j= j - 1;
    }
  }
}

