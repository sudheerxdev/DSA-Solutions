class Solution {
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        // code here  
        vector<vector<pair<int, int>>> adj(n+1);
        int m = edges.size();
        for(int i = 0;i<m;i++){
            adj[edges[i][0]].push_back({0, edges[i][1]});
            adj[edges[i][1]].push_back({1, edges[i][0]});
        }


        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

        q.push({0, src});

        vector<int> dist(n+1, INT_MAX);
        dist[src] = 0;

        while(!q.empty()){
            int replace = q.top().first;
            int node = q.top().second;
            q.pop();
            if(node == dst) return replace;

            for(auto it: adj[node]){
                int c = it.first, i = it.second;
                if(replace + c < dist[i]){
                    dist[i] = replace + c;
                    q.push({dist[i], i});

                }
            }
        }
        return -1;
    }
};
//GFG POTD solution for 17 September
