/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int ans = INT_MIN;
    int solve(Node* root){
        if(!root) return INT_MAX;

        int leftMin = solve(root->left);
        int rightMin = solve(root->right);

        int minVal = min(leftMin,rightMin);
        ans = max(ans,root->data-minVal);

        return min(root->data,min(leftMin,rightMin));
    }
    int maxDiff(Node* root) {
        // code here
        solve(root);
        return ans;
    }
};
//GFG POTD solution for 20 August
