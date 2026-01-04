class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int x : nums) {
            int p = round(cbrt(x));
            if (p * p * p == x && isPrime(p)) {
                ans += (1 + p + p * p + x);
                continue;
            }

            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    int q = x / i;
                    if (i != q && isPrime(i) && isPrime(q)) {
                        ans += (1 + i + q + x);
                    }
                    break;
                }
            }
        }

        return ans;
    }
};
