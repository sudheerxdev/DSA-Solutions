class Solution {
public:
    int n;

    int solve(int i, vector<int>& nums, int target, vector<int>& t) {
        if(i == n-1) {
            return t[i] = 0; //no more steps. reached destination
        }

        if(t[i] != INT_MIN) {
            return t[i];
        }

        int result = INT_MIN;

        for(int j = i+1; j < n; j++) {
            if(abs(nums[i] - nums[j]) <= target) {
                int temp = 1 + solve(j, nums, target, t);

                result = max(result, temp);
            }
        }

        return t[i] = result;
    }

    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();

        vector<int> t(n+1, INT_MIN);

        int result = solve(0, nums, target, t);

        
        return result < 0 ? -1 : result;

    }
};
