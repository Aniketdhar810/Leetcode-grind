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
    // int maxDepth(TreeNode* root) {
    //     if(root==NULL) return 0;
    //     int l=maxDepth(root->left);
    //     int r=maxDepth(root->right);
    //     return 1+max(l,r);
    // }
int dfsHeight (TreeNode *root) {
    if (root == NULL) return 0;
    int leftHeight = dfsHeight (root -> left);
    if (leftHeight == -1) return -1;
    int rightHeight = dfsHeight (root -> right);
    if (rightHeight == -1) return -1;
    if (abs(leftHeight - rightHeight) > 1) return -1;   
    return max (leftHeight, rightHeight) + 1;

}
    bool isBalanced(TreeNode* root) {
        // if (root == nullptr) {
        //     return true;
        // }
        // int leftHeight = maxDepth(root->left);
        // int rightHeight = maxDepth(root->right);
        // if (abs(leftHeight - rightHeight) <= 1 &&
        //     isBalanced(root->left) &&
        //     isBalanced(root->right)) {
        //     return true;
        // }
        // return false;
        return dfsHeight (root) != -1;
    }
};