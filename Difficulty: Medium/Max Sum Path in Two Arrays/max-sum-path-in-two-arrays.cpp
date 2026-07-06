class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        int i = 0, j = 0;
        int n1 = a.size();
        int n2 = b.size();
        
        long long sum1 = 0, sum2 = 0, result = 0;

        while (i < n1 && j < n2) {
            if (a[i] < b[j]) {
                sum1 += a[i++];
            } else if (b[j] < a[i]) {
                sum2 += b[j++];
            } else {
                // Common element found
                result += max(sum1, sum2) + a[i];
                i++;
                j++;
                sum1 = 0;
                sum2 = 0;
            }
        }

        while (i < n1) sum1 += a[i++];
        while (j < n2) sum2 += b[j++];

        result += max(sum1, sum2);

        return (int)result;
    }
};

//GFG POTD solution for 06 July
