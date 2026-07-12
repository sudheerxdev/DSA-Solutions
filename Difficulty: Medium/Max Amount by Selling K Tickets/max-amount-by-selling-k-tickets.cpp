class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        const int MOD=1e9+7;
        // code here
        priority_queue<int>pq;
        for(int x:arr){
            pq.push(x);
        }
        long long ans=0;
        while(k-- && !pq.empty()){
            int x=pq.top();
            pq.pop();
            ans= (ans+x)%MOD;
            
            if(x>1){
                pq.push(x-1);
            }
        }
        return ans;
    }
};
//GFG POTD solution for 12 July
