<h2><a href="https://www.geeksforgeeks.org/problems/print-anagrams-together/1">Print Anagrams Together</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given an array <strong>arr[]</strong> of strings, group together all strings that are <strong>anagrams</strong> of each other.</span></p>
<p><span style="font-size: 18px;">Two strings are anagrams if they contain the same characters with the same frequencies, possibly in a different order.</span></p>
<p><span style="font-size: 18px;">The strings within each group must appear in the same order as they occur in the input array.</span></p>
<p><span style="font-size: 18px;">Return a 2D array where each inner array represents a group of anagrams.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = ["act", "god", "cat", "dog", "tac"]
<strong>Output: </strong>[["act", "cat", "tac"], ["god", "dog"]]<strong>
Explanation: </strong>There are 2 groups of anagrams "god", "dog" make group 1. "act", "cat", "tac" make group 2.</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input: </strong>arr[] = ["no", "on", "is"]
<strong>Output: </strong>[["is"], ["no", "on"]]<strong>
Explanation: </strong>There are 2 groups of anagrams "is" makes group 1. "no", "on" make group 2.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input</strong>: arr[] = ["listen", "silent", "enlist", "abc", "cab", "bac", "rat", "tar", "art"]<br><strong>Output</strong>: [["abc", "cab", "bac"], ["listen", "silent", "enlist"], ["rat", "tar", "art"]]<br><strong>Explanation</strong>: <br>Group 1: "abc", "bac", and "cab" are anagrams.
Group 2: "listen", "silent", and "enlist" are anagrams.
Group 3: "rat", "tar", and "art" are anagrams.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ arr.size() ≤ 10<sup>4</sup><br></span><span style="font-size: 18px;">1 ≤ arr[i].size() ≤ 20</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Morgan Stanley</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Snapdeal</code>&nbsp;<code>D-E-Shaw</code>&nbsp;<code>Goldman Sachs</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Hash</code>&nbsp;<code>Strings</code>&nbsp;<code>Data Structures</code>&nbsp;