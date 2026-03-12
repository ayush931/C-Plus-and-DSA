/**
 * Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum. The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes)
 */

/**
 * Time and Space complexity -> O(n)
 */

class Solution
{
public:
  int pathSumHelper(TreeNode *root, int targetSum, long int currSum, unordered_map<long int, int> pathCount)
  {
    if (root == NULL)
    {
      return 0;
    }

    currSum += root->val;
    int ansCount = pathCount[currSum - targetSum];
    pathCount[currSum]++;
    ansCount += pathSumHelper(root->left, targetSum, currSum, pathCount) + pathSumHelper(root->right, targetSum, currSum, pathCount);

    pathCount[currSum]--;
    return ansCount;
  };
  int pathSum(TreeNode *root, int targetSum)
  {
    unordered_map<long int, int> pathCount;
    pathCount[0] = 1;
    return pathSumHelper(root, targetSum, 0, pathCount);
  }
};