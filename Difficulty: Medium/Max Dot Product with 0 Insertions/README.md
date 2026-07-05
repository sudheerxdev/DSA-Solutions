<h2><a href="https://www.geeksforgeeks.org/problems/maximize-dot-product2649/1">Max Dot Product with 0 Insertions</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given two arrays <strong>a[]</strong> and <strong>b[]</strong></span><span style="font-size: 18px;"> </span><span style="font-size: 18px;">of positive integers</span><span style="font-size: 18px;"> </span><span style="font-size: 18px;">of size <strong>n</strong> and <strong>m</strong> respectively, where <strong>m </strong></span><strong><span style="font-size: 18px;">≤ n</span></strong><span style="font-size: 18px;">.&nbsp;&nbsp;</span><span style="font-size: 18px;">You are allowed to insert zeros anywhere into the second array <strong>b </strong>so that its length becomes equal to <strong>n</strong>. </span></p>
<ul>
<li><span style="font-size: 18px;">The dot product of two arrays of equal length n is defined as:&nbsp;</span><span style="font-size: 18px;">a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1]. </span></li>
<li><span style="font-size: 18px;">Return the <strong>maximum </strong>possible dot product of the two arrays.</span></li>
</ul>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: a[] = [2, 3, 1, 7, 8], b[] = [3, 6, 7]
<strong>Output:</strong> 107
<strong>Explanation</strong>: Maximum dot product is obtained after inserting 0 at the first and third positions in array b.<br>Therefore b becomes [0, 3, 0, 6, 7]. 
Maximum dot product = 2*0 + 3*3 + 1*0 + 7*6 + 8*7 = 107. Therefore answer for this test case is 107.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input</strong>: a[] = [1, 2, 3], b[] = [4] 
<strong>Output:</strong> 12 
<strong>Explanation</strong>: Maximum dot product is obtained after inserting 0 at the first and second positions in array b.<br>Therefore b becomes [0, 0, 4]. 
Maximum Dot Product = 1*0 + 2*0 + 3*4 = 12. Therefore answer for this test case is 12.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ m ≤ n ≤ 10<sup>3</sup></span><br><span style="font-size: 18px;">1 ≤ a[i], b[i] ≤ 10<sup>3</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Directi</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;