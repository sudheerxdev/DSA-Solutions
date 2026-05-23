#include <bits/stdc++.h> 
vector<int> nextGreaterElement(vector<int>& arr, int n){
    // Write your code here.
    vector<int>res(n) ; 
    stack<int> st ;
    for(int i = n - 1 ; i >= 0 ; i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(st.empty()){
            res[i]= -1;
        }
        else{
            res[i]= st.top();
        }
        st.push(arr[i]);
    }
    return res;
}
