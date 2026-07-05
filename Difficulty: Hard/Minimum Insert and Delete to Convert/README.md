<h2><a href="https://www.geeksforgeeks.org/problems/minimum-insertions-to-make-two-arrays-equal/1">Minimum Insert and Delete to Convert</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given two arrays <strong>a[]</strong> and <strong>b[] </strong>of size n and m respectively, find the minimum insertions and deletions on the array a[], required to make both the arrays identical.</span></p>
<ul>
<li><span style="font-size: 18px;">The array </span><span style="font-size: 18px;">b[] is sorted and all its elements are distinct.</span></li>
<li><span style="font-size: 18px;">The array a[] may or may not be sorted and may have duplicates.</span></li>
<li><span style="font-size: 18px;">Operations can be performed at any index in a[] not necessarily at the end.</span></li>
</ul>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>a[] = [1, 2, 5, 3, 1], b[] = [1, 3, 5]
<strong>Output: </strong>4
<strong>Explanation:</strong>
Delete 2 from a: a[] = [1, 5, 3, 1]
Insert 3 after 1: a[] = [1, 3, 5, 3, 1]
Delete the last two elements: a[] = [1, 3, 5]
Total operations = 1 + 1 + 2 = 4.</span>
</pre>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input: </strong><span style="font-size: 18px;">a[] = [1, 4], b[] = [1, 4]
</span><strong style="font-size: 18px;">Output : </strong><span style="font-size: 18px;">0</span></span>
<span style="font-size: 18px;"><strong>Explanation: </strong>Both the Arrays are already identical.</span>
</pre>
<p><span style="font-size: 18px;"><strong>&nbsp;</strong></span><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n, m ≤ 10<sup>5</sup><br>1 ≤ a[i], b[i] ≤ 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Google</code>&nbsp;<code>Codenation</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Hash</code>&nbsp;<code>Dynamic Programming</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;