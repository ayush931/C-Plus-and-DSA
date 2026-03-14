/**
 * Given a Binary Tree, write a function that returns the size of the largest subtree which is also a Binary Search Tree (BST). If the complete Binary Tree is BST, then return the size of the whole tree.
 */

class NodeInfo {
public:
  int minValue;
  int maxValue;
  int maxCurrentSum;

  NodeInfo(int min, int max, int sum) {
    minValue = min;
    maxValue = max;
    maxCurrentSum = sum;
  }
};

class Solution {
public:
  int ans = 0;
  NodeInfo maxSumBSTHelper(TreeNode *root) {
    if (!root) {
      return NodeInfo(INT_MAX, INT_MIN, 0);
    }
    NodeInfo leftSubtree = maxSumBSTHelper(root->left);
    NodeInfo rightSubtree = maxSumBSTHelper(root->right);

    if (root->val > leftSubtree.maxValue && root->val < rightSubtree.minValue) {
      // root node forms a BST
      ans = max(ans, leftSubtree.maxCurrentSum + rightSubtree.maxCurrentSum + root->val);
      return NodeInfo(min(leftSubtree.minValue, root->val), max(rightSubtree.maxValue, root->val), leftSubtree.maxCurrentSum + rightSubtree.maxCurrentSum + root->val);
    }

    // root node does not form a BST
    return NodeInfo(INT_MIN, INT_MAX, max(leftSubtree.maxCurrentSum, rightSubtree.maxCurrentSum));
  };

  int maxSumBST(TreeNode *root) {
    maxSumBSTHelper(root);
    return ans;
  }
};

/**
 * Time and Space complexity -> O(n)
 */