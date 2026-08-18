class Solution {
  public:
    string compress(string &s) {
        // code here

        int n = s.size();

        // Z-array
        vector<int> z(n, 0);

        int l = 0, r = 0;

        for (int i = 1; i < n; i++) {
            if (i < r)
                z[i] = min(r - i, z[i - l]);

            while (i + z[i] < n &&
                   s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }

            if (i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }

        // dp[i] = minimum encoded length for s[i...n-1]
        const int INF = 1e9;
        vector<int> dp(n + 1, INF);

        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {

            // Write s[i]
            dp[i] = 1 + dp[i + 1];

            // Use '*'
            if (i > 0 &&
                2 * i <= n &&
                z[i] >= i) {

                dp[i] = min(dp[i],
                             1 + dp[2 * i]);
            }
        }

        // Construct answer
        string ans;
        int i = 0;

        while (i < n) {

            // Prefer '*' when it still gives
            // the shortest possible answer.
            if (i > 0 &&
                2 * i <= n &&
                z[i] >= i &&
                1 + dp[2 * i] == dp[i]) {

                ans += '*';
                i *= 2;
            }
            else {
                ans += s[i];
                i++;
            }
        }

        return ans;
    }
};

//GFG POTD solution for 18 August
