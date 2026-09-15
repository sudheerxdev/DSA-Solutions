class Solution {
  public:
    int maxProduct(vector<int> &arr, int k) {
            int n = arr.size();

            sort(arr.begin(), arr.end());

            if (arr[n - 1] <= 0 && k % 2 == 1) {
                long long ans = 1;

                // Take k largest elements
                // They are closest to zero.
                for (int i = n - 1; i >= n - k; i--) {
                    ans *= arr[i];
                }

                return ans;
            }
            long long ans = 1;

            int left = 0;
            int right = n - 1;

            if (k % 2 == 1) {
                ans *= arr[right];
                right--;
                k--;
            }        while (k > 0) {

                long long leftProduct =
                    1LL * arr[left] * arr[left + 1];

                long long rightProduct =
                    1LL * arr[right] * arr[right - 1];

                if (leftProduct > rightProduct) {
                    ans *= leftProduct;
                    left += 2;
                } else {
                    ans *= rightProduct;
                    right -= 2;
                }

                k -= 2;
            }

            return ans;
        }
};
//GFG POTD solution for 12 September
