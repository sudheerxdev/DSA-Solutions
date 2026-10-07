# [Max Path Sum Between Two Leaves](https://www.geeksforgeeks.org/problems/maximum-path-sum/1)
## Hard
Given the root of a binary tree, where each node contains an integer value, find the maximum possible path sum between any two leaf nodes. If the tree has fewer than two leaf nodes, return -1.
Examples:
Input: root = [3, 4, 5, -10, 4, N, N] &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 
Output: 16
Explanation: The leaf nodes are -10, 4 (right child of 4), and 5.
Possible paths between leaf nodes are:
-10 -&gt; 4 -&gt; 3 -&gt; 5 = -10 + 4 + 3 + 5 = 2
-10 -&gt; 4 -&gt; 4 = -10 + 4 + 4 = -2
4 -&gt; 4 -&gt; 3 -&gt; 5 = 4 + 4 + 3 + 5 = 16Hence, the maximum path sum is obtained from the path 4 -&gt; 4 -&gt; 3 -&gt; 5, giving 16.

Input: root = [-15, 5, 6, -8, 1, 3, 9, 2, -3, N, N, N, N, N, 0, N, N, N, N, 4, -1, N, N, 10]Output: 27Explanation: The leaf nodes are 2, -3, 1, 4, and 10.
Some possible paths between leaves are:
2 -&gt; -8 -&gt; 5 -&gt; 1 = 2 + (-8) + 5 + 1 = 0
-3 -&gt; -8 -&gt; 5 -&gt; 1 = -3 + (-8) + 5 + 1 = -5
2 -&gt; -8 -&gt; 5 -&gt; -15 -&gt; 6 -&gt; 3 = 2 + (-8) + 5 + (-15) + 6 + 3 = -7
1 -&gt; 5 -&gt; -15 -&gt; 6 -&gt; 9 -&gt; 0 -&gt; 4 = 1 + 5 + (-15) + 6 + 9 + 0 + 4 = 10
3 -&gt; 6 -&gt; 9 -&gt; 0 -&gt; -1 -&gt; 10 = 3 + 6 + 9 + 0 + (-1) + 10 = 27
Hence, the maximum path sum is obtained from the path 3 -&gt; 6 -&gt; 9 -&gt; 0 -&gt; -1 -&gt; 10, giving 27.
Input: root = [3, 4, 1, -10, 4, N, N]  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; 
Output: 12
Explanation:The leaf nodes are -10, 4 (right child of 4), and 1.
Possible paths between leaf nodes are:
-10 -&gt; 4 -&gt; 4 = -10 + 4 + 4 = -2
-10 -&gt; 4 -&gt; 3 -&gt; 1 = -10 + 4 + 3 + 1 = -2
4 -&gt; 4 -&gt; 3 -&gt; 1 = 4 + 4 + 3 + 1 = 12
Hence, the maximum path sum is obtained from the path 4 -&gt; 4 -&gt; 3 -&gt; 1, giving 12.