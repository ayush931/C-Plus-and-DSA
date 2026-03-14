/**
 * Given the preorder traversal of a binary search tree, construct the BST.
 * Input: Given preorder: [10, 5, 3, 8, 20, 15, 25]
 * Output: Inorder Traversal of the BST is 3, 5, 6, 10, 15, 20, 25
 */

class Solution {
public:
  TreeNode *bstFromPreorderHelper(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend, unordered_map<int, int> inmap) {
    // base case
    if (prestart > preend || instart > inend) {
      return NULL;
    }

    TreeNode *root = new TreeNode(preorder[prestart]);
    int inroot_idx = inmap[preorder[prestart]];
    int leftsubtree_elements = inroot_idx - instart;

    root->left = bstFromPreorderHelper(preorder, prestart + 1, prestart + leftsubtree_elements, inorder, instart, inroot_idx - 1, inmap);
    root->right = bstFromPreorderHelper(preorder, prestart + leftsubtree_elements + 1, preend, inorder, inroot_idx + 1, inend, inmap);

    return root;
  };

  TreeNode *bstFromPreorder(vector<int> &preorder) {
    vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end());

    unordered_map<int, int> inmap;
    for (int i = 0; i < inorder.size(); i++) {
      inmap[inorder[i]] = i; // storing value-index pairs
    }

    return bstFromPreorderHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inmap);
  }
};

/**
 * Time complexity -> O(nlogn) + O(n)
 * Space complexity -> O(n) + O(n) + O(n)
 */

// optimal solution

class Solution {
public:
  TreeNode *bstFromPreorderHelper(vector<int> &preorder, int &index, int upper_bound) {

    if (index >= preorder.size()) {
      return NULL;
    }

    if (preorder[index] >= upper_bound) {
      return NULL;
    }

    TreeNode *root = new TreeNode(preorder[index]);
    index++;

    root->left = bstFromPreorderHelper(preorder, index, root->val);
    root->right = bstFromPreorderHelper(preorder, index, upper_bound);

    return root;
  }

  TreeNode *bstFromPreorder(vector<int> &preorder) {
    int index = 0;
    return bstFromPreorderHelper(preorder, index, INT_MAX);
  }
};

/**
 * Time and space complexity -> O(N) and O(h)
 */