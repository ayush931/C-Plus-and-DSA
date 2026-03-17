/**
 * Given a stream of integers, find the median of the stream.
 */

class MedianFinder {
  priority_queue<int> maxpq;                            // for storing the lower half of stream
  priority_queue<int, vector<int>, greater<int>> minpq; // storing greater half of the stream
  
  public:
  MedianFinder() {
  }

  void addNum(int num) {
    if (maxpq.empty() || num <= maxpq.top()) {
      maxpq.push(num);
    }
    else {
      minpq.push(num);
    }

    // rebalancing the pq
    if (maxpq.size() > minpq.size() + 1) {
      minpq.push(maxpq.top());
      maxpq.pop();
    }
    else if (minpq.size() > maxpq.size()) {
      maxpq.push(minpq.top());
      minpq.pop();
    }
  }

  double findMedian() {
    if (minpq.size() == maxpq.size()) { // even elements
      return (minpq.top() + maxpq.top()) / 2.0;
    }
    else {
      // odd elements
      return maxpq.top();
    }
  }
};

// Time complexity -> O(nlogn)

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */