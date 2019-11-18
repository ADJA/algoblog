/**
 * Sparse table. Solves static RMQ problem (without element changes).
 * O(NlogN) on precomputation, O(1) on minimum query.
 *
 * Based on the problem RMQSQ from SPOJ.com:
 * https://www.spoj.com/problems/RMQSQ/
 */

#include <iostream>
#include <cstdio>

using namespace std;

int n;

bool isPrime(int n) {
  for (int i = 2; i * i < n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  scanf("%d", &n);

  if (isPrime(n)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
