class Solution {
public:
    int dp[10][82];

    int solve(int pos, int sum) {
        if (sum < 0) return 0;
        if (pos == 0)
            return (sum == 0);

        if (dp[pos][sum] != -1)
            return dp[pos][sum];

        int ans = 0;

        for (int d = 0; d <= 9; d++) {
            ans += solve(pos - 1, sum - d);
        }

        return dp[pos][sum] = ans;
    }

    int countWays(int n, int sum) {
        memset(dp, -1, sizeof(dp));

        int ans = 0;

        // First digit cannot be zero
        for (int first = 1; first <= 9; first++) {
            ans += solve(n - 1, sum - first);
        }

        return (ans == 0) ? -1 : ans;
    }
};
//GFG POTD solution for 16 July
