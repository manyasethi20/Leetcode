class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> out;
        out.reserve(nums.size());
        for(int x : nums) {
            int m = out.size();
            if(m < 2 || out[m - 1] != x || out[m - 2] != x) {
                out.push_back(x);
            }
        }
        for(size_t i = 0; i < out.size(); ++i) nums[i] = out[i];
        return (int)out.size();
    }
};