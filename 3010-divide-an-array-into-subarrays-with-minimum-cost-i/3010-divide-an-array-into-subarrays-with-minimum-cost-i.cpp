class Solution {
public:
    int minimumCost(vector<int>& nums) {
        vector<int> temp(nums.begin() + 1, nums.end());
        sort(temp.begin(), temp.end());
        return nums[0] + temp[0] + temp[1];
    }
};