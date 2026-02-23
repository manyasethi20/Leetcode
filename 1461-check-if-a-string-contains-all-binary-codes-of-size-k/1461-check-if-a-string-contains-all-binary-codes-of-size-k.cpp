class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int need = 1 << k;

        if (n - k + 1 < need) return false;

        vector<bool> seen(need, false);
        int mask = need - 1;
        int num = 0, count = 0;

        for (int i = 0; i < n; i++) {
            num = ((num << 1) & mask) | (s[i] - '0');

            if (i >= k - 1 && !seen[num]) {
                seen[num] = true;
                count++;
                if (count == need) return true;
            }
        }
        return false;
    }
};