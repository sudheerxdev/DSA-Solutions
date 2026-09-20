class Solution {
  public:
    int largestSubsquare(vector<vector<char>> mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> horizontal(n, vector<int>(m, 0));
        vector<vector<int>> vertical(n, vector<int>(m, 0));
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 'X') {
                    count++;
                } else {
                    count = 0;
                }
                horizontal[i][j] = count;
            }
        }

        for (int j = 0; j < m; j++) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][j] == 'X') {
                    count++;
                } else {
                    count = 0;
                }
                vertical[i][j] = count;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int small = min(horizontal[i][j], vertical[i][j]);
                while (small > maxi) {
                    if (horizontal[i - small + 1][j] >= small &&
                        vertical[i][j - small + 1] >= small) {
                        maxi = small;
                    }
                    small--;
                }
            }
        }

        return maxi;
    }
};
//GFG POTD solution for 20 September
