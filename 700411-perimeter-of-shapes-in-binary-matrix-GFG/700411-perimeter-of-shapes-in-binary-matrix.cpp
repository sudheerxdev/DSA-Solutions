class Solution {
  public:
    int findPerimeter(vector<vector<int>> &mat) {
        // code here
        int m=mat.size(),n=mat[0].size();

        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    ans+=4;
                    if(j+1<n && mat[i][j+1]==1)ans-=2;
                    if(i+1<m && mat[i+1][j]==1)ans-=2;
                }
            }
        }
        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna