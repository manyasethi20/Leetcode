class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                result[i] = 0;
                continue;
            }

            int jump = nums[i] % n;
            int target = (i + jump + n) % n;
            result[i] = nums[target];
        }
        return result;
    }
};
