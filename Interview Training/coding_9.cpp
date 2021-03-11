/**
 * Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome.
 * A palindrome is a word or phrase that is the same forwards and backwards.
 * A permutation is a rearrangement of letters.
 * The palindrome does not need to be limited to just dictionary words.
*/

#include <bits/stdc++.h>

using namespace std;

int checkOdd(string s1, int *lettersMap)
{
  int oneOdd = 0;
  for (char &i : s1)
  {
    if (lettersMap[i - 'a'] & 1)
    {
      if (oneOdd)
        return 0;
      oneOdd = 1;
    }
  }
  return 1;
}

int sol(string s1)
{
  int lettersCountArr[27] = {0};
  int i;
  for (char &i : s1)
  {
    if (!isspace(i))
      lettersCountArr[i - 'a']++;
  }
  return checkOdd(s1, lettersCountArr);
}

int main()
{
  string a;
  getline(cin, a);
  cout << sol(a) << "\n";
  return 0;
}