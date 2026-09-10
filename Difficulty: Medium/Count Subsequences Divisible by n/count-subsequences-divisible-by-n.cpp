class Solution {
  public:
    const int MOD = 1e9 + 7;
    int countSubsequences(string& s, int n) {
        // code here
        int m = s.size();
        vector<int> cntPrev(n, 0), cntCurr(n, 0);
        int d = s[0] - '0';
        cntPrev[d % n]++;
        for (int i = 1; i < m; i++) {
            int d = s[i] - '0';
            cntCurr = cntPrev;
            for (int r = 0; r < n; r++) {
                cntCurr[(r * 10 + d) % n] = 
                    (cntCurr[(r * 10 + d) % n] + cntPrev[r]) % MOD;
            }
            cntCurr[d % n] = (cntCurr[d % n] + 1) % MOD;
            cntPrev = cntCurr;
        }
        return cntPrev[0];
    }
};
//GFG POTD solution for 29 August
