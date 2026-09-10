<h2><a href="https://www.geeksforgeeks.org/problems/number-of-subsequences-in-a-string-divisible-by-n5947/1">Count Subsequences Divisible by n</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given a numeric string <strong>s</strong> containing only digits and an integer <strong>n</strong>, count the number of non-empty subsequences of s whose numeric value is divisible by n. Return the answer modulo 1e9 + 7.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: s = "1234", n = 4
<strong>Output:</strong> 4</span>
<span style="font-size: 18px;"><strong>Explanation</strong>: The subsequences 4, 12, 24 and 124 are divisible by 4.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input</strong>: s = "330", n = 6
<strong>Output:</strong> 4</span>
<span style="font-size: 18px;"><strong>Explanation</strong>: The subsequences 30, 30, 330 and 0 are divisible by 6.</span>
</pre>
<div><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ |s| * n ≤ 10<sup>6</sup></span></div></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;