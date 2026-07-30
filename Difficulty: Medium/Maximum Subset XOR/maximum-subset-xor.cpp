class Solution {
  public:
    int maxSubsetXOR(vector<int> &arr) {
        // code here
        int N = arr.size();
        int maxX = arr[0];
        for (int i = 1; i < N; i++) {
            if (arr[i] > maxX) maxX = arr[i];
        }
        
        if (maxX == 0) return 0;
        
        int ans = 0;        
        while (true) {
            ans = max(ans, ans^maxX);            
            for (int i = 0; i < N; i++) arr[i] = min(arr[i], arr[i]^maxX);
            
            maxX = arr[0];
            for (int i = 0; i < N; i++) maxX = max(maxX, arr[i]);
            if (maxX == 0) break;            
        }
        
        return ans;        
    }
};
//GFG POTD solution for 30 July
