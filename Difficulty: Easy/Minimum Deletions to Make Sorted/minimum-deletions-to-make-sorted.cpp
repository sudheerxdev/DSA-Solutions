class Solution {
public:
    int minDeletions(vector<int>& arr) {
        vector<int> lis;

        for (int x : arr) {
            auto it = lower_bound(lis.begin(), lis.end(), x);

            if (it == lis.end())
                lis.push_back(x);
            else
                *it = x;
        }

        return arr.size() - lis.size();
    }
};
//GFG POTD solution for 22 July
