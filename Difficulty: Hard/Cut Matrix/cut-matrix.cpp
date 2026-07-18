class Solution {
public:
    static constexpr int MOD = 1000000007;
    int findWays(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> suff(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                suff[i][j] = matrix[i][j]
                           + suff[i + 1][j]
                           + suff[i][j + 1]
                           - suff[i + 1][j + 1];
            }
        }
        vector<vector<vector<int>>> dp(
            k + 1,
            vector<vector<int>>(n, vector<int>(m, 0))
        );
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (suff[r][c] > 0)
                    dp[1][r][c] = 1;
            }
        }
        for (int rem = 2; rem <= k; rem++) {
            vector<vector<int>> dpSumRow(n + 1, vector<int>(m, 0));
            vector<vector<int>> dpSumCol(n, vector<int>(m + 1, 0));
            for (int r = n - 1; r >= 0; r--) {
                for (int c = m - 1; c >= 0; c--) {
                    dpSumRow[r][c] =
                        (dp[rem - 1][r][c] + dpSumRow[r + 1][c]) % MOD;
                    dpSumCol[r][c] =
                        (dp[rem - 1][r][c] + dpSumCol[r][c + 1]) % MOD;
                }
            }
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < m; c++) {
                    if (suff[r][c] == 0)
                        continue;
                    long long totalWays = 0;
                    int next_r = findNextRow(suff, r, c, n);
                    if (next_r < n) {
                        totalWays =
                            (totalWays + dpSumRow[next_r][c]) % MOD;
                    }
                    int next_c = findNextCol(suff, r, c, m);
                    if (next_c < m) {
                        totalWays =
                            (totalWays + dpSumCol[r][next_c]) % MOD;
                    }
                    dp[rem][r][c] = totalWays;
                }
            }
        }
        return dp[k][0][0];
    }
private:
    int findNextRow(vector<vector<int>>& suff, int r, int c, int n) {
        int low = r + 1;
        int high = n;
        int ans = n;
        int target = suff[r][c];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (suff[mid][c] < target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    int findNextCol(vector<vector<int>>& suff, int r, int c, int m) {
        int low = c + 1;
        int high = m;
        int ans = m;
        int target = suff[r][c];
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (suff[r][mid] < target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
//GFG POTD solution for 18 July
