class Solution {
public:
    int numberOfSpecialChars(string word) {
        set <char > small ; 
        set<char> capital ; 
        for(int i = 0 ; i < word.length() ; i++){
            if(word[i] >= 'a' && word[i] <= 'z'){
                small.insert(word[i]);
            }
            if(word[i] >= 'A' && word[i] <= 'Z'){
                capital.insert(word[i]);
            }

        }
        int count = 0 ; 
        for(char ch = 'a' ; ch <= 'z' ; ch++){
            if(small.count(ch) && capital.count(ch- 32)){
                count ++;
            }
        }
        return count ; 
    }
};
