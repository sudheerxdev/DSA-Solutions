class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int num1 = INT_MIN ; 
        int num2 = -1 ; 
        for(int i = 0 ; i < arr.size() ; i++){
           num1 = max(num1 , arr[i]);
        }
        for(int i = 0 ; i < arr.size() ; i++){
           if(arr[i] < num1){
               num2 = max(num2 , arr[i]);
           }
        }
        return num2;
        
    }
};