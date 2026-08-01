class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        // code here
        vector<long long>diff(n+1,0);
        
        for (int i = 0; i < a.size(); i++) {
        int start = a[i];
        int end = b[i];
        int val = k[i];
        
        diff[start] += val;           // Turn the faucet on
        if (end + 1 < n) {
            diff[end + 1] -= val;     // Turn the faucet off
        }
    }
    
    long long max_val = 0;
    long long current_val = 0;
    
    for (int i = 0; i < n; i++) {
        current_val += diff[i];
        max_val = max(max_val, current_val);
    }
    
    return max_val;
        
    }
};
//GFG POTD solution for 01 August
