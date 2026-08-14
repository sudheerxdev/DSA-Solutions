class Solution {
  public:
    bool isPossible(vector<int>& arr, int s, int x) {
        // code here
        if(s == x) return 1;
        long long pre = s , cur = s;
        vector<long long>v = {s};
        for(int i:arr)
        {
            long long toadd = pre + i;
            v.push_back(toadd);
            pre+=toadd;
        }
        long long need = x;
        reverse(v.begin(),v.end());
        for(long long i:v)
        {
            if(i<=need) need-=i;
            // else return 0;
        }
        return need == 0;
    }
};
//GFG POTD solution for 14 August
