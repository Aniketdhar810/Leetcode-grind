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
    vector<vector<long long>> levelOrder(TreeNode* root) {
        vector<vector<long long>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int size=q.size();
            vector<long long>level(size);
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                int index = leftToRight ? i : (size - i - 1);
                level[index] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(level);
        }
        return ans;
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<vector<long long>>tree=levelOrder(root);
        vector<long long>sum_Tree;
        if(tree.size()<k){
            return -1;
        }
        for(int i=0;i<tree.size();i++){
            long long sum=0;
            for(int j=0;j<tree[i].size();j++){
                sum+=tree[i][j];
            }
            sum_Tree.push_back(sum);
        }
        sort(sum_Tree.rbegin(),sum_Tree.rend());
        return sum_Tree[k-1];
    }
};