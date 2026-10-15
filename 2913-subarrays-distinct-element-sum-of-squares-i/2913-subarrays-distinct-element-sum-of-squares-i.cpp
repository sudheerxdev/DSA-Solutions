
#include <vector>
#include <unordered_set>

class Solution {
public:
    int sumCounts(std::vector<int>& nums) {
        int totalSumOfSquares = 0;
        int n = nums.size();
        
        // Fix the starting index of the subarray
        for (int i = 0; i < n; ++i) {
            std::unordered_set<int> distinctElements;
            
          
            for (int j = i; j < n; ++j) {
                distinctElements.insert(nums[j]);
                
               
                int distinctCount = distinctElements.size();
               
                totalSumOfSquares += (distinctCount * distinctCount);
            }
        }
        
        return totalSumOfSquares;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna