//GFG POTD solution for 07 oct

/* Node Structure
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = nullptr;
        right = nullptr;
    }
}
*/

#include <algorithm>
#include <climits>

class Solution {
  private:
    int solve(Node* root, int &max_sum) {
        if (root == nullptr) {
            return INT_MIN;
        }

        // Base case: Leaf node
        if (root->left == nullptr && root->right == nullptr) {
            return root->data;
        }

        int leftSum = solve(root->left, max_sum);
        int rightSum = solve(root->right, max_sum);

        // If both left and right children exist, a path between two leaves can be formed
        if (root->left != nullptr && root->right != nullptr) {
            max_sum = std::max(max_sum, leftSum + rightSum + root->data);
            return std::max(leftSum, rightSum) + root->data;
        }

        // If only one child exists, pass up the valid path sum from the existing child
        return (root->left != nullptr ? leftSum : rightSum) + root->data;
    }

  public:
    int maxPathSum(Node *root) {
        int max_sum = INT_MIN;
        int val = solve(root, max_sum);

        // Special case: If the root node itself is where the two leaf paths meet,
        // but it wasn't caught inside helper (e.g. root has both subtrees leading to leaves)
        if (root != nullptr && root->left != nullptr && root->right != nullptr) {
            max_sum = std::max(max_sum, leftSum_or_both(root, max_sum));
        }

        return (max_sum == INT_MIN) ? -1 : max_sum;
    }

  private:
    int leftSum_or_both(Node* root, int &max_sum) {
        // Cleaning up the wrapper function call logic
        return max_sum;
    }
};
//for Daily POTD(Unstop/leetcode/GFG) follow @POTDunstop


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna