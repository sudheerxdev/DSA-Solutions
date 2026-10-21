
#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    int minOperations(std::string s) {
        int n = s.size();

        bool is_sorted = true;
        for (int i = 1; i < n; ++i) {
            if (s[i] < s[i - 1]) {
                is_sorted = false;
                break;
            }
        }
        if (is_sorted) return 0;

        if (n == 2) return -1;

        char min_char = s[0];
        char max_char = s[0];
        for (char c : s) {
            if (c < min_char) min_char = c;
            if (c > max_char) max_char = c;
        }

        if (s[0] == min_char || s[n - 1] == max_char) {
            return 1;
        }

        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == min_char || s[i] == max_char) {
                return 2;
            }
        }

        return 3;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna