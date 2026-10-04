class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                low++;
                high++;
            } else if (s[i] == ')') {
                if (low > 0) {
                    low--;
                }
                high--;
            } else {
                if (low > 0) {
                    low--;
                }
                high++;
            }

            if (high < 0) {
                return false;
            }
        }
        return low == 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna