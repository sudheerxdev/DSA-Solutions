#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
    int memo[101][102][102]; // i, last_inc, last_dec
    int n;

    int solve(int i, int last_inc, int last_dec, const vector<int>& arr) {
        if (i == n) return 0;

        if (memo[i][last_inc][last_dec] != -1) {
            return memo[i][last_inc][last_dec];
        }

        // Option 1: Skip arr[i]
        int ans = solve(i + 1, last_inc, last_dec, arr);

        // Option 2: Add arr[i] to Increasing Subsequence
        int real_inc = (last_inc == 0) ? -1 : last_inc;
        if (last_inc == 0 || arr[i] > real_inc) {
            ans = max(ans, 1 + solve(i + 1, arr[i], last_dec, arr));
        }

        // Option 3: Add arr[i] to Decreasing Subsequence
        int real_dec = (last_dec == 0) ? 101 : last_dec;
        if (last_dec == 0 || arr[i] < real_dec) {
            ans = max(ans, 1 + solve(i + 1, last_inc, arr[i], arr));
        }

        return memo[i][last_inc][last_dec] = ans;
    }

public:
    int minCount(vector<int>& arr) {
        n = arr.size();
        memset(memo, -1, sizeof(memo));

        int max_selected = solve(0, 0, 0, arr);
        return n - max_selected;
    }
};
//GFG POTD solution for 07 September
