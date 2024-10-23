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
    vector<int> levelSum(TreeNode* root) {
        vector<int>level_Sum;
        if(root==NULL) return level_Sum;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int cur_Sum=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                cur_Sum+=node->val;
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
            }
            level_Sum.push_back(cur_Sum);
        }
        return level_Sum;
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int>levelSums=levelSum(root);
        queue<TreeNode*>nodeQueue;
        nodeQueue.push(root);
        int levelIndex = 1;
        root->val = 0;  
        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                int siblingSum =
                    (currentNode->left ? currentNode->left->val : 0) +
                    (currentNode->right ? currentNode->right->val : 0);

                if (currentNode->left) {
                    currentNode->left->val = levelSums[levelIndex] - siblingSum;
                    nodeQueue.push(currentNode->left);
                }
                if (currentNode->right) {
                    currentNode->right->val =
                        levelSums[levelIndex] - siblingSum;
                    nodeQueue.push(currentNode->right);
                }
            }
            ++levelIndex;
        }
        return root;
    }
};