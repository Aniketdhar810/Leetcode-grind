class Solution {
public:
    bool check(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL)
            return true;
        if (root1 == NULL || root2 == NULL)
            return false;
        if (root1->val != root2->val)
            return false;

        // Check flip equivalence in two scenarios:
        // 1. No flip: left-left and right-right
        // 2. Flip: left-right and right-left
        bool noFlip = check(root1->left, root2->left) &&
                      check(root1->right, root2->right);
        bool flip = check(root1->left, root2->right) &&
                    check(root1->right, root2->left);

        return noFlip || flip;
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return check(root1, root2);
    }
};
