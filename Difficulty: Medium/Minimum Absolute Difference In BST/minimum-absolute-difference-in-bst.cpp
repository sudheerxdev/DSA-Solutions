/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
  public:
    void inorder(Node* root, int&prev, int&res){
            if(root){
                inorder(root->left, prev, res);
                if(prev >=0){
                    res = min(res, root->data - prev);
                }
                prev = root->data;
                inorder(root->right, prev, res);
            }
        }
    int absDiff(Node *root) {
        int res = INT_MAX;
                int prev = -1;
                inorder(root, prev, res);
                return res;

    }
};
//GFG POTD solution for 18 September
