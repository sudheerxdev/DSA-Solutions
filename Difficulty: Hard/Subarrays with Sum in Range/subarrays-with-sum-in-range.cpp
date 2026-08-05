class Solution {
  public:
    int countSubarray(vector<int>& arr, int l, int r) {
        int n = arr.size();

        vector<long long> prefix(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + arr[i];

        return mergeSort(prefix, 0, n, l, r);
    }

  private:
    int mergeSort(vector<long long>& prefix, int low, int high, int l, int r) {

        if (low >= high)
            return 0;

        int mid = (low + high) / 2;

        int cnt = 0;

        cnt += mergeSort(prefix, low, mid, l, r);
        cnt += mergeSort(prefix, mid + 1, high, l, r);

        int i = mid + 1;
        int j = mid + 1;

        for (int k = low; k <= mid; k++) {

            while (i <= high && prefix[i] - prefix[k] < l)
                i++;

            while (j <= high && prefix[j] - prefix[k] <= r)
                j++;

            cnt += (j - i);
        }

        vector<long long> temp;

        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (prefix[left] <= prefix[right])
                temp.push_back(prefix[left++]);
            else
                temp.push_back(prefix[right++]);
        }

        while (left <= mid)
            temp.push_back(prefix[left++]);

        while (right <= high)
            temp.push_back(prefix[right++]);

        for (int i = low; i <= high; i++)
            prefix[i] = temp[i - low];

        return cnt;
    }
};
//GFG POTD solution for 05 August
