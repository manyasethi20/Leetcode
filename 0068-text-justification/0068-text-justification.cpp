class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while(i < n) {
            int lineLen = words[i].size();
            int j = i + 1;

            while(j < n && lineLen + 1 + words[j].size() <= maxWidth) {
                lineLen += 1 + words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line = "";

            if(j == n || gaps == 0) {
                for(int k = i; k < j; k++) {
                    line += words[k];
                    if(k != j - 1) line += " ";
                }
                line += string(maxWidth - line.size(), ' ');
            } else {
                int totalSpaces = maxWidth - (lineLen - gaps);
                int spacePerGap = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for(int k = i; k < j; k++) {
                    line += words[k];
                    if(k != j - 1) {
                        int spaces = spacePerGap + (extraSpaces > 0 ? 1 : 0);
                        line += string(spaces, ' ');
                        if(extraSpaces > 0) extraSpaces--;
                    }
                }
            }
            result.push_back(line);
            i = j;
        }
        return result;
    }
};