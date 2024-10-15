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
    void traversal(TreeNode* node,int level,vector<int>&ans){
        if(node==NULL) return ;
        if(level==ans.size()) ans.push_back(node->val);
        //for leftside view simply swap below two lines
        traversal(node->right,level+1,ans);
        traversal(node->left,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        traversal(root,0,ans);
        return ans;
    }
};