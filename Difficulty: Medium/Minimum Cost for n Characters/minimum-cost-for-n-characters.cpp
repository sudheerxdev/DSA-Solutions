class Solution {
  public:
    int minCost(int n, int i, int d, int c) {
        // code here
        vector<int>dp(n+1);
        dp[1]=i;

        for(int k = 2 ; k<=n;k++){
            if(k%2==0){
                dp[k] = min(dp[k-1]+i,dp[k/2]+c);
            }
            else{
                int m = k/2;
                int n = m+1;

                int directInsert = dp[k-1]+i;
                int mulInsert = dp[m]+i+c;
                int mulDelete = dp[n]+d+c;
                dp[k] = min({directInsert,mulInsert,mulDelete});
            }
        }
        return dp[n];
    }
};

//GFG POTD solution for 31 August
