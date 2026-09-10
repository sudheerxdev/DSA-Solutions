class Solution {
  public:
    bool isNegativeWeightCycle(int n, vector<vector<int>>& edges) {
        // code here
        vector<int> dist(n+1, 1e8);
        int m = edges.size();

        for(int i = 1; i<n; i++){
            for(int j = 0; j<m; j++){
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];

                if(dist[u] + wt <dist[v])
                    dist[v] = dist[u]+wt;
            }
        }

        for(int j = 0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] + wt <dist[v]) return 1;
        }
        return 0;
    }
};
//GFG POTD solution for 26 August
