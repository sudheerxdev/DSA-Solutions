class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int k = 3 ; 
        int n = nums.size();
        int count = 0 ; 
        // initialised the fiorst windo 
        if(2*(nums[k-1] + nums[k -k ]) ==  (nums[k - 2])){
            count ++;
        }
        // start the next windwo 
        for(int i = k ; i < n ; i++){
            if(2*(nums[i] +  nums[i - 2])==(nums[i - 1])){
                count ++; 
            }

        }
        return count ;

    }
};
