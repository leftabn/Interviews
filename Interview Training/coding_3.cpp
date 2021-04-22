/**
 * Bitmap
 */

#include <bits/stdc++.h>

using namespace std;

void bitmapSet(uint64_t *bitmap, int value) { *bitmap |= (1 << value); }

int bitmapGet(uint64_t *bitmap, int value) {
  if (*bitmap & (1 << value))
    return 1; // has a duplicate
  bitmapSet(bitmap, value);
  return 0;
}

int solver(int *arr, int n) {
  int i;
  uint64_t bitmap = 0;
  for (i = 0; i < n; i++) {
    if (bitmapGet(&bitmap, arr[i])) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int arr[] = {1, 5, 28, 30, 1, 14, 28, 2, 7, 5};
  int len = (sizeof(arr)/sizeof(*arr)); // (sizeof(arr)/sizeof(arr[0]))
  cout << solver(arr, len) << "\n";
  return 0;
}