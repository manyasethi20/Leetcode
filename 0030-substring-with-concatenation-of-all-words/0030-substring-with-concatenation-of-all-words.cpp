class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if(words.empty() || s.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if(s.size() < totalLen) return result;

        unordered_map<string, int> required;
        for(string &w : words) required[w]++;

        for(int offset = 0; offset < wordLen; offset++) {
            int left = offset, count = 0;
            unordered_map<string, int> current;

            for(int right = offset; right + wordLen <= s.size(); right += wordLen) {
                string word = s.substr(right, wordLen);

                if(required.count(word)) {
                    current[word]++;
                    count++;

                    while(current[word] > required[word]) {
                        string leftWord = s.substr(left, wordLen);
                        current[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if(count == wordCount) {
                        result.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        current[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                }
                else {
                    current.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return result;
    }
};