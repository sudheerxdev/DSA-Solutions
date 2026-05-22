class Solution {
public:
    void helper(vector<int>& nums, int start , int end){
        while(start <= end){
            swap(nums[start++] , nums[end--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size() ;
        k = k % n;
        if(nums.size() == 1){

        }
       else{
         // rotate kaER dio pahle  LAST ME 
        helper(nums , n - k , n - 1 ); 
        // starting ka ab rotate mar do 
        helper(nums , 0 , n - k -1);
        // pura rorate mar do 
        helper(nums , 0 , n - 1);
       }

    }
};
