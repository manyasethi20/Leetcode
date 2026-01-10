class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);

        for (int j = 1; j <= m; j++)
            prev[j] = prev[j-1] + s2[j-1];

        for (int i = 1; i <= n; i++) {
            curr[0] = prev[0] + s1[i-1];
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1])
                    curr[j] = prev[j-1];
                else
                    curr[j] = min(
                        s1[i-1] + prev[j],
                        s2[j-1] + curr[j-1]
                    );
            }
            prev = curr;
        }

        return prev[m];
    }
};
