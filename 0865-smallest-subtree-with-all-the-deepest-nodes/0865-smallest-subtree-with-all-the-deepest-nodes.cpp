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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*, TreeNode*> parent;
        vector<TreeNode*> level;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            level.clear();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                level.push_back(node);
                if (node->left) {
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if (node->right) {
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }

        unordered_set<TreeNode*> s(level.begin(), level.end());
        while (s.size() > 1) {
            unordered_set<TreeNode*> next;
            for (auto node : s)
                next.insert(parent[node]);
            s = move(next);
        }

        return *s.begin();
    }
};
