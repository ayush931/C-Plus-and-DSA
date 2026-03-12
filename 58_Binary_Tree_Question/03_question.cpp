/**
 * Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
 * Input: preorder = [3, 9, 20, 15, 7], inorder = [9, 3, 15, 20, 7]
 * Output: [3, 9, 20, null, null, 15, 7]
 */

// Time and Space complexity -> O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
  TreeNode *buildTreeHelper(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend, unordered_map<int, int> &inmap) {
    if (prestart > preend || instart > inend) {
      return NULL; // handling the leaf node
    }

    TreeNode *rootNode = new TreeNode(preorder[prestart]);
    int rootInorderIndex = inmap[rootNode->val];
    int leftSubtreeSize = rootInorderIndex - instart;

    rootNode->left = buildTreeHelper(preorder, prestart + 1, prestart + leftSubtreeSize, inorder, instart, rootInorderIndex - 1, inmap);
    rootNode->right = buildTreeHelper(preorder, prestart + leftSubtreeSize + 1, preend, inorder, rootInorderIndex + 1, inend, inmap);

    return rootNode;
  };

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    unordered_map<int, int> inmap;
    for (int i = 0; i < inorder.size(); i++) {
      inmap[inorder[i]] = i;
    }

    return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inmap);
  }
};