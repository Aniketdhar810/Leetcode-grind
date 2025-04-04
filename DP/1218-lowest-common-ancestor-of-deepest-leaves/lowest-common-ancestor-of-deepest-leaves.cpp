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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        TreeNode* ans=root;
        int maxi=0;
        function<int(TreeNode*,int)> dfs = [&](TreeNode* node,int d)->int {
            int left=d,right=d;
            if(node->left){
                left=dfs(node->left,d+1);
            }
            if(node->right){
                right=dfs(node->right,d+1);
            }
            maxi=max(maxi,d);
            if(left==maxi && right==maxi) ans=node;
            return max({left,right,d});
        };
        dfs(root,0);
        return ans;

    }
};