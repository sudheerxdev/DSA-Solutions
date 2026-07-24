<h2><a href="https://www.geeksforgeeks.org/problems/longest-consecutive-sequence-in-binary-tree/1">Longest Consecutive Path in Binary tree</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 14pt;">Given the root of a Binary Tree</span><span style="font-size: 18px;">, find the length of the <strong>longest </strong>path consisting of connected nodes such that each next node has a value exactly 1 greater than its parent.</span></p>
<p><span style="font-size: 18px;">The path must move from parent to child only and follow increasing consecutive values.</span></p>
<p><span style="font-size: 18px;">If no such path exists, return -1.</span></p>
<p><strong><span style="font-size: 18px;">Examples:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> root[] = [1, 2, 3]<br><br><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/928570/Web/Other/blobid0_1779268664.png" width="191" height="109">                                </span>
<span style="font-size: 18px;"><strong>Output:</strong> 2</span>
<span style="font-size: 18px;"><strong>Explanation : </strong>Longest sequence is 1, 2. So answer for this test case is 2.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input : </strong>root[] = [10, 20, 30, 40, N, 60, 90]<br><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/928570/Web/Other/blobid2_1779268917.png" width="266" height="175"></span>
<span style="font-size: 18px;"><strong>Output : </strong>-1</span>
<span style="font-size: 18px;"><strong>Explanation: </strong>For the above test case no sequence is possible. So output is -1.</span></pre>
<p><span style="font-size: 18px;"></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>DFS</code>&nbsp;<code>Binary Tree</code>&nbsp;<code>Data Structures</code>&nbsp;