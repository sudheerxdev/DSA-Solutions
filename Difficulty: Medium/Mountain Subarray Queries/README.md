<h2><a href="https://www.geeksforgeeks.org/problems/mountain-subarray-problem/1">Mountain Subarray Queries</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given an array <strong>arr[] </strong>and a list of queries. For each query [l, r], find whether the subarray <strong>arr[l...r]</strong> is a mountain array. </span><span style="font-size: 18px;">A subarray is called a mountain array if there exists an index<strong> k (l ≤ k ≤ r) </strong>such that: </span><span style="font-size: 18px;"><strong>arr[l] ≤ arr[l + 1] ≤ ... ≤ arr[k] ≥ arr[k + 1] ≥ ... ≥ arr[r].</strong></span></p>
<ul>
<li><span style="font-size: 18px;">Elements of a Mountain subarray are first non-decreasing and then non-increasing. </span></li>
<li><span style="font-size: 18px;">A subarray that is entirely non-decreasing or entirely non-increasing is also considered a mountain.</span></li>
</ul>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [2, 3, 2, 4, 4, 6, 3, 2], queries[][] = [[0, 2], [1, 3]]
<strong>Output: </strong>[true, false]<strong>
Explanation: </strong>For query [0, 2], the subarray is [2, 3, 2]. The elements first increase and then decrease, so it forms a mountain.<br>For query [1, 3], the subarray is [3, 2, 4]. The elements decrease and then increase, so it does not form a mountain.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [2, 2, 2, 2], queries[][] = [[0, 2], [1, 3]]
<strong>Output: </strong>[true, true]<strong>
Explanation:</strong> All subarrays of the given array are mountain.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:<br></strong></span><span style="font-size: 18px;">1 &lt;= arr.size(), queries.size() &lt;= 10<sup>5<br></sup></span><span style="font-size: 18px;">1 &lt;= arr[i] &lt;= 10<sup>6</sup><br></span><span style="font-size: 18px;">0 &lt;= l &lt;= r &lt; arr.size()</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;