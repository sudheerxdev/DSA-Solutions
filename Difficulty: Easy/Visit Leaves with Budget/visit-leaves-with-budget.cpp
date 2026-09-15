class Solution {
  public:
    void dfs(Node* root, int level, vector<int>& leaves) {
        if (root == nullptr)
            return;
        if (root->left == nullptr && root->right == nullptr) {
            leaves.push_back(level);
            return;
        }
        dfs(root->left, level + 1, leaves);
        dfs(root->right, level + 1, leaves);
    }
    int getCount(Node *root, int k) {
        if (root == nullptr || k <= 0)
            return 0;
        vector<int> leaves;
        dfs(root, 1, leaves);
        sort(leaves.begin(), leaves.end());
        int count = 0;
        int cost = 0;
        for (int depth : leaves) {
            if (cost + depth > k)
                break;
            cost += depth;
            count++;
        }
        return count;
    }
};
//GFG POTD solution for 15 September
