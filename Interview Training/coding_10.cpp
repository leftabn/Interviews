/**
 * Is Unique: Implement an algorithm to determine if a string has all unique
 * characters. What if you cannot use additional data structures?
 */

#include <bits/stdc++.h>

using namespace std;

int sol(string s1) {
  if (s1.length() > 96)
    return 0;
  int markLetters[256] = { 0 };
  for (char& i : s1) {
    if (!markLetters[i])
      markLetters[i] = 1;
    else
      return 0;
  }
  return 1;
}

int main() {
  string a = "";
  for (int i = 32; i < 128; i++)
    a += (char)i;
  cout << sol(a) << "\n";
  return 0;
}