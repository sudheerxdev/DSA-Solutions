<h2><a href="https://www.geeksforgeeks.org/problems/largest-zigzag-sequence5416/1">Largest Zigzag Sequence</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 14pt;">Given a square matrix <strong>mat[][]</strong> of size <strong>n × n</strong></span><span style="font-size: 18.6667px;">. A zigzag sequence starts from the top and ends at the bottom. Two consecutive elements of sequence cannot belong to the same column. </span></p>
<p><span style="font-size: 14pt;">Return the </span><span style="font-size: 14pt;">maximum</span><span style="font-size: 14pt;"> sum of such a zigzag sequence.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>mat[][] = [[3, 1, 2], [4, 8, 5], [6, 9, 7]]<strong>
Output: </strong>18<strong>
Explanation:<br></strong><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/929925/Web/Other/blobid5_1782911641.png" alt="" width="197" height="143"><strong><br></strong>One optimal zigzag sequence is: 3 -&gt; 8 -&gt; 7, where the sum = 3 + 8 + 7 = 18.<br></span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>mat[][] = [[1, 2, 4], [3, 9, 6], [11, 3, 15]]<strong>
Output: </strong>28<strong>
Explanation:<br></strong><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/929925/Web/Other/blobid8_1782911811.png" alt="" width="197" height="143">
One optimal zigzag sequence is: 4 -&gt; 9 -&gt; 15, where the sum = 4 + 9 + 15 = 28.</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 ≤ n ≤ 100<br>1 ≤ mat[i][j] ≤ 1000&nbsp;</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Directi</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;