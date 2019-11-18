/**
 * Test generator for the problem RMQSQ from SPOJ.com:
 * https://www.spoj.com/problems/RMQSQ/
 */

#include <iostream>

using namespace std;

int main() {
  srand(time(0));

  int n = rand() % 999 + 2;
  printf("%d\n", n);

  return 0;
}
