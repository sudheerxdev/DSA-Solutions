class Solution {
  public:
    vector<int> lexicographicallyLargest(vector<int> &arr) {
        int n=arr.size();
        int i=0;
        while(i<n){
            int j=i;
            int rem=arr[i]%2;
            while(j<n&&arr[j]%2==rem){
                j++;
            }
            sort(arr.begin()+i, arr.begin()+j, [](int a, int b){
                return a>b;
            });
            i=j;
        }
        return arr;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna