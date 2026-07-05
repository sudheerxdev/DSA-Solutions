class Solution {
  public:
   bool solve(int rem, int idx, vector<int>& arr, int k,
               vector<vector<int>>& dp)
    {
        if (idx >= arr.size())
        {
            return false;
        }

        if (dp[rem][idx] != -1)
        {
            return dp[rem][idx];
        }

        int newRem = (rem + arr[idx]) % k;

        if (newRem == 0)
        {
            return dp[rem][idx] = true;
        }

        bool take = solve(newRem, idx + 1, arr, k, dp);
        bool skip = solve(rem, idx + 1, arr, k, dp);

        return dp[rem][idx] = take || skip;
    }

    bool divisibleByK(vector<int>& arr, int k) 
    {
        int n = arr.size();

        vector<vector<int>> dp(k, vector<int>(n, -1));

        return solve(0, 0, arr, k, dp);
    }
};
//GFG POTD solution for 02 July
