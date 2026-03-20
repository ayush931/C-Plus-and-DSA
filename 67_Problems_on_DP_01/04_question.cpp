/**
 * Matrix Chain Multiplication
 * Given the dimension of a sequence of matrices in an array arr[], where the dimension of the ith matrix is (arr[i - 1] * arr[i]), the task is to find the most efficient way to multiply these matrices together such that the total number of element multiplications is minimum.
 * 
 * Input1: arr[] = {40, 20, 30, 10, 30}
 * Output1: 26000
 * Explanation: There are 4 matrices of dimensions 40 x 20, 20 x 30, 30 x 10, 10 x 30. Let the input 4 matrices be A, B, C and D. The minimum number of multiplications are obtained by putting parentheses in the following way(A(BC))D. The minimum is 20 * 30 * 10 + 40 * 20 * 10 + 40 * 10 * 30.
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int f (int i, int j, vector<int> &arr) {
  if (i == j or i + 1 == j) return 0;
  if (dp[i][j] != -1) return dp[i][j];
  int ans = INT_MAX;

  for (int k = i + 1; k < j; k++) {
    ans = min(ans, f(i, k, arr) + f(k, j, arr) + arr[i] * arr[k] * arr[j]);
  }
  return dp[i][j] = ans;
};

int main() {
  int n;
  cin >> n;
  vector<int> v(n);

  dp.clear();
  dp.resize(1005, vector<int>(1000, 0));
  for (int i = 0; i < n; i++) cin >> v[i];

  for (int len = 3; len <= n; len++) {
    for (int i = 0; i + len - 1 < n; i++) {
      int j = i + len - 1;
      dp[i][j] = INT_MAX;
      for (int k = i + 1; k < j; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + v[i] * v[k] * v[j]);
      }
    }
  }

  cout << f(0, n - 1, v) << endl;
  return 0;
}