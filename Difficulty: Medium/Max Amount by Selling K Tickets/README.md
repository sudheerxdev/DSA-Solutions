<h2><a href="https://www.geeksforgeeks.org/problems/ticket-sellers3241/1">Max Amount by Selling K Tickets</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given an integer array <strong>arr[]</strong>, where arr[i] denotes the number of tickets available with the i-th ticket seller. </span></p>
<ul>
<li><span style="font-size: 18px;">The price of each ticket is equal to the number of tickets remaining with that seller at the time of sale.&nbsp;</span></li>
<li><span style="font-size: 18px;">A seller can sell at most one ticket at a time, and after each sale, the price of the next ticket from that seller decreases by 1. </span></li>
<li><span style="font-size: 18px;">All sellers are allowed to sell <strong>at most k</strong> tickets in total. </span></li>
</ul>
<p><span style="font-size: 18px;">Find the maximum amount that can be earned by selling k tickets. </span><span style="font-size: 18px;">Return the answer modulo <strong>10<sup>9</sup>+7</strong>.</span></p>
<p><strong><span style="font-size: 18px;">Examples:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> arr[] = [4, 3, 6, 2, 4], k = 3
<strong>Output:</strong> 15
<strong>Explanation:</strong> One optimal sequence is to sell two tickets from the seller with 6 tickets (the price of first would be 6 and second 5) and one ticket from a seller with 4 tickets. This gives a total earning of 6 + 5 + 4 = 15.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> arr[] = [5, 3, 5, 2, 4, 4], k = 2
<strong>Output:</strong> 10
<strong>Explanation:</strong> One optimal sequence is to sell one ticket each from the two sellers with 5 tickets, earning 5 + 5 = 10.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ arr.size() ≤ 10<sup>5</sup><br>1 ≤ arr[i], k ≤ 10<sup>6</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>BankBazaar</code>&nbsp;<code>Linkedin</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Data Structures</code>&nbsp;