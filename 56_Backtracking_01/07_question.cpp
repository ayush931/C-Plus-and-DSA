/**
 * Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

 * Each number in candidates may only be used once in the combination.

 * Note: The solution set must not contain duplicate combinations.

 * Example 1:
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output:
  [
  [1,1,6],
  [1,2,5],
  [1,7],
  [2,6]
  ]

 * Example 2:
  Input: candidates = [2,5,2,1,2], target = 5
  Output:
  [
  [1,2,2],
  [5]
  ]

 * Constraints:
  1 <= candidates.length <= 100
  1 <= candidates[i] <= 50
  1 <= target <= 30
 */

class Solution
{
public:
  vector<vector<int>> result;
  void f(vector<int> &c, int idx, int t, vector<int> &v)
  {
    if (t == 0)
    {
      result.push_back(v);
      return;
    }
    if (idx == c.size())
      return;
    if (c[idx] <= t)
    {
      // we can pick
      v.push_back(c[idx]);
      f(c, idx + 1, t - c[idx], v);
      v.pop_back();
    }

    int j = idx + 1;
    while (j < c.size() and c[j] == c[j - 1])
      j++;
    f(c, j, t, v);
  };

  vector<vector<int>> combinationSum2(vector<int> &c, int target)
  {
    result.clear();
    sort(c.begin(), c.end());
    vector<int> v;
    f(c, 0, target, v);
    return result;
  }
};