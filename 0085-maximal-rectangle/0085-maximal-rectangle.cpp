class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int R = mat.size(), C = mat[0].size();
        vector<vector<int>> dp(R, vector<int>(C, 0));
        int ans = 0;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (mat[i][j] == '1') {
                    dp[i][j] = (j == 0) ? 1 : dp[i][j-1] + 1;
                    int width = dp[i][j];
                    for (int k = i; k >= 0; k--) {
                        width = min(width, dp[k][j]);
                        ans = max(ans, width * (i - k + 1));
                    }
                }
            }
        }
        return ans;
    }
};