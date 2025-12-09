class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        vector<long long> left(200001, 0), right(200001, 0);

        for(int x : nums) right[x]++;
        long long ans = 0;
        for(int j = 0; j < nums.size(); j++) {
            int x = nums[j];
            right[x]--;

            int d = x * 2;
            if(d <= 200000) {
                ans = (ans + left[d] * right[d]) % MOD;
            }
            left[x]++;
        } 
        return ans;
    }
};