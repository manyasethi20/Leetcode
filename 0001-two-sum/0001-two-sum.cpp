class Solution {
public:
    vector<int> twoSum(vector <int>& nums, int target) {
        unordered_map<int, int> mp;
        int x, index, need;
        for(int i = 0; i < nums.size(); i++) {
            x = nums[i];
            need = target - x;
            if(mp.find(need) != mp.end()) {
                return {mp[need], i};
            } else {
                mp[nums[i]] = i;
            }
        }
        return {};
    }
};