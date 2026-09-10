class Solution {
  public:
    vector<int> getMarks(vector<int> &l, vector<int> &r, vector<int> &rank) {
        // code here
        vector<int>ass;
        vector<int>pref(l.size()+1,0);
        for(int i=1;i<=l.size();i++)
        {
            if(i==1)
            {
                pref[i]=r[i-1]-l[i-1]+1;
            }
            else
            {
                pref[i]+=pref[i-1];
                pref[i]+=r[i-1]-l[i-1]+1;
            }
        }
        // for(auto i:pref)cout<<i<<" ";
        // 3 7 9
        // 3 6
        for(int i=0;i<rank.size();i++)
        {
            int ll=0,u=pref.size();

            while(ll<=u)
            {
                int m=ll+(u-ll)/2;
                if(pref[m]<rank[i])ll=m+1;
                else u=m-1;
            }
            // cout<<u<<endl;
            rank[i]-=pref[u];
            // ass.push_back(l[u]+rank[i]-1);
            cout<<l[u]+rank[i]-1<<" ";

        }
        return ass;
    }
};
//GFG POTD solution for 30 August
