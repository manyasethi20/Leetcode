class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> answer(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int sum = 0;

                int startRow = max(0, i - k);
                int endRow = min(m - 1, i + k);

                int startCol = max(0, j - k);
                int endCol = min(n - 1, j + k);

                for(int r = startRow; r <= endRow; r++) {
                    for(int c = startCol; c <= endCol; c++) {
                        sum += mat[r][c];
                    }
                }
                answer[i][j] = sum;
            }
        }
        return answer;
    }
};