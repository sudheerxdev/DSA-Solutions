class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int>ans(n) ;
        stack<int>st;
        for(int i = n - 1 ; i >= 0 ; i--){
            if(st.empty()){
                ans[i]= -1;
            }
            else if(st.size() > 0 && arr[i] < st.top()){
                ans[i]=st.top();
            }
            else if(st.size() > 0 && arr[i] >= st.top()){
                while(st.size()>0 && st.top() <= arr[i]){
                    st.pop();
                }
                // etna hone pe ya to kux nhi bacha hoga ya to bada element hoga i par 
                if(st.empty()){
                    ans[i]=-1;
                }
                else{
                    ans[i]=st.top();
                }
            }
            st.push(arr[i]);
        }
        // reverse(ans.begin() , ans.end());
        return ans;
    }
};