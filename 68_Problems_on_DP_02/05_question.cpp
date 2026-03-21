/**
 * Given an input string s and a pattern p, implement regular expression
 matching with support for '.' and '*' where:
 * '.' Matches any single character.​​​​
 * '*' Matches zero or more of the preceding element.
 * Return a boolean indicating whether the matching covers the entire input
 string (not partial).

 * Example 1:
 * Input: s = "aa", p = "a"
 * Output: false
 * Explanation: "a" does not match the entire string "aa".

 * Example 2:
 * Input: s = "aa", p = "a*"
 * Output: true
 * Explanation: '*' means zero or more of the preceding element, 'a'. Therefore,
 by repeating 'a' once, it becomes "aa".

 * Example 3:
 * Input: s = "ab", p = ".*"
 * Output: true
 * Explanation: ".*" means "zero or more (*) of any character (.)".

 * Constraints:
 * 1 <= s.length <= 20
 * 1 <= p.length <= 20
 * s contains only lowercase English letters.
 * p contains only lowercase English letters, '.', and '*'.
 * It is guaranteed for each appearance of the character '*', there will be a
 previous valid character to match.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> dp;
  bool f(string s, string p, int i, int j) {
    if (j == p.size())
      return i == s.size();
    if (dp[i][j] != -1)
      return dp[i][j];
    if (j + 1 < p.size() and p[j + 1] == '*') {
      return dp[i][j] = f(s, p, i, j + 2) or ((i < s.size() and (s[i] == p[j] or p[j] == '.')) ? f(s, p, i + 1, j) : false);
    } else if (i < s.size() and p[j] == '.' or p[j] == s[i]) {
      return dp[i][j] = f(s, p, i + 1, j + 1);
    } else {
      return dp[i][j] = false;
    }
  };

  bool isMatch(string s, string p) {
    dp.clear();
    // dp.resize(25, vector<int> (25, -1));
    dp.resize(25, vector<int>(25, 0));
    dp[s.size()][p.size()] = 1;
    for (int i = s.size(); i >= 0; i--) {
      for (int j = p.size() - 1; j >= 0; j--) {
        if (j + 1 < p.size() and p[j + 1] == '*') {
          dp[i][j] = dp[i][j + 2] or ((i < s.size() and (s[i] == p[j] or p[j] == '.')) ? dp[i + 1][j] : false);
        } else if (i < s.size() and p[j] == '.' or p[j] == s[i]) {
          dp[i][j] = dp[i + 1][j + 1];
        } else {
          dp[i][j] = false;
        }
      }
    }
    // return f(s, p, 0, 0);
    return dp[0][0];
  }
};
