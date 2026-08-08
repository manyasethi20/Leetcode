class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                prefix[i + 1][j + 1] = mat[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
            }
        }
         vector<vector<int>> answer(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int sum = 0;

                int startRow = max(0, i - k);
                int endRow = min(m - 1, i + k);

                int startCol = max(0, j - k);
                int endCol = min(n - 1, j + k);

                int whole = prefix[endRow + 1][endCol + 1];
                int top = prefix[startRow][endCol + 1];
                int left = prefix[endRow + 1][startCol];
                int overlap = prefix[startRow][startCol];

                answer[i][j] = whole - top - left + overlap;
            }
        }
        return answer;
    }
};