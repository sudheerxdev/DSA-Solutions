class Solution {
public:
    vector<vector<int>> socialNetwork(vector<int>& arr) {
        vector<vector<pair<int, int>>> vec(arr.size() + 2);
        int curr = 2;

        for (auto &b : arr) {
            for (auto &[x, y] : vec[b]) {
                vec[curr].push_back({x, y + 1});
            }
            vec[curr++].push_back({b, 1});
        }

        vector<vector<int>> ans;

        for (int i = 1; i < vec.size(); i++) {
            for (auto &[x, y] : vec[i]) {
                ans.push_back({i, x, y});
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna