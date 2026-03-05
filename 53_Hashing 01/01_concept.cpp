/**
 * 1. Division method:-
 * h(k) = k mod m -> brackets
 *
 * 2. Mid square method
 * h(k) = k^2 and extract middle digit
 *
 * 3. Digit folding method:- Fold key into equal size parts
 *
 * 4. Multiplication method:- n(k) = floor(M(kA mod 1))
 * m -> size of hash table, 0 < A < 1
 */

/**
 * Collision:-
 * Open hashing / Closed addressing: -> O(n)
 * Closed hashing / Open addressing:-
 * h(k) = k mod 10 at (h(k) + i) mod 10 0 <= i <= 9
 * linear probing, qudratic probing
 * quadratic probing:- (h(k) + i^2) mod M 0 <= i < M
 * double hashing:- (h1(k) + ih2(k)) mod M 0 <= i <= M
 * h2 = k mod 5, h1 = k mod 10
 */

/**
 * Load factor:- n / m
 * n - no of elements
 * m - no of buckets
 * Load factor = n / m -> average enteries in one bucket
 * load factor limit = 0.75
 * Rehashing -> increasing size of hash table and redistributing elements in it
 */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Hashing {
  vector<list<int>> hashtable;
  int buckets;

  public:
  Hashing(int size) {
    buckets = size;
    hashtable.resize(size);
  }

  int hashValue(int key) {
    return key % buckets; // division method
  }

  void addKey(int key) {
    int idx = hashValue(key);
    hashtable[idx].push_back(key);
  }

  list<int>::iterator search(int key) {
    int idx = hashValue(key);
    return find(hashtable[idx].begin(), hashtable[idx].end(), key);
  }

  void deleteKey(int key) {
    int idx = hashValue(key);

    auto it = search(key); // search once

    if (it != hashtable[idx].end()) {
      hashtable[idx].erase(it);
      cout << key << " is deleted" << endl;
    }
    else {
      cout << "Key is not present in the hashtable" << endl;
    }
  }
};

int main() {
  Hashing h(10);

  h.addKey(5);
  h.addKey(9);
  h.addKey(3);

  h.deleteKey(3);
  h.deleteKey(3);

  return 0;
}