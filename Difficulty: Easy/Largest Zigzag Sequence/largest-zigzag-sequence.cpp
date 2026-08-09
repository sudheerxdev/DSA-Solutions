class Solution {
public:
    int zigzagSequence(vector<vector<int>>& mat) {

        int n = mat.size();

        vector<int> dp(n);

        // First row
        for(int j = 0; j < n; j++) {
            dp[j] = mat[0][j];
        }

        for(int i = 1; i < n; i++) {

            // Find largest and second largest in dp
            int maxi = -1;
            int secondMaxi = -1;

            int maxColumn = -1;

            for(int j = 0; j < n; j++) {

                if(dp[j] > maxi) {
                    secondMaxi = maxi;
                    maxi = dp[j];
                    maxColumn = j;
                }
                else if(dp[j] > secondMaxi) {
                    secondMaxi = dp[j];
                }
            }

            vector<int> newdp(n);

            for(int j = 0; j < n; j++) {

                if(j != maxColumn) {
                    newdp[j] = mat[i][j] + maxi;
                }
                else {
                    newdp[j] = mat[i][j] + secondMaxi;
                }
            }

            dp = newdp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
//GFG POTD solution for 09 August
