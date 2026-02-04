class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string w;
        while (ss >> w) words.push_back(w);

        if (pattern.size() != words.size()) return false;

        unordered_map<char, int> p;
        unordered_map<string, int> wmap;

        for (int i = 0; i < pattern.size(); i++) {
            if (p[pattern[i]] != wmap[words[i]])
                return false;

            p[pattern[i]] = wmap[words[i]] = i + 1;
        }
        return true;
    }
};