class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        vector<int> need(128, 0);
        for(char c : t) need[c]++;

        int required = t.size();
        int left = 0, right = 0;
        int start = 0, minLen = INT_MAX;

        while(right < s.size()) {
            if(need[s[right]] > 0) {
                required--;
            }

            need[s[right]]--;
            right++;

            while(required == 0) {
                if(right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                need[s[left]]++;

                if(need[s[left]] > 0) {
                    required++;
                }

                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen); 
    }
};