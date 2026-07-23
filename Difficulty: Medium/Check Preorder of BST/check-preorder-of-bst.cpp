class Solution {
public:
    bool canRepresentBST(vector<int>& arr) {
        int N = arr.size();

        vector<int> suffix(N);
        suffix[N - 1] = arr[N - 1];

        for (int i = N - 2; i >= 0; i--)
            suffix[i] = min(arr[i], suffix[i + 1]);

        stack<int> st;
        st.push(-1);

        for (int i = N - 1; i >= 0; i--) {
            while (st.top() != -1 && arr[st.top()] < arr[i])
                st.pop();

            if (st.top() != -1) {
                if (suffix[st.top()] < arr[i])
                    return false;
            }

            st.push(i);
        }

        return true;
    }
};
//GFG POTD solution for 23 July
