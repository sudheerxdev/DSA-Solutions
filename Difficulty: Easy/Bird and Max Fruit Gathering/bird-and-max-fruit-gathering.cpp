#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();

        // If m >= n, we can collect from all trees
        if (m >= n) {
            int total = 0;
            for (int fruits : arr) {
                total += fruits;
            }
            return total;
        }

        int current_sum = 0;

        // Calculate the sum of the first window of size m
        for (int i = 0; i < m; ++i) {
            current_sum += arr[i];
        }

        int max_sum = current_sum;

        // Slide the window across the circular array
        for (int i = 1; i < n; ++i) {
            // Subtract the element leaving the window
            // Add the element entering the window (with modulo for wrap-around)
            current_sum = current_sum - arr[i - 1] + arr[(i + m - 1) % n];
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};
//GFG POTD solution for 04 September
