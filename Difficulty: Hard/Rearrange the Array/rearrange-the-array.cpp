class Solution {
public:
    static const int MOD = 1000000007;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    int minOperations(vector<int> &a) {
        int n = a.size();

        vector<int> vis(n, 0);
        vector<int> mx(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int cur = i, len = 0;

                while (!vis[cur]) {
                    vis[cur] = 1;
                    cur = a[cur] - 1;
                    len++;
                }

                int x = len;
                for (int p = 2; p * p <= x; p++) {
                    int cnt = 0;
                    while (x % p == 0) {
                        cnt++;
                        x /= p;
                    }
                    mx[p] = max(mx[p], cnt);
                }
                if (x > 1)
                    mx[x] = max(mx[x], 1);
            }
        }

        long long ans = 1;
        for (int p = 2; p <= n; p++) {
            if (mx[p])
                ans = (ans * power(p, mx[p])) % MOD;
        }

        return ans;
    }
};
//GFG POTD solution for 13 July
