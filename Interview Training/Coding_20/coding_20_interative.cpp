#include <iostream>

#define lli long long int

using namespace std;

lli solver(lli n) {
  lli ans;
  lli v[3] = {1, 1, 2};
  if (n <= 2)
    ans = v[n];
  else {
    lli i;
    for (i = 3; i <= n; i++) {
      ans = v[0] + v[1] + v[2];
      v[0] = v[1];
      v[1] = v[2];
      v[2] = ans;
    }
  }
  return ans;
}

int main() {
  printf("%lld\n", solver(1000));
  return 0;
}