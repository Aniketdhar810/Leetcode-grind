/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> arr;
    void postorder_t(Node* root){
        if(root==NULL){
            return;
        }
        for (Node* child : root->children) {
            postorder_t(child);
        }
        arr.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        postorder_t(root);
        return arr;
    }
};