<h2><a href="https://www.geeksforgeeks.org/problems/count-ways-to-increase-lcs-length-of-two-strings-by-one2236/1">Ways to Increase LCS by One</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given two strings <strong>s1</strong> and <strong>s2</strong> consisting of lowercase English letters of length <strong>n1</strong> and <strong>n2</strong> respectively, find the number of ways to insert exactly one character into string s1 such that the length of the Longest Common Subsequence (LCS) of both strings increases by exactly 1.</span><br><br><strong><span style="font-size: 18px;">Examples :</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s1 = "abab", s2 = "abc"
<strong>Output: </strong>3
<strong>Explanation: </strong></span><span style="font-size: 18px;">The LCS length of the given two strings is 2. There are 3 valid insertions in s1 which increase the LCS length to 3:
"abcab" -&gt; LCS = 3
"abacb" -&gt; LCS = 3
"ababc" -&gt; LCS = 3</span></pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>s1 = "abcabc", s2 = "abcd"<strong>
Output: </strong>4<strong>
Explanation: </strong></span><span style="font-size: 18px;">The LCS length of the given two strings is 3. There are 4 valid insertions in s1 which increase the LCS length to 4:
"abcdabc" -&gt; LCS = 4
"abcadcb" -&gt; LCS = 4
"abcabdc" -&gt; LCS = 4
"abcabcd" -&gt; LCS = 4</span>
</pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong></span><br><span style="font-size: 18px;">1&lt;= n1, n2 &lt;=100<br></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Algorithms</code>&nbsp;