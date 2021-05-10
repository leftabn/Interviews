/**
 * URLify: Write a method to replace all spaces in a string with '%20'. You may
 * assume that the string has sufficient space at the end to hold the additional
 * characters, and that you are given the "true" length of the string. (Note: If
 * implementing in Java, please use a character array so that you can perform
 * this operation in place.)
 */

#include <bits/stdc++.h>

using namespace std;

string sol(string s1, int stringlen) {
  int i = (s1.length() - 1);
  while (i >= 0) {
    if (isspace(s1[stringlen])) {
      s1[i--] = '0';
      s1[i--] = '2';
      s1[i--] = '%';
      stringlen--;
    } else
      s1[i] = s1[stringlen--];
  }
  return s1;
}

int main() {
  int realLen;
  string a;
  getline(cin, a);
  cin >> realLen;
  cout << sol(a, realLen - 1) << "\n";
  return 0;
}