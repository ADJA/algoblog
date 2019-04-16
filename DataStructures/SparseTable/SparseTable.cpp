/**
 * Sparse table. Solves static RMQ problem (without element changes).
 * O(NlogN) on precomputation, O(1) on minimum query.
 *
 * Based on the problem RMQSQ from SPOJ.com:
 * https://www.spoj.com/problems/RMQSQ/
 */

#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int MAXN = 105000;
const int MAXLOG = 20;

int n;
int a[MAXN];

int table[MAXLOG][MAXN];
int logs[MAXN];

void computeLogs() {
  for (int i = 2; i <= n; i++) {
    logs[i] = logs[i / 2] + 1;
  }
}

void buildSparseTable() {
  for (int i = 0; i <= logs[n]; i++) {
    int curLen = 1 << i;
    for (int j = 0; j + curLen <= n; j++) {
      if (curLen == 1) {
        table[i][j] = a[j];
      } else {
        table[i][j] = min(table[i - 1][j], table[i - 1][j + (curLen / 2)]);
      }
    }
  }
}

int getMin(int l, int r) {
  int p = logs[r - l + 1];
  int pLen = 1 << p;
  return min(table[p][l], table[p][r - pLen + 1]);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  computeLogs();
  buildSparseTable();

  int qn;
  scanf("%d", &qn);

  for (int i = 0; i < qn; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n", getMin(l, r));
  }

  return 0;
}
