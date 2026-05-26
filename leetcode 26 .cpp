class Solution {
public:
    int numberOfSpecialChars(string word) {
    set<int>st ; 
    for(char i = 'a' ; i <= 'z' ; i++){
        st.insert((int)i);
    }
    for(char i = 'A' ; i <= 'Z' ; i++){
        st.insert((int)i);
    }
    int count = 0 ; 
    for(int i = 0 ; i < word.length() ; i++){
        if(st.find((int)word[i]) == st.end() && st.find((int)word[i] + 32) == st.end()){
            count++;
        }
    }
    return count ; 


    }
};
