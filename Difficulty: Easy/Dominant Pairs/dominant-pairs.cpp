class Solution {
  public:
    int dominantPairs(vector<int> &arr) {
        // Code here
        int n = arr.size();

        sort(arr.begin(),arr.begin()+n/2);
        sort(arr.begin()+n/2,arr.end());

        int i = 0;
        int ans = 0;
        for(int j = n/2;j<n;j++){
            while(i < n/2 && arr[i] < 5*arr[j]) i++;
            if(i == n/2) break;
            ans += (n/2-i);
        }
        return ans;
    }
};
//GFG POTD solution for 16 September
