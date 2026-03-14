/**
 * Given a binary tree, check if it is a binary search tree or not.
 *
 * Time -> O(n) and space -> O(h)
 */

class Solution {
public:
  bool isValidBSTHelper(TreeNode *root, long minValue, long maxValue) {
    if (root == NULL) {
      return true;
    }

    if (root->val <= minValue || root->val >= maxValue) {
      return false;
    }

    return isValidBSTHelper(root->left, minValue, root->val) && isValidBSTHelper(root->right, root->val, maxValue);
  }

  bool isValidBST(TreeNode *root) {
    return isValidBSTHelper(root, LONG_MIN, LONG_MAX);
  }
};

// another solution using inorder

class Solution {
  public:

  bool isValidBSTHelper(TreeNode *root, TreeNode* &prev) {
    if (root == NULL) {
      return true;
    };

    if (!isValidBSTHelper(root->left, prev)) {    // left subtree
      return true;
    }

    if (prev != NULL && root->val <= prev->val) {   // root node
      return false;
    }
    prev = root;

    return isValidBSTHelper(root->right, prev);   // right subtree
  }

  bool isValidBST(TreeNode* root) {
    TreeNode *prev = NULL;
    return isValidBSTHelper(root, prev);
  }
}