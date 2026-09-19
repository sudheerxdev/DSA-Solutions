class Solution {
  public:

    int solve(vector<vector<int>> &dp, string &s1, string &s2, int i, int j, int c1, int c2) {

        if(i == s1.size() && j == s2.size()) return 0;
        if(i == s1.size()) return (s2.size()-j) * c2;
        if(j == s2.size()) return (s1.size()-i) * c1;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]) dp[i][j] = solve(dp, s1, s2, i+1, j+1, c1, c2);
        else {
            int delI = solve(dp, s1, s2, i+1, j, c1, c2);
            if(delI != INT_MAX) delI += c1;
            int delJ = solve(dp, s1, s2, i, j+1, c1, c2);
            if(delJ != INT_MAX) delJ += c2;
            dp[i][j] = min(delI, delJ);
        }
        return dp[i][j];
    }

    int findMinCost(string &s1, string &s2, int costS1, int costS2) {
        // code here
        vector<vector<int>> v(s1.size() +1, vector<int> (s2.size() + 1, -1));
        return solve(v, s1, s2, 0, 0, costS1, costS2);
    }
};
//GFG POTD solution for 19 September
