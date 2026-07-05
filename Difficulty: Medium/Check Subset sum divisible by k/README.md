<h2><a href="https://www.geeksforgeeks.org/problems/subset-with-sum-divisible-by-m2546/1">Check Subset sum divisible by k</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given an array <strong>arr[] </strong>of positive integers and a value <strong>k.</strong> Return <strong>true </strong>if the sum of any non-empty subset of the given array is divisible by k otherwise, return <strong>false</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [3, 1, 7, 5] , k = 6
<strong>Output: </strong>true
<strong>Explanation: </strong>If we take the subset {7, 5} then sum will be 12 which is divisible by 6.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [1, 2, 6] , k = 5
<strong>Output: </strong>false
<strong>Explanation: </strong>All possible subsets of the given set are {1}, {2}, {6}, {1, 2}, {2, 6}, {1, 6} and {1, 2, 6}. There is no subset whose sum is divisible by 5.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ arr.size(), k ≤ 10<sup>3</sup><br></span><span style="font-size: 18px;">1 ≤ arr[i] ≤ 10<sup>3</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;<code>Arrays</code>&nbsp;<code>Data Structures</code>&nbsp;