class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int target = nums.size() - 1;

        while(target > 0) {
            for(int i = 0;i < target; i++) {
                if(i + nums[i] >= target) {
                    target = i;
                    jumps++;
                    break;
                }
            }
        }
        return jumps;
    }
};