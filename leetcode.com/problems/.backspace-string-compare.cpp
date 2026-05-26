class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1 ; 
        stack<char>st2 ; 
        int m = s.length() , n = t.length();
        for(int i = 0; i < m ; i++){
            if(!st1.empty() && s[i]=='#'){
                st1.pop();
            }
            else{
                if(s[i]!= '#')
                  st1.push(s[i]);
            }
        }
        for(int i = 0; i < n ; i++){
             if(!st2.empty() && t[i]=='#'){
                st2.pop();
            }
            else{
                if(t[i]!= '#'){
                    st2.push(t[i]);
                }
            }
        }
        if(st1.empty() && st2.empty()){
            return true;
        }
        while(!st1.empty()  && !st2.empty()){
            if(st1.top()!= st2.top()){
                return false;
            }
            else{
                st1.pop();
                st2.pop();
            }
        }
         if(st1.empty() && st2.empty()){
            return true;
        }
        return false;

    }
};
