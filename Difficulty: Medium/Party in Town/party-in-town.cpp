class Solution {
  public:
    int partyHouse(vector<vector<int>> &adj) {
        int n = adj.size();

        auto bfs = [&](int start){
            vector<int> dist(n,-1);
            queue<int> q;

            q.push(start);
            dist[start] = 0;

            int farthest = start;

            while(!q.empty()){
                int u = q.front();
                q.pop();

                for(int v : adj[u]) {
                    v--;

                    if(dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);

                        if(dist[v] > dist[farthest])
                        farthest= v;
                    }
                }
            }
            return pair<int, int>{farthest, dist[farthest]};
        };

        auto first = bfs(0);
        auto second = bfs(first.first);

        return(second.second+1)/2;

    }
};
//GFG POTD solution for 13 September
