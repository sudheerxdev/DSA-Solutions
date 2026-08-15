class Solution {
  public:
    int countWithout(int n, int d) {
        // code here
        if (n == 0) {
            return 0;
        }

        string s = to_string(n);
        long long len = s.size(), res = 0, has_d = 0;

        vector<long long> p9(11);
        p9[0] = 1;
        for (int i = 1; i <= 10; i++) {
            p9[i] = p9[i - 1] * 9; 
        }

        for (int i = 0; i < len; i++) {
            int dg = s[i] - '0', op = 0;

            int start = (i == 0 ? 1 : 0);
            for (int j = start; j < dg; j++) {
                if (j != d) {
                    op++;
                }
            }

            res += op * p9[len - (i + 1)];

            if (dg == d) {
                has_d = 1;
                break;
            }
        }

        for (int i = 1; i < len; i++) {
            int op = 0;
            for (int j = 1; j <= 9; j++) {
                if (j != d) {
                    op++;
                }
            }

            res += op * p9[i - 1];
        }

        res += (!has_d);

        return res;
    }
};
//GFG POTD solution for 15 August
