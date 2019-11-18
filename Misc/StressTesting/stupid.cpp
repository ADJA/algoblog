/**
 * O(n) solution for the problem 
 * of checking whether n is a prime number.
 */

#include <iostream>
#include <cstdio>

using namespace std;

int n;

bool isPrime(int n) {
  for (int i = 2; i < n; i++) {
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
