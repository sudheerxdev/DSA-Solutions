# [Palindrome with Replacement](https://www.geeksforgeeks.org/problems/palindrome-with-minimum-sum--170648/1)
## Medium
Given a string s consisting of lowercase English letters and the character '?',&nbsp; 

Replace every '?' with a lowercase English letter such that the resulting string is a palindrome. 
If it is possible to form a palindrome, return the minimum possible sum of the absolute ASCII differences between every pair of adjacent characters in the resulting string. 
If it is not possible to form a palindrome, return -1.

Examples:
Input: s = a???c??c????
Output: 4
Explanation: One optimal palindrome is "abbbccccbbba". The sum of the absolute ASCII differences between adjacent characters is 1 + 0 + 0 + 1 + 0 + 0 + 0 + 1 + 0 + 0 + 1 = 4, which is the minimum possible. 
Input: s = a???c??c???c
Output: -1
Explanation: It is not possible to replace the '?' characters to make the string a palindrome because the first and last characters are different and cannot be changed.