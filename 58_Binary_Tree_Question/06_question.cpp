/**
 * Amount of Time for Binary tree to be infected
 * You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with the value start.
 * The node is currently uninfected.
 * The node is adjacent to an infected node.
 * Return the number of minutes needed for the entire tree to be infected.
 * Input: root = [1, 2, 5, 3, 4, null, 6]
 * Output: [1, null, 2, null, 3, null, 4, null, 5, null, 6]
 */

// Time -> O(n)
// space -> O(n)

class Solution {
public:
  int calculateTime(TreeNode *startTime, unordered_map<TreeNode *, TreeNode *> &parent) {
    unordered_set<TreeNode *> infected;
    queue<TreeNode *> q;
    q.push(startTime);
    infected.insert(startTime);
    int time = 0;

    while (!q.empty()) {
      int currLevelNode = q.size();
      bool infectFlag = false;
      while (currLevelNode--) {
        TreeNode *currNode = q.front();
        q.pop();

        if (currNode->left && !infected.count(currNode->left)) {
          infectFlag = true;
          infected.insert(currNode->left);
          q.push(currNode->left);
        }

        if (currNode->right && !infected.count(currNode->right)) {
          infectFlag = true;
          infected.insert(currNode->right);
          q.push(currNode->right);
        }

        if (parent[currNode] && !infected.count(parent[currNode])) {
          infectFlag = true;
          infected.insert(parent[currNode]);
          q.push(parent[currNode]);
        }
      }
      if (infectFlag) time++;
    }
    return time;
  };

  TreeNode *makeParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent, int start) {
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *startNode;
    while (!q.empty()) {
      TreeNode *currNode = q.front();
      q.pop();
      if (currNode->val == start) {
        startNode = currNode;
      }

      if (currNode->left) {
        parent[currNode->left] = currNode;
        q.push(currNode->left);
      }

      if (currNode->right) {
        parent[currNode->right] = currNode;
        q.push(currNode->right);
      }
    }
    return startNode;
  };

  int amountOfTime(TreeNode *root, int start) {
    unordered_map<TreeNode *, TreeNode *> parent;
    TreeNode *startNode = makeParent(root, parent, start);
    return calculateTime(startNode, parent);
  }
};