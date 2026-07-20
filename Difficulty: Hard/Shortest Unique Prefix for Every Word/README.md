<h2><a href="https://www.geeksforgeeks.org/problems/shortest-unique-prefix-for-every-word/1">Shortest Unique Prefix for Every Word</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p data-start="23" data-end="171"><span style="font-size: 14pt;">Given an array of strings <strong>arr[ ]</strong>, find the shortest prefix of each string that uniquely identifies it among all strings in the array. </span><span style="font-size: 14pt;">A prefix<strong> </strong>is unique if it is not a prefix of any other string in the array. </span></p>
<p data-start="333" data-end="396"><span style="font-size: 14pt;"><strong data-start="333" data-end="342">Note:</strong> No string in the given array is a prefix of another string.</span></p>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = ["zebra", "dog", "duck", "dove"]
<strong>Output: </strong>["z", "dog", "du", "dov"]
<strong>Explanation: </strong>z =&gt; zebra, dog =&gt; dog, duck =&gt; du, dove =&gt; dov </span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = ["geeksgeeks", "geeksquiz", "geeksforgeeks"]
<strong>Output: </strong>["geeksg", "geeksq", "geeksf"]<br><strong>Explanation: </strong>geeksgeeks =&gt; geeksg, geeksquiz =&gt; geeksq, geeksforgeeks =&gt; geeksf<br></span></pre>
<div><span style="font-size: 18px;"></span></div></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Microsoft</code>&nbsp;<code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Trie</code>&nbsp;<code>Advanced Data Structure</code>&nbsp;