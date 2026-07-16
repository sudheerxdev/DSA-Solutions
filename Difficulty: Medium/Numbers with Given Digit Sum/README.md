<h2><a href="https://www.geeksforgeeks.org/problems/count-of-n-digit-numbers-whose-sum-of-digits-equals-to-given-sum0733/1">Numbers with Given Digit Sum</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given two integers <strong>n</strong> and <strong>sum</strong>, determine the number of <strong>n-digit</strong> positive integers whose digits add up to sum.</span></p>
<ul>
<li><span style="font-size: 18px;">An n-digit number cannot have leading zeros; that is, the first digit must be between 1 and 9.</span></li>
<li><span style="font-size: 18px;">If there exist no n digit number with sum of digits equal to given sum, return <strong>-1</strong>.</span></li>
</ul>
<p><strong><span style="font-size: 18px;">Examples :</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> n = 2, sum = 2
<strong>Output:</strong> 2
<strong>Explaination:</strong> The valid 2-digit numbers whose digits sum to 2 are 11 and 20.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> n = 1, sum = 10
<strong>Output:</strong> -1
<strong>Explaination: </strong></span><span style="font-size: 18px;">A single-digit number can only have a digit sum between 0 and 9.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> n = 2, sum = 10
<strong>Output:</strong> 9
<strong>Explaination: </strong>The 2-digit numbers whose digits add up to 10 are: 19, 28, 37, 46, 55, 64, 73, 82, 91.</span></pre>
<p><span style="font-size: 18px;"></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;<code>Mathematical</code>&nbsp;