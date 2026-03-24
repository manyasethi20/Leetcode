class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int size = n * m;

        vector<int> arr;
        for (auto &row : grid) {
            for (auto &x : row) {
                arr.push_back(x % 12345);
            }
        }

        vector<int> prefix(size, 1), suffix(size, 1);

        for (int i = 1; i < size; i++) {
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % 12345;
        }

        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % 12345;
        }

        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < size; i++) {
            int val = (prefix[i] * suffix[i]) % 12345;
            res[i / m][i % m] = val;
        }

        return res;
    }
};