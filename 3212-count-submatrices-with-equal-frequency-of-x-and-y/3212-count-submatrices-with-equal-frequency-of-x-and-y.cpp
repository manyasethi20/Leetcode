class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> sum(n+1, vector<int>(m+1, 0));
        vector<vector<int>> countX(n+1, vector<int>(m+1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                int val = 0;
                if (grid[i-1][j-1] == 'X') val = 1;
                else if (grid[i-1][j-1] == 'Y') val = -1;

                sum[i][j] = val + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];

                countX[i][j] = countX[i-1][j] + countX[i][j-1] - countX[i-1][j-1];
                if (grid[i-1][j-1] == 'X') countX[i][j]++;
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (sum[i][j] == 0 && countX[i][j] > 0)
                    ans++;
            }
        }

        return ans;
    }
};