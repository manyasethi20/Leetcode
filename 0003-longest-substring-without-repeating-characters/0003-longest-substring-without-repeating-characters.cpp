class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ans = 0;

        for(int i = 0; i < n; i++) {
            unordered_set<char> seen;
            for(int j = i; j < n; j++) {
                if(seen.count(s[j])) break;
                seen.insert(s[j]);
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};