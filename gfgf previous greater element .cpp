class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {
        //  code here
        stack<int > st ; 
        int n = arr.size();
        vector<int > res(n);
   
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && st.top() <=arr[i] ){
                st.pop();
            }
            if(st.empty()){
                res[i] = -1;
            }else{
                res[i] = st.top();
            }
            st.push(arr[i]);
        }
        return res;
    }
};
