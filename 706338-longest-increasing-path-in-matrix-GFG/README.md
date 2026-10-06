# [Longest Increasing Path in Matrix](https://www.geeksforgeeks.org/problems/longest-increasing-path-in-a-matrix/1)
## Hard
Given a matrix with&nbsp;n&nbsp;rows and&nbsp;m&nbsp;columns. Your task is to find the length of the longest path in with the following constraints

The values in path strictly increasing.&nbsp; For example if a path of length k has values a1, a2, a3, .... ak&nbsp; , then for every i from [2, k] this condition must hold ai&nbsp;&gt; ai-1.&nbsp; 
No cell should be revisited in the path.
From each cell,&nbsp; you can move in any of of the four directions: left, right, up, or down. 
You are not allowed to move diagonally or move outside the boundary.

Examples:
Input: n = 3, m = 3, matrix[][] = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: 5
Explanation: One such path is 1 -&gt; 2 -&gt; 3 -&gt; 6 -&gt; 9, where each number is strictly greater than the previous.
Input: n = 3, m = 3, matrix[][] = [[3, 4, 5], [6, 2, 6], [2, 2, 1]]
Output: 4
Explanation: One of the longest increasing paths is 3 -&gt; 4 -&gt; 5 -&gt; 6.