class Solution {
  public:
  void dfs(vector<vector<int>> &mat,vector<vector<int>> &grid,int i,int j,int m,int n,
    int prev){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==1 || mat[i][j]<prev) return;
        grid[i][j]=1;
        prev = mat[i][j];
        
        dfs(mat,grid,i-1,j,m,n,prev);
        dfs(mat,grid,i+1,j,m,n,prev);
        dfs(mat,grid,i,j-1,m,n,prev);
        dfs(mat,grid,i,j+1,m,n,prev);
    }
    int countCoordinates(vector<vector<int>>& mat) {
        // code here
        int m=mat.size();
        int n=mat[0].size();
        
        vector<vector<int>> io(m,vector<int>(n,0));
        vector<vector<int>> as(m,vector<int>(n,0));
        int prev = -1;
        for(int i=0;i<m;i++){
            if(!io[i][0]) dfs(mat,io,i,0,m,n,prev);
            if(!as[i][n-1]) dfs(mat,as,i,n-1,m,n,prev);
        }
        for(int i=0;i<n;i++){
            if(!as[m-1][i]) dfs(mat,as,m-1,i,m,n,prev);
            if(!io[0][i]) dfs(mat,io,0,i,m,n,prev);
        }
        int v=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(io[i][j] && as[i][j]) v++;
            }
        }
        return v;
    }
};
//GFG POTD solution for 08 July
