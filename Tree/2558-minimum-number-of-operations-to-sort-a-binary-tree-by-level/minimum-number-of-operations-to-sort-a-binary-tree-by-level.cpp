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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>level;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        vector<vector<int>>tree=levelOrder(root);
        int ans=0;
        //Q ya hai minimum swaps required to sort ans array
        for(int i=1;i<tree.size();i++){
            vector<pair<int,int>>mp;
            for(int j=0;j<tree[i].size();j++){
                mp.push_back({tree[i][j],j});
            }
            sort(mp.begin(),mp.end());
            for(int j=0;j<tree[i].size();j++){
                pair<int,int>p=mp[j];
                int val=p.first;
                int index=p.second;
                if(j!=index){
                    ans++;
                    swap(mp[j],mp[index]);
                    j--;
                }
            }
        }
        return ans;
    }
};