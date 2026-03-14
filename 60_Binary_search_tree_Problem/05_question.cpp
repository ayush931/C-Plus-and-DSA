/**
 * Write a C++ program to construct all unique binary search trees (BSTs) for keys ranging from 1 to N. The program should prompt the user to enter the value of N, and then construct and display all possible BSTs for the given range of keys.
 */

class Solution {
public:
  vector<TreeNode *> generateTreesHelper(int start, int end) {
    vector<TreeNode *> treesList;
    // base case
    if (start > end) {
      treesList.push_back(NULL);
      return treesList;
    }

    for (int i = start; i <= end; i++) {
      // recursive case
      vector<TreeNode *> leftSubtrees = generateTreesHelper(start, i - 1);
      vector<TreeNode *> rightSubtrees = generateTreesHelper(i + 1, end);

      for (TreeNode *leftSubtree : leftSubtrees) {
        for (TreeNode *rightSubtree : rightSubtrees) {
          TreeNode *rootNode = new TreeNode(i);
          rootNode->left = leftSubtree;
          rootNode->right = rightSubtree;
          treesList.push_back(rootNode);
        }
      }
    }
    return treesList;
  };

  vector<TreeNode *> generateTrees(int n) {
    return generateTreesHelper(1, n);
  }
};