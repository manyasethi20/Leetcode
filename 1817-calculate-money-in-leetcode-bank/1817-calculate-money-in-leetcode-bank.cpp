class Solution {
public:
    int totalMoney(int n) {
        int total = 0;
        int week_start = 1;

        while(n > 0) {
            int days = min(n, 7);

            for(int i = 0; i < days; i++) {
                total += week_start + i;
            }

            week_start++;
            n -= days;
        }
        return total;
    }
};