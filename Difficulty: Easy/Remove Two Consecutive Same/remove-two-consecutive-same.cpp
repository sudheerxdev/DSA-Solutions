class Solution {
  public:
    int removeConsecutiveSame(vector<string>& arr) {
        // code here
        stack<string>st ; 
        for(int i = 0 ; i < arr.size() ; i++){
            if(!st.empty() && arr[i]==st.top()){
                st.pop();
            }else{
             st.push(arr[i]);
            }
        }
        return st.size()  ;
    }
};