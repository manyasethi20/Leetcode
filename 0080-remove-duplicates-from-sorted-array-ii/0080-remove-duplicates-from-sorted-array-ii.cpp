class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int write = 0;
        int i = 0;
        while(i < (int)nums.size()) {
            int val = nums[i];
            int count = 0;
            while(i < (int)nums.size() && nums[i] == val) {
                if(count < 2) {
                    nums[write++] = nums[i];
                }
                ++count;
                ++i;
            }
        }
        return write;
    }
};