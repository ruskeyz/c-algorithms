#include <stdio.h>

// swap function
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// display function
void display(int s[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", s[i]);
  }
  printf("\n");
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