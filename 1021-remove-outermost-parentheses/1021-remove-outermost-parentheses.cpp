
class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int depth = 0;
        
        for (char c : s) {
            if (c == '(') {
                if (depth > 0) {
                    result += c;
                }
                depth++;
            } else {
                depth--;
                if (depth > 0) {
                    result += c;
                }
            }
        }
        
        return result;
    }
};



// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna