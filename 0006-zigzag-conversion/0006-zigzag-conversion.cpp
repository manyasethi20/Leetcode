class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.size()) return s;

        vector<string> rows(numRows);
        int curr = 0;
        int dir = -1;

        for(char c : s) {
            rows[curr] += c;
            if(curr == 0 || curr == numRows - 1) dir *= -1;
            curr += dir;
        }

        string result = "";
        for(string &row : rows) result += row;

        return result;
    }
};