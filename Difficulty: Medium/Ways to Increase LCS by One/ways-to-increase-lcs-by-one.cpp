class Solution {
  public:
    int waysToIncreaseLCSBy1(string &s1, string &s2) {
        int n = s1.size(), m = s2.size();

        // pref[i][j] = LCS of s1[0..i-1] and s2[0..j-1]
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    pref[i][j] = pref[i - 1][j - 1] + 1;
                else
                    pref[i][j] = max(pref[i - 1][j], pref[i][j - 1]);
            }
        }

        // suf[i][j] = LCS of s1[i..] and s2[j..]
        vector<vector<int>> suf(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j])
                    suf[i][j] = suf[i + 1][j + 1] + 1;
                else
                    suf[i][j] = max(suf[i + 1][j], suf[i][j + 1]);
            }
        }

        int L = pref[n][m];
        int ans = 0;

        // Try every insertion position in s1
        for (int pos = 0; pos <= n; pos++) {
            bool used[26] = {0};

            // Match inserted character with every occurrence in s2
            for (int j = 0; j < m; j++) {
                int c = s2[j] - 'a';
                if (used[c]) continue;

                if (pref[pos][j] + 1 + suf[pos][j + 1] == L + 1) {
                    used[c] = true;
                    ans++;
                }
            }
        }

        return ans;
    }
};
//GFG POTD solution for 03 July
