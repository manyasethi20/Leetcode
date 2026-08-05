class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int left = 0;
        int ans = 0;
        unordered_map<int, int> freq;

        for(int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;

            while(freq.size() > k) {
                freq[nums[left]]--;

                if(freq[nums[left]] == 0) freq.erase(nums[left]);

                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};