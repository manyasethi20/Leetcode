class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> good(n, false);
        good[n - 1] = true;

        for(int i = n - 2; i >= 0; --i) {
            int furthest = min(n - 1, i + nums[i]);
            for(int j = i + 1; j <= furthest; j++) {
                if(good[j]) {
                    good[i] = true;
                    break;
                }
            }
        }
        return good[0];
    }
};