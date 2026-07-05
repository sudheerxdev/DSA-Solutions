<h2><a href="https://www.geeksforgeeks.org/problems/count-the-number-of-ways-to-tile-the-floor-of-size-n-x-m-using-1-x-m-size-tiles0509/1">Ways to Tile the Floor</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given a floor of dimensions <strong>n × m</strong> and an unlimited supply of tiles of size <strong>1 × m</strong>, find the total number of ways to completely tile the floor.<br></span><span style="font-size: 18px;">Each tile can be placed in one of the following ways:</span></p>
<ul>
<li><span style="font-size: 18px;">Horizontally, covering 1 row and m columns.</span></li>
<li><span style="font-size: 18px;">Vertically, covering m rows and 1 column.</span></li>
</ul>
<p><span style="font-size: 18px;">Count all possible ways to cover the entire floor such that there are no overlaps and no uncovered cells.</span></p>
<p><span style="font-size: 18px;">Since the number of possible tilings can be very large, return the answer modulo <strong>10<sup>9</sup>+7</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Note:</strong> n and m are positive integers, and m ≥ 2.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 4, m = 4
<strong>Output: </strong>2
<strong>Explanation: </strong>There are exactly two valid ways to tile the floor. <br><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/704694/Web/Other/blobid0_1782463809.png" width="356" height="201"></span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 2, m = 3
<strong>Output: </strong>1
</span><strong><span style="font-size: 18px;">Explanation: </span></strong><span style="font-size: 18px;">Placing a tile vertically would require a height of 3, which exceeds the floor's height of 2. The only way to cover the entire floor is by placing 2 horizontally, one in each row, resulting in exactly one valid tiling. </span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n ≤ 10<sup>5</sup></span><br><span style="font-size: 18px;">2 ≤ m ≤ 10<sup>5</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;