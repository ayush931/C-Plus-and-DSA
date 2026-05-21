/**
 * There are n cities labelled from 1 to n. You are given an integer n and connections where connections[i] = [xi, yi, costi] indicates that the cost of connecting city xi and yi (bidirectional connection) is costi.
 * Return the minimum cost to connect all the n cities such that there is atleast one path between each pair of cities. If it is impossible to connect all the n cities, then return -1.
 * The cost is the sum of the connection's costs used.

 * Input: n = 3, connections = [[1, 2, 5], [1, 3, 6], [2, 3, 1]]
 * Output: 6
 * Explanation: Choosing any 2 edges will connect all cities so we choose the minimum 2.

 * Input: n = 4, connections = [[1, 2, 3], [3, 4, 4]]
 * Output: -1
 * Explanation: There is no way to connect all cities even if all the edges are used.
 */