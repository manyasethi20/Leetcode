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
    void inorder(TreeNode* root, vector<TreeNode*>& nodes) {
        if (!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }

    TreeNode* build(int l, int r, vector<TreeNode*>& nodes) {
        if (l > r) return NULL;
        int mid = l + (r - l) / 2;
        TreeNode* root = nodes[mid];
        root->left = build(l, mid - 1, nodes);
        root->right = build(mid + 1, r, nodes);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        inorder(root, nodes);
        return build(0, nodes.size() - 1, nodes);
    }
};
