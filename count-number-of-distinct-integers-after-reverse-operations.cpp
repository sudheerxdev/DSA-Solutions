class Solution {
public:
    int reverse(int num){
        int rev = 0 ; 
        while(num != 0){
            rev = rev * 10 + num % 10 ; 
            num /= 10 ;
        } 
        return rev;
        
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int res = reverse(nums[i]);
            nums.push_back(res);
        }
        unordered_set<int> st(nums.begin() , nums.end());
        return st.size();
    }
};
