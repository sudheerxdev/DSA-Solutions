class Solution {
  public:
    int dp[100005][2];
    int recur(vector<int>& h, vector<int>& l, int index, int canTake) {
        
        if(index>=h.size()) return 0;
        if(dp[index][canTake]!=-1) return dp[index][canTake];
        
        
        int op1=INT_MIN,op2=INT_MIN,op3=INT_MIN;
        // leave dont take anything on this day
        op1 = recur(h,l,index+1,1);
        // take high effort task on this day
        if(canTake) op2 = h[index] + recur(h,l,index+1,0);
        // take low effort task on this day
        op3 = l[index] + recur(h,l,index+1,0);
        
        return dp[index][canTake] = max({op1,op2,op3});
    }  
    int maxTask(vector<int>& h, vector<int>& l) {
        memset(dp,-1,sizeof(dp));
        return recur(h,l,0,1);
    }
};
//GFG POTD solution for 10 August
