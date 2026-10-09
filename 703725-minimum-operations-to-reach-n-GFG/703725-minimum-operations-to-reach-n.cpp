//GFG POTD solution for 09 oct

class Solution {
public:
int minOperation(int n) {
int cnt = 0;
while (n != 0) {
if (n % 2 == 0)
n /= 2;
else
n--;
cnt++;
}
return cnt;
}
};
//For Daily POTD(Unstop/leetcode/GFG) follow @POTDunstop


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna