class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int m = nums.size();
        int k = 0, t = 0;
        for(int i = 0; i < m; i++) {
            for(int j = i + 1; j < m; j++) {
                if(nums[i] + nums[j] == target) {
                    k = i;
                    t = j;
                }
            }
        }
        return {k, t};
    }
};