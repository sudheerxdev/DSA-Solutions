class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        int maxm=*max_element(arr.begin(),arr.end());
        vector<int> dp(maxm+2,0);
        for(int ele: arr){
            dp[ele]=1+max(dp[ele-1],dp[ele+1]);
        }
        return *max_element(dp.begin(),dp.end());
    }
};
//GFG POTD solution for 05 September
