class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>> rows;

        for (int i = 0; i < k; i++) {
            vector<int> temp;
            for (int j = y; j < y + k; j++) {
                temp.push_back(grid[x + i][j]);
            }
            rows.push_back(temp);
        }

        reverse(rows.begin(), rows.end());

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                grid[x + i][y + j] = rows[i][j];
            }
        }

        return grid;
    }
};