class Solution {
  public:
    int X[4]={-1, 0, 1, 0};
    int Y[4]={0, 1, 0, -1};

    virtual bool isSafe(int i, int j, int n, int m, vector<vector<int>> &mat, vector<vector<bool>> &visited){
      if(i<0 || i>=n || j<0 || j>=m || mat[i][j]==0 || visited[i][j]) return false;

      if(i>0 && mat[i-1][j]==0) return false;
      if(i<(n-1) && mat[i+1][j]==0) return false;
      if(j>0 && mat[i][j-1]==0) return false;
      if(j<(m-1) && mat[i][j+1]==0) return false; 


      return true;
    }

    virtual int shortestPath(vector<vector<int>> &mat){
      queue<pair<int, pair<int, int>>> q;             


      int n=mat.size();
      int m=mat[0].size();


      vector<vector<bool>> visited(n, vector<bool>(m, false));

      for(int i=0; i<n; i++) if(isSafe(i, 0, n, m, mat, visited)){
                                    q.push({1, {i, 0}});
                                    visited[i][0]=true; }

      while(!q.empty()){
        auto fr=q.front(); q.pop();

        int cost=fr.first;
        int x=(fr.second).first;
        int y=(fr.second).second;

        if(y==m-1) return cost;

        for(int k=0; k<4; k++){
          int xk=x+X[k];
          int yk=y+Y[k];

          if(isSafe(xk, yk, n, m, mat, visited)){
                                    q.push({cost+1, {xk, yk}});
                                    visited[xk][yk]=true; }

        }

      }

      return -1;                     
    }
};
//GFG POTD solution for 14 September
