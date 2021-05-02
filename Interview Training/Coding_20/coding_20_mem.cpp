#include <iostream>
#include <map>

#define lli long long int

using namespace std;

lli solver(lli n, map<lli, lli> &mem) {
  lli ans;
  if (n < 0)
    ans = 0;
  else if (n <= 2)
    ans = mem[n];
  else if (mem[n])
    ans = mem[n];
  else {
    mem[n] = solver(n - 1, mem) + solver(n - 2, mem) + solver(n - 3, mem);
    ans = mem[n];
  }
  return ans;
}

int main() {
  map<lli, lli> mem = map<lli, lli>();
  mem[0] = 1;
  mem[1] = 1;
  mem[2] = 2;
  lli n = 1000;
  printf("%lld\n", solver(n, mem));
  return 0;
}