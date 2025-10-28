class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, maximum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) ans++;
            else ans = 0;

            maximum = max(maximum, ans);
        }
        return maximum;
    }
};