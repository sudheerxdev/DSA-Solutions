class Solution {
  public:
    void generateNumbers(int left, int d, int num, vector <int> &res) {
        if (left == 0) {
            res.push_back(num);
            return;
        }
        
        for (int i = d + 1; i <= 9; i++) {
            generateNumbers(left - 1, i, num * 10 + i, res);
        }
    }
  
    vector<int> increasingNumbers(int n) {
        // code here
        vector <int> res;

        if (n == 1) {
            for (int i = 0; i <= 9; i++) res.push_back(i);
            return res;
        }
        
        if (n > 9) return res;
        
        for (int d = 1; d <= 9; d++) {
            generateNumbers(n - 1, d, d, res);
        }
        
        return res;        
    }
};
//GFG POTD solution for 25 June
