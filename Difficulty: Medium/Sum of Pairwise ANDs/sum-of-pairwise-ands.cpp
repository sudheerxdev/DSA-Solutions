class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        long long ans =0 ;
        for(long long i=0;i<32;i++){
            long long k = 0;
            for(long long j=0;j<n;j++){
                if(arr[j] & (1<<i)){ 
                    k++; 
                }
            }
            ans += (1<<i)*(((k)*(k-1))/2); 
        }
        return ans;
    }
};
//GFG POTD solution for 06 September
