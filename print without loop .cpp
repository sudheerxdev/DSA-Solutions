
void  helper(vector<int>&ans , int n ){
    if(n <= 0 ){
        return ; 
    }
    helper(ans , n - 1);
    if(n != 0)ans[n-1]=n;
    
}
vector<int> printNos(int x) {
    // Write Your Code He
    vector<int > ans(x);
     helper(ans , x);
     return ans ;
}
