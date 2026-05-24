/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode * root , int &targetsum , int sum){
        if(root == nullptr){
            return false;
        }
        sum += root -> val ;
        if(root -> left == nullptr && root-> right == nullptr){
            return sum == targetsum;
        }
        bool left = helper(root->left , targetsum , sum);
        bool right = helper(root->right , targetsum , sum);
        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root , targetSum , 0);
    }
};
