#include <stdio.h>
#include "binary-search.h"

int binary_search(int s[], int n, int length) {
    
    int low = 0;
    int high = length-1;
    while (low <= high) {
        int mid = low + high;
        int guess = s[mid];
        if (guess == n) {
            return mid;
        }
        if (guess > n) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return 0;
}
void display(int s[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", s[i]);
  }
  printf("\n");
}

 int main() {
  int s[] = {1, 3, 5, 7, 9};
  int length = sizeof(s) / sizeof(s[0]);
  int n = 3;
  binary_search(s, n, length);
}

