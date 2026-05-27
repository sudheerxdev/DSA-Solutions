class Solution {
public:
    int monotoneIncreasingDigits(int n) {
       stack<char> st ; 
       
       string str = to_string(n);
       int len = str.length();
       string res = "";
       int i ;
       bool flag = true;
       for( i = 0 ; i < len ; i++){
          if(!st.empty() && st.top()  > str[i] ){
            flag = false;
             break;
          }
          st.push(str[i]);
       }
       if(flag == false){
       char ch = st.top();
        st.pop();

        st.push(ch - 1);
       }
       while(!st.empty()){
        res += st.top();
        st.pop();
       }
       reverse(res.begin() , res.end());
       string newstr = "";
       while(i < len){
        newstr += '9';
        i++;
       }
       res = res + newstr;
       int intres = stoi(res);
       return intres;
    }
};
