#include <iostream>
#include <map>

#define lli long long int

using namespace std;

lli solver(lli n, map<lli, lli> &mem) {
  if (n <= 2)
    return mem[n];
  else if (n < 0)
    return 0;
  else if (mem[n])
    return mem[n];
  mem[n] = solver(n - 1, mem) + solver(n - 2, mem) + solver(n - 3, mem);
  return mem[n];
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