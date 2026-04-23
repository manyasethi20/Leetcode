class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(nums.size(), 0);
        
        for (auto& [num, indices] : mp) {
            long long totalSum = accumulate(indices.begin(), indices.end(), 0LL);

            long long prefix = 0;

            for(int i = 0; i < indices.size(); i++){
                long long leftSum = prefix;
                prefix += indices[i];
                long long rightSum = totalSum - prefix;
                long long totalLeftSum = ((long long)i * indices[i]) - leftSum;
                long long totalRightSum = rightSum - ((long long)(indices.size() - i - 1) * indices[i]);
                ans[indices[i]] = totalLeftSum + totalRightSum;
            }
        }

        return ans;
    }
};