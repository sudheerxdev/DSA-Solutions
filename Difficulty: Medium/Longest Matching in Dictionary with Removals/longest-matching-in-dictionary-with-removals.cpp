class Solution {
  public:
    string findLongestWord(string &s, vector<string> &d) {
        // code here
        unordered_map<char,vector<int>> mp;
        for(int i=s.size()-1;i>=0;i--){
            mp[s[i]].push_back(i);
        }
        string res = "";
        for(int i=0;i<d.size();i++){
            if(d[i].size()<res.size()){
                continue;
            }
            unordered_map<char,vector<int>> temp = mp;
            // cout<<temp.size()<<" ";
            int prev = -1;
            bool found = false;
            string curr = d[i];
            for(int j=0;j<d[i].size();j++){
                char c = d[i][j];
                if(!temp.count(c) || temp[c].size()==0) break;

                int currIdx = temp[c].back();
                temp[c].pop_back();
                bool exit = false;
                while(currIdx<prev){
                    if(temp[c].size()==0){
                        exit = true;
                        break;
                    }
                    currIdx = temp[c].back();
                    temp[c].pop_back();
                    if(currIdx>prev){
                        break;
                    }
                }
                if(exit){
                    break;
                }
                prev = currIdx;

                if(j==d[i].size()-1){
                    found = true;
                }
            }
            if(found){
                if(curr.size()>res.size()){
                    res = curr;
                    continue;
                }else if(curr.size()==res.size()){
                    if(res>curr){
                        res=curr;
                    }
                }else{
                    continue;
                }
            }
        }
        return res;
    }
};

/*


*/
//GFG POTD solution for 22 September
