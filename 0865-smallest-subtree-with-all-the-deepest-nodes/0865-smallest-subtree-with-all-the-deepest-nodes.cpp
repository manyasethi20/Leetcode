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
    int maxDepth = 0;

    void findDepth(TreeNode* root, int depth) {
        if (!root) return;
        maxDepth = max(maxDepth, depth);
        findDepth(root->left, depth + 1);
        findDepth(root->right, depth + 1);
    }

    TreeNode* lcaDeepest(TreeNode* root, int depth) {
        if (!root) return nullptr;
        if (depth == maxDepth) return root;

        TreeNode* left = lcaDeepest(root->left, depth + 1);
        TreeNode* right = lcaDeepest(root->right, depth + 1);

        if (left && right) return root;
        return left ? left : right;
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        findDepth(root, 0);
        return lcaDeepest(root, 0);
    }
};
