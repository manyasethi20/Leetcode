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
    unordered_map<int, long long> mp;
    int maxDepth = 0;

    void dfs(TreeNode* node, int depth) {
        if (!node) return;
        mp[depth] += node->val;
        maxDepth = max(maxDepth, depth);
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }

    int maxLevelSum(TreeNode* root) {
        dfs(root, 1);

        long long maxSum = LLONG_MIN;
        int ans = 1;

        for (int i = 1; i <= maxDepth; i++) {
            if (mp[i] > maxSum) {
                maxSum = mp[i];
                ans = i;
            }
        }

        return ans;
    }
};
