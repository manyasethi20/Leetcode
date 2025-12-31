class Solution {
public:
    vector<int> parent, rank;
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row * col;
        int TOP = n, BOTTOM = n + 1;

        parent.resize(n + 2);
        rank.resize(n + 2, 0);
        for (int i = 0; i < n + 2; i++) parent[i] = i;

        vector<vector<int>> grid(row, vector<int>(col, 1));
        vector<int> dir = {0, 1, 0, -1, 0};

        for (int i = n - 1; i >= 0; i--) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 0;

            int id = r * col + c;

            if (r == 0) unite(id, TOP);
            if (r == row - 1) unite(id, BOTTOM);

            for (int d = 0; d < 4; d++) {
                int nr = r + dir[d], nc = c + dir[d + 1];
                if (nr >= 0 && nr < row && nc >= 0 && nc < col &&
                    grid[nr][nc] == 0) {
                    unite(id, nr * col + nc);
                }
            }

            if (find(TOP) == find(BOTTOM))
                return i;
        }
        return 0;
    }
};
