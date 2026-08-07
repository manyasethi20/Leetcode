class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int currentPrefix = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            currentPrefix += nums[i];

            int needed = currentPrefix - k;

            count += mp[needed];
            
            mp[currentPrefix]++;
        }
        return count;
    }
};