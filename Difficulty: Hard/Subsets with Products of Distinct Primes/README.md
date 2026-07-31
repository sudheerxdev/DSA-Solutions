<h2><a href="https://www.geeksforgeeks.org/problems/game-of-subsets/1">Subsets with Products of Distinct Primes</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given an </span><span style="font-size: 18px;">integer </span><span style="font-size: 18px;">array </span><strong style="font-size: 18px;">arr[]</strong><span style="font-size: 18px;">, count the number of different subsets whose </span><span style="font-size: 18px;">product can be represented as a product of one or more distinct<strong> </strong>prime numbers.&nbsp; Two subsets are</span><span style="font-size: 18px;"> considered different if the set of chosen array indexes are not same.</span></p>
<p><span style="font-size: 18px;">Return the count modulo 10<sup>9</sup> + 7.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [1, 2, 3, 4]
<strong>Output: </strong>6
<strong>Explanation: <br></strong>The subsets are:
[2], product = 2 = 2
[3], product = 3 = 3
[1, 2], product = 2 = 2
[1, 3], product = 3 = 3
[2, 3], product = 6 = 2 × 3
[1, 2, 3], product = 6 = 2 × 3
All these products can be expressed as a product of one or more distinct prime numbers. Hence, the count is 6.<br>Note that [4] or any other subset with 4 are not chosen because prducts having 4 have repeated primes 2.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = [2, 2, 3]<strong>
Output: </strong>5<strong>
Explanation: <br></strong>Since subsets formed using different indices are considered different, the chosen subsets are:
[2] (using the first 2)
[2] (using the second 2)
[3]
[2, 3] (using the first 2)
[2, 3] (using the second 2)
Each subset has a product that can be expressed as a product of one or more distinct prime numbers. <br>Therefore, the answer is 5.</span></pre>
<p><span style="font-size: 18px;"><strong></strong></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Bit Magic</code>&nbsp;