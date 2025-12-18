class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                string r = "row" + to_string(i) + board[i][j];
                string c = "col" + to_string(j) + board[i][j];
                string b = "box" + to_string((i/3)*3 + j/3) + board[i][j];

                if (seen.count(r) || seen.count(c) || seen.count(b))
                    return false;

                seen.insert(r);
                seen.insert(c);
                seen.insert(b);
            }
        }
        return true;
    }
};
