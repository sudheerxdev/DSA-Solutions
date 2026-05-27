class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower[26];
        int upper [26] ;
        for(int i = 0 ; i < 26 ; i++){
            lower[i]=-1;
            upper[i]=-1;
        }
        int len = word.length();
        for(int i = 0 ; i < len ; i++){
            if(islower(word[i])){
                lower[ word[i] - 'a'] = i;
            }
            else{
                if(upper[ word[i] - 'A'] != -1) continue;
                upper[ word[i] - 'A']=i;
            }
        }
        int count = 0 ; 
        for(int i = 0 ; i < 26 ; i++){
            if(lower[i] != -1 && upper[i] != -1 && (lower[i] < upper[i])){
                count ++;
            }
        }
        return count;
    }
};
