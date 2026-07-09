class Solution {
	private:
	void insert(stack<int>&st , int x){
	    if(st.empty()){
	        st.push(x);
	        return ;
	    }
	    int top = st.top();
	    st.pop();
	    insert(st , x);
	    st.push(top);
	}
	void reverse(stack<int>&st){
	    if(st.empty()){
	        return ;
	    }
	    int top = st.top();
	    st.pop();
	    reverse(st);
	    insert(st , top);
	}
	public:
	void reverseStack(stack<int> &st) {
		// code here
		reverse(st);
	}
};
