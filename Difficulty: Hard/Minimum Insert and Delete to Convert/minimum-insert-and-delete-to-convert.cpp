class Solution {
  public:
    virtual int minInsAndDel(vector<int> &a, vector<int> &b){
      int n=a.size(), m=b.size();
      unordered_map<int, bool> inB;
      for(int i=0; i<m; i++) inB[b[i]]=true;
      vector<int> lis;
      for(int i=0; i<n; i++){
        if(inB[a[i]]){
          auto it = lower_bound(lis.begin(), lis.end(), a[i]);
          if(it == lis.end()) lis.push_back(a[i]);
          else *it=a[i];
          
        }  
      }
      return (n-lis.size()) + (m-lis.size());
    }
};
//GFG POTD solution for 30 June
