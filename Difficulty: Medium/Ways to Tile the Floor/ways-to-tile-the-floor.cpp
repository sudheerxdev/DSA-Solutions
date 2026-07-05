class Solution {
  public:
    int countWays(int n, int m) {
        // code here.
        int mod=1e9+7;

        vector<int>dp(n+1,0);

        for(int i=0;i<=n;i++){

            if(i<m)dp[i]=1;

            else if(i==m)dp[i]=2;

            else dp[i]=(dp[i-1]+dp[i-m])%mod;

        }

        return (dp[n]%mod);
    }
};
//GFG POTD solution for 27 June
