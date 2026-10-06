class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st ;
        for(char ch : s){
            if(ch == ')' && !st.empty() && st.top()=='('){

                st.pop();
            }else{
                st.push(ch);
            }
        }
        int ans = 0 ;
       
        return st.size();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna