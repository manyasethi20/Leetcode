class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) { return a[2] < b[2]; });

        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;

        vector<bool> knows(n, false);
        knows[0] = knows[firstPerson] = true;

        int i = 0;
        while (i < meetings.size()) {
            int time = meetings[i][2];
            vector<pair<int,int>> curr;

            while (i < meetings.size() && meetings[i][2] == time) {
                unite(meetings[i][0], meetings[i][1]);
                curr.push_back({meetings[i][0], meetings[i][1]});
                i++;
            }

            unordered_set<int> affected;
            for (auto &p : curr) {
                affected.insert(p.first);
                affected.insert(p.second);
            }

            unordered_map<int, bool> hasSecret;
            for (int p : affected) {
                if (knows[p])
                    hasSecret[find(p)] = true;
            }

            for (int p : affected) {
                if (hasSecret[find(p)])
                    knows[p] = true;
                else
                    parent[p] = p;  
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++)
            if (knows[i]) res.push_back(i);
        return res;
    }
};
