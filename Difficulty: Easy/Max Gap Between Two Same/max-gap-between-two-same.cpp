class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        vector<int> t(26, -1);
        int ans = -1;
        
        for(int i = 0; i < s.size(); i += 1){
            char c = s[i];
            int idx = c - 'a';
            
            if(t[idx] != -1){
                ans = max(ans, i - t[idx] - 1);
            }else{
                t[idx] = i;
            }
        }
        
        return ans;
    }
};
//GFG POTD solution for 05 July
