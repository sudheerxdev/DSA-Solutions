class Solution {
public:
    int sumi= 0 ; 
    void helper(TreeNode * root , int sum){
        if(root == nullptr){
            return ;
        }
         sum = sum * 10 + root -> val ;
        if(root->left == nullptr && root -> right ==  nullptr){
            sumi += sum;
        }
       
        helper(root -> left , sum );
        helper(root -> right , sum);

    }
    int sumNumbers(TreeNode* root) {
        helper(root , 0);
        return sumi;
    }
};
