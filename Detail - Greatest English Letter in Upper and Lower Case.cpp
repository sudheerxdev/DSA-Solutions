class Solution {
public:
    string greatestLetter(string s) {
         set <char > small ; 
        set<char> capital ; 
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                small.insert(s[i]);
            }
            if(s[i] >= 'A' && s[i] <= 'Z'){
                capital.insert(s[i]);
            }

        }
        string count = ""; 
        for(char ch = 'Z' ; ch >=  'A' ; ch--){
            if(small.count(ch+32) && capital.count(ch)){
                return string(1,ch);
            }
        }
        return count ; 
    }
};
