class Solution {
  public:
    int countWays(string &s1, string &s2) {
        // code here
        const int n = s1.length();
        const int m = s2.length();
        const int MOD = 1000000007;
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i <= n; ++i) 
            dp[i][0] = 1;
        
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                }
                else
                    dp[i][j] = (dp[i - 1][j]) % MOD;
            }
        }
        
        return dp[n][m];
    }
};
// Time Complexity : O(n * m)
// Space Complexity : O(n * m)
// This is a classical problem of Dynamic Programming
//GFG POTD solution for 26 June
