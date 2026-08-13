class Solution {
  public:
    vector<int> maxDistance(int V, int src, vector<vector<int>> &edges) {
        vector<vector<pair<int,int>>>adj(V);
        for(auto e : edges){
            adj[e[0]].push_back({e[1],e[2]});
        }
        vector<int>dist(V,INT_MIN);
        dist[src] = 0;
        priority_queue<pair<int,int>>pq;
        pq.push({0,src});
        while(!pq.empty()){
            auto [_w,u] = pq.top();
            pq.pop();
            for(auto [v,w] : adj[u]){
                if(dist[v] < w + dist[u]){
                    dist[v] = w + dist[u];
                    pq.push({dist[v],v});
                }
            }
        }
        return dist;
    }
};
//GFG POTD solution for 13 August
