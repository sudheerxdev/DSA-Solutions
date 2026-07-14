class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int mixi = INT_MIN;
        for(auto & num : arr){
            mixi = max(mixi , num);
        }
        return mixi;
    }
};
