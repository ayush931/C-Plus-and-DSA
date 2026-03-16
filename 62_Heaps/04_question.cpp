/**
 * Given two binary max heaps as arrays, the task is to merge the given heaps
 */

class Solution {
  public:

  void heapify(vector<int> &v, int size, int curr) {
    // loop till curr has child node
    while((2 * curr + 1) < size) {
      int leftChild = 2 * curr + 1;
      int rigthChild = 2 * curr + 2;
      int maxChild = leftChild;

      if (rigthChild < size && v[rigthChild] > v[leftChild]) {
        maxChild = rigthChild;
      }

      if (v[maxChild] <= v[curr]) {
        return;
      }

      swap(v[maxChild], v[curr]);
      curr = maxChild;
    }
  };

  vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    vector<int> mergedHeap;
    for (auto ele:a) {
      mergedHeap.push_back(ele);
    }

    for (auto ele:b) {
      mergedHeap.push_back(ele);
    }

    // loop all parent node
    int lastParentNode = (n + m) / 2 - 1;
    for (int i = lastParentNode; i >= 0; i--) {
      heapify(mergedHeap, n + m, i);
    }

    return mergedHeap;
  }
};

// Time complexity -> O(n + m)