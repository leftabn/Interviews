#include <iostream>

#define lli long long int

using namespace std;

lli solver(lli n) {
  lli v[3] = {1, 1, 2};
  if (n <= 2)
    return v[n];
  else {
    lli i, ans;
    for (i = 3; i <= n; i++) {
      ans = v[0] + v[1] + v[2];
      v[0] = v[1];
      v[1] = v[2];
      v[2] = ans;
    }
    return ans;
  }
}

int main() {
  printf("%lld\n", solver(1000));
  return 0;
}