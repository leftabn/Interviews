// Given 1 list cointaing birth year and death year of people, find the year with the most number of people alive
#include <bits/stdc++.h>

using namespace std;

struct Person 
{
  int birthYear;
  int deathYear;
};

struct Person personArr[102];

map<int, int> uniqueYears;

int sol()
{
  uniqueYears = map<int, int>();
  int n;
  cin >> n;
  int i;
  for (i = 0; i < n; i++)
  {
    cin >> personArr[i].birthYear >> personArr[i].deathYear;
    uniqueYears[personArr[i].birthYear] = 0;
    uniqueYears[personArr[i].deathYear] = 0;
  }
  
  for (i = 0; i < n; i++)
  {
    uniqueYears[personArr[i].birthYear] += 1;
    uniqueYears[personArr[i].deathYear] -= 1;
  }
  
  int auxCount = 0;
  int count = 0;
  int ans;
  map<int, int>::iterator it;
  for (it = uniqueYears.begin(); it != uniqueYears.end(); it++)
  {
    auxCount += it->second;
    if (auxCount > count)
    {
      count = auxCount;
      ans = it->first;
    }
  }
  return ans;
}

int main()
{
  cout << sol() << "\n";
  return 0;
}