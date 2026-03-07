/**
 * Given an array arr[] of length N, find the length of the longest subarray with a sum equal to 0.

 * Input 1:- n = 8;
 * arr[] = {15, -2, 2, -8, 1, 7, 10, 23}
 * Output 1: 5
 */

#include <bits/stdc++.h>
using namespace std;

int maxLengthZeroSumSubarray(vector<int> &v) {
  unordered_map<int, int> m;
  int prefixSum = 0;
  int maxlen = INT_MIN;

  for (int i = 0; i < v.size(); i++) {
    prefixSum += v[i];
    if (prefixSum == 0) {
      maxlen++;
    }

    if (m.find(prefixSum) != m.end()) {
      maxlen = max(maxlen, i - m[prefixSum]);
    }
    else {
      m[prefixSum] = i;
    }
  }

  return maxlen;
};

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  cout << maxLengthZeroSumSubarray(v) << endl;

  return 0;
}

// Time and space -> O(n)