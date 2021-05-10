/**
 * Recursive Multiply: Write a recursive function to multiply two positive integers without using the 
 * operator.You can use addition, subtraction, and bit shifting, but you should minimize the number
 * of those operations
*/

#include <iostream>

int mult(int a, int b) {
  int ans;
  if (a > b)
    ans = mult(b, a);
  else if (a == 0)
    ans = 0;
  else if (a == 1)
    ans = b;
  else {
    int tmp = (a >> 1);
    int prod = mult(tmp, b); // rec
    if (a & 1) // impar?
      ans = (prod + prod + b);
    else
      ans = (prod + prod);
  }
  return ans;
}

int main() {
  std::cout << mult(1587, 999) << "\n";
  return 0;
}