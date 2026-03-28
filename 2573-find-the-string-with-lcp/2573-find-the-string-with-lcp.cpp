class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        for (int i = 0; i < n; i++) {
            if (lcp[i][i] != n - i) return "";
        }

        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };

        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b) parent[b] = a;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (lcp[i][j] > 0) {
                    unite(i, j);
                }
            }
        }

        vector<char> res(n);
        unordered_map<int, char> mp;
        char ch = 'a';

        for (int i = 0; i < n; i++) {
            int p = find(i);
            if (!mp.count(p)) {
                if (ch > 'z') return ""; 
                mp[p] = ch++;
            }
            res[i] = mp[p];
        }

        string word(res.begin(), res.end());

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (word[i] == word[j]) {
                    dp[i][j] = 1 + ((i+1 < n && j+1 < n) ? dp[i+1][j+1] : 0);
                }
            }
        }

        if (dp != lcp) return "";

        return word;
    }
};