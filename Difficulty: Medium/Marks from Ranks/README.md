<h2><a href="https://www.geeksforgeeks.org/problems/find-marks-from-ranks/1">Marks from Ranks</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 14pt;">Consider an input where all marks obtained are divided into intervals of consecutive numbers<strong> </strong>represented as </span><span style="font-size: 14pt;"><strong>l[]</strong> and <strong>r[] </strong>where l[i] and r[i] represent the starting and ending marks (inclusive) of the i-th interval.&nbsp;</span></p>
<ul>
<li><span style="font-size: 14pt;">The intervals are sorted in increasing order and do not overlap. </span></li>
<li><span style="font-size: 14pt;">The rank of a mark is defined by its position among all valid marks in increasing order, with the smallest mark assigned rank 1, the next smallest rank 2, and so on.</span></li>
</ul>
<p><span style="font-size: 14pt;">Given an array <strong>rank[]</strong>. for each value in rank[], find the corresponding mark and return as an array.</span></p>
<p><strong>Examples:</strong></p>
<pre><span style="font-size: 18.6667px;"><strong>Input: </strong>l[] = [1, 6, 14], r[] = [3, 9, 15], rank[] = [2, 5, 8]<strong>
Output: </strong>[2, 7, 14]<strong>
Explanation: </strong></span><span style="font-size: 18.6667px;">The valid marks are 1, 2, 3, 6, 7, 8, 9, 14, 15. Their corresponding ranks are 1 to 9 as there are 9 distinct marks. Therefore, rank 2 corresponds to mark 2, rank 5 corresponds to mark 7, and rank 8 corresponds to mark 14.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>l[] = [5, 10], r[] = [7, 12], rank[] = [1, 4, 6]<strong>
Output: </strong>[5, 10, 12]<strong>
Explanation: </strong>The valid marks are 5, 6, 7, 10, 11, 12. Their corresponding ranks are 1 to 6 in increasing order. Hence, rank 1 corresponds to mark 5, rank 4 corresponds to mark 10, and rank 6 corresponds to mark 12.</span></pre></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Searching</code>&nbsp;