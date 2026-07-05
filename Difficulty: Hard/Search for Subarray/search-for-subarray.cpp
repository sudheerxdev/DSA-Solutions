class Solution {
  public:
    vector<int> search(vector<int> &a, vector<int> &b) {
        // code here
        
        int n = a.size();
        int m = b.size();
        vector<int> result;

        if (m == 0) return result;

        // Step 1: Precompute the LPS (Longest Prefix Suffix) array for b
        vector<int> lps(m, 0);
        int len = 0; // length of the previous longest prefix suffix
        int i = 1;
        while (i < m) {
            if (b[i] == b[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Step 2: Search for b in a using the LPS array
        int j = 0; // index for b[]
        int k = 0; // index for a[]
        while (k < n) {
            if (a[k] == b[j]) {
                k++;
                j++;
            }

            if (j == m) {
                // Match found! Store the starting index
                result.push_back(k - j);
                j = lps[j - 1];
            } else if (k < n && a[k] != b[j]) {
                // Mismatch after j matches
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    k++;
                }
            }
        }

        return result;
        
    }
};
//GFG POTD solution for 14 May
