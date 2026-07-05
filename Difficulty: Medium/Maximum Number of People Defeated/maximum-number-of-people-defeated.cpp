class Solution {
public:
    long long calc(int n) { return 1LL * (n) * (n + 1) * ((2 * n) + 1); }

    int maxPeopleDefeated(int p) {
        long long target = 1LL * p * 6;
        int high = 1;

        while (calc(high) < target)
            high *= 2;

        if (calc(high) == target)
            return high;

        int low = high / 2;

        while (low != high) {
            int mid = (low + high + 1) / 2;
            int val = calc(mid);
            if (val == target)
                return mid;
            else if (val < target)
                low = mid;
            else
                high = mid - 1;
        }

        return low;
    }
};

//GFG POTD solution for 23 June
