# Advanced DSA Roadmap

After completing the core topics in this repository, here are the advanced topics you should learn to master Competitive Programming and Advanced Data Structures & Algorithms.

## 1. Advanced Graph Algorithms

- **Bellman-Ford Algorithm:** Finding the shortest path in a graph with negative edge weights.
- **Floyd-Warshall Algorithm:** All-pairs shortest path algorithm.
- **Strongly Connected Components (SCC):**
  - Kosaraju's Algorithm
  - Tarjan's Algorithm
- **Connectivity:**
  - Bridges in a graph
  - Articulation Points
- **Eulerian & Hamiltonian Paths:**
  - Hierholzer’s Algorithm for Eulerian Circuit
  - Backtracking for Hamiltonian Path
- **Network Flow:**
  - Ford-Fulkerson Method
  - Edmonds-Karp Algorithm
  - Dinic's Algorithm
- **Bipartite Matching:** Hopcroft-Karp Algorithm.

## 2. Advanced Dynamic Programming (DP)

- **DP with Bitmasking:** Useful for problems involving subsets or permutations (e.g., TSP).
- **Digit DP:** Counting numbers in a range $[L, R]$ satisfying certain properties.
- **DP on Trees:** Problems like finding the diameter of a tree or Maximum Weight Independent Set.
- **DP Optimizations:**
  - Convex Hull Trick
  - Knuth Optimization
  - Divide and Conquer Optimization
- **Matrix Exponentiation:** Solving linear recurrences (like $N$-th Fibonacci) in $O(\log N)$.

## 3. Advanced Data Structures

- **Bit Manipulation:**
  - Setting/Clearing/Toggling bits.
  - Check if a number is a power of 2.
  - Count set bits (Brian Kernighan’s Algorithm).
  - Bitmasking techniques.
  - XOR tricks (finding unique elements, etc.).
- **Segment Trees:** Range Sum/Min/Max queries with Lazy Propagation for range updates.
- **Fenwick Trees (Binary Indexed Trees):** Efficient range sum queries and point updates.
- **Tries (Prefix Trees):** Efficient string search, prefix matching, and XOR problems.
- **Sparse Table:** Range Minimum Query (RMQ) in $O(1)$ after $O(N \log N)$ preprocessing.
- **Square Root Decomposition:**
  - Block decomposition for range queries.
  - Mo's Algorithm for offline range queries.
  - Mo's Algorithm on Trees.
- **Disjoint Set Union (DSU) Advanced:**
  - Path compression and Union by rank/size.
  - DSU on Trees (Sack).
  - Rollback DSU.
- **Monotonic Stack & Queue:** Solving "Next Greater Element" and "Sliding Window Maximum".
- **Heaps Advanced:**
  - Fibonacci Heap.
  - Median in a Stream using two heaps.
- **Persistent Data Structures:** Persistent Segment Trees and Persistent Tries.
- **Link-Cut Trees & Splay Trees:** Dynamic tree connectivity and balanced BSTs.

## 4. Advanced Tree Algorithms

- **Lowest Common Ancestor (LCA):** Binary Lifting and Euler Tour methods.
- **Heavy-Light Decomposition (HLD):** Decomposing trees into paths for range queries.
- **Centroid Decomposition:** Divide and conquer on trees.
- **Tree Flattening:** Converting tree problems to array problems using DFS entry/exit times.

## 5. Advanced String Algorithms

- **Pattern Matching:**
  - Knuth-Morris-Pratt (KMP) Algorithm
  - Rabin-Karp (Rolling Hash)
  - Z-Algorithm
  - Aho-Corasick Algorithm (Multiple pattern matching).
- **Suffix Structures:**
  - Suffix Array & LCP Array
  - Suffix Tree
  - Suffix Automaton
- **Manacher's Algorithm:** Finding the longest palindromic substring in $O(N)$.

## 6. Computational Geometry

- **Foundations:** Points, Lines, Polygons, and Intersection logic.
- **Convex Hull:**
  - Graham Scan
  - Jarvis March
- **Sweep Line Algorithm:** Closest pair of points, line segment intersection.
- **Pick's Theorem & Shoelace Formula:** Calculating area of polygons.

## 7. Advanced Mathematics & Number Theory

- **Prime Numbers:**
  - Segmented Sieve
  - Miller-Rabin Primality Test
  - Pollard's Rho Algorithm for Factorization
- **Modular Arithmetic:**
  - Fermat's Little Theorem
  - Chinese Remainder Theorem (CRT)
  - Modular Multiplicative Inverse
- **Combinatorics:**
  - Inclusion-Exclusion Principle
  - Catalan Numbers
  - Burnside's Lemma
- **Matrix Exponentiation:** Solving linear recurrences in $O(\log N)$.
- **Fast Fourier Transform (FFT):** Polynomial multiplication in $O(N \log N)$.

## 8. Miscellaneous Techniques

- **Sliding Window & Two Pointers:** Optimized array traversal.
- **Prefix Sum & Difference Array:** Handling range updates and queries.
- **Meet-in-the-middle:** Reducing $O(2^N)$ to $O(2^{N/2})$.
- **Coordinate Compression:** Mapping large values to a smaller range.
- **Game Theory:**
  - Nim Game
  - Sprague-Grundy Theorem.
- **Randomized Algorithms:** Treaps and Skip Lists.

## Recommended Platforms for Practice

- **Codeforces:** For competitive programming problems.
- **LeetCode (Hard):** For advanced interview-style questions.
- **CSES Problem Set:** Excellent for standard advanced algorithms (CSES.fi).
- **AtCoder:** High-quality mathematical and logic-based problems.
