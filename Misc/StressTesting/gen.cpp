/**
 * Test generator producing an integer n between 2 and 1000.
 */

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  // Use first command line argument as a seed.
  srand(atoi(argv[1]));

  int n = rand() % 999 + 2;
  printf("%d\n", n);

  return 0;
}
