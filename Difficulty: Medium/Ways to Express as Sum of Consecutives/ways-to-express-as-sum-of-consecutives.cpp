class Solution {
  public:
    int getCount(int n) {
        // code here
        int left = 1;
        int right = 1;
        int count = 0;
        int sum = 0;
        
        while(right < n){
            sum += right;
            
            while(sum > n){
                sum -= left;
                left++;
            }
            
            if(sum == n) count += 1;
            
            right++;
        }
        return count;
    }
};
