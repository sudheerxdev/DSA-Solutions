<h2><a href="https://www.geeksforgeeks.org/problems/minimum-time1238/1">Minimum Cost for n Characters</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given four integers <strong>n</strong>, <strong>i</strong>, <strong>d</strong>, and <strong>c</strong>, where:</span></p>
<ul>
<li><span style="font-size: 18px;">i is the cost of inserting a single character,</span></li>
<li><span style="font-size: 18px;">d is the cost of deleting the last character,</span></li>
<li><span style="font-size: 18px;">c is the cost of copying the entire current string and pasting it immediately (thereby doubling its length).</span></li>
</ul>
<p><span style="font-size: 18px;">Find the minimum cost required to obtain exactly n characters on the screen. Initially, the screen is empty.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 9, i = 1, d = 2, c = 1<strong>
Output: </strong>5<strong>
Explanation: </strong>Perform the following operations:
Insert (1 character)
Insert (2 characters)
Copy-paste (4 characters)
Copy-paste (8 characters)
Insert (9 characters)
Total cost = 1 + 1 + 1 + 1 + 1 = 5.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 9, i = 10, d = 1, c = 1<strong>
Output: </strong>17<strong>
Explanation: </strong></span><span style="font-size: 18px;">Perform the following operations:
Insert (1 character)
Copy-paste (2 characters)
Copy-paste (4 characters)
Delete (3 characters)
Copy-paste (6 characters)
Delete (5 characters)
Copy-paste (10 characters)
Delete (9 characters)
Total cost = 10 + 1 + 1 + 1 + 1 + 1 + 1 + 1 = 17.
Since insertion is expensive, it is cheaper to use copy-paste operations and adjust the length using deletions.</span></pre>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;