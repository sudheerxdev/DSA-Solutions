//GFG POTD solution for 22 oct
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int minimumSum(string &s) {
        int n = s.length();

        // Step 1: Check feasibility and resolve forced '?'
        for (int i = 0; i < n / 2; ++i) {
            int j = n - 1 - i;
            if (s[i] != '?' && s[j] != '?' && s[i] != s[j]) {
                return -1;
            }
            if (s[i] == '?' && s[j] != '?') {
                s[i] = s[j];
            } else if (s[i] != '?' && s[j] == '?') {
                s[j] = s[i];
            }
        }

        // Step 2: Collect anchors in the first half (0 to n/2)
        vector<char> anchors;
        for (int i = 0; i <= n / 2; ++i) {
            if (s[i] != '?') {
                anchors.push_back(s[i]);
            }
        }

        // If no anchors exist, we can set all characters to 'a' with 0 cost
        if (anchors.empty()) {
            return 0;
        }

        // Step 3: Calculate sum of absolute differences between consecutive anchors
        int first_half_cost = 0;
        for (size_t i = 0; i + 1 < anchors.size(); ++i) {
            first_half_cost += abs(anchors[i] - anchors[i + 1]);
        }

        // Total cost is 2 * first_half_cost due to palindrome symmetry
        return 2 * first_half_cost;
    }
};
//for Daily POTD(Unstop/leetcode/GFG) follow @POTDunstop


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna