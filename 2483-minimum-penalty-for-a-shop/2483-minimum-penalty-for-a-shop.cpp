class Solution {
public:
    int bestClosingTime(string customers) {
        int score = 0, maxScore = 0, ans = 0;

        for (int i = 0; i < customers.size(); i++) {
            score += (customers[i] == 'Y') ? 1 : -1;
            if (score > maxScore) {
                maxScore = score;
                ans = i + 1;
            }
        }
        return ans;
    }
};
