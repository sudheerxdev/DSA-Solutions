class Solution {
  public:
    void helper(stack<int>& s , int n){
        if(n ==0 ){
            s.pop();
            return ;
        }
        int num =  s.top();
        s.pop();
        helper(s , n - 1);
        s.push(num);
    }
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        int n = s.size();
        helper(s , n /2 );
    }
};