class Solution {
  public:
    int solve(int n, string s) {
        vector<int>mp(26);
        int cnt = 0, notUse =0;

        for(char ch : s){
            if(mp[ch - 'A'] == 0){
                if(cnt<n){
                    cnt++;
                    mp[ch-'A'] = 2;
                }else{
                    mp[ch-'A']=1;
                    notUse++;
                }
            }else if(mp[ch-'A'] == 2){
                mp[ch] = 0;
                cnt--;
            }else{
                mp[ch]=0;
            }
            // cout<<ch<<" "<<mp[ch-'A']<<" "<<notUse<<" "<<cnt<<" "<<n<<endl;
        }

        return notUse;
    }
};

//GFG POTD solution for 02 September
