#include <bits/stdc++.h>
/**
 * Check Permutation: Given two strings,
 * write a method to decide if one is a permutation of the other
*/
using namespace std;

int sol(string s1, string s2)
{
  if (s1.length() != s2.length()) 
    return 0;
  int lettersCheckArr[27] = {0};
  for (char &i : s1)
    lettersCheckArr[i - 'a'] = 1;
  for (char &i : s2)
  {
    if (!lettersCheckArr[i - 'a'])
      return 0;
  }
  return 1;
}

int main()
{
  string a, b;
  cin >> a;
  cin >> b;
  cout << sol(a,b) << "\n";
  return 0;
}