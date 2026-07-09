class Solution {
	private:
	void helper(stack<int>&st ,stack<int>&stk ){
	    if(st.empty()){
	        return ;
	    }
	    int top = st.top();
	    st.pop();
	    helper(st , stk);
	    stk.push(top);
	    st.push(top);
	}
	public:
	stack<int> cloneStack(stack<int>& st) {
		// code here
		stack<int>stk;
		// push all elemnt of original stack
	    helper(st , stk);
	    return stk;
	}
};
