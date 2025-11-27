class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string a = strs[0];
        string b = strs.back();
        int i = 0;
        while(i < a.size() && i < b.size() && a[i] == b[i]) {
            i++;
        }

        return a.substr(0, i);
    }
};