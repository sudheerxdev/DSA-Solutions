class Solution {
  public:

      map<int, pair<int,int>> dirs{
      {1, {1, 0}},
      {2, {-1, 0}},
      {3, {0, 1}},
      {4, {0, -1}},
      {5, {1, 1}},
      {6, {-1, -1}},
      {7, {1, -1}},
      {8, {-1, 1}}
      };



      bool helper(vector<vector<char>> &mat, string &word,int i,int j,int k,int d){
          int n=mat.size(),m=mat[0].size(),len=word.size();

          if(k==len) return 1;

          if(d==0){
              for(auto x:dirs){
                  int ni=i+x.second.first, nj=j+x.second.second;
                  if(ni<0 || ni==n || nj<0 || nj==m || mat[ni][nj]!=word[k]) continue;
                  if(helper(mat,word,ni,nj,k+1,x.first)) return 1;
              }
          }
          else{
              int ni=i+dirs[d].first,nj=j+dirs[d].second;
              if(ni<0 || ni==n || nj<0 || nj==m || mat[ni][nj]!=word[k]) return 0;
              if(helper(mat,word,ni,nj,k+1,d)) return 1;
          }
          return 0;
      }

      vector<vector<int>> searchWord(vector<vector<char>> mat, string word) {
          // Code here

          int n=mat.size(),m=mat[0].size();
          vector<vector<int>> res;

          for(int i=0;i<n;i++){
              for(int j=0;j<m;j++){
                  if(mat[i][j]==word[0] && helper(mat,word,i,j,1,0)) res.push_back({i,j});
              }
          }
          sort(res.begin(),res.end());
          return res;

      }
};
//GFG POTD solution for 08 September
