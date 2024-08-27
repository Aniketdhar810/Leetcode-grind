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
    vector<int> arr;
    void postorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        arr.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        // postorder(root);
        // return arr;
        vector<int>postorder;
        if(root==NULL) return postorder;
        stack<TreeNode*>st1;
        stack<TreeNode*>st2;
        TreeNode* node=root;
        st1.push(node);
        while(!st1.empty()){
            node=st1.top();
            st1.pop();
            st2.push(node);
            if(node->left!=NULL){
                st1.push(node->left);
            }
            if(node->right!=NULL){
                st1.push(node->right);
            }
        }
        while(!st2.empty()){
            node=st2.top();
            st2.pop();
            postorder.push_back(node->val);
        }
        return postorder;
    }
};