class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        vector<vector<string>>res ; 
        unordered_map<string , vector<string>>mp;
        for(auto & str : arr){
            string st = str;
            sort(st.begin() , st.end());
            mp[st].push_back(str);
        }
        for(auto & [key , value] : mp){
            res.push_back(value);
        }
        return res;
    }
};