<h2><a href="https://www.geeksforgeeks.org/problems/find-smallest-non-zero-number4510/1">Smallest Non-Zero Number</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 14pt;">Given an array <strong>arr[],</strong> find the smallest number x such that when x is processed sequentially with each element of the array (from index 0 to n-1), it <strong>never becomes negative</strong>, under the following conditions:</span></p>
<ol>
<li><span style="font-size: 14pt;">If x is greater than the current array element, x is <strong>increased</strong> by the difference between x and the array element.</span></li>
<li><span style="font-size: 14pt;">If x is less than or equal to the current array element, x is <strong>decreased</strong> by the difference between the array element and x.</span></li>
</ol>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>arr[] = [3, 4, 3, 2, 4]
<strong>Output:</strong> 4
<strong>Explanation</strong>: Start with x = 4:
- For arr[0] = 3, x becomes 5.
- For arr[1] = 4, x becomes 6.
- For arr[2] = 3, x becomes 9.
- For arr[3] = 2, x becomes 16.
- For arr[4] = 4, x becomes 28.<br>x remains positive throughout the process.
If x &lt; 4, it would become negative at some point.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>arr[] = [4, 4]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Start with x = 3:
- For arr[0] = 4, x becomes 2.
- For arr[1] = 4, x becomes 0.<br>x remains non-negative. If x &lt; 3, it would become negative.</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 ≤ arr.size() ≤ 10<sup>6<br></sup>1&lt;= arr[i] &lt;= 10<sup>4</sup><sup><br></sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Data Structures</code>&nbsp;