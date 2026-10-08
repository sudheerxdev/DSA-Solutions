//GFG POTD solution for 08 oct

class Solution {
public:
int maxFrequency(vector<int>& arr, int k) {
sort(arr.begin(), arr.end());
long long windowSum = 0;
int left = 0;
int ans = 1;
for (int right = 0; right < arr.size(); right++) {
windowSum += arr[right];
while (1LL * arr[right] * (right - left + 1) - windowSum > k) {
windowSum -= arr[left];
left++;
}
ans = max(ans, right - left + 1);
}
return ans;
}
};
//for Daily POTD(Unstop/leetcode/GFG) follow @POTDunstop


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna