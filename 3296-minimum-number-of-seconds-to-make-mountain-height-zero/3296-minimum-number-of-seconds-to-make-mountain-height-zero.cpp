class Solution {
public:
    
    bool can(long long T, int H, vector<int>& w) {
        long long total = 0;

        for(int t : w) {
            long long val = (2*T)/t;

            long long x = (sqrt(1 + 4*val) - 1)/2;

            total += x;

            if(total >= H)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        long long l = 0, r = 1e18;
        long long ans = r;

        while(l <= r) {
            long long mid = (l + r)/2;

            if(can(mid, mountainHeight, workerTimes)) {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        return ans;
    }
};