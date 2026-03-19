/**
 * There are N stones, numbered 1,2,....,N. The height of ith stone is h. There is a frog who is initially on Stone 1. He will repeat an action some number of times to reach Stone N. The action is that if the frog is currently on Stone i, it jumps to one of the following:
 * Stone i + 1, i + 2, ...., i + k. Here, a cost of |hi - hj| is incurred, where j is the stone to land on.
 * Find the minimum possible total cost incurred before the frog reaches stone N.
 * Input1: n = 5, k = 3, 10 30 40 50 20
 * Output1: 30
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int f (vector<int> &heights, int i, int k) {
  if (i == heights.size() - 1) return 0;
  if (dp[i] != -1) return dp[i];
  int ans = INT_MAX;
  for (int j = 1; j <= k; j++) {
    if (i + j >= heights.size()) break;
    ans = min(ans, abs(heights[i] - heights[i + j]) + f(heights, i + j, k));
  }
  return dp[i] = ans;
};

int fbu (vector<int> &heights, int k) {
  int n = heights.size();
  dp[n - 1] = 0;
  for (int i = n - 2; i >= 0; i--) {    // order
    for (int j = 1; j <= k; j++) {
      if (i + j >= n) break;
    }
    dp[i] = min(dp[i], abs(heights[i] - heights[i + j]) + dp[i + j]);
  }
  return dp[0];
};

int main() {
  int n, k;
  cin >> n >> k;

  dp.clear();
  // dp.resize(100005, -1);
  dp.resize(100005, INT_MAX);

  vector<int> v(n, 0);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  // cout << f(v, 0, k) << endl;
  cout << fbu(v, k) << endl;
  return 0;
}