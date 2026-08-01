class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currentStreak = 0;
        int maxStreak = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) currentStreak++;
            else currentStreak = 0;

            maxStreak = max(currentStreak, maxStreak);
        }
        return maxStreak;
    }
};