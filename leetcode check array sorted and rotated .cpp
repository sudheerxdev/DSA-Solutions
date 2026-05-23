class Solution {
public:
    bool check(vector<int>& nums) {
       vector<int > arr ; 
        if(nums[0]<nums[nums.size() - 1]){
                arr.push_back(0);
            }
       for(int i = 0 ; i < nums.size() - 1 ; i++){
            if(nums[i+1] < nums[i] ){
                arr.push_back(i);
            }
           
            if(arr.size() >= 2){
                return false;
            }
       }
       return true;
    }
};
