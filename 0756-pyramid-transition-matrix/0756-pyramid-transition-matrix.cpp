class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;

    bool dfs(string curr) {
        if (curr.size() == 1) return true;
        if (memo.count(curr)) return memo[curr];

        bool res = false;
        helper(curr, 0, "", res);
        memo[curr] = res;
        return res;
    }

    void helper(string &curr, int idx, string next, bool &res) {
        if (res) return;

        if (idx == curr.size() - 1) {
            if (dfs(next)) res = true;
            return;
        }

        string key = curr.substr(idx, 2);
        if (!mp.count(key)) return;

        for (char c : mp[key]) {
            helper(curr, idx + 1, next + c, res);
        }
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed)
            mp[s.substr(0,2)].push_back(s[2]);

        return dfs(bottom);
    }
};
