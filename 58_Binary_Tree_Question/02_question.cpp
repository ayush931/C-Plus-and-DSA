/**
 * A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root. The path sum of a path is the sum of the node's values in the path.
 * Given the root of a binary tree, return the maximum path sum of any non-empty path.
 */

class Solution
{
public:
  int maxSumPathHelper(TreeNode *root, int &maxSum)
  {
    if (root == NULL)
    {
      return 0;
    }

    int leftMaxSum = max(0, maxSumPathHelper(root->left, maxSum));
    int rightMaxSum = max(0, maxSumPathHelper(root->right, maxSum));

    maxSum = max(maxSum, root->val + leftMaxSum + rightMaxSum);
    return root->val + max(leftMaxSum, rightMaxSum);
  };

  int maxPathSum(TreeNode *root)
  {
    int maxSum = INT_MIN;
    maxSumPathHelper(root, maxSum);
    return maxSum;
  }
};