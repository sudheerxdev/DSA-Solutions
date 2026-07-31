class Solution {
public:
    int countSubsets(vector<int>& arr) {
        const int MOD = 1000000007;
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};

        vector<int> freq(31, 0);
        for (int x : arr) freq[x]++;

        vector<int> mask(31, -1);

        for (int x = 2; x <= 30; x++) {
            int t = x;
            int m = 0;
            bool ok = true;

            for (int i = 0; i < 10; i++) {
                int cnt = 0;
                while (t % primes[i] == 0) {
                    t /= primes[i];
                    cnt++;
                }
                if (cnt > 1) {
                    ok = false;
                    break;
                }
                if (cnt == 1)
                    m |= (1 << i);
            }

            if (ok) mask[x] = m;
        }

        vector<long long> dp(1 << 10, 0);
        dp[0] = 1;

        for (int x = 2; x <= 30; x++) {
            if (freq[x] == 0 || mask[x] == -1) continue;

            int m = mask[x];
            for (int s = (1 << 10) - 1; s >= 0; s--) {
                if ((s & m) == 0) {
                    dp[s | m] = (dp[s | m] + dp[s] * freq[x]) % MOD;
                }
            }
        }

        long long ans = 0;
        for (int s = 1; s < (1 << 10); s++)
            ans = (ans + dp[s]) % MOD;

        long long pw = 1;
        while (freq[1]--)
            pw = (pw * 2) % MOD;

        ans = (ans * pw) % MOD;

        return (int)ans;
    }
};
//GFG POTD solution for 31 July
