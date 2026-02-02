class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        auto comp = [&nums](int a, int b) {
            if (nums[a] != nums[b]) return nums[a] < nums[b];
            else return a < b;
        };
        set<int, decltype(comp)> lst(comp), rst(comp);
        int l = 1, r = 1;
        long long sums = 0, res = LLONG_MAX;
        while (r < n) {
            if (r - l > dist) {
                auto it1 = lst.find(l);
                if (it1 != lst.end()) {
                    sums -= nums[*it1];
                    lst.erase(it1);
                }
                auto it2 = rst.find(l);
                if (it2 != rst.end()) {
                    rst.erase(it2);
                }
                l++;
            }
            rst.insert(r);
            if (lst.size() < k-1 || nums[*(rst.begin())] < nums[*(lst.rbegin())]) {
                auto it = rst.begin();
                lst.insert(*it);
                sums += nums[*it];
                rst.erase(it);
            }
            if (lst.size() >= k) {
                auto it = prev(lst.end());
                sums -= nums[*it];
                rst.insert(*it);
                lst.erase(it);
            }
            if (lst.size() == k-1) res = min(res,sums);
            r++;
        }
        return res + nums[0];
    }
};