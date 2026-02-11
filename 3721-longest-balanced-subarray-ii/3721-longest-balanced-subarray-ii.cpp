struct Node {
    int mn = 0, mx = 0, lazy = 0;
};

class SegmentTree {
public:
    int n;
    vector<Node> t;

    SegmentTree(const vector<int>& a) : n(a.size()), t(4 * n + 1) {
        build(a, 1, n, 1);
    }

    void add(int l, int r, int v) { update(l, r, v, 1, n, 1); }

    int find_last(int start, int val) {
        if (start > n) return -1;
        return find(start, n, val, 1, n, 1);
    }

private:
    void apply(int i, int v) {
        t[i].mn += v;
        t[i].mx += v;
        t[i].lazy += v;
    }

    void push(int i) {
        if (t[i].lazy) {
            apply(i<<1, t[i].lazy);
            apply(i<<1|1, t[i].lazy);
            t[i].lazy = 0;
        }
    }

    void pull(int i) {
        t[i].mn = min(t[i<<1].mn, t[i<<1|1].mn);
        t[i].mx = max(t[i<<1].mx, t[i<<1|1].mx);
    }

    void build(const vector<int>& a, int l, int r, int i) {
        if (l == r) { t[i].mn = t[i].mx = a[l-1]; return; }
        int m = (l + r) >> 1;
        build(a, l, m, i<<1);
        build(a, m+1, r, i<<1|1);
        pull(i);
    }

    void update(int L, int R, int v, int l, int r, int i) {
        if (L <= l && r <= R) { apply(i, v); return; }
        push(i);
        int m = (l + r) >> 1;
        if (L <= m) update(L, R, v, l, m, i<<1);
        if (R > m) update(L, R, v, m+1, r, i<<1|1);
        pull(i);
    }

    int find(int L, int R, int val, int l, int r, int i) {
        if (t[i].mn > val || t[i].mx < val) return -1;
        if (l == r) return l;
        push(i);
        int m = (l + r) >> 1;
        int res = -1;
        if (R > m) res = find(L, R, val, m+1, r, i<<1|1);
        if (res != -1) return res;
        if (L <= m) return find(L, R, val, l, m, i<<1);
        return -1;
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size(), len = 0;
        map<int, queue<int>> occ;
        auto sgn = [](int x){ return x%2==0 ? 1 : -1; };

        vector<int> pref(n);
        pref[0] = sgn(nums[0]);
        occ[nums[0]].push(1);

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i-1];
            if (occ[nums[i]].empty()) pref[i] += sgn(nums[i]);
            occ[nums[i]].push(i+1);
        }

        SegmentTree seg(pref);

        for (int i = 0; i < n; i++) {
            int pos = seg.find_last(i + len, 0);
            if (pos != -1) len = max(len, pos - i);

            int next = n + 1;
            occ[nums[i]].pop();
            if (!occ[nums[i]].empty()) next = occ[nums[i]].front();
            seg.add(i + 1, next - 1, -sgn(nums[i]));
        }

        return len;
    }
};
