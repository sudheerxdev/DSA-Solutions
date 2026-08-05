<h2><a href="https://www.geeksforgeeks.org/problems/count-the-number-of-subarrays/1">Subarrays with Sum in Range</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given an integer array <strong>arr[]</strong> and two integers <strong>l</strong> and <strong>r</strong>, find the number of subarrays whose sum lies in the range [l, r] (inclusive).</span></p>
<p><span style="font-size: 18px;">A subarray is a contiguous sequence of elements within the array.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> l = 3, r = 8, arr[] = [1, 4, 6]
<strong>Output: </strong>3
<strong>Explanation: </strong>The subarrays are [1,4], [4] and [6]. Therefore answer for this test case is 3.
</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> l = 4, r = 13, arr[] = [2, 3, 5, 8]
<strong>Output: </strong>6
<strong>Explanation: </strong>The subarrays are [2, 3], [2, 3, 5], [3, 5], [5], [5, 8] and [8]. <br>Therefore answer for this test case is 6.
</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ arr.size() ≤ 10<sup>5</sup><br>1 ≤ arr[i] ≤ 10<sup>4</sup><br>1 ≤ l ≤ r ≤ 10<sup>9</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>sliding-window</code>&nbsp;<code>Arrays</code>&nbsp;