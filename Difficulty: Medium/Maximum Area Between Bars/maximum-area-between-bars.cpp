class Solution {
  public:
    int maxArea(vector<int> &height) {
        int l =0;
        int n =height.size();
        int r= n-1;
        int ans =0;
        while(l<r) {
            int k = min(height[l],height[r])*(r-l-1);
            ans = max(ans,k);
            if (height[l]>height[r]) r--;
            else l++;
        }
        return ans;
        
        
    }
};
//GFG POTD solution for 22 June
