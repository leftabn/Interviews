/**
 * Verify if an array has the Max Heap structure
 */

#include <bits/stdc++.h>

using namespace std;

int LChild(int i) { return (i << 1); }

int RChild(int i) { return ((i << 1) | 1); }

int sol(int* arr, int n) {
  int i;
  for (i = 1; i < (n / 2); i++) {
    if ((arr[i - 1] < arr[LChild(i) - 1]) && (arr[i - 1] < arr[RChild(i) - 1]))
      return 0;
  }
  return 1;
}

int main() {
  int arr_hm[] = { 9, 8, 6, 5, 2, 1 }; // MAX HEAP
  int arr_nh[] = { 1, 3, 6, 5, 7, 1 }; // NOT MAX HEAP
  int len = 6;
  cout << "HEAP MAX? " << sol(arr_hm, len) << "\n";
  cout << "HEAP MAX? " << sol(arr_nh, len) << "\n";
  return 0;
}