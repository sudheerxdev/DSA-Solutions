class Solution {
    // 'int solve(vector<int>&arr,int i,vector<int>&dp,int sum){
    //     int n =arr.size();
    //     if(i>=arr.size()) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int take = 0;
    //     if(i>0 && i<n){
    //     take = sum-(abs(1-arr[i-1]))+(abs(1-arr[i+1]));
    //     }
    //     else if(i>0){
    //         take = sum-(abs(1-arr[i-1]));
    //     }
    //     else{
    //         take = sum-(abs(1-arr[i+1]));
    //     }
    //     int change =  (abs(1-arr[i-1])+abs(1-arr[i+1]))+solve(arr,i+1,dp,take);
    //     int notchange = abs(arr[i]-arr[i-1])+abs(arr[i]-arr[i+1])+solve(arr,i+1,dp,sum);
    //     return dp[i] = max(change,notchange);
    // }'
  public:
    int maxDiffSum(vector<int>& arr) {
        // code here
        int n =arr.size();
        if(n<=1) return 0;
        int keep = 0;
        int change = 0;
        for(int i = 1;i<n;i++){
            int keepr = max(keep+abs(arr[i]-arr[i-1]),change+abs(arr[i]-1));
            int changer = max(keep+abs(1-arr[i-1]),0);

            keep = keepr;
            change = changer;
        }
        return max(keep,change);
    }
};
//GFG POTD solution for 03 September
