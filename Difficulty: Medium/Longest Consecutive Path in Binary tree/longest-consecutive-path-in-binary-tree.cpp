class Solution {
    int ans = 1;
    
    void dfs(Node* root, int prev, int len) {
        if (!root) return;
        
        if (root->data == prev + 1)
            len++;
        else
            len = 1;
        
        ans = max(ans, len);
        
        dfs(root->left, root->data, len);
        dfs(root->right, root->data, len);
    }

public:
    int longestConsecutive(Node* root) {
        if (!root) return -1;
        dfs(root, root->data - 1, 0);
        return ans == 1 ? -1 : ans;
    }
};
//GFG POTD solution for 24 July
