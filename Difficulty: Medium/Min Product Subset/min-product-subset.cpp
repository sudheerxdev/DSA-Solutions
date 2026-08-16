class Solution {
public:
    int minProd(vector<int>& arr) {
        int n = arr.size();
        long long minProd = LLONG_MAX;

        for (int mask = 1; mask < (1 << n); mask++) {
            long long product = 1;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    product *= arr[i];
                }
            }
            minProd = min(minProd, product);
        }

        return (int)minProd;
    }
};
//GFG POTD solution for 16 August
