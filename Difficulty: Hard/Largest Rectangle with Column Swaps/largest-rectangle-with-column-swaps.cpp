class Solution {
  public:
    int maxArea(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size(), ans=0;

        vector<int> h(m, 0);

        for(int i=0; i<n; i++){

          for(int j=0; j<m; j++) h[j]=mat[i][j]? h[j]+1: 0;

          vector<int> hc=h;
          sort(hc.rbegin(), hc.rend());

          for(int j=0; j<m; j++) ans=max(ans, hc[j]*(j+1));

        }

        return ans;// code here

    }
};
//GFG POTD solution for 27 August
