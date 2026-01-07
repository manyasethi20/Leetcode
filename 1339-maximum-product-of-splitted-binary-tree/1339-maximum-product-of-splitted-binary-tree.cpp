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
    static const int MOD = 1e9 + 7;
    vector<long long> sums;

    long long dfs(TreeNode* root) {
        if (!root) return 0;
        long long s = root->val + dfs(root->left) + dfs(root->right);
        sums.push_back(s);
        return s;
    }

    int maxProduct(TreeNode* root) {
        long long total = dfs(root);
        long long ans = 0;

        for (long long s : sums) {
            ans = max(ans, s * (total - s));
        }
        return ans % MOD;
    }
};
