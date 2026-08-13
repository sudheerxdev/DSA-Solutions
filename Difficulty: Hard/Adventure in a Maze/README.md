<h2><a href="https://www.geeksforgeeks.org/problems/adventure-in-a-maze2051/1">Adventure in a Maze</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 14pt;">Given a maze represented as an <strong>n x n</strong> grid, <strong>grid[][]</strong>, using 0-based indexing. Each cell contains one of the values 1, 2, or 3, which determines the direction(s) you are allowed to move from that cell:</span></p>
<ul>
<li><span style="font-size: 14pt;">1 - you may move Right only.</span></li>
<li><span style="font-size: 14pt;">2 - you may move Down only.</span></li>
<li><span style="font-size: 14pt;">3 - you may move Right or Down (both directions are available).</span></li>
</ul>
<p><span style="font-size: 14pt;">You start at the top-left cell (0, 0) (the Entry) and must reach the bottom-right cell (n-1, n-1) (the Exit), following the movement rule of each cell you pass through. You are never allowed to move outside the boundaries of the grid.</span></p>
<p><span style="font-size: 14pt;">The Adventure of a path is the sum of the values of all cells visited along that path (including both the entry and exit cells).</span></p>
<p><span style="font-size: 14pt;">Find the total number of distinct valid paths from Entry to Exit, and among all such paths, the maximum possible Adventure. Return the answer as [totalPaths, maxAdventure].</span></p>
<p><span style="font-size: 14pt;"><strong>Note:</strong> Return totalPaths <strong>modulo</strong> 10<sup>9</sup> + 7, maxAdventure needs no modulo, as it stays small regardless of grid size.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input:</strong> grid[][] = [[3, 2], [1, 3]]
<strong>Output:</strong> [2, 8]
<strong>Explanation:</strong>
There are 2 valid paths from [0, 0] to [1, 1]:
Path 1: [0, 0] -&gt; [0, 1] -&gt; [1, 1], values 3 + 2 + 3 = 8
Path 2: [0,0] -&gt; [1, 0] -&gt; [1, 1], values 3 + 1 + 3 = 7
The maximum Adventure among these is 8, so the output is [2, 8].</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>grid[][] = [[1, 1, 3, 2, 1], [3, 2, 2, 1, 2], [1, 3, 3, 1, 3], [1, 2, 3, 1, 2], [1, 1, 1, 3, 1]]
<strong>Output: </strong>[4, 18]
<strong>Explanation: </strong>There are 4 valid paths from Entry to Exit, with total Adventures 
18, 17, 17, and 16 respectively. The maximum among these is 18, so the output is [4, 18].
</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 ≤ n ≤ 100</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Matrix</code>&nbsp;