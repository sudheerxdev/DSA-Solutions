
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                zero = i;
                break;
            }
        }

       
        auto check = [&](int step) {
            for (int i = 1; i < n; ++i) {
                int p_idx = zero + (i - 1) * step;
                int c_idx = zero + i * step;
                p_idx = (p_idx % n + n) % n;
                c_idx = (c_idx % n + n) % n;
                if (nums[p_idx] > nums[c_idx]) return false;
            }
            return true;
        };

        int ans = INT_MAX;

        // Case 1: Increasing to the right (step = 1)
        if (check(1)) {
            ans = min(ans, zero);
            ans = min(ans, n - zero + 2);
        }

        // Case 2: Increasing to the left (step = -1)
        if (check(-1)) {
            ans = min(ans, zero + 2);
            ans = min(ans, n - zero);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};



// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna