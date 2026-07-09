class Solution {
public:
    int countKdivPairs(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        int count = 0;

        for (int x : arr) {
            int rem = x % k;
            int complement = (k - rem) % k;

            count += freq[complement];

            freq[rem]++;
        }

        return count;
    }
};