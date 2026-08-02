<h2><a href="https://www.geeksforgeeks.org/problems/count-in-array2138/1">Sequences where Adjacent Divide</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given two positive integer&nbsp;<strong>n</strong> and <strong>m.</strong> Find the number of arrays of size n that can be formed such that:</span></p>
<ul>
<li><span style="font-size: 18px;">Each element is in the range [1, m].</span></li>
<li><span style="font-size: 18px;">All adjacent are such that one of them divide the another i.e element A<sub>i</sub>&nbsp;divides A<sub>i + 1&nbsp;</sub>or A<sub>i+1</sub>&nbsp;divides A<sub>i</sub>.</span></li>
</ul>
<p><strong><span style="font-size: 18px;">Examples:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> n = 3, m = 3
<strong>Output :</strong> 17
<strong>Explanation: </strong>The possible arrays are [1, 1, 1], [1, 1, 2], [1, 1, 3], [1, 2, 1], [1, 2, 2], [1, 3, 1], [1, 3, 3], [2, 1, 1], [2, 1, 2], [2, 1, 3], [2, 2, 1], [2, 2, 2], [3, 1, 1], [3, 1, 2], [3, 1, 3], [3, 3, 1] and [3, 3, 3].
</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 1, m = 10 
<strong>Output:</strong> 10
<strong>Explanation: </strong><span style="font-size: 14pt;">The possible arrays are </span></span><span style="font-size: 14pt;">[1], [2], [3], [4], [5], [6], [7], [8], [9] and [10].</span></pre>
<p><span style="font-size: 18px;"></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Modular Arithmetic</code>&nbsp;