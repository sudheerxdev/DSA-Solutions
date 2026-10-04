# [Perimeter of Shapes in Binary Matrix](https://www.geeksforgeeks.org/problems/find-perimeter-of-shapes/1)
## Easy
Given a binary matrix mat[][] of size n × m, where each cell contains either 0 or 1, find the total perimeter of all figures formed by cells containing 1s. Two cells are considered adjacent if they share a common side.
A single cell containing 1 has a perimeter of 4, whereas two adjacent cells containing 1 (i.e., 11) together have a perimeter of 6.
&nbsp;
Examples :
Input: mat[][] = [[0,1,0,0,0], [1,1,1,0,0], [1,0,0,0,0]]Output: 12Explanation: The five cells form a single figure. Hence, the perimeter of the figure is 12.     
Input: mat[][] = [[1,0], [1,1]]Output: 8Explanation: The two adjacent cells share one common side. Hence, the perimeter of the figure is 6.  