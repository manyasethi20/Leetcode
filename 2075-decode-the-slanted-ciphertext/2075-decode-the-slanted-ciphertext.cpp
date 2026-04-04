class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if (n == 0) return "";

        int cols = n / rows;
        string result = "";

        for (int start = 0; start < cols; start++) {
            int i = 0, j = start;

            while (i < rows && j < cols) {
                result += encodedText[i * cols + j];
                i++;
                j++;
            }
        }

        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};