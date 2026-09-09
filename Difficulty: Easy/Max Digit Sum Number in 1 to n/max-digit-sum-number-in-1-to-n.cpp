class Solution {
  public:
    virtual int dig_sum(int x){
      if(!x) return 0;
      return x%10 + dig_sum(x/10);
    }

    virtual int findMax(int n){
      int b=1, ans=n;

      while(n){
        int cur = (n-1)*b + (b-1);
        if((dig_sum(cur) > dig_sum(ans)) || ((dig_sum(cur) == dig_sum(ans) && cur>ans))){
          ans=cur;
        }
        b*=10;
        n/=10;        
      }

      return ans;
    }
};
//GFG POTD solution for 09 September
