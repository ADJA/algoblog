#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>

using namespace std;

const int MAXN = 105000;
const int MAXLOG = 20;

int n;
int a[MAXN];

int table[MAXLOG][MAXN];
int logs[MAXN];

void buildLogs() {
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
  int lg = logs[r - l + 1];
  int lgLen = 1 << lg;
  return min(table[lg][l], table[lg][r - lgLen + 1]);
}

int main() {
  //assert(freopen("input.txt","r",stdin));
  //assert(freopen("output.txt","w",stdout));

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  buildLogs();
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