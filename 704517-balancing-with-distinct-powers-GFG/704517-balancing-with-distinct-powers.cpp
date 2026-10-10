//GFG POTD solution for 10 oct

class Solution {
public:
bool balancePan(int a, int b) {
while (b > 0) {
int r = b % a;

if (r == 0 || r == 1) {
b /= a;
}
else if (r == a - 1) {
b = b / a + 1;
}
else {
return false;
}
}

return true;
}
};
//for Daily POTD(Unstop/leetcode/GFG) follow @POTDunstop


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna