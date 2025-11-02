class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = INT_MIN;
        int curr = 1;
        for(int i = 0; i < nums.size(); i++) {
            curr = curr * nums[i];
            max_product = max(curr, max_product);
            if(curr == 0) {
                curr = 1;
            }
        }

        curr = 1;
        for(int i = nums.size() - 1; i >= 0; i--) {
            curr = curr * nums[i];
            max_product = max(curr, max_product);
            if(curr == 0) {
                curr = 1;
            }
        }
        return max_product;
    }
};