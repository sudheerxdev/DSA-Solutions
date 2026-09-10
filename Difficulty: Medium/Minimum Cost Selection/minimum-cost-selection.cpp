class Solution {
  public:
    int dp[100001][4];
    int func(int level,int prev,vector<vector<int>>&mat,int n)
    {
        if(level==n)
        {
            return 0;
        }
        if(dp[level][prev]!=-1)
        {
            return dp[level][prev];
        }
        int ans=INT_MAX;
        for(int i=0;i<=2;i++)
        {
            if(i!=prev)
            {
                int p=func(level+1,i,mat,n);
                if(p!=INT_MAX)
                {
                    ans=min(ans,p+mat[level][i]);
                }
            }
        }
        return dp[level][prev]=ans;
    }
    int minCost(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        memset(dp,-1,sizeof(dp));
        int ans=func(0,3,mat,n);
        return ans;
    }
};
//GFG POTD solution for 28 August
