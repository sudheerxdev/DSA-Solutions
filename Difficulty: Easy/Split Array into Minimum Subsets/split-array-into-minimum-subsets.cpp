class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        // code here
        int count = 1 ; 
        sort(arr.begin() , arr.end());
        for(int i = 1 ; i < arr.size() ; i++){
            if(arr[i] - arr[i - 1] >1){
                count ++;
            }
        }
        return count ;
    }
};
