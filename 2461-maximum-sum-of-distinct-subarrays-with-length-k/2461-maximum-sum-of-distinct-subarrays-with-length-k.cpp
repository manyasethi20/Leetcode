class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long windowSum = 0;
        long long maxSum = 0;

        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
            freq[nums[i]]++;
        }

        if (freq.size() == k)
            maxSum = windowSum;

        for (int i = 0; i < nums.size() - k; i++) {
            windowSum = windowSum - nums[i] + nums[i + k];

            freq[nums[i]]--;
            if (freq[nums[i]] == 0)
                freq.erase(nums[i]);

            freq[nums[i + k]]++;

            if (freq.size() == k)
                maxSum = max(maxSum, windowSum);
        }

        return maxSum;
    }
};