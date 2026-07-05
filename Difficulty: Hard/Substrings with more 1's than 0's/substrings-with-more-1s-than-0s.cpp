class Solution {
public:
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) {
            this->n = n;
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & (-idx);
            }
        }

        int query(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & (-idx);
            }
            return sum;
        }
    };

    int countSubstring(string& s) {
        int n = s.size();

        vector<int> pref(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + (s[i - 1] == '1' ? 1 : -1);
        }

        vector<int> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        Fenwick bit(vals.size());

        long long ans = 0;

        for (int x : pref) {
            int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;

            // Count previous prefix sums strictly smaller than current
            ans += bit.query(idx - 1);

            bit.update(idx, 1);
        }

        return (int)ans;
    }
};
//GFG POTD solution for 04 July
