class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        // code here
       
         vector<pair<int,int>>adj[V];
         for(int i=0;i<edges.size();i++)
         {
             int u=edges[i][0];
              int v=edges[i][1];
               int w=edges[i][2];
               adj[u].push_back({v,w});
               adj[v].push_back({u,w});
         }
         vector<int>dis(V,INT_MAX);
         dis[src]=0;
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
         p.push({0,src});
          while(!p.empty())
          {
                int d=p.top().first;
                int node=p.top().second;
                p.pop();
                for(int i=0;i<adj[node].size();i++)
                {
                      int nei=adj[node][i].first;
                      int w=adj[node][i].second;
                      if(w+d<dis[nei])
                      {
                         dis[nei]=w+d;
                         p.push({dis[nei],nei});
                      }
                }
          }
          
             if(dis[dest]==INT_MAX)
              return -1;
          
          return dis[dest];
    }
};
//GFG POTD solution for 28 July
