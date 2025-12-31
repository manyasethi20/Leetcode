class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> next(m, vector<int>(n, 0));

        int dirs[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = 0;
                for (auto& d : dirs) {
                    int x = i + d[0], y = j + d[1];
                    if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 1)
                        live++;
                }

                if (board[i][j] == 1) {
                    if (live == 2 || live == 3)
                        next[i][j] = 1;
                } else {
                    if (live == 3)
                        next[i][j] = 1;
                }
            }
        }
        board = next;
    }
};
