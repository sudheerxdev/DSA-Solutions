class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st ; 
        // push a hint 
        st.push(0);
        for(char ch : s){
            if(ch == '('){
                st.push(0);
            }
            else{
                int value = st.top();
                st.pop();
                int score = max(2 * value , 1);
                 st.top() += score;
            }

        }
        return st.top();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna