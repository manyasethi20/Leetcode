class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int lo = 1, hi = cells.size(), ans = 0;
        vector<int> dir = {0, 1, 0, -1, 0};

        auto canCross = [&](int day) {
            vector<vector<int>> grid(row, vector<int>(col, 0));
            for (int i = 0; i < day; i++)
                grid[cells[i][0]-1][cells[i][1]-1] = 1;

            queue<pair<int,int>> q;
            vector<vector<bool>> vis(row, vector<bool>(col, false));

            for (int j = 0; j < col; j++) {
                if (grid[0][j] == 0) {
                    q.push({0, j});
                    vis[0][j] = true;
                }
            }

            while (!q.empty()) {
                auto [r, c] = q.front(); q.pop();
                if (r == row - 1) return true;

                for (int k = 0; k < 4; k++) {
                    int nr = r + dir[k], nc = c + dir[k+1];
                    if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                        !vis[nr][nc] && grid[nr][nc] == 0) {
                        vis[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            return false;
        };

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (canCross(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};
