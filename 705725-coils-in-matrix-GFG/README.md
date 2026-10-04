# [Coils in Matrix](https://www.geeksforgeeks.org/problems/form-coils-in-a-matrix4726/1)
## Medium
Given a positive integer n, consider a 4n * 4n matrix filled with integers from 1 to (4n) * (4n) in row-major order (left to right, top to bottom). Form two coils from the matrix:The first coil starts from the top-left cell (0, 0) and spirals inward.The second coil starts from the bottom-right cell (4n - 1, 4n - 1) and spirals inward in the opposite direction.Return these two coils in the same order.Examples:Input: n = 1Output: [[1, 5, 9, 13, 14, 15, 11, 7], [16, 12, 8, 4, 3, 2, 6, 10]] 
Explanation: The matrix is 
 So, the two coils are as given in the Output.Input: n = 2
Output:
[[1, 9, 17, 25, 33, 41, 49, 57, 58, 59, 60, 61, 62, 63, 55, 47, 39, 31, 23, 15, 14, 13, 12, 11, 19, 27, 35, 43, 44, 45, 37, 29],  [64, 56, 48, 40, 32, 24, 16, 8, 7, 6, 5, 4, 3, 2, 10, 18, 26, 34, 42, 50, 51, 52, 53, 54, 46, 38, 30, 22, 21, 20, 28, 36]]  
Explanation:
 
