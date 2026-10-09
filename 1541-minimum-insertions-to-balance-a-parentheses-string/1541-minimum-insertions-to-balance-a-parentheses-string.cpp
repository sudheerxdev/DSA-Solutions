// Leetcode POTD solution for 09 oct

#include <string>
using namespace std;
class Solution {
public:
    int minInsertions(string s) {
        int add = 0;
        int bal = 0;
        for (char c : s) {
            if (c == '(') {

                if (bal % 2 > 0) {
                    ++add;
                    --bal;
                }
                bal += 2;
            } else {
                --bal;
                if (bal < 0) {
                    ++add;
                    bal += 2;
                }
            }
        }
        return add + bal;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna