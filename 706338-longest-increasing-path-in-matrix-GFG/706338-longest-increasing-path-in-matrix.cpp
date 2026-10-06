class Solution {
  public:
    int longIncPath(vector<vector<int>> &matrix, int n, int m) {
        vector<vector<int>> dp(n, vector<int>(m, 0));

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        function<int(int,int)> dfs = [&](int x, int y) {
            if (dp[x][y] != 0)
                return dp[x][y];

            dp[x][y] = 1;  // Path containing only this cell

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && nx < n &&
                    ny >= 0 && ny < m &&
                    matrix[nx][ny] > matrix[x][y]) {

                    dp[x][y] = max(dp[x][y],
                                   1 + dfs(nx, ny));
                }
            }

            return dp[x][y];
        };

        int ans = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(i, j));
            }
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna