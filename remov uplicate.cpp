#include<stack>
string removeDuplicate(string &s)
{
    // Write your code here
    int n = s.length();
    if(n < 2){
        return s;
    }
    stack<char>st ; 
    st.push(s[0]);
    for(int i = 1 ; i < n ; i++){
        if(st.top() != s[i]){
            st.push(s[i]);
        }
    }
    string str = "";
    while(!st.empty()){
        str =  st.top() + str;
        st.pop();
    }
    return str;
}
