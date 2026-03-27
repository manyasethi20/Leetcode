class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        int shift = k % n;

        vector<vector<int>> result = mat;

        for (int i = 0; i < m; i++) {
            vector<int> newRow(n);

            for (int j = 0; j < n; j++) {
                if (i % 2 == 0) {
                    newRow[j] = mat[i][(j + shift) % n];
                } else {
                    newRow[j] = mat[i][(j - shift + n) % n];
                }
            }

            result[i] = newRow;
        }

        return result == mat;
    }
};