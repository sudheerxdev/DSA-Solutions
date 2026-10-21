class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        // code here
       
                int curr = arr[0], ans = arr[0];
                for (int i = 1; i < arr.size(); i++) {
                    curr = min(arr[i], curr + arr[i]);
                    ans = min(ans, curr);
                }
                return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna