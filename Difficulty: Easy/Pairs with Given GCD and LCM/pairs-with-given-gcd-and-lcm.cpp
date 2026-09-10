 class Solution {
   public:
     int pairCount(int x, int y) {

         if (y % x != 0)
             return 0;

         int n = y / x;
         int ans = 0;

         // Find factor pairs of n
         for (int i = 1; i * i <= n; i++) {

             if (n % i == 0) {

                 int j = n / i;

                 // i and j must be coprime
                 if (i != j && __gcd(i, j) == 1)
                     ans += 2;
             }
         }


         if (n == 1)
             ans = 1;

         return ans;
     }
 };
//GFG POTD solution for 10 September
