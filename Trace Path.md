## 01. Trace Path

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/trace-path3840/1)

### Problem Description

**Task:** Given a rectangular grid with n rows and m columns, and a string s representing a sequence of movement commands. Geek can start from any cell of the grid and follows all the commands in s in the same order.The string s consists only of the characters L, R, D, and U, where:L: Move one cell left, from (i, j) to (i, j - 1).R: Move one cell right, from (i, j) to (i, j + 1).D: Move one cell up, from (i, j) to (i - 1, j).U: Move one cell down, from (i, j) to (i + 1, j).Determine whether there exists at least one starting cell such that Geek remains within the grid after performing all the commands in s.Examples:Input: n = 1, m = 1, s = "R"

#### Examples

##### Example 1

- **Output:**
```text
true
```
- **Explanation:** One possible cell is (1, 3). (1, 3) - > (1, 2) - > (1, 1) - > (1, 2) - > (2, 2). Thus, there is a cell from where if Geek starts, it remains inside the grid throughout tracing the route.

### Time and Auxiliary Space Complexity

- **Expected Time Complexity:** O(|s|)
- **Expected Auxiliary Space Complexity:** O(1)

### Accepted Solutions (1)

#### Solution 1 (C++)

- **Submitted:** 2026-10-24 12:13:25
- **Status:** Correct
- **Marks:** 2

```cpp
//GFG POTD solution for 24 oct

#include <string>
#include <algorithm>

class Solution {
public:
    bool isPossible(int n, int m, std::string& s) {
        int cur_r = 0, cur_c = 0;
        int min_r = 0, max_r = 0;
        int min_c = 0, max_c = 0;

        for (char ch : s) {
            if (ch == 'L') {
                cur_c--;
            } else if (ch == 'R') {
                cur_c++;
            } else if (ch == 'D') {
                cur_r--; // Move up/decrease row
            } else if (ch == 'U') {
                cur_r++; // Move down/increase row
            }

            min_r = std::min(min_r, cur_r);
            max_r = std::max(max_r, cur_r);
            min_c = std::min(min_c, cur_c);
            max_c = std::max(max_c, cur_c);
        }

        int height = max_r - min_r + 1;
        int width = max_c - min_c + 1;

        return (height <= n && width <= m);
    }
};
//for Daily POTD(Unstop/leetcode/GFG) follow @POTDunstop
```

*Generated on: 24/10/2026, 12:16:08*