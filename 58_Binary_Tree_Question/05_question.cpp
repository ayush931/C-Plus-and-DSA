/**
 * Given the root of a binary tree, flattern the tree into a 'linked list':
 * The 'linked list' should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
 * The 'linked list' should be in the same order as a pre-order traversal of the binary tree.
 *
 * Input 1: root = [1, 2, 5, 3, 4, null, 6]
 * Output 1: 1 -> 2 -> 3 -> 4 -> 5 -> 6
 */

class Solution
{
public:
  TreeNode *lastNode = NULL;
  void flatten(TreeNode *root)
  {
    if (root == NULL)
    {
      return;
    }

    flatten(root->right);
    flatten(root->left);

    root->right = lastNode;
    root->left = NULL;

    lastNode = root;
    return;
  }
};