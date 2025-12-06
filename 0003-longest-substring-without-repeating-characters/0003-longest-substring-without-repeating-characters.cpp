class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int l = 0, ans = 0;

        for(int r = 0; r < s.size(); r++) {
            while(seen.count(s[r])) {
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};