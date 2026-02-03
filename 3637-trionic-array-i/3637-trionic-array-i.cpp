class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int p,q;
        if(n<=3)
            return false;
        for(p=1; p<n; p++)
        {
            if(nums[p] <= nums[p-1])
                break;
        }
        p--;
        cout<<p<<" ";
        if(p==0 || p>=n-2)
            return false;
        for(q = p+1; q<n-1; q++)
        {
            if(nums[q] >= nums[q-1])
                break;
        }
        q--;
        cout<<q<<endl;
        if(p==q || q==n-1)
            return false;
        for(int i = q; i<n-1; i++)
        {
            if(nums[i+1] <= nums[i])
                return false;
        }
        return true;
    }
};