class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> temp;
        for (int x : nums)
            if (x != val) temp.push_back(x);
        nums = temp;
        return nums.size();
    }
};