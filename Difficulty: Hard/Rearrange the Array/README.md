<h2><a href="https://www.geeksforgeeks.org/problems/rearrange-the-array-1639032648/1">Rearrange the Array</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Consider an array<strong> </strong></span><span style="font-size: 18px;"><strong>a[]</strong> = [1, 2, 3, ..., n] and a permutation <strong>b[]</strong> of size n containing all integers from 1 to n exactly once.</span></p>
<ul>
<li><span style="font-size: 18px;">The array b[] defines a rearrangement operation. </span></li>
<li><span style="font-size: 18px;">During a single operation, every element at position i in a[] moves to position b[i] (1-based indexing).</span></li>
<li><span style="font-size: 18px;">We must do at least one operation on a[].</span></li>
</ul>
<p><span style="font-size: 18px;">Find the <strong>minimum</strong> number of operations required for all elements to return to their original positions simultaneously, i.e., for a[] to become: </span><span style="font-size: 18px;">[1, 2, 3, ..., n] </span><span style="font-size: 18px;">again.</span></p>
<p><span style="font-size: 18px;"><strong>Note:</strong>&nbsp; The answer can be large, so return the answer <strong>modulo 10^9+7.</strong></span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> b[] = [1, 2, 3]
<strong>Output:</strong> 1
</span><span style="font-size: 18px;"><strong style="font-size: 18px;">Explanation: </strong><span style="font-size: 18px;">Initially, a[] = [1, 2, 3] and b[] = [1, 2, 3]
After one operation:<br>a[1] = 1 goes to position 1 as b[1] = 1.<br>a[2] = 2 goes to position 2.<br>a[3] = 3 goes to position 3.
so, now a[] becomes [1, 2, 3].
</span><span style="font-size: 18px;">All elements remain at their original positions. Hence, the answer is 1.</span></span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> b[] = [2, 3, 1, 5, 4]
<strong>Output:</strong> 6</span>
<span style="font-size: 18px;"><strong style="font-size: 18px;">Explanation: </strong><span style="font-size: 18px;">The sequence of arrays obtained after each operation is:
Initially : [1, 2, 3, 4, 5]
1 : [3, 1, 2, 5, 4]
2 : [2, 3, 1, 4, 5]
3 : [1, 2, 3, 5, 4]
4 : [3, 1, 2, 4, 5]
5 : [2, 3, 1, 5, 4]
6 : [1, 2, 3, 4, 5]
After 6 operations, all elements return to their original positions simultaneously. Therefore, the answer is 6.</span></span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1&nbsp;<span style="font-size: 18.6667px;">≤</span>&nbsp;n&nbsp;<span style="font-size: 18.6667px;">≤</span>&nbsp;10<sup>4<br><span style="font-size: 14pt;">a.size() = b.size() = n</span><br></sup>b[] is a permutation of integers from 1 to n.</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>DFS</code>&nbsp;<code>Prime Number</code>&nbsp;<code>LCS</code>&nbsp;<code>Algorithms</code>&nbsp;