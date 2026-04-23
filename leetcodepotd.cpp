class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) mp[nums[i]].push_back(i);

        for(auto &p : mp){
            auto &v = p.second;
            int m = v.size();
            vector<long long> pref(m);
            pref[0] = v[0];

            for(int i = 1; i < m; i++)
                pref[i] = pref[i-1] + v[i];

            for(int i = 0; i < m; i++){
                long long left = (long long)v[i]*i - (i ? pref[i-1] : 0);
                long long right = (pref[m-1] - pref[i]) - (long long)v[i]*(m-i-1);
                ans[v[i]] = left + right;
            }
        }
        return ans;
    }
};
