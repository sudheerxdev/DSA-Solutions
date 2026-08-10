<h2><a href="https://www.geeksforgeeks.org/problems/high-effort-vs-low-effort0213/1">High Effort vs Low Effort</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given two integer arrays <strong>h[]</strong> and <strong>l[]</strong>, where h[i] and l[i] denote the number of tasks that can be completed on the<strong> i-th </strong>day by performing a high-effort task and a low-effort task, respectively.</span></p>
<p><span style="font-size: 18px;">For each day, you may choose exactly one of the following:</span></p>
<ul>
<li><span style="font-size: 18px;">Perform no task.</span></li>
<li><span style="font-size: 18px;">Perform a low-effort task.</span></li>
<li><span style="font-size: 18px;">Perform a high-effort task, which can only be performed on the first day or if no task was performed on the previous day.</span><span style="font-size: 18px;"><br></span></li>
</ul>
<p><span style="font-size: 18px;">Return the maximum total number of tasks that can be completed over all days.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>h[] = [2, 8, 1], l[] = [1, 2, 1]
<strong>Output:</strong> 9
<strong>Explanation</strong>: Pick the high-effort task on day 1 and the low-effort task on day 2. Total = 8 + 1 = 9.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input</strong>: h[] = [3, 6, 8, 7, 6], l[] = [1, 5, 4, 5, 3]
<strong>Output:</strong> 20
<strong>Explanation</strong>: Pick the high-effort task on day 0 and low-effort tasks on all remaining days. Total = 3 + 5 + 4 + 5 + 3 = 20.</span></pre>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;