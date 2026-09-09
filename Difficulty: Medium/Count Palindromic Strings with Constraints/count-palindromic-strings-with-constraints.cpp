class Solution {
  public:
    int palindromicStrings(int n, int k) {
        // code here
        int ans = k, mod = 1e9 + 7;
        vector<vector<int>> dp(k+1, vector<int> (k+1, 1));
        for(int i=2; i<=k; i++) {
            for(int j=1; j<i; j++) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
            }
        }

        vector<int> fact(n+1, 1);
        for(int i=2; i<=n; i++) {
            fact[i] = (1ll * i * fact[i-1]) % mod;
        }


        for(int m=2; m<=n; m++) {
            int term = (1ll * dp[k-m%2][m/2] * (m%2==1 ? k : 1)) % mod; 
            ans = (ans + (1ll * term * fact[m/2]) % mod) % mod;
        }

        return ans;
    }
};
//GFG POTD solution for 01 September
